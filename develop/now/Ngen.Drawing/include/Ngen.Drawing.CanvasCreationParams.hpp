
#ifndef __NGEN_DRAWING_CANVASCREATIONPARAMS_HPP
#define __NGEN_DRAWING_CANVASCREATIONPARAMS_HPP

#include "Ngen.Drawing.VertexBuffer.hpp"

using namespace Ngen;
//using namespace Ngen::Math;

namespace Ngen {
   namespace Drawing {

      class ngen_drawing_api CanvasCreationParams {
		public:
			uword Width;
			uword Height;
			//Color4 Background;
			uword ColorDepth;
			real ZFar;
			real ZNear;
			bool Stero;

			CanvasCreationParams(uword width=800, uword height=640, /*Color4 background,*/ uword depth=32, real zfar=-1.0, real znear=1.0, bool stero=false) :
				Width(width), Height(height), /*Background(background),*/ ColorDepth(depth), ZFar(zfar), ZNear(znear), Stero(stero) {
			}

			CanvasCreationParams(const CanvasCreationParams& copy) :
				Width(copy.Width), Height(copy.Height), /*Background(copy.Background),*/ ColorDepth(copy.ColorDepth),
               ZFar(copy.ZFar), ZNear(copy.ZNear), Stero(copy.Stero) {
			}
		};
   }
}

#endif // __NGEN_DRAWING_CANVASCREATIONPARAMS_HPP
