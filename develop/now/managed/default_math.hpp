
#ifndef __NGEN_DEFAULT_RTI_HPP
#define __NGEN_DEFAULT_RTI_HPP

#include "Ngen.hpp"
#include "Ngen.Reflection.hpp"

// TODO: auto generate this pattern for RTI thru source code processing

namespace _mirror {
   const mirror assembly_default          = const_mirror("default")
   const mirror namespace_default         = const_mirror("default");
   const mirror class_memory              = const_mirror("memory");
   const mirror method_memory_malloc      = const_mirror("malloc");
   const mirror method_memory_free        = const_mirror("free");
}

namespace _delegate {
   const StaticDelegate<uint8*, uword, bool>       memory_malloc     = StaticDelegate(&Memory::New<uint8>);
   const StaticDelegate<void_t, uint8*>            memory_free       = StaticDelegate(&Memory::Delete<uint8>);
}

namespace _structure {
   Structure
}


#endif // __NGEN_DEFAULT_RTI_HPP
