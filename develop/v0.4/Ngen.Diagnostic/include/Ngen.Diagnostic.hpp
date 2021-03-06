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
#ifndef __NGEN_DIAGNOSTIC_HPP
#define __NGEN_DIAGNOSTIC_HPP

#include "Build.Ngen.Diagnostic.Logic.hpp"

#include "Ngen.Diagnostic.TestResult.hpp"
#include "Ngen.Diagnostic.TestGroup.hpp"
#include "Ngen.Diagnostic.Test.hpp"


namespace Ngen {
   namespace Diagnostic {

      class ngen_diagnostic_api TestSuite {
      public:
         static void PrintStandardIntroduction() {
            Console::WriteLine(const_string("NGEN FRAMEWORK\nDIAGNOSTICS & TESTING SUITE\nCopyright (c) FIXCON, LCC 2018"));
            Console::WriteLine(string::Empty());
         }

         static void Run(bool batchPrinting=false) {

         }
      };
   }
}
#endif // __NGEN_DIAGNOSTICS_HPP
