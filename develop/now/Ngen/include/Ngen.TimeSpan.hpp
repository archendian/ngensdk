/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2017 FIXCOM, LLC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sub-license, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#ifndef __NGEN_TIMESPAN_HPP
#define __NGEN_TIMESPAN_HPP

#include "Ngen.Typedefs.hpp"
#include "Ngen.String.hpp"

using namespace std;
using namespace chrono;

namespace Ngen {
   class TimeSpan {
   public:
      TimeSpan(bool utc=false) : mPoint(system_clock::now()), mTime(system_clock::to_time_t(mPoint)), mIsUtc(utc) {}
      TimeSpan(system_clock::time_point time, bool utc=false) : mPoint(time), mTime(system_clock::to_time_t(time)), mIsUtc(utc) {}

      uint64 Nanosecond() { return (uint64)duration_cast<chrono::nanoseconds>(mPoint.time_since_epoch()).count(); }
      uint64 Microsecond() { return (uint64)duration_cast<chrono::microseconds>(mPoint.time_since_epoch()).count(); }
      uint64 Millisecond() { return (uint64)duration_cast<chrono::milliseconds>(mPoint.time_since_epoch()).count(); }
      uint64 Second() { return (uint64)duration_cast<chrono::seconds>(mPoint.time_since_epoch()).count(); }
      uint64 Minute() { return (uint64)duration_cast<chrono::minutes>(mPoint.time_since_epoch()).count(); }
      uint64 Hour() { return (uint64)duration_cast<chrono::hours>(mPoint.time_since_epoch()).count(); }
      uint64 Day() { return (uint64)(Hour()/24); }

      TimeSpan& operator-=(const TimeSpan& rhs) {
          mPoint = system_clock::time_point(mPoint - rhs.mPoint);
          return *this;
      }

      TimeSpan operator-(const TimeSpan& rhs) const {
          return TimeSpan(system_clock::time_point(mPoint - rhs.mPoint));
      }

      bool operator==(const TimeSpan& rhs) const {
         return mIsUtc == rhs.mIsUtc && mPoint == rhs.mPoint;
      }

      bool operator!=(const TimeSpan& rhs) const {
         return mIsUtc != rhs.mIsUtc || mPoint != rhs.mPoint;
      }

      TimeSpan& operator=(const TimeSpan& rhs) {
         this->mPoint = rhs.mPoint;
         this->mIsUtc = rhs.mIsUtc;
         return *this;
      }

      bool IsUtcTime() const { return mIsUtc; }

   protected:
      system_clock::time_point mPoint;
      time_t mTime;
      bool mIsUtc;

      friend class Time;
   };

   typedef TimeSpan timespan;
}

#endif // __NGEN_TIMESPAN_HPP
