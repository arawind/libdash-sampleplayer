/*
 * Logger.cpp
 *
 *  Created on: 21-Nov-2013
 *      Author: arawind
 */

#include "Logger.h"

using namespace libdash::framework::input;
using namespace libdash::framework::helpers;

Logger::Logger() {
	// TODO Auto-generated constructor stub

}

Logger::~Logger() {
	// TODO Auto-generated destructor stub
}
uint32_t Logger::log   (int segmentNumber, uint64_t bytesDownloaded){
	//std::cout << "Rate Changed! " << logs.size() << std::endl;
	uint64_t time = Time::GetCurrentUTCTimeInMilliSec();
	uint32_t rate = 0;
	int duration = 0;
	if(logs.size() > 0){
		LogElement *log = logs.back();
		rate = log->getRate();
		int n;
		float dur = 0;
		uint64_t sumBytes = 0;
		if(log->getSegmentNumber() == segmentNumber){
			duration = time - log->getStart();
			log->setDuration(duration);
			log->setPayload(bytesDownloaded);
		}
		else{
			LogElement *newLog = new LogElement(segmentNumber, time, duration, bytesDownloaded, rate);
			logs.push_back(newLog);
		}
		n = (logs.size() < 5) ? logs.size() : 5;

		for(int i = logs.size() - 1; i > logs.size() - n - 1 ; i--){
			//std::cout<< i << " "<< logs.size() << std::endl;
			//dur += logs.at(i)->getDuration()/1000.0;

			dur = (logs.back()->getDuration() + logs.back()->getStart() - logs.at(i)->getStart())/1000.0;
			sumBytes += logs.at(i)->getPayload();
		}


		if(dur != 0){
			rate = sumBytes/dur;
			log->setRate(rate);
			//std::cout << rate << " dur: " <<dur << std::endl;
		}

		//std::cout << "----" << std::endl;
	}
	else{
		LogElement *newLog = new LogElement(segmentNumber, time, duration, bytesDownloaded, rate);
		logs.push_back(newLog);
	}
	return rate;
}

void Logger::rateLog (int segmentNumber, uint32_t rate){
	uint64_t time = Time::GetCurrentUTCTimeInMilliSec();
	int duration = 0;
	if(logs.size() > 0)
		duration = time - logs.at(0)->getStart();
	LogElement *newLog = new LogElement(segmentNumber, time, duration, 0, rate );
	logs.push_back(newLog);
}

const std::vector<LogElement *> & Logger::getLogs() const{
	return (std::vector<LogElement *>  &)this->logs;
}
