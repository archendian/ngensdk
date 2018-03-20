#ifndef __NGEN_DRAWING_EGFXBUFFERUSAGE__HPP
#define __NGEN_DRAWING_EGFXBUFFERUSAGE__HPP

#include "Ngen.Drawing.Typedefs.hpp"

namespace Ngen {
   namespace Drawing {

		enum class EGraphicBufferUsage {
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
   }
}


#endif // __NGEN_DRAWING_EGFXBUFFERUSAGE__HPP
