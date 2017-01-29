
#include <Ngen.hpp>
#include <Ngen.Reflection.hpp>

namespace Ngen {
   namespace Reflection {
      namespace Code {

         enum class EWordType {
            ALPHANUMERIC,
            ALPHA,
            NUMERIC,
            SYMBOL,
            PUNCUATION,
            SPACE
            NEWLINE,
            EOLINE,
            EOFILE,
         };

         enum class ETokenType {

         };

         typedef BitFlags<EDialectFeature> DialectFeatureFlags;


         class Dialect;

         class reflection_code_api DialectBuilder {
         public:
            DialectBuilder(Dialect* dialect) : mDialect(dialect) {}

         protected:
            Dialect* mDialect;
         };

         class reflection_code_api Dialect {
         public:
            typedef Map<mirror, Dialect> TMirrorMap;

            Dialect* Get(const mirror& name) {
               Dialect* result = null;
               if(mLanguage.ContainsKey(name)) {
                  result = &mLanguage[name];
               }

               return result;
            }

            Dialect* Create(const mirror& name, VoidStaticDelegate<DialectBuilder>::TFunction initializer) {
               Dialect* result = Dialect::Get(name;)
               if(isnull(result)){

                  mLanguage.Add(name, Dialect(name));
                  result = &mLanguage[name];
                  result->Initialize(initializer)
               }

               return result;
            }

         protected:
            Dialect(const mirror& name) : mName(name) {
            }

            mirror mName;

            mirror mTypeDeclaration;

            Array<mirror> mKeyword;

            static TMirrorMap mLanguage;
         };




         class reflection_code_api Parser {
         public:
            typedef Array<string> KeywordSplit;
            typedef Array<string> TypeSplit;

            Parser(Dialect* dialect) : mDialect(dialect) {

            }


         protected:
            Dialect* mDialect;

         };

      }
   }
}

class LanguageDescription {

};

int main() {


   cout << "Hello world!" << endl;
   return 0;
}
