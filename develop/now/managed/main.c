// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the shared library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

#include "default_rti.hpp"

using namespace Ngen;
using namespace Reflection;

Library* thislib = Library::Grab(rti_libname(default));

AssemblyInfo* ngen_assembly_info = AssemblyInfo::New(thislib->Name(), const_mirror("default"), [](AssemblyBuilder assembly) {
     auto ngen_namespace_info = assembly.AddNamespace(const_mirror("Ngen"), null, [](NamespaceBuilder space) {
          auto memory_class = space.AddNestedType(const_mirror("Memory"), null, [](TypeBuilder type) {
             type.SetTrait(ETypeTrait::Static, true);
             type.SetTrait(ETypeTrait::Final, true);

             type.AddStaticMethod("UnknownNew", StaticDelegate<unknown, uword>)
          });
     });
});
