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
#include "Ngen.Drawing.hpp"

namespace Ngen {
   namespace Drawing {
      GLenum gl_typeof(EShaderType type) {
         switch(type) {
         case EShaderType::VERTEX: return GL_VERTEX_SHADER;
         case EShaderType::GEOMETRY: return GL_GEOMETRY_SHADER;
         case EShaderType::FRAGMENT: return GL_FRAGMENT_SHADER;
         default: return 0;
         }
      }

		GLenum gl_typeof(EGpuElementType type) {
			switch(type) {
			case EGpuElementType::REAL: return GL_FLOAT;
			case EGpuElementType::FLOAT: return GL_FLOAT;
			case EGpuElementType::DOUBLE: return GL_DOUBLE;
			case EGpuElementType::UINT: return GL_UNSIGNED_INT;
			case EGpuElementType::INT: return GL_INT;
			case EGpuElementType::BYTE: return GL_BYTE;
			case EGpuElementType::BOOL: return GL_BOOL;
			default: return 0;
			}
		}

		uword gl_sizeof(EGpuElementType type, uword length) {
			switch(type) {
			case EGpuElementType::REAL: return sizeof(float)*length;
			case EGpuElementType::FLOAT: return sizeof(float)*length;
			case EGpuElementType::DOUBLE: return sizeof(double)*length;
			case EGpuElementType::UINT: return sizeof(uint32)*length;
			case EGpuElementType::INT: return sizeof(int32)*length;
			case EGpuElementType::BYTE: return sizeof(char8)*length;
			case EGpuElementType::BOOL: return sizeof(bool)*length;
			default: return 0;
			}
		}

		GLenum gl_typeof(EGpuDrawMode mode) {
			switch(mode) {
			case EGpuDrawMode::POINT: return GL_POINTS;
			case EGpuDrawMode::QUAD: return GL_QUADS;
			case EGpuDrawMode::POLYGON: return GL_POLYGON;
			case EGpuDrawMode::QUAD_STRIP: return GL_QUAD_STRIP;
			case EGpuDrawMode::TRIANGLE: return GL_TRIANGLES;
			case EGpuDrawMode::TRIANGLE_FAN: return GL_TRIANGLE_FAN;
			case EGpuDrawMode::TRIANGLE_STRIP: return GL_TRIANGLE_STRIP;
			case EGpuDrawMode::LINE: return GL_LINES;
			case EGpuDrawMode::LINE_STRIP: return GL_LINE_STRIP;
			case EGpuDrawMode::LINE_LOOP: return GL_LINE_LOOP;
			default: return 0;
			}
		}

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
