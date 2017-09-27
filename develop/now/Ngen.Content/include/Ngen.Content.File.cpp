





#include <Ngen.hpp>

namespace Ngen {
  namespace Content {
    
    class Path {
      public:
        
        static const string& SystemPathChar() const;
        static string GetLastNode(const string& node=const_string("/\|"));
    };
    
    class FileInfo {
      public:
      
      
        const string& FileName() const {
          string result = string::Empty();
          
          
          return result;
        }
      protected:
        string mFullPath;
        
    };
    
    class File : public virtual Stream {
    
    };
  }
}
