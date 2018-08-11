#include "Ngen.Drawing.VertexScheme.hpp"

namespace Ngen {
   namespace Drawing {
      VertexScheme _o3 = VertexScheme("o3", {
         VertexElement(const_mirror("Origin"), 0, EVertexElementType::REAL, 3),
      });

      VertexScheme _o3c3 = VertexScheme("o3c3", {
         VertexElement(const_mirror("Origin"), 0, EVertexElementType::REAL, 3),
         VertexElement(const_mirror("Color"), 0, EVertexElementType::REAL, 3),
      });

      VertexScheme _o3c3n3u2 = VertexScheme("o3", {
         VertexElement(const_mirror("Origin"), 0, EVertexElementType::REAL, 3),
         VertexElement(const_mirror("Color"), 0, EVertexElementType::REAL, 3),
         VertexElement(const_mirror("Normal"), 0, EVertexElementType::REAL, 3),
         VertexElement(const_string("UV"), 0, EVertexElementType::REAL, 2),
      });

      VertexScheme* VertexScheme::o3() { return &_o3; }
      VertexScheme* VertexScheme::o3c3() { return &_o3c3; }
      VertexScheme* VertexScheme::o3c3n3u2() { return &_o3c3n3u2; }
   }
}
