/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

Copyright (c) 2013 Ngeneers Inc.

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
#include "Ngen.Scene.Rpg.Typedef.hpp"
#include "Ngen.Scene.Rpg.EItemType.hpp"

namespace Ngen {
	namespace Scene {
		namespace Rpg {

			typedef Map<mirror, ItemScheme> ItemSchemeMap;
			typedef VoidStaticDelegate<ItemScheme*, Character*, Character*>::TFunction UseItemFunction;

			ItemSchemeMap ITEM_SCHEME = ItemSchemeMap(10);
			
			class ngen_scene_rpg_api ItemScheme {
			public:
				ItemScheme(const mirror& name, EItemType type, uword maxPerSlot, UseItemFunction useItem) : mName(name), mType(type), mMaxPerSlot(maxPerSlot), mUse(useItem) {
					ITEM_SCHEME.Add(name, *this);
				}

				void Use(Character* owner, Character* target) {
					mUse(this, owner, target);
				}

				mirror Name() const { return mName; }
				EItemType Type() const { return mType; }
				ItemScheme* Self() { return &ITEM_SCHEME[mName]; }
			protected:

				mirror mName;
				EItemType mType;
				uword mMaxPerSlot;
				UseItemFunction mUse;
			};
		}
	}
}