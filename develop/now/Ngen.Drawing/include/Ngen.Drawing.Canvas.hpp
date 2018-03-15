
#ifndef __NGEN_DRAWING_CANVAS_HPP
#define __NGEN_DRAWING_CANVAS_HPP

#include "Ngen.Drawing.CanvasCreationParams.hpp"

using namespace Ngen;
//using namespace Ngen::Math;

namespace Ngen {
   namespace Drawing {

      class ngen_drawing_api Canvas {
      public:
         Canvas() : mWindow(null), mParam() {}

         Canvas(Window* window, const CanvasCreationParams& params);
         virtual ~Canvas();

         //Color4 Background() const {
         //   return mParam.Background;
         //}

         //Vector2 Size() const {
         //   return Vector2(mParam.Width, mParam.Height);
         //}

         void Clear() const;
         void Update() const;

      protected:
         Window* mWindow;
         CanvasCreationParams mParam;
      };
   }
}


#endif // __NGEN_DRAWING_CANVAS_HPP
