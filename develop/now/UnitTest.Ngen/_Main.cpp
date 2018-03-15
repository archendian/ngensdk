/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2016 FIXCOM, LLC

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
#include "_External.hpp"

using namespace Ngen;
//using namespace Ngen::Math;
using namespace Ngen::Drawing;
using namespace Ngen::Diagnostic;

CanvasCreationParams NGEN_CCPARAM;

int main(int32 length, const char** args) {
   auto window = Window(0, 0, 800, 640, const_string("Ngen Framework"));
   window.Show();

   auto ccparam = CanvasCreationParams();
   ccparam.Width = window.Width();
   ccparam.Height = window.Height();
   ccparam.ColorDepth = 32;
   ccparam.Stero = false;
   ccparam.ZFar = 100.0f;
   ccparam.ZNear = 0.01f;
   //ccparam.Background = Color4::Blue();

   auto canvas = Canvas(&window, ccparam);

   while(window.HandleMessage()) {
      canvas.Clear();

      canvas.Update();
   }

   return 0;
}
