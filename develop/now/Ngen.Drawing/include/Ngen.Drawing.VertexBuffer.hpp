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
#ifndef __NGEN_DRAWING_VERTEXBUFFER_HPP
#define __NGEN_DRAWING_VERTEXBUFFER_HPP

#include "Ngen.Drawing.EGfxDrawMode.hpp"
#include "Ngen.Drawing.EGfxBufferUsage.hpp"
#include "Ngen.Drawing.VertexSemantic.hpp"

namespace Ngen {
   namespace Drawing {


		class ngen_drawing_api VertexBuffer : public virtual GraphicBuffer {
		public:
				VertexBuffer() : GraphicBuffer(0, EGraphicBufferUsage::STATIC_DRAW), mScheme(0), mSize(0) {}

				VertexBuffer(VertexScheme* scheme, uword length, EGraphicBufferUsage usage=EGraphicBufferUsage::STATIC_DRAW) :
				   GraphicBuffer(0, usage), mScheme(scheme), mSize(scheme->Size()*length) {
					glGenVertexBuffer(1, &this->mId);
					glBindVertexbuffer(GL_ARRAY_BUFFER, this->mId);
					scheme->Set();
					glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
				}

				VertexBuffer(ubyte* vertex, VertexScheme* scheme, uword length, bool shadow=false, EGraphicBufferUsage usage=EGraphicBufferUsage::STATIC_DRAW) :
               GraphicBuffer(0, usage), mLength(length), mScheme(scheme){
					glGenVertexBuffer(1, &this->mId);
					glBindVertexbuffer(GL_ARRAY_BUFFER, this->mId);
					scheme->Set();
					this->Set(vertex, length, shadow);
					glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
               this->mUsage = usage;
				}

				VertexBuffer(VertexBuffer&& mov);

				~VertexBuffer();

				void Bind() const;
				void Draw(EGraphicDrawMode drawMode);
				void Draw(EGraphicDrawMode drawMode, uword begin, uword end);
				void UnBind() const;
				uword Size() const;

		protected:
			uword mLength;
			uword mSize;
			VertexScheme* mScheme;
		};
   }
}

#endif // __NGEN_DRAWING_VERTEXBUFFER_HPP
