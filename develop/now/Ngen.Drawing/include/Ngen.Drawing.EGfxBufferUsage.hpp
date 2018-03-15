#ifndef __NGEN_DRAWING_EGFXBUFFERUSAGE__HPP
#define __NGEN_DRAWING_EGFXBUFFERUSAGE__HPP

#include "Ngen.Drawing.Typedefs.hpp"

namespace Ngen {
   namespace Drawing {

		enum class EGfxBufferUsage {
			STATIC_DRAW,
			STATIC_READ,
			STATIC_COPY,
			STREAM_READ,
			STREAM_DRAW,
			STREAM_COPY,
			DYNAMIC_DRAW,
			DYNAMIC_READ,
			DYNAMIC_COPY
		}

      GLenum typeof(EGfxBufferUsage usage) {
			switch(usage) {
			case EGfxBufferUsage::STATIC_DRAW:   return GL_STATIC_DRAW;
			case EGfxBufferUsage::STATIC_READ:   return GL_STATIC_READ;
			case EGfxBufferUsage::STATIC_COPY:   return GL_STATIC_COPY;
			case EGfxBufferUsage::STREAM_READ:   return GL_STREAM_READ;
			case EGfxBufferUsage::STREAM_DRAW:   return GL_STREAM_DRAW;
			case EGfxBufferUsage::STREAM_COPY:   return GL_STREAM_COPY;
			case EGfxBufferUsage::DYNAMIC_DRAW:  return GL_DYNAMIC_DRAW;
			case EGfxBufferUsage::DYNAMIC_READ:  return GL_DYNAMIC_READ;
			case EGfxBufferUsage::DYNAMIC_COPY:  return GL_DYNAMIC_COPY;
			default: return 0;
			}
		}
   }
}


#endif // __NGEN_DRAWING_EGFXBUFFERUSAGE__HPP
