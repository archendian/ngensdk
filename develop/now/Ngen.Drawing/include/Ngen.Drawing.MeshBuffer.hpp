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
#ifndef __NGEN_DRAWING_MESHBUFFER_HPP
#define __NGEN_DRAWING_MESHBUFFER_HPP

#include "Ngen.Drawing.VertexBuffer.hpp"

namespace Ngen {
   namespace Drawing {



		class ngen_drawing_api MeshBuffer : public virtual GraphicBuffer {
		public:
			template<typename TVertex>
			MeshBuffer(EGfxBufferDrawMode mode, VertexScheme* scheme, TVertex* vertices, uword vertexCount, uword* indices, uword indexCount) :
				mMode(mode), mVertex(vertices, scheme, vertexCount), mIndex(indices, indexCount) {
				}

			MeshBuffer(EGfxBufferDrawMode mode, const VertexBuffer& vertex, const Array<uword>& index) :
				mMode(mode), mVertex(&vertex), mIndex(index) {
         }

			void Bind() const {
				mVertex->Bind();
			}

			void Unbind() {
				mVertex->Unbind();
			}

			EGfxBufferDrawMode DrawMode() const { return mMode; }
			VertexScheme* Scheme() const { return mVertex->Scheme(); }

			void Draw() const;

		protected:
			EGraphicBufferDrawMode mMode;
			VertexBuffer* mVertex;
			Array<uword> mIndex;
		};
   }
}
#endif // __NGEN_DRAWING_MESHBUFFER_HPP
