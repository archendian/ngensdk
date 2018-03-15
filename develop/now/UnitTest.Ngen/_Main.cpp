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
using namespace Ngen::Math;
using namespace Ngen::Drawing;
using namespace Ngen::Diagnostic;

Window*              NGEN_WINDOW;
CanvasCreationParams NGEN_CCPARAM;
Canvas*              NGEN_CANVAS;

int main(int32 length, const char** args) {
   NGEN_WINDOW = Window(0, 0, 800, 640, const_string("Ngen Framework"));
   NGEN_WINDOW.Show();

   NGEN_CCPARAM.Width = NGEN_WINDOW.Width();
   NGEN_CCPARAM.Height = NGEN_WINDOW.Height();
   NGEN_CCPARAM.ColorDepth = 32;
   NGEN_CCPARAM.Stero = false;
   NGEN_CCPARAM.ZFar = 100.0f;
   NGEN_CCPARAM.ZNear = 0.01f;
   NGEN_CCPARAM.Background = Color4::Blue();
   NGEN_CANVAS = Canvas(NGEN_WINDOW, NGEN_CCPARAM);

   do {
      NGEN_CANVAS.Clear();
      NGEN_CANVAS.Update();
   } while(NGEN_WINDOW.HandleMessage());

   return 0;
}
