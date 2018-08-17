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
#ifndef __NGEN_ALARM_HPP
#define __NGEN_ALARM_HPP

#include "Ngen.Alarm.hpp"
#include "Ngen.String.hpp"
#include "Ngen.Event.hpp"
#include "Ngen.Time.hpp"

namespace Ngen {

   class Alarm {
   public:
      typedef VoidStaticDelegate<Alarm*> TTick;

      Alarm(uword rateInSeconds, TTick onTick) : Activated(), Deactivated(), Ticked(),
               mOnTick(onTick), mIsActive(false), mRate(rateInSeconds), mRemaing(rateInSeconds) {
         Ticked += Callback(0, (Delegate*)&mOnTick);
         mCache.Add(this);
      }

      ~Alarm() {
         Ticked -= Callback(0, (Delegate*)&mOnTick);
         mCache.Remove(this);
      }

      void Activate() {
         mIsActive = true;
         Activated.Fire(this);
      }

      void Deactivate() {
         mIsActive = false;
         Deactivated.Fire(this);
      }

      void Tick() {
         if(mIsActive) {
            auto now = Time::Now();
            uword span = now.Millisecond() - mLastTick.Millisecond();
            mRemaing -= span;

            if(mRemaing <= 0 || mRate == 0) {
               Ticked.Fire(this);
               mRemaing = mRate;
            }

            mLastTick = Time::Now();
         }
      }

      static uword Count() {
         return mCache.Length();
      }

      event Activated;
      event Deactivated;
      event Ticked;

      static void TickAll() {
         for(uword i = 0; i < mCache.Length(); ++i) {
            //mCache.Begin(i)->Tick();
         }
      }

      static void ClearAll() {
         mCache.Clear();
      }

   protected:
      TTick mOnTick;
      bool mIsActive;
      uword mRate;
      uword mRemaing;
      timespan mLastTick;

      static Array<Alarm*> mCache;
   };
}
#endif
