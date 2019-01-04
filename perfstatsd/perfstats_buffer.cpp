/*
 * Copyright (C) 2018 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define LOG_TAG "perfstatsd_buffer"

#include "perfstats_buffer.h"

using namespace android::pixel::perfstatsd;

void PerfstatsBuffer::emplace(statsdata &&data) {
    while (mStorage.size() + 1 > mBufferSize) {
        if (mStorage.empty()) {
            break;
        }
        mStorage.pop();
    }
    mStorage.emplace(std::forward<statsdata>(data));
}

const std::queue<statsdata> &PerfstatsBuffer::dump(void) {
    return mStorage;
}
