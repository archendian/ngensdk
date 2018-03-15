#ifndef __NGEN_DRAWING_VERTEXBUFFER_HPP
#define __NGEN_DRAWING_VERTEXBUFFER_HPP

#include "Ngen.Drawing.EGfxDrawMode.hpp"
#include "Ngen.Drawing.EGfxBufferUsage.hpp"
#include "Ngen.Drawing.VertexSemantic.hpp"

namespace Ngen {
   namespace Drawing {


		class ngen_drawing_api VertexBuffer {
		public:
				VertexBuffer() : mId(0), mScheme(0), mSize(0) {}

				VertexBuffer(VertexScheme* scheme, uword length) : mId(0), mScheme(scheme), mSize(scheme->Size()*length) {
					glGenVertexBuffer(1, &mId);
					glBindVertexbuffer(GL_ARRAY_BUFFER, mId);
					scheme->Set();
					glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
				}

				VertexBuffer(unknown vertex, VertexScheme* scheme, uword length) :  mId(0), mLength(length), mScheme(scheme){
					glGenVertexBuffer(1, &mId);
					glBindVertexbuffer(GL_ARRAY_BUFFER, mId);
					scheme->Set();
					this->Fill(vertex, length);
					glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
				}

				VertexBuffer(VertexBuffer&& mov);

				~VertexBuffer();

				void Bind() const;
				bool Fill(unknown vertex, uword newCount);
				void Draw(EGfxDrawMode drawMode);
				void Draw(EGfxDrawMode drawMode, uword begin, uword end);
				void UnBind() const;
				uword Size() const;

		protected:
			uword mId;
			uword mLength;
			uword mSize;
			VertexScheme* mScheme;
		};
   }
}

#endif // __NGEN_DRAWING_VERTEXBUFFER_HPP
