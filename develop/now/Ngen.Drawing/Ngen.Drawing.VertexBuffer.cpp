


namespace Ngen {
   namespace Drawing {
      VertexBuffer::VertexBuffer(VertexScheme* scheme, uword length) : mId(0), mLength(length), mSize(scheme->Size()*length), mScheme(scheme),{
         glGenVertexBuffer(1, &mId);
         glBindVertexbuffer(GL_ARRAY_BUFFER, mId);
         scheme->Set();
         glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
      }

      VertexBuffer::VertexBuffer(unknown vertex, VertexScheme* scheme, uword length) :  mId(0),  mSize(scheme->Size()*length), mLength(length), mScheme(scheme){
         glGenVertexBuffer(1, &mId);
         glBindVertexbuffer(GL_ARRAY_BUFFER, mId);
         scheme->Set();
         this->Fill(vertex, length);
         glBindVertexbuffer(GL_ARRAY_BUFFER, 0);
      }

      VertexBuffer::VertexBuffer(VertexBuffer&& mov) : mId(mov.mId), mSize(mov.mSize) mLength(mov.mLength), mScheme(mov.mScheme)  {
         mov.mId=null;
         mov.mScheme=null;
         mov.mLength=0;
      }

      VertexBuffer::~VertexBuffer() {
         if(mId != null) {
            glDeleteBuffers(1, mId);
         }
      }

      void VertexBuffer::Bind() const {
         glBindVertexbuffer(GL_ARRAY_BUFFER, mId);
      }

      bool VertexBuffer::Fill(unknown vertex, uword newCount) {
         mSize = newCount * mScheme->Size();
         glBufferData(mId, mSize, (unknown)vertex, typeof(EGfxBufferUsage::STATIC_DRAW));
      }

      void VertexBuffer::Draw(EGfxBufferDrawMode drawMode) {
         glDrawArrays(0, mLength, typeof(drawMode));
      }

      void VertexBuffer::Draw(EGfxBufferDrawMode drawMode, uword begin, uword end) {
         glDrawArrays(begin, end, typeof(drawMode));
      }

      void VertexBuffer::UnBind() const { glBindVertexbuffer(GL_ARRAY_BUFFER, 0); }
      uword VertexBuffer::Size() const { return mScheme->Size() * mLength; }

   }
}
