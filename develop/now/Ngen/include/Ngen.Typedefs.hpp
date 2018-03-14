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
#ifndef __NGEN_TYPEDEFS_HPP
#define __NGEN_TYPEDEFS_HPP

#include "Build.Ngen.External.hpp"

namespace Ngen {

   template<typename T> struct Limit {
      static T Min() { return 0; }
      static T Max() { return 0; }
   };


   /** @brief An 8-bit wide character value. */
   typedef char char8;

   /** @brief An 16-bit wide character value. */
   typedef char16_t char16;

   /** @brief An 32-bit wide character value. */
   typedef char32_t char32;

   /** @brief A wide character value. */
   typedef wchar_t wchar;

   /** @brief An 8-bit wide unsigned integer value. */
   typedef unsigned char uint8;

   /** @brief An 8-bit wide signed integer value. */
   typedef signed char int8;

   /** @brief A 16-bit wide unsigned integer value. */
   typedef unsigned short uint16;

   /** @brief A 16-bit wide signed integer value. */
   typedef signed short int16;

   /** @brief A 32-bit wide unsigned integer value. */
   typedef unsigned int uint32;

   /** @brief A 32-bit wide signed integer value. */
   typedef signed int int32;

   /** @brief A 64-bit wide unsigned integer value. */
   typedef unsigned long long int uint64;

   /** @brief An 64-bit wide signed integer value. */
   typedef signed long long int int64;

   /** @brief An 32-bit wide floating-point integer value. */
   typedef float float32;

   /** @brief An 64-bit wide floating-point integer value. */
   typedef double float64;

   /** @brief The floating-point value used by complex data structures used in geometric
    * calculations.
    */
#  if _tkn_UseDoublePrecision == _tknval_True
      typedef float64 real;
#  else
      typedef float32 real;
#  endif

   /** @brief A user-defined literal for converting floating point constants
    * to the frameworks 'real'.
    */
   static inline constexpr real operator"" _rl(long double value) {
      return (real)value;
   }

   /** @brief The unsigned integral data type used in indexing arithmetic. */
#  if _tkn_RegisterWidth == _tknval_RegisterWidth_32
      typedef uint32 uword;
#  elif _tkn_RegisterWidth == _tknval_RegisterWidth_64
      typedef uint64 uword;
#  endif

   /** @brief The signed integral data type used in indexing arithmetic. */
#  if _tkn_RegisterWidth == _tknval_RegisterWidth_32
      typedef int32 word;
#  elif _tkn_RegisterWidth == _tknval_RegisterWidth_64
      typedef int64 word;
#  endif

#  if _tkn_UseUnicodeEncoding == _tknval_False
#     define E
      typedef char8 echar;
      typedef const char8* estring;
#  else
#     define E u
      typedef char16 echar;
      typedef const char16* estring;
#  endif

   /** @brief A pointer with all type information discarded. */
   typedef void* unknown;

	/** @brief A pointer value that represents an invalid data structure. */
#  define null 0x0

	/** @brief A constant expression used to check if a pointer is null. */
   template<typename T> static constexpr bool isnull(T* rhs) { return rhs == null; }
   template<typename T> static constexpr bool isnull(T& rhs) { return &rhs == null; }

	/** @brief A data-structure used to represent void. Needed for use with delegates, events, and callbacks. */
   struct void_t {
   	void_t() {}
   	void_t(const void_t& copy) {}
   	bool operator==(const void_t& rhs) const { return true; }
   	bool operator!=(const void_t& rhs) const { return false; }
	};

	// -------------------------------------------------------------------
	// C++ TRAIT LOGIC AND PRIMITIVE LIMITS
	// -------------------------------------------------------------------

	/** @brief A logic structure used by the trait class for determining if a C++ typename represents a primitive data structure.
    */
   template<typename T> struct __is_primitive { static constexpr bool result() { return false; } };

   /** @brief A logic structure used by the trait class for determining if a C++ typename represents a primitive data structure with an integral value type.
    */
   template<typename T> struct __is_integral { static constexpr bool result() { return false; } };

   /** @brief A logic structure used by the trait class for determining if a C++ typename represents a primitive data structure with a decimal value type.
    */
   template<typename T> struct __is_decimal { static constexpr bool result() { return false; } };

   /** @brief A logic structure used by the trait class for determining if a C++ typename is movable.
    */
   template<typename T> struct __is_movable { static constexpr bool result() { return false; } };

   /** @brief A logic structure used by the trait class for determining if a C++ typename has minimum and maximum value boundaries.
    */
   template<typename T> struct __is_limited { static constexpr bool result() { return false; } };

   /** @brief A logic structure used by the trait class for determining if a C++ typename represents a nullable pointer reference.
    */
   template<typename T> struct __is_nullable { static constexpr bool result() { return false; } };

   /** @brief A logic structure used by the trait class for determining if a two typenames are equal.
    */
	template<typename TLhs, typename TRhs> struct __is_equal { static constexpr bool result() { return false; } };
	template<typename TLhs> struct __is_equal<TLhs, TLhs> { static constexpr bool result() { return true; } };

	// SEE: Build.Ngen.Macros.hpp
////
//   trait_make_limited_integral(int8, -127, 128);
//   trait_make_limited_integral(int16, -32768 , 32767);
//   trait_make_limited_integral(int32, -2147483648, 2147483647);
//   trait_make_limited_integral(int64, -9223372036854775808, 9223372036854775807);
//   trait_make_limited_integral(uint8, 0, 256);
//   trait_make_limited_integral(uint16, 0, 65536);
//   trait_make_limited_integral(uint32, 0, 4294967294);
//   trait_make_limited_integral(uint64, 0, 18446744073709551614);
//   trait_make_limited_integral(char16, -32768 , 32767);
//   trait_make_limited_integral(char32, -2147483648, -2147483647);
//   trait_make_limited_decimal(float32, -3.4028*(10^-38), 3.4028*(10^38));
//   trait_make_limited_decimal(float64, -1.7977 *(10^-308), 1.7977 *(10^308));
//   trait_make_nullable_primitive(unknown);
//   trait_make_primitive(void_t);

	/** @brief Recursive structure used to represent the index required for accessing the typename in a template parameter pack. */
	template<uword... Indices> struct index_pack_t { template<uword N> using append = index_pack_t<Indices..., N>; };

	/** @brief A meta-programming structure used to create an index_pack_t. */
	template<uword Size> struct make_index_pack_t { typedef typename make_index_pack_t<Size-1>::type::template append<Size-1> type; };
	template<> struct make_index_pack_t<0u> { typedef index_pack_t<> type; };

	/** @brief A template expression used to create an index_pack_t for a set of template parameters. */
	template<typename... Types> using pack_indices_t = typename make_index_pack_t<sizeof...(Types)>::type;

   class Attribute;
   class Assembly;
   class Mirror;
   class Type;
   class Object;
   class Encoding;
   class Reference;
   class Stream;
   class Task;
   class Library;
   class Field;
   class DateTime;
   class Event;
   class Exception;
   class Constructor;
   class Callback;
   class Application;
   class Delegate;
   class Dynamic;
   class DynamicMember;
   class Structure;
   class File;
   class Folder;
   class Window;

   template<typename TEnum> class BitField;
   template<typename TEncoding> class Text;
   template<typename TReturn, typename... TParams> class NonVoidDelegate;
   template<typename... TParams> class VoidDelegate;
   template<typename TReturn, typename... TParams> class StaticDelegate;
   template<typename... TParams> class VoidStaticDelegate;
   template<typename TOwner, typename TReturn, typename... TParams> class MemberDelegate;
   template<typename TOwner, typename... TParams> class VoidMemberDelegate;
   template<typename TOwner, typename TReturn, typename... TParams> class ConstMemberDelegate;
   template<typename TOwner, typename... TParams> class VoidConstMemberDelegate;
   template<typename T> class Array;
   template<typename T> class List;
   template<typename T> class Stack;
   template<typename TKey, typename TValue> class KeyValuePair;
   template<typename TKey, typename TValue> class Map;
   template<typename... TSet> class Table;

     /** @brief A specialization structure used to bind a C++ typename to an Ngen.Type pointer that represent the reflection type information. */
   template<typename T> struct __type { static Type* value() { return 0x0; } };

   /** @brief A template function that gets the Ngen.Type pointer bound to a C++ typename. */
   template<typename T> Type* typeof() { return __type<T>::value(); }

   /** @brief A template function that gets the Ngen.Type pointer bound to the C++ typename of a given instance of that type. */
   Type* typeof(const Mirror& typeName); // Implementation: see [Ngen.Reflection]+Ngen.Reflection.AssemblyInfo.cpp

   /** @brief A specialization of Ngen.typeof template function that gets the Ngen.Type pointer for an Ngen.Object reference. */
   Type* typeof(const Object& variable);

   /*
      uint64 uint32 uint16 uint8 int64 int32 int16 int8 float32 float64 float16 byte ubyte unknown object typeof
      const_string string mirror const_mirror char8 char16 char32 isnull void_t string8 string16 string32 u32string
      utf8string utf16string wstring dynamic dynamic_member inref
   */
}

#endif // __NGEN_TYPEDEFS_HPP
