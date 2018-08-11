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
#ifndef __NGEN_DRAWING_EVERTEXELEMENTTYPE_HPP
#define __NGEN_DRAWING_EVERTEXELEMENTTYPE_HPP

#include "Ngen.Drawing.Typedefs.hpp"

namespace Ngen {
   namespace Drawing {

      enum class EVertexElementType {
         BOOLEAN,
			FLOAT,
			DOUBLE,
			UINT,
			INT,
			ULONG,
			LONG,
#if tknval_RegisterWidth == 32
			REAL = FLOAT,
			WORD = LONG,
			UWORD = ULONG,
#else
			REAL = DOUBLE,
			WORD = INT,
			UWORD = UINT,
#endif
		};

		/*
		GLenum gl_typeof(EVertexElementType type) {
			switch(type) {
			case EVertexElementType::FLOAT: return Glenum::;
			case EVertexElementType::DOUBLE: return GL_DOUBLE;
			case EVertexElementType::UINT: return GL_UINT;
			case EVertexElementType::INT: return GL_INT;
			case EVertexElementType::ULONG: return GL_ULONG;
			case EVertexElementType::LONG: return GL_LONG;
			default: return 0;
			}
		}

		uword gl_sizeof(EVertexElementType type, uword length=1) {
			switch(type) {
			case EVertexElementType::FLOAT: return sizeof(float)*length;
			case EVertexElementType::DOUBLE: return sizeof(double)*length;
			case EVertexElementType::UINT: return sizeof(uint32)*length;
			case EVertexElementType::INT: return sizeof(int32)*length;
			case EVertexElementType::ULONG: return sizeof(uint64)*length;
			case EVertexElementType::LONG: return sizeof(int64)*length;
			default: return 0;
			}
		}
*/
   }
}

#endif // __NGEN_DRAWING_EVERTEXELEMENTTYPE_HPP
