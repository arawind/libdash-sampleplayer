/*
 * Logger.h
 *
 *  Created on: 21-Nov-2013
 *      Author: arawind
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include "libdash.h"
#include "IDASHManagerObserver.h"
#include "../helpers/Time.h"
#include "../helpers/LogElement.h"

namespace libdash {
namespace framework {
namespace input {

	class Logger
	{
		private:
			std::vector<libdash::framework::helpers::LogElement *>	logs;
		public:
			Logger();
			virtual ~Logger();
			uint32_t log   (int segmentNumber, uint64_t bytesDownloaded);
			void rateLog (int segmentNumber, uint32_t rate);
			const std::vector<libdash::framework::helpers::LogElement *> & getLogs() const;
	};

} /* namespace input */
} /* namespace framework */
} /* namespace libdash */

#endif /* LOGGER_H_ */
