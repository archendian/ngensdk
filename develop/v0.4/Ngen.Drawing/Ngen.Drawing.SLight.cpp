

#include "Ngen.Drawing.SLight.hpp"

namespace Ngen {
   namespace Drawing {

      GpuScheme _point = GpuScheme(("PointLight"), {
                              GpuElement("Origin", 0u, EGpuElementType::FLOAT, 3),
                              GpuElement("Color", 0, EGpuElementType::FLOAT, 4),
                              GpuElement("Strength", 0, EGpuElementType::FLOAT, 1)
                            });

      GpuScheme _directional = GpuScheme("DirectionalLight", {
                                 GpuElement("Origin", 0, EGpuElementType::FLOAT, 3),
                                 GpuElement("Color", 0, EGpuElementType::FLOAT, 4),
                                 GpuElement("Direction", 0, EGpuElementType::FLOAT, 3),
                                 GpuElement("Strength", 0, EGpuElementType::FLOAT, 1)
                              });

      GpuScheme* SLightPoint::Scheme() { return &_point; }
      GpuScheme* SLightDirectional::Scheme() { return &_directional; }
   }
}
