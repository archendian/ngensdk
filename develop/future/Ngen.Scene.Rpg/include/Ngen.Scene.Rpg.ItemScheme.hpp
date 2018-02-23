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
#include <Ngen.hpp>
#include "Ngen.Scene.Rpg.EItemType.hpp"

namespace Ngen {
	namespace Scene {
		namespace Rpg {
			
			class ngen_scene_rpg ItemScheme {
			public:
				ItemScheme(const mirror& name, EItemType kind, ItemPickupFunc pickup, ItemDropFunc dropped, 
					ItemGiveFunc give, ItemAcceptFunc accept, ItemUseFunc use, ItemTargetFunc target, uint maxPerSlot=9) : mName(name), mItemKind(kind), mPickup(pickup),
						mDrop(dropped), mGive(give), mAccept(accept), mUse(use), mTarget(target), mErrNothingToRemove(errNothingToRemove),
						mRemoveFromContainer(removeFromContainer), mAddToContainer(addToContainer), mPerSlot(maxPerSlot) {
							
				}
				
				void PickUp(Character* who);
				void Drop(Character* who);
				void Give(Xharacter* who, Character* to);
				void Accept(Character* to, Character* who);
				void Use(Character* who);
				void Target(Character* who, Character* to);
				void ErrorNothingToRemove(ItemContainer* parent, ItemSlot* slot);
				void RemoveFromContainer(ItemContainer* parent, ItemSlot* slot) { }
				void AddToContainer(ItemContainer* parent, ItemSlot* slot) { }
				
			protected:
				mirror mName;
				EItemType mType;
				ItemPickupFunc mPickup;
				ItemDropFunc mDrop;
				ItemGiveFunc mGive;
				ItemTakeFunc mTake;
				ItemUseFunc mUse;
				ErrNothingToRemove mErrNothingToRemove;
				RemoveFromContainerSlot mRemoveFromContainer;
				AddToContainerSlot mAddToContainer;
				
				uint mMaxPerSlot;
			};
		}
	}
}