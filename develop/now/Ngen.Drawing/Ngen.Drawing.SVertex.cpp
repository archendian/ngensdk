#include "Ngen.Drawing.SVertex.hpp"

namespace Ngen {
   namespace Drawing {
      void initialize_vertex_element_array(GpuScheme* scheme) {
         auto element = scheme->Elements();
         if(!element.IsNullOrEmpty()) {
            auto begin = element.Begin();
            auto end = element.End();
            uword index = 0;

            do {
               glVertexAttribPointer(index, element.Length(), gl_typeof(begin->Type()), 0, begin->Offset(), 0);
            } while(begin++ != end);
         }
      }

      GpuScheme _vertexo = GpuScheme("VertexO", {
         GpuElement(const_mirror("Origin"), 0, EGpuElementType::REAL, 3),
      }, &initialize_vertex_element_array);

      GpuScheme _vertexoc = GpuScheme("VertexOC", {
         GpuElement(const_mirror("Origin"), 0, EGpuElementType::REAL, 3),
         GpuElement(const_mirror("Color"), 0, EGpuElementType::REAL, 3),
      }, &initialize_vertex_element_array);

      GpuScheme _vertexocnu = GpuScheme("VertexOCNU", {
         GpuElement(const_mirror("Origin"), 0, EGpuElementType::REAL, 3),
         GpuElement(const_mirror("Color"), 0, EGpuElementType::REAL, 3),
         GpuElement(const_mirror("Normal"), 0, EGpuElementType::REAL, 3),
         GpuElement(const_string("UV"), 0, EGpuElementType::REAL, 2),
      }, &initialize_vertex_element_array);

      GpuScheme _vertexocnuu = GpuScheme("VertexONCUU", {
         GpuElement(const_mirror("Origin"), 0, EGpuElementType::REAL, 3),
         GpuElement(const_mirror("Color"), 0, EGpuElementType::REAL, 3),
         GpuElement(const_mirror("Normal"), 0, EGpuElementType::REAL, 3),
         GpuElement(const_string("UV1"), 0, EGpuElementType::REAL, 2),
         GpuElement(const_string("UV2"), 0, EGpuElementType::REAL, 2),
      }, &initialize_vertex_element_array);


      GpuScheme _vertexocnuw = GpuScheme("VertexONCUW", {
         GpuElement(const_mirror("Origin"), 0, EGpuElementType::REAL, 3),
         GpuElement(const_mirror("Color"), 0, EGpuElementType::REAL, 3),
         GpuElement(const_mirror("Normal"), 0, EGpuElementType::REAL, 3),
         GpuElement(const_string("UV"), 0, EGpuElementType::REAL, 2),
         GpuElement(const_string("Weight"), 0, EGpuElementType::REAL, 1),
      }, &initialize_vertex_element_array);

      GpuScheme* SVertexO::Scheme() { return &_vertexo; }
      GpuScheme* SVertexOC::Scheme() { return &_vertexoc; }
      GpuScheme* SVertexOCNU::Scheme() { return &_vertexocnu; }
      GpuScheme* SVertexOCNUU::Scheme() { return &_vertexocnuu; }
      GpuScheme* SVertexOCNUW::Scheme() { return &_vertexocnuw; }
   }
}
