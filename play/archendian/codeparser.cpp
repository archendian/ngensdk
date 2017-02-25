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
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
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

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <tuple>
#include <cstring>

using namespace std;

class math {
public:
   static unsigned int gcd(unsigned int x, unsigned int y) {
       while (y != 0) {
           tie(x, y) = make_tuple(y, x % y);
       }
       return x;
   }

   static unsigned int sumulate(unsigned int x) {
      return (x*(x + 1)) / 2;
   }

   static unsigned int factorial(unsigned int x) {
      // return x*(x + 1);
      unsigned int result = 1;
      while(x > 0) {
         result *= x--;
      }

      return result;
   }

   static unsigned int fibonacci(unsigned int i) {
      unsigned x = 0;
      unsigned y = 1;
      i--;
      while(i-- > 0) {
         y = x+y;
         x = y-x;
      }

      return y;

   }

   static unsigned max_tripath(unsigned* triangle, unsigned len) {
      const unsigned size = sizeof(len) / sizeof(unsigned);
      const unsigned tn = (unsigned)std::sqrt(2.0 * size);

      for (int n = tn - 1; n > 0; --n)  {
         for (int k = (n * (n-1)) / 2; k < (n * (n+2)) / 2; ++k) {
            triangle[k] += std::max(triangle[k + n], triangle[k + n + 1]);
         }
      }

      return triangle[0];
   }
};

class console {
   static void writeline(string message) {
      std::cout << message << std::endl;
   }
};

int main() {
   unsigned int x = 988;
   std::cout << "fact_ex(10): \t" << math::gcd  (x, 890) << std::endl;

   unsigned triangle[] = {
      75,
      95,64,
      17,47,82,
      18,35,87,10,
      20, 4,82,47,65,
      19, 1,23,75, 3,34,
      88, 2,77,73, 7,63,67,
      99,65,04,28, 6,16,70,92,
      41,41,26,56,83,40,80,70,33,
      41,48,72,33,47,32,37,16,94,29,
      53,71,44,65,25,43,91,52,97,51,14,
      70,11,33,28,77,73,17,78,39,68,17,57,
      91,71,52,38,17,14,91,43,58,50,27,29,48,
      63,66,04,68,89,53,67,30,73,16,69,87,40,31,
       4,62,98,27,23, 9,70,98,73,93,38,53,60, 4,23,
   };

   std::cout << "Maximum total: " << math::max_tripath(triangle, sizeof(triangle)) << "\n\n";

   cin.get();
   return 0;
}


//tokens
char tab_space = '\t';
char prep_start = '#'
char linecont = '\\';
char white_space = ' ';
char scope_stop = '}';
char line_stop = ';';
char scope_start = '{';
char template_stop = '>';

// keywords
string endofline = string("\n\r"); // single array
string class_start = string("class ");
string template_start = string("template<");
string namespace_start = string("namespace ");
string operator_add = string("operator+");

namespace Ngen {
   namespace Reflection {
      namespace Code {

      class GrammerRule {
      public:

         union {

         };
      };
      /** @brief Artifacts are single character tokens found in source strings that are used
       by the lexer to determine the split order.
      */
      class Artifact {
      public:
         __inline_containers(Artifact);

         string Id;
         string Description;

         Artifact(string::TChar id, string description=string::Empty()) : Id(id) {}

         string::TChar Char() const {

                  }
         const Artifact Tab = Artifact('\t', )
      };

      /** @brief Expressions are defined by a single character or string used to operate on sources generated by the
         compiler when processing token trees.
      */
      class Expression {
      public:

      };

      class Lexicon {
      public:

      };
      /** @brief */
      class Token {
      public:
         TokenProfile* Profile;
         Token* Next;
         Token* Previous;
         string Source;

         Token(TokenProfile* profile, Token* previous, string source) :
            Profile(profile), Previous(previous), Next(null), Source(source) {
            previous->Next = this;
         }


      };

      /** @brief */
      class TokenProfile {
      public:
         __inline_containers(TokenProfile);

         string Name;
         string Shadow;
         string Description;

         TokenProfile(string name, string shadow, string description) :
            Name(name), Shadow(shadow), Description(description) {}
      };

      /** @brief */
      class SourceToken {
      public:
         __inline_containers(SourceToken);

         string TokenName;
         string TokenSource;

         SourceToken(string name, string source) : TokenName(name), TokenSource(source) {}
      };

      // processing token labels
      typedef Map<string, string> TokenTypeMap;

      // building tokens
      typedef map<string, token> token_tree;
      typedef map<string, token_tree> token_tree_group;

      // handling regex
      static volatile token_tree_group grammer_group;
      static volatile token_tree current_group;
      static volatile token current_token;

      void process_grammer_line(string line) {

      }

      void process_grammer(fstream file) {
         auto group = token_tree_group();
         auto current = token_tree();
         string line;

         do {
            line = file.getline();
            for(uword i = 0; i < line.size(); i++) {
               if(line[0] == '/' && line[1] == '/') {
                  break;
               } else if(line[0] == '@') {
                  line
               }


            }
         }
      }

      int main(const char** args, size_t arglen) {
         fstream grammer;
         fstream files[arglen-1] source;
         token_tree tree;

         // load file streams for processing
         try {
            grammer = fstream(args[0]);
            for(size_t i = 0; i < arglen-1; i++) {
               files[i] = fstream(args[i+1]);
            }

         catch(std::exception e) {
            throw std::exception(e.what());
         }

         auto grammer = fstream(args[0]);

         for(int i = 0; i < arglen; i++) {



         }

         auto filename = string(args[0]);
         auto outrti = filename << ".npp";

      }
   }
}
