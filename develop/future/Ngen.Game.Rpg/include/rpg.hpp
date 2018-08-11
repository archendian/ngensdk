






struct s_stat {
	s_stat(const char* name, unsigned maxValue) : Current(maxValue), Max(maxValue), Enhanced(0);
	unsigned Value() { return Current; }	
	unsigned MaxValue() { return Max + (Enhanced); }	
	s_stat& operator+=(unsigned value) { Current += value; return *this; }
	s_stat& operator-=(unsigned value) { Current -= value; return *this; }
	
	unsigned Current;
	unsigned Max;
	unsigned Enhanced;
}

struct s_spell {
	
}

struct s_npc {}
struct s_character_scheme {
	
}

template<typename... T>
struct s_event {
	typedef (void)(T...) function;
	s_event(function func) : Function(1) {
		Function +=
	}
	
	s_event<T...>& operator+=(function func) {
		 Function.push_back(func);
	}
	
	void operator()(T params) {
		for(unsigned i = 0; i < Function.length(); i++) {
			Function[i](params...);
		}
	}
	
	vector<function> Function;
};

struct s_item_image_set {
		
	string Name;
};

struct s_item_scheme {
	
	string Name;
	string ImageSet;
	
	s_event<s_character*, s_item_scheme*> OnUse;
	s_event<s_character*, s_item_scheme*> OnDrop;
};

class Character;
class CharacterScheme;
class ItemScheme;
class BagSlot;
class EquipmentScheme;
class BagScheme;
class Bag;

class BagSlot {
public:
	unsigned Count;
	BagSlot* Item;
	Bag* Parent;
	
	BagSlot(Bag* parent, ItemScheme* item, uword count=1) : Count(count), Item(item), Parent(parent) {
		if(count > item->MaxPerBagSlot()) {
			Count = item->MaxPerBagSlot();
			Parent->TryAddNew(item, count - Count);
		}
	}
};

/** @breif instance of an item-scheme */
class BagSceheme {
public:
	Array<ItemSlot> Slot;
	
	BagSceheme(unsigned count=16) : Slot(16) {
		
	}
	
	
};

class ngen_scene_rpg_api Bag {
public:
	Array<BagSlot*> Slot;
	
	Bag(BagSceheme* scheme) : Slot(count) {
		for(unsigned i = 0; i < slotCount; i++) {
			Slot[i] = BagSlot::Empty();
		}
	}
};

void rpg_on_character_equip(Character* c, Item* item);
void rpg_on_character_unequip(Character* c, Item* item);
void rpg_on_character_use_item(Character* c, Item* item);
void rpg_on_character_throw_item(Character* c, Character* t, Item* item);


struct CharacterScheme {
	CharacterScheme(const mirror& name, unsigned level, unsigned maxHp, unsigned maxMp, unsigned str, unsigned wis, unsigned aim,
			unsigned def, unsigned per, unsigned luck) :
				Name(name), Level("Lvl", level), Exp("Xp", 0), Hp("HP", maxHp), Mp("MP", maxMp), Strength("STR", str),
				Wisdom("WIS", wis), Aim("AIM", aim), Defence("DEF", def), Perception("PER", per), Luck("LCK", luck),
				OnUnequipItem(1), OnEquipItem(1), OnUseItem(1), OnDropItem(1), OnThrowItem(1) {
			// correct the experience earned stat
			Exp.Max = (level * 100);
			Exp.Value = 0;
			
			// bind builtin event handlers
			OnUnequipItem += &rpg_on_character_equip;
	}
	
	
	mirror Name;
	s_stat Level;
	s_stat Exp;
	s_stat Hp;
	s_stat Mp;
	s_stat Strength;
	s_stat Wisdom;
	s_stat Aim;
	s_stat Defence;
	s_stat Perception;
	s_stat Luck;
	
	Event<Character*, EquipmentScheme*> 			OnUnequipItem;
	Event<Character*, EquipmentScheme*> 			OnEquipItem;
	Event<Character*, Character*, ItemScheme*> 		OnUseItem;
	Event<Character*, ItemScheme*> 					OnDropItem;
	Event<Character*, Character*, ItemScheme*> 		OnThrowItem;
};



