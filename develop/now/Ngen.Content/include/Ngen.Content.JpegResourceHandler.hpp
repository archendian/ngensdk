





#include <Ngen.hpp>

namespace Ngen {
  namespace Content {

      class AssetHandler {
      public:
         Asset(const string& name) : mName(name) {}

      protected:
         mirror mName;
         T mResource;
      };
  }
}
