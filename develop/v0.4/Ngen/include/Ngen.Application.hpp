/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

Copyright (c) 2016 FIXCOM, LLC

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
#ifndef __NGEN_APPLICATION_HPP
#define __NGEN_APPLICATION_HPP

#include "Ngen.Mirror.hpp"
#include "Ngen.Task.hpp"

namespace Ngen {
   /**@brief
    */
   class Application {
   public:
      Application(const string& identity) : mId(identity), mIsRunning(false), mIsPaused(false) {
      }

      void Initialize() {
         Initialized.Fire(this);
      }

      void Run(uword fps=0) {
         Initialize();

         mIsRunning = true;
         Started.Fire(this);

         while(mIsRunning) {
            if(!mIsPaused) {
               this->Update();
            }
         }

         Close();
      }

      virtual void Update() {
         Updated.Fire(this);
      }

      virtual void Close() {
         if(mIsRunning) {
            mIsRunning = false;
            Closed.Fire(this);
         }
      }

      event Started;
      event Closed;
      event Paused;
      event Updated;
      event Initialized;

   protected:
      static Application* mCurrent;

      mirror mId;
      bool mIsRunning;
      bool mIsPaused;
   };
}

#endif // __NGEN_REFLECTION_HPP
