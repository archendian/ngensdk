/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2016 NGENWARE STUDIOS, LLC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sub-license, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#include "default_rti.hpp"

using namespace Ngen;
using namespace Reflection;

Library* thislib = Library::Grab(rti_libname(default));

// TODO: auto generate this pattern for RTI thru source code processing

AssemblyInfo* ngen_assembly_info = AssemblyInfo::New(thislib->Name(), _mirror::assembly_default, [](AssemblyBuilder assembly) {
   auto ngen_namespace_info = assembly.AddNamespace(_mirror::namespace_default, null, [](NamespaceBuilder space) {
      auto memory_class = space.AddNestedType(_mirror::class_memory, null, [](TypeBuilder type) {
      type.SetTrait(ETypeTrait::Static, true);
      type.SetTrait(ETypeTrait::Final, true);
      type.SetTrait(ETypeTrait::Public, true);

      const auto StaticDelegate(&Memory::New<uint8>)
      type.AddStaticMethod(_mirror::method_memory_malloc, (Delegate*)_delegate::memory_malloc, [](MethodBuilder method){

         });
      type.AddStaticMethod(_mirror::method_memory_free, (Delegate*)_delegate::memory_free, [](MethodBuilder method){

         });
      });
   });
});
