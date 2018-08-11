

#include "Ngen.Drawing.VertexBuffer.hpp"

namespace Ngen {
   namespace Drawing {

      VertexBuffer::VertexBuffer(VertexScheme* scheme, uword length, EGraphicBufferUsage usage) :
         GraphicBuffer(0), mSize(scheme->Size()*length), mLength(length), mScheme(scheme) {
      /*
         glGenVertexBuffer(1, &this->mId);
         glBindVertexbuffer(GL_ARRAY_BUFFER, mId);
         scheme->Set();
         glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
      */
      }

      VertexBuffer::VertexBuffer(VertexScheme* scheme, byte* vertex, uword length, bool shadow, EGraphicBufferUsage usage) :
          GraphicBuffer(0),  mSize(scheme->Size()*length), mLength(length), mScheme(scheme){
      /*
         glGenVertexBuffer(1, &this->mId);
         glBindVertexbuffer(GL_ARRAY_BUFFER, mId);
         scheme->Set();
         this->Fill(vertex, length);
         glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
      */
      }

      VertexBuffer::VertexBuffer(VertexBuffer&& mov) : GraphicBuffer(mov.mId), mSize(mov.mSize), mLength(mov.mLength), mScheme(mov.mScheme)  {
         mov.mId=null;
         mov.mScheme=null;
         mov.mLength=0;
      }

      VertexBuffer::~VertexBuffer() {
         if(mId != null) {
            //glDeleteBuffers(1, mId);
         }
      }

      void VertexBuffer::Bind() const {
         //glBindVertexbuffer(GL_ARRAY_BUFFER, this->mId);
      }

      // virtual GraphicBuffer->pSet
      void VertexBuffer::pSet(byte* vertex, uword length) {
         mSize = length * mScheme->Size();
         mLength = length;
         //glBufferData(this->mId, mSize, (ubyte*)vertex, typeof(this->mUsage));
      }

      void VertexBuffer::Draw(EGraphicDrawMode drawMode) {
         //glDrawArrays(0, mLength, typeof(drawMode));
      }

      void VertexBuffer::Draw(EGraphicDrawMode drawMode, uword begin, uword end) {
         //glDrawArrays(begin, end, typeof(drawMode));
      }


      void VertexBuffer::Unbind() const {
         //glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
      }

      uword VertexBuffer::Size() const { return mScheme->Size() * mLength; }
   }
}
