
#ifndef __NGEN_DEFAULT_RTI_HPP
#define __NGEN_DEFAULT_RTI_HPP

#include "Ngen.hpp"
#include "Ngen.Reflection.hpp"

// TODO: auto generate this pattern for RTI thru source code processing

namespace _mirror {
   const mirror assembly_default          = const_mirror("default")
   const mirror namespace_default         = const_mirror("default");
   const mirror class_memory              = const_mirror("memory");
   const mirror method_memory_new         = const_mirror("new");
   const mirror method_memory_delete      = const_mirror("delete");
}

namespace _delegate {
   const StaticDelegate<uint8*, uword, bool>       memory_new        = StaticDelegate(&Memory::New<uint8>);
   const VoidStaticDelegate<uint8*>                memory_delete     = StaticDelegate(&Memory::Delete<uint8>);

   const mirror AssemblyName = const_mirror(E"default");
   const mirror LibraryName = const_mirror(E"default");

extern "C" {
   uword assembly_count() { return 1; }

   AssemblyInfo* assembly_load(const mirror& name) {
      switch(name) {
      case AssemblyName: _internal_load_default_assembly(); return &default_assembly;
      default: return null;
      }
   }


   AssemblyInfo default_assembly;
   void _internal_load_default_assembly() {
      default_assembly = AssemblyInfo::New(LibraryName, AssemblyName, [] (AssemblyBuilder DEFAULT) {
         DEFAULT.AddNamespace(const_mirror(E"Ngen"), null, [] (NamespaceBuilder NGEN) {
            // todo: traits, fields, methods
            NGEN.AddType(const_mirror(E"Memory"), null, [] (TypeBuilder MEMORY) {
               MEMORY.SetTrait(ETypeTrait::Static, true);
               MEMORY.SetTrait(ETypeTrait::Final, true);

               MEMORY.AddMethod(const_mirror(E"New"), );
            });
         });
      });
   }
}



#endif // __NGEN_DEFAULT_RTI_HPP
