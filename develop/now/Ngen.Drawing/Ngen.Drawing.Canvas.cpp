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
#include "Ngen.Drawing.Canvas.hpp"

namespace Ngen {
   namespace Drawing {
      #if tkn_Platform == tknval_Platform_Windows
      HDC win32_HDC;
      HGLRC win32_HRC;

      Canvas::Canvas(Window* window, CanvasCreationParams params) : mWindow(window), mParams(params) {
         params.Width = mWindow->Width();
         params.Height = mWindow->Height();

         PIXELFORMATDESCRIPTOR pfd;
         int iFormat;

         *win32_HDC = GetDC ((HWND)window->Handle());
         ZeroMemory (&pfd, sizeof (pfd));
         pfd.nSize = sizeof (pfd);
         pfd.nVersion = 1;
         pfd.dwFlags = PFD_DRAW_TO_WINDOW |
         PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
         pfd.iPixelType = PFD_TYPE_RGBA;
         pfd.cColorBits = 24;
         pfd.cDepthBits = 16;
         pfd.iLayerType = PFD_MAIN_PLANE;
         iFormat = ChoosePixelFormat (*win32_HDC, &pfd);
         SetPixelFormat (*win32_HDC, iFormat, &pfd);

         *win32_HRC = wglCreateContext(*win32_HDC);
         wglMakeCurrent(*win32_HDC, *win32_HRC);
      }

      Canvas::~Canvas() {
         wglMakeCurrent (NULL, NULL);
         wglDeleteContext (win32_HRC);
         ReleaseDC ((HWND)mWindow->Handle(), win32_HDC);
      }

      void Canvas::Update() const {
         SwapBuffers(win32_HDC);
      }
      #endif
   }
}
