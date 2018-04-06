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
#ifndef __NGEN_DRAWING_EGFXDRAWMODE_HPP
#define __NGEN_DRAWING_EGFXDRAWMODE_HPP

#include "Ngen.Drawing.Typedefs.hpp"

namespace Ngen {
   namespace Drawing {

      enum class EGraphicDrawMode {
			POINT,
			QUAD,
			QUAD_STRIP,
			POLYGON,
			TRIANGLE,
			TRIANGLE_STRIP,
			TRIANGLE_FAN,
			LINE,
			LINE_STRIP,
			LINE_LOOP,

		};

		GLenum typeof(EGraphicDrawMode mode) {
			switch(mode) {
			case EGraphicDrawMode::POINT: return GL_POINTS;
			case EGraphicDrawMode::QUAD: return GL_QUADS;
			case EGraphicDrawMode::POLYGON: return GL_POLYGON;
			case EGraphicDrawMode::QUAD_STRIP: return GL_QUAD_STRIP;
			case EGraphicDrawMode::TRIANGLE: return GL_TRIANGLES;
			case EGraphicDrawMode::TRIANGLE_FAN: return GL_TRIANGLE_FAN;
			case EGraphicDrawMode::TRIANGLE_STRIP: return GL_TRIANGLE_STRIP;
			case EGraphicDrawMode::LINE: return GL_LINES;
			case EGraphicDrawMode::LINE_STRIP: return GL_LINE_STRIP;
			case EGraphicDrawMode::LINE_LOOP: return GL_LINE_LOOP;
			default: return 0;
			}
		}
   }
}
#endif // __NGEN_DRAWING_EGFXDRAWMODE_HPP
