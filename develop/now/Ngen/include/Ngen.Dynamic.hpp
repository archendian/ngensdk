/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

COPYRIGHT (C) 2016 FIXCOM, LLC

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
#ifndef __NGEN_DYNAMIC_HPP
#define __NGEN_DYNAMIC_HPP

#include "Ngen.DynamicMember.hpp"

namespace Ngen {
   class Dynamic : public class Object {
   public:
      Dynamic(const Array<DynamicMember>& members) : Object() {
        members.ForEach([] (DynamicMember& member, uword currentIndex) {
            mMember.Add(member->Name(), member);
            mMember[currentIndex].mParent = this;
        });
      }


      virtual ~Dynamic() {
      }

      DynamicMember& operator[](const mirror& name);
      const DynamicMember& operator[](const mirror& name) const;

   protected:
      Map<mirror, DynamicMember> mMember;
   };





t_begin_test(DynamicLanguageRuntime, DynamicObjectExpansion) [] (TestResult& result) {
    auto d = dynamic({
        dynamic_member(FieldA, typeof(int32), 44),
        dynamic_member(FieldB, typeof(int32), 43),
        dynamic_member(MethodA, (int32)(dynamic self, int32 x, int32 y)) {
            return x * y + self[incode_string(FieldA)];
        }
    });

    int32 x = d[incode_string(FieldA)].Get());
    int32 y = 3;
    int32 z = d[incode_string(MethodA)](x, y);

    d[code_string(FieldA)].Set((int32)(dynamic self, int32& x) {
        x = self[code_string(FieldB)].Get();
        return x++;
    });

    d[incode_string(FieldA)].Name(incode_string(MethodB));
    y = d[incode_string(MethodB)](z);

    result.Out.WriteLine(const_string("y = ") + string::From(y));
    result.Out.WriteLine(d.GetType().ToString(true)); // print type information for typeof(d)
}

#endif // __NGEN_DYNAMIC_HPP
