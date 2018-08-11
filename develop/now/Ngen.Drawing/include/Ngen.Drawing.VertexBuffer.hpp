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

#include "Ngen.Drawing.GraphicBuffer.hpp"
#include "Ngen.Drawing.EGraphicDrawMode.hpp"
#include "Ngen.Drawing.EGraphicBufferUsage.hpp"
#include "Ngen.Drawing.VertexScheme.hpp"
#include <GL/glu.h>

namespace Ngen {
   namespace Drawing {


		class ngen_drawing_api VertexBuffer : public virtual GraphicBuffer {
		public:
				VertexBuffer() : GraphicBuffer(0, EGraphicBufferUsage::STATIC_DRAW), mSize(0), mLength(0), mScheme(null) {}
				VertexBuffer(VertexScheme* scheme, uword length, EGraphicBufferUsage usage=EGraphicBufferUsage::STATIC_DRAW);
				VertexBuffer(VertexScheme* scheme, byte* vertex, uword length, bool shadow=false, EGraphicBufferUsage usage=EGraphicBufferUsage::STATIC_DRAW);
				VertexBuffer(VertexBuffer&& mov);
				~VertexBuffer();

				void Bind() const;
				void Draw(EGraphicDrawMode drawMode);
				void Draw(EGraphicDrawMode drawMode, uword begin, uword end);
				void Unbind() const;
				uword Size() const;
				VertexScheme* Scheme() { return mScheme; }
				const VertexScheme* Scheme() const { return mScheme; }
            uword Length() const { return mLength; }

		protected:

         void pSet(byte* vertex, uword length);

			uword mSize;
			uword mLength;
			VertexScheme* mScheme;
		};
   }
}

#endif // __NGEN_DRAWING_VERTEXBUFFER_HPP
