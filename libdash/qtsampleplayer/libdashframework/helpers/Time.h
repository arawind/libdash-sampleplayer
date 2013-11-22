/*
 * Time.h
 *****************************************************************************
 * Copyright (C) 2013, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef DASH_HELPERS_TIME_H_
#define DASH_HELPERS_TIME_H_

#include <time.h>
#include <string>
#include "libdash.h"
#include <sys/time.h>
namespace libdash
{
	namespace framework{
    namespace helpers
    {
        class Time
        {
            public:
                static uint32_t     GetCurrentUTCTimeInSec  ();
                static uint64_t	    GetCurrentUTCTimeInMilliSec();
                static std::string  GetCurrentUTCTimeStr    ();

            private:
                static struct tm*   GetCurrentUTCTime       ();

        };
    }
	}
}

#endif /* DASH_HELPERS_TIME_H_ */
