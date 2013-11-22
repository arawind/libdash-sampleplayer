/*
 * LogElement.h
 *
 *  Created on: 21-Nov-2013
 *      Author: arawind
 */

#ifndef LOGELEMENT_H_
#define LOGELEMENT_H_
#include "libdash.h"
namespace libdash {
namespace framework {
namespace helpers {

class LogElement {
public:
	LogElement(int segmentNumber, uint64_t start, int duration, uint64_t paylaod, uint32_t rate);
	uint64_t getStart();
	int getSegmentNumber();
	int getDuration();
	uint64_t getPayload();
	uint32_t getRate();
	void setDuration(int duration);
	void setPayload(uint64_t payload);
	void setRate(uint32_t rate);
	virtual ~LogElement();
private:
	int segmentNumber;
	uint64_t start;
	int duration; //milliseconds
	uint64_t payload;
	uint32_t rate;
};

} /* namespace helpers */
} /* namespace framework */
} /* namespace libdash */

#endif /* LOGELEMENT_H_ */
