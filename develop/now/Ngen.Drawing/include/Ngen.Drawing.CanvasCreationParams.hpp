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
#ifndef __NGEN_DRAWING_CANVASCREATIONPARAMS_HPP
#define __NGEN_DRAWING_CANVASCREATIONPARAMS_HPP

#include "Ngen.Drawing.MeshBuffer.hpp"

using namespace Ngen;
using namespace Ngen::Math;

namespace Ngen {
   namespace Drawing {

      class ngen_drawing_api CanvasCreationParams {
		public:
			uword Width;
			uword Height;
			Color4 Background;
			uword ColorDepth;
			real ZFar;
			real ZNear;
			bool Stero;

			CanvasCreationParams(uword width=800, uword height=640, /*Color4 background,*/ uword depth=32, real zfar=-1.0, real znear=1.0, bool stero=false) :
				Width(width), Height(height), /*Background(background),*/ ColorDepth(depth), ZFar(zfar), ZNear(znear), Stero(stero) {
			}

			CanvasCreationParams(const CanvasCreationParams& copy) :
				Width(copy.Width), Height(copy.Height), /*Background(copy.Background),*/ ColorDepth(copy.ColorDepth),
               ZFar(copy.ZFar), ZNear(copy.ZNear), Stero(copy.Stero) {
			}
		};
   }
}

#endif // __NGEN_DRAWING_CANVASCREATIONPARAMS_HPP
