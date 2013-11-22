/*
 * LogElement.cpp
 *
 *  Created on: 21-Nov-2013
 *      Author: arawind
 */

#include "LogElement.h"

namespace libdash {
namespace framework {
namespace helpers {

LogElement::LogElement(int segmentNumber, uint64_t start, int duration, uint64_t payload, uint32_t rate) :
	segmentNumber (segmentNumber),
	start (start),
	duration (duration),
	payload (payload),
	rate (rate)
{

}

LogElement::~LogElement() {
}

uint64_t LogElement::getStart(){
	return this->start;
}


int LogElement::getSegmentNumber(){
	return this->segmentNumber;
}

int LogElement::getDuration(){
	return this->duration;
}

void LogElement::setDuration(int duration){
	this->duration = duration;
}

uint64_t LogElement::getPayload(){
	return this->payload;
}

void LogElement::setPayload(uint64_t payload){
	this->payload = payload;
}

uint32_t LogElement::getRate(){
	return this->rate;
}

void LogElement::setRate(uint32_t rate){
	this->rate = rate;
}

}
}
}
