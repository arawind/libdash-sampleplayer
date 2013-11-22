/*
 * IDASHReceiverObserver.h
 *****************************************************************************
 * Copyright (C) 2012, bitmovin Softwareentwicklung OG, All Rights Reserved
 *
 * Email: libdash-dev@vicky.bitmovin.net
 *
 * This source code and its use and distribution, is subject to the terms
 * and conditions of the applicable license agreement.
 *****************************************************************************/

#ifndef LIBDASH_FRAMEWORK_INPUT_IDASHRECEIVEROBSERVER_H_
#define LIBDASH_FRAMEWORK_INPUT_IDASHRECEIVEROBSERVER_H_

namespace libdash
{
    namespace framework
    {
        namespace input
        {
            class IDASHReceiverObserver
            {
                public:
                    virtual ~IDASHReceiverObserver () {}
                    virtual	void OnDownloadRateChanged    (uint64_t bytesDownloaded) = 0;
                    virtual void OnSegmentDownloaded      (uint32_t downloadRate) = 0;
            };
        }
    }
}
#endif /* LIBDASH_FRAMEWORK_INPUT_IDASHRECEIVEROBSERVER_H_ */
