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
#ifndef __NGEN_HPP
#define __NGEN_HPP

#include "Build.Ngen.Token.hpp"
#include "Build.Ngen.Configuration.hpp"
#include "Build.Ngen.Macro.hpp"
#include "Build.Ngen.Logic.hpp"
#include "Build.Ngen.External.hpp"

#include "Ngen.Typedefs.hpp"
#include "Ngen.Trait.hpp"
#include "Ngen.Cast.hpp"
#include "Ngen.Memory.hpp"
#include "Ngen.Algorithm.hpp"
#include "Ngen.Reference.hpp"
#include "Ngen.KeyValuePair.hpp"
#include "Ngen.BitField.hpp"
#include "Ngen.Calculator.hpp"
#include "Ngen.Library.hpp"
#include "Ngen.Console.hpp"

#include "Ngen.Delegate.hpp"
#include "Ngen.StaticDelegate.hpp"
#include "Ngen.MemberDelegate.hpp"
#include "Ngen.ConstMemberDelegate.hpp"

#include "Ngen.Map.hpp"
#include "Ngen.Stack.hpp"
#include "Ngen.Table.hpp"

#include "Ngen.String.hpp"
#include "Ngen.Mirror.hpp"
#include "Ngen.Event.hpp"
#include "Ngen.Exception.hpp"
#include "Ngen.TimeStamp.hpp"
#include "Ngen.Time.hpp"
#include "Ngen.Stream.hpp"
//#include "Ngen.Task.hpp"

#include "Ngen.Structure.hpp"
#include "Ngen.Object.hpp"
#include "Ngen.Attribute.hpp"
#include "Ngen.Type.hpp"
#include "Ngen.Assembly.hpp"


// The C-API used to register reflected APIs through a binding language

extern "C" {
   namespace Ngen {
//      ngen_api abstract class Encoding {
//
//      }
//
//      ngen_api class Compression {
//
//      }
//
//      ngen_api class Cryptography {
//
//      }
//
//      namespace Web {
//
//         struct HtmlTagProfile {
//            string Name;
//            uword MinVersion;
//            uword MaxVersion;
//            bool RequiredClose;
//
//            bool IsSupported(uword version) {
//               return version <= MinVersion && (version >= MaxVersion || MaxVersion == 0);
//            }
//         };
//
//         struct SHtmlTagProfiles {
//            static Array<HtmlTagProfile> Collection;
//            static const HtmlTagProfile* Get(const string name);
//            static const HtmlTagProfile* Get(uword hashcode);
//
//            Array<HtmlTagProfile> SHtmlTagProfiles::Collection(
//               { "head",       1, 0, true },
//               { "body",       1, 0, true },
//               { "header",     1, 0, true },
//               { "footer",     1, 0, true },
//               { "meta",       1, 0, true },
//               { "img",        1, 0, true },
//               { "div",        1, 0, true },
//               { "dl",         1, 0, true },
//               { "dt",         1, 0, true },
//               { "datalist",   5, 0, true },
//               { "canvas",     5, 0, true },
//               { "embed",      5, 0, true },
//               { "frame",      1, 4, true },
//               { "frameset",   1, 4, true },
//            });
//
//            Map<uword, HtmlTagProfile*> mCachedHtmlTag;
//         } EHtmlTagProfile;
//
//
//
//         const HtmlTagProfile* SHtmlTagProfiles::Get(const string name) {
//            return SHtmlTagProfiles::Get(name.ToHashcode());
//         }
//
//         const HtmlTagProfile* SHtmlTagProfiles::Get(uword hashcode) {
//            HtmlTagProfile* result = mCachedHtmlTag[hashcode];
//
//            if(!isnull(result)) {
//               for(uword i = 0; i < Collection.Length(); ++i) {
//                  if(Collection[i].Name.ToHashcode() == hashcode) {
//                     result = &Collection[i];
//                     mCachedHtmlTag.Add(hashcode, result);
//                     break;
//                  }
//               }
//            }
//
//            return result;
//         }
//
//         template<typename TTag, typename TAttribute>
//         class ngen_web_api MarkupTag {
//         public:
//
//            MarkupTag(const string& name);
//
//            MarkupTag& Add(const string& name, const string& value) {
//               if(mAttributes.Keys().Contains(name)) {
//                  THROW(InvalidOperationException());
//               }
//
//               mAttributes.Add(name, value);
//            }
//
//         protected:
//            string mName;
//            Map<string, string> mAttributes;
//         };
//
//         template<typename TTagProfile, typename TAttributeProfile>
//         ngen_web_api class MarkupSource {
//         public:
//            typedef MarkupTag<TTagProfile, TAttributeProfile> TTag;
//            MarkupSource() {}
//
//
//         protected:
//            File mFile;
//         }
//
//         using HtmlSource = MarkupSource<EHtmlTagName, EHtmlAttributeName>;
//         typedef HtmlSource::TTag HtmlTag;
//
//         using XmlSource = MarkupSource<EXmlTagName, EXmlkAttributeName>;
//         typedef XmlTag::TTag XmlTag;
//
//         ngen_api class HtmlTag : public File {
//
//         }
//
//         ngen_api class CssSource : public File {
//
//         }
//
//         ngen_api class JavascriptSource : public File {
//
//         }
//      }
//   }
//
//   namespace ngen {
//
//      ngen_api class Password {
//
//      };
//
//      ngen_api class User {
//
//      protected:
//         string mName;
//
//      }
//
//      ngen_api Environment {
//         ngen_api static string FrameworkId();
//         ngen_api static string SystemId();
//         ngen_api static string SystemPath();
//         ngen_api static string CurrentUserName();
//         ngen_api static string CurrentUserPath();
//
//
//         ngen_api static string EncodingId();
//      };
//   }
}
#endif // __NGEN_HPP
