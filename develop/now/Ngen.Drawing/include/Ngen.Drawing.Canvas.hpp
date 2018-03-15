
#ifndef __NGEN_DRAWING_CANVAS_HPP
#define __NGEN_DRAWING_CANVAS_HPP

#include "Build.Ngen.Drawing.Logic.hpp"

using namespace Ngen::Math;

namespace Ngen {
   namespace Drawing {

      class ngen_drawing_api CanvasCreationParams {
		public:
			uword Width;
			uword Height;
			Color4 Background;
			uword ColorDepth;
			real ZFar;
			real ZNear;
			bool Stero;

			CanvasCreationParams(uword width=800, uword height=640, Color4 background, uword depth=32, real zfar=-1.0, real znear=1.0, bool stero=false) :
				Width(width), Height(height), Background(background), ColorDepth(depth), ZFar(zfar), ZNear(znear), Stero(stero) {
			}
		};

      class ngen_drawing_api Canvas {
      public:
         Canvas(Window* window, const CanvasCreationParams& params);

         Color4 Background() const {
            return mParam.Background;
         }

         Vector2 Size() const {
            return Vector2(mParam.Width, mParam.Height);
         }

         void Clear() const {
            glClearColor(Background().R,
                         Background().G,
                         Background().B,
                         Background().A);
            glClear(GL_COLOR_BUFFER_BIT);
         }

         void Update() const;

      protected:
         Window* mWindow;
         CanvasCreationParams mParam;
      };
   }
}


#endif // __NGEN_DRAWING_CANVAS_HPP
