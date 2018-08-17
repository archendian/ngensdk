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
#ifndef __NGEN_DRAWING_EGFXBUFFERUSAGE__HPP
#define __NGEN_DRAWING_EGFXBUFFERUSAGE__HPP

#include "Ngen.Drawing.Typedefs.hpp"

namespace Ngen {
   namespace Drawing {

		enum class EGpuBufferUsage {
			STATIC_DRAW,
			STATIC_READ,
			STATIC_COPY,
			STREAM_READ,
			STREAM_DRAW,
			STREAM_COPY,
			DYNAMIC_DRAW,
			DYNAMIC_READ,
			DYNAMIC_COPY
		};

		GLenum gl_typeof(EGpuBufferUsage usage) {
			switch(usage) {
			case EGpuBufferUsage::STATIC_DRAW:   return GL_STATIC_DRAW;
			case EGpuBufferUsage::STATIC_READ:   return GL_STATIC_READ;
			case EGpuBufferUsage::STATIC_COPY:   return GL_STATIC_COPY;
			case EGpuBufferUsage::STREAM_READ:   return GL_STREAM_READ;
			case EGpuBufferUsage::STREAM_DRAW:   return GL_STREAM_DRAW;
			case EGpuBufferUsage::STREAM_COPY:   return GL_STREAM_COPY;
			case EGpuBufferUsage::DYNAMIC_DRAW:  return GL_DYNAMIC_DRAW;
			case EGpuBufferUsage::DYNAMIC_READ:  return GL_DYNAMIC_READ;
			case EGpuBufferUsage::DYNAMIC_COPY:  return GL_DYNAMIC_COPY;
			default: return 0;
			}
		}
   }
}


#endif // __NGEN_DRAWING_EGFXBUFFERUSAGE__HPP
