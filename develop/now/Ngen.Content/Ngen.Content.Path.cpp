


#include <Ngen.hpp>

namespace Ngen {
  namespace Content {
     _static tchar Path::PathSeperatorChar() {
       #if _tkn_Platform == _tknval_Platform_Windows 
         return '/';
       #else
         return '/';
       #endif
     }
  }
}
class Path {
      public:
        
        static const string& SystemPathChar() const;
        static string GetLastNode(const string& node=const_string("/\|"));
    };
}
