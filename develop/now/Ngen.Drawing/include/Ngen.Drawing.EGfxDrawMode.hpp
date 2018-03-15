#ifndef __NGEN_DRAWING_EGFXDRAWMODE_HPP
#define __NGEN_DRAWING_EGFXDRAWMODE_HPP

#include "Ngen.Drawing.Typedefs.hpp"

namespace Ngen {
   namespace Drawing {

      enum class EGfxDrawMode {
			POINT,
			QUAD,
			QUAD_STRIP,
			POLYGON,
			TRIANGLE,
			TRIANGLE_STRIP,
			TRIANGLE_FAN,
			LINE,
			LINE_STRIP,
			LINE_LOOP,

		};

		GLenum typeof(EGfxDrawMode mode) {
			switch(mode) {
			case EGfxDrawMode::POINT: return GL_POINTS;
			case EGfxDrawMode::QUAD: return GL_QUADS;
			case EGfxDrawMode::POLYGON: return GL_POLYGON;
			case EGfxDrawMode::QUAD_STRIP: return GL_QUAD_STRIP;
			case EGfxDrawMode::TRIANGLE: return GL_TRIANGLES;
			case EGfxDrawMode::TRIANGLE_FAN: return GL_TRIANGLE_FAN;
			case EGfxDrawMode::TRIANGLE_STRIP: return GL_TRIANGLE_STRIP;
			case EGfxDrawMode::LINE: return GL_LINES;
			case EGfxDrawMode::LINE_STRIP: return GL_LINE_STRIP;
			case EGfxDrawMode::LINE_LOOP: return GL_LINE_LOOP;
			default: return 0;
			}
		}
   }
}
#endif // __NGEN_DRAWING_EGFXDRAWMODE_HPP
