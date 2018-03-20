


namespace Ngen {
   namespace Drawing {
       GLenum typeof(EGraphicBufferUsage usage) {
			switch(usage) {
			case EGraphicBufferUsage::STATIC_DRAW:   return GL_STATIC_DRAW;
			case EGraphicBufferUsage::STATIC_READ:   return GL_STATIC_READ;
			case EGraphicBufferUsage::STATIC_COPY:   return GL_STATIC_COPY;
			case EGraphicBufferUsage::STREAM_READ:   return GL_STREAM_READ;
			case EGraphicBufferUsage::STREAM_DRAW:   return GL_STREAM_DRAW;
			case EGraphicBufferUsage::STREAM_COPY:   return GL_STREAM_COPY;
			case EGraphicBufferUsage::DYNAMIC_DRAW:  return GL_DYNAMIC_DRAW;
			case EGraphicBufferUsage::DYNAMIC_READ:  return GL_DYNAMIC_READ;
			case EGraphicBufferUsage::DYNAMIC_COPY:  return GL_DYNAMIC_COPY;
			default: return 0;
			}
		}

      VertexBuffer::VertexBuffer(VertexScheme* scheme, uword length, EGraphicBufferUsage usage) : GraphicBuffer(0), mLength(length), mSize(scheme->Size()*length), mScheme(scheme),{
         glGenVertexBuffer(1, &this->mId);
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

      void VertexBuffer::pSet(ubyte* vertex, uword length) {
         mSize = length * mScheme->Size();
         mLength = length;
         glBufferData(this->mId, mSize, vertex, typeof(this->mUsage));
      }

      void VertexBuffer::Draw(EGraphicDrawMode drawMode) {
         glDrawArrays(0, mLength, typeof(drawMode));
      }

      void VertexBuffer::Draw(EGraphicDrawMode drawMode, uword begin, uword end) {
         glDrawArrays(begin, end, typeof(drawMode));
      }

      void VertexBuffer::UnBind() const { glBindVertexbuffer(GL_ARRAY_BUFFER, 0); }
      uword VertexBuffer::Size() const { return mScheme->Size() * mLength; }

   }
}
