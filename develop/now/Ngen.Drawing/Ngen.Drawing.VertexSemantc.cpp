
namespace Ngen {
   namespace Drawing {
      VertexScheme _o3 = VertexScheme("o3", {
         VertexElement("Origin", 0, EVertexElementType::REAL, 3),
      });

      VertexScheme _o3c3 = VertexScheme("o3c3", {
         VertexElement("Origin", 0, EVertexElementType::REAL, 3),
         VertexElement("Color", 0, EVertexElementType::REAL, 3),
      });

      VertexScheme* VertexScheme::o3() { return &_o3; }
      VertexScheme* VertexScheme::o3c3() { return &_o3c3; }
   }
}
