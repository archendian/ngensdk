#ifndef __NGEN_DRAWING_EGFXDRAWMODE_HPP
#define __NGEN_DRAWING_EGFXDRAWMODE_HPP

#include "Ngen.Drawing.Typedefs.hpp"

namespace Ngen {
   namespace Drawing {

      enum class EGraphicDrawMode {
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

		GLenum typeof(EGraphicDrawMode mode) {
			switch(mode) {
			case EGraphicDrawMode::POINT: return GL_POINTS;
			case EGraphicDrawMode::QUAD: return GL_QUADS;
			case EGraphicDrawMode::POLYGON: return GL_POLYGON;
			case EGraphicDrawMode::QUAD_STRIP: return GL_QUAD_STRIP;
			case EGraphicDrawMode::TRIANGLE: return GL_TRIANGLES;
			case EGraphicDrawMode::TRIANGLE_FAN: return GL_TRIANGLE_FAN;
			case EGraphicDrawMode::TRIANGLE_STRIP: return GL_TRIANGLE_STRIP;
			case EGraphicDrawMode::LINE: return GL_LINES;
			case EGraphicDrawMode::LINE_STRIP: return GL_LINE_STRIP;
			case EGraphicDrawMode::LINE_LOOP: return GL_LINE_LOOP;
			default: return 0;
			}
		}
   }
}
#endif // __NGEN_DRAWING_EGFXDRAWMODE_HPP
