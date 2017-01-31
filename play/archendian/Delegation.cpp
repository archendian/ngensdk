#include <Ngen.hpp>
#include <iostream> 
// ^ for std::cin.get();

using namespace Ngen;

#define yes true
#define no false

int main() {
    auto query = StaticDelegate<bool, string&>([](string& e) {
        return e.Length() => 7;
    });
    
    auto print = 
        
        
    auto text = const_string("Life is a carton of cigarettes.  You never know which box had more cancers in it.");
    auto collection = text.Split(' ', yes); 
    auto select = collection.Where(query);
    
    
    for(uword i = 0; i < select.Length(); ++i) {
        Console::WriteLine(select[i]);
    }
    
    std::cin.get(); //Console::Wait();
}