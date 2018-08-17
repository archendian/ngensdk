/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2018 FIXCOM, LLC

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
#ifndef __NGEN_WINDOW_HPP
#define __NGEN_WINDOW_HPP

#include "Ngen.Map.hpp"
#include "Ngen.Event.hpp"
#include "Ngen.String.hpp"

namespace Ngen {
   class ngen_api Window {
   public:
      Event OnMoved;
      Event OnResized;
      Event OnClosed;

      Window() : OnMoved(), OnResized(), OnClosed(), mHandle(0), mX(0), mY(0), mWidth(0), mHeight(0) {}
      Window(uword x, uword y, uword width, uword height, const string& title);
      Window(Window&& window) : OnMoved(window.OnMoved), OnResized(window.OnResized), OnClosed(window.OnClosed),
          mHandle(window.mHandle), mX(window.mX), mY(window.mY), mWidth(window.mWidth), mHeight(window.mHeight) {
         window.mHandle=0;
      }

      virtual ~Window();

      void Close();
      void Show();
      void Hide();
      bool HandleMessage();
      unknown Handle() const { return mHandle; }
      void Resize(uword width, uword height);
      void Move(uword x, uword y);
      uword Width() const { return mWidth; }
      uword Height() const { return mHeight; }
      uword X() const { return mX; }
      uword Y() const { return mY; }

   protected:
      unknown mHandle;
      uword mX;
      uword mY;
      uword mWidth;
      uword mHeight;
   };
}


#endif // __NGEN_WINDOW_HPP
