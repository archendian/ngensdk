#ifndef __NGEN_DRAWING_MESHBUFFER_HPP
#define __NGEN_DRAWING_MESHBUFFER_HPP

#include "Ngen.Drawing.VertexBuffer.hpp"

namespace Ngen {
   namespace Drawing {



		class ngen_drawing_api MeshBuffer {
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
			EGfxBufferDrawMode mMode;
			VertexBuffer* mVertex;
			Array<uword> mIndex;
		};
   }
}
#endif // __NGEN_DRAWING_MESHBUFFER_HPP
