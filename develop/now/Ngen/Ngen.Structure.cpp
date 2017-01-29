
#include "Ngen.Structure.hpp"

namespace Ngen {
   StructureMap Structure::mStructures = StructureMap();
   StructurePtrMap Structure::mAliases = StructurePtrMap();

   Structure* structureof(const mirror& typeName) { return Structure::Get(typeName); }
}
