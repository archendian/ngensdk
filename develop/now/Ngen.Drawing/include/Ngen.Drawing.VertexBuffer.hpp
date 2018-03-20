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

				VertexBuffer(VertexScheme* scheme, uword length, EGraphicBufferUsage usage=EGraphicBufferUsage::STATIC_DRAW) : GraphicBuffer(0, usage), mScheme(scheme), mSize(scheme->Size()*length) {
					glGenVertexBuffer(1, &this->mId);
					glBindVertexbuffer(GL_ARRAY_BUFFER, this->mId);
					scheme->Set();
					glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
				}

				VertexBuffer(ubyte* vertex, VertexScheme* scheme, uword length, bool shadow=false, EGraphicBufferUsage usage=EGraphicBufferUsage::STATIC_DRAW) :  GraphicBuffer(0, usage), mLength(length), mScheme(scheme){
					glGenVertexBuffer(1, &this->mId);
					glBindVertexbuffer(GL_ARRAY_BUFFER, this->mId);
					scheme->Set();
					this->Set(vertex, length, shadow);
					glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
				}

				VertexBuffer(VertexBuffer&& mov);

				~VertexBuffer();

				void Bind() const;
				void Draw(EGfxDrawMode drawMode);
				void Draw(EGfxDrawMode drawMode, uword begin, uword end);
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
