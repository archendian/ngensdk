#include "Ngen.Drawing.SVertex.hpp"

namespace Ngen {
   namespace Drawing {

      VertexScheme _vertexo = VertexScheme("VertexO", {
         VertexElement(const_mirror("Origin"), 0, EGpuElementType::REAL, 3),
      });

      VertexScheme _vertexoc = VertexScheme("VertexOC", {
         VertexElement(const_mirror("Origin"), 0, EGpuElementType::REAL, 3),
         VertexElement(const_mirror("Color"), 0, EGpuElementType::REAL, 3),
      });

      VertexScheme _vertexocnu = VertexScheme("VertexOCNU", {
         VertexElement(const_mirror("Origin"), 0, EGpuElementType::REAL, 3),
         VertexElement(const_mirror("Color"), 0, EGpuElementType::REAL, 3),
         VertexElement(const_mirror("Normal"), 0, EGpuElementType::REAL, 3),
         VertexElement(const_string("UV"), 0, EGpuElementType::REAL, 2),
      });

      VertexScheme _vertexocnuu = VertexScheme("VertexONCUU", {
         VertexElement(const_mirror("Origin"), 0, EGpuElementType::REAL, 3),
         VertexElement(const_mirror("Color"), 0, EGpuElementType::REAL, 3),
         VertexElement(const_mirror("Normal"), 0, EGpuElementType::REAL, 3),
         VertexElement(const_string("UV1"), 0, EGpuElementType::REAL, 2),
         VertexElement(const_string("UV2"), 0, EGpuElementType::REAL, 2),
      });


      VertexScheme _vertexocnuw = VertexScheme("VertexONCUW", {
         VertexElement(const_mirror("Origin"), 0, EGpuElementType::REAL, 3),
         VertexElement(const_mirror("Color"), 0, EGpuElementType::REAL, 3),
         VertexElement(const_mirror("Normal"), 0, EGpuElementType::REAL, 3),
         VertexElement(const_string("UV"), 0, EGpuElementType::REAL, 2),
         VertexElement(const_string("Weight"), 0, EGpuElementType::REAL, 1),
      });

      VertexScheme* SVertexO::Scheme() { return &_vertexo; }
      VertexScheme* SVertexOC::Scheme() { return &_vertexoc; }
      VertexScheme* SVertexOCNU::Scheme() { return &_vertexocnu; }
      VertexScheme* SVertexOCNUU::Scheme() { return &_vertexocnuu; }
      VertexScheme* SVertexOCNUW::Scheme() { return &_vertexocnuw; }
   }
}
