
#include "Ngen.Drawing.MeshBuffer.hpp"

namespace Ngen {
   namespace Drawing {

      void MeshBuffer::Draw() const {
         glDrawElements(typeof(mMode), mVertex->mLength, GL_UNSIGNED_INT, mIndex->Begin());
      }
   }
}
