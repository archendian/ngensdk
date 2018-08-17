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
#ifndef __NGEN_TIME_HPP
#define __NGEN_TIME_HPP

#include "Ngen.TimeSpan.hpp"
#include "Ngen.Exception.hpp"

using namespace std;
using namespace chrono;

namespace Ngen {

      class Time {
      public:
          static TimeSpan Now(bool utc=false) { return TimeSpan(utc); }
          static TimeSpan UtcNow() { return Now(true); }
          //static uint64 TickPerMicrosecond() { return TickPerMillisecond() / 1000 < 1 ? 0 : TickPerMillisecond() / 1000; }
          //static uint64 TickPerMillisecond() { return TickPerSecond() / 1000; }
          //static uint64 TickPerSecond() { return (uint64)system_clock::period()::den; }

           static string DayByNumber(uword day=1) {
               if(day > 12) {
                  THROW(Exception());
               }

               return day == 0 ? const_string("Sunday") : mMonthName[day];
           }

           static uword DayNumber(string day=const_string("Monday")) {
               uword result = mDayName.Length();

               if(!mDayName.Contains(day, inref result)) {
                   THROW(Exception());
               }

               return result;
           }

           static string MonthByNumber(uword month=1) {
               if(month > 12) {
                  THROW(Exception());
               }

               return month == 0 ? const_string("January") : mMonthName[month];
           }

           static uword MonthNumber(string month=const_string("January")) {
               uword result = mDayName.Length();

               if(!mMonthName.Contains(month, inref result)) {
                   THROW(Exception());
               }

               return result;
           }

       protected:
           static Array<string> mDayName;
           static Array<string> mMonthName;
      };
}


#endif // __NGEN_TIME_HPP
