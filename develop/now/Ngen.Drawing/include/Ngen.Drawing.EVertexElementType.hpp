
#ifndef __NGEN_DRAWING_EVERTEXELEMENTTYPE_HPP
#define __NGEN_DRAWING_EVERTEXELEMENTTYPE_HPP

#include "Ngen.Drawing.Typedefs.hpp"

namespace Ngen {
   namespace Drawing {

      enum class EVertexElementType {
			FLOAT,
			DOUBLE,
			UINT,
			INT,
			ULONG,
			LONG,
#if tknval_RegisterWidth == 32
			REAL = FLOAT,
			WORD = LONG,
			UWORD = ULONG,
#else
			REAL = DOUBLE,
			WORD = INT,
			UWORD = UINT,
#endif
		};

		GLenum typeof(EVertexElementType type) {
			switch(type) {
			case EVertexElementType::FLOAT: return GL_FLOAT;
			case EVertexElementType::DOUBLE: return GL_DOUBLE;
			case EVertexElementType::UINT: return GL_UINT;
			case EVertexElementType::INT: return GL_INT;
			case EVertexElementType::ULONG: return GL_ULONG;
			case EVertexElementType::LONG: return GL_LONG;
			default: return 0;
			}
		}

		uword sizeof(EVertexElementType type, uword length=1) {
			switch(type) {
			case EVertexElementType::FLOAT: return sizeof(float)*length;
			case EVertexElementType::DOUBLE: return sizeof(double)*length;
			case EVertexElementType::UINT: return sizeof(uint32)*length;
			case EVertexElementType::INT: return sizeof(int32)*length;
			case EVertexElementType::ULONG: return sizeof(uint64)*length;
			case EVertexElementType::LONG: return sizeof(int64)*length;
			default: return 0;
			}
		}
   }
}

#endif // __NGEN_DRAWING_EVERTEXELEMENTTYPE_HPP
