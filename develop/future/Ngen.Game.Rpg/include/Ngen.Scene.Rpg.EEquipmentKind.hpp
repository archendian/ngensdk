/*  _______    ________
    \      \  /  _____/  ____   ___
    /   |   \/   \  ____/ __ \ /   \
   /    |    \    \_\  \  ___/|   | \
   \____|__  /\______  /\___  >___| /
           \/        \/     \/    \/
The MIT License (MIT)

Copyright (c) 2018 FIXCOM, LLC

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
#ifndef __NGEN_SCENE_RPG_EEQUIPMENTPURPOSE_HPP
#define __NGEN_SCENE_RPG_EEQUIPMENTPURPOSE_HPP

#include "Build.Ngen.Scene.Rpg.Logic.hpp"

namespace Ngen {
	namespace Scene {
		namespace Rpg {
			
			enum class EEquipmentPurpose {
				Ring,				// Marriage, gaudy, enchanted-rings
				Head,				// Headgear, helmets, circlets
				Hand,				// Swords, pistols, shields
				TwoHand,            // Large blunt, bows, rifles
				Leg,				// Leggings, plate-legs, pants
				Feet,				// Shoes, boots, stockings
				Wrist,				// Braclets, watches, gagdets
				Glove,				// Gloves, mittens, bracers
				Shirt,				// Under-garments, plads, under-armor
				Neck,				// Necklaces, amulets
				Shoulder,			// Shoulder-pads, plate-wear
				Eye,				// Goggles, glasses. masks
			};
		}
	}
}
#endif