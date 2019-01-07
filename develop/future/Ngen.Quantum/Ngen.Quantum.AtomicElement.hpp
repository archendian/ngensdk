






#include <Ngen.hpp>
using namespace Ngen;

namespace Ngen {

	template<typename TKey, typename T>
	class Hashset {
	public:
		typedef KeyValuePair<TKey, T> TKvPair;
		
		Instance() : mInstance(0) {
		}
		
		void Add(const TKey& hash, const T& ref) {
			mInstance.Add(TKvPair(hash, T(ref));
		}
		
		Array<T> operator[](const mirror& key) {
			if(index <= result.Length()) {
				THROW(Exception());
			}
			
			auto result = Array<T>(1);
			
			auto begin = mInstance.Begin();
			auto end = mInstance.End();
			
			do {
				if(begin->Key == key) {
					result.Add(begin->Value);
				}
				
				begin++;
			} while (begin != end);
			
			return result;
		}
		
		void Remove(const TKey& hash) {
			if(index <= result.Length()) {
				THROW(Exception());
			}
			
			auto index = Array<uword>(1);
			auto begin = mInstance.Begin();
			auto end = mInstance.End();
			
			uword i = 0;
			do {
				if(begin->Key == key) {
					index.Add(i);
				}
				
				begin++;
				i++;
			} while (begin != end);
			
			for(i = 0; i < index.Length(); ++i) {
				mInstance.RemoveAt(index[i]);
			}
		}
	protected:
		Array<TKvPair> mInstance;
	};

	class Log {
	public:
		Log() {}
		virtual ~Log() {}
		
		virtual void Write(const string& message) pure;
		virtual void WriteLine(const string& message) pure;
	protected:
	};
	
	class ConsoleLog : public virtual Log {
	public:
		ConsoleLog() : Log() {}
		
		virtual void Write(message) {
			Console::Write(message);
		}
		
		virtual void WriteLine(message) {
			Console::WriteLine(message);
		}
	} ConsoleLogObj;
	
	class Logger {
	public:
		Logger() {
		}
		
		static void Write(const mirror& filter, const string& message) {
			
		}
		
		static void AddLog(const string& filter, Log* log) {
			mLogByFilter.Add(filter, log);
			mLogs.Add(&mLogByFilter[filter]);
		}
		
		string void Write(const mirror& filter, const string& message) {
			auto logs = mLogByFilter[filter]->Write(message);
		}
		
	protected:
		static Array<Log*> mLogs;
		static Hashset<mirror, Log*> mLogByFilter;
	};
}

class Character;

VoidStaticDelegate<Character*, Item*>::TFunction ItemUseFunction;
VoidStaticDelegate<Character*, Item*, Character* target>::TFunction ItemThrowFunction;
VoidStaticDelegate<Character*, Item*>::TFunction ItemEquipFunction;
VoidStaticDelegate<Character*, Item*>::TFunction ItemUnequipFunction;

VoidStaticDelegate<AtomicElement*>::TFunction AtomicElementBuilder;

enum class EAtomicElementType {
	NONMETAL = 0,
	HALONGEN,
	LANTHANIDE,
	NOBLE_GAS,
	ALKALINE,
	ALKALINE_EARTH,
	ACTINIDE,
	TRANSITION,
	POST_TRANSITION,
	METALLOID,
};

enum class EAtomicParticle {
	PROTON,
	ELECTRON,
	NUETRON,
};

const real NUETRON_MASS_AMU = 1.008664f;
const real PROTON_MASS_AMU = 1.007276f;
const real ELECTRON_MASS_AMU = 0.00054858f;

class AtomicElement {
public:
	string Name;
	string Symbol;
	string Type;
	real Weight;
	uword Group;
	uword Period;
	Array<uword> Shell;
	
	AtomicElement(const string& name, const string& symbol, EAtomicElementType type, AtomicElementBuilder build) : Name(name), Symbol(symbol), Type(type), Weight(0.f),Group(0), Period(0), Shell(1), PerShell(0) {\
		build(this);
		mElement.Add(name, *this);
		mELementBySymbol(symbol, &mElement[name]);
	}
	
	AtomicElement(const string& name, const string& symbol, EAtomicElementType type,  uword shellCount, AtomicElementBuilder build) : Name(name), Symbol(symbol), Type(type), Weight(0.f),Group(0), Period(0), Shell(shellCount), PerShell(0) {
		build(this);
		mElement.Add(name, *this);
		mELementBySymbol(symbol, &mElement[name]);
	}
	
	// in amus
	real MassInAmu() const {
		uword ecount = 0;
		for(uword i = 0; i < Shell.Count(); ++i) {
			ecount += Shell[i];
		}
		
		real value = ELECTRON_MASS_AMU * ecount;
		value += PROTON_MASS_AMU * Number;
		value += NUETRON_MASS_AMU * Number;
	};
	
	// in amus
	real IsotopeMassInAmu(uword index) const {
		uword ecount = 0;
		for(uword i = 0; i < Shell.Count(); ++i) {
			ecount += Shell[i];
		}
		
		real value = ELECTRON_MASS_AMU * ecount;
		value += PROTON_MASS_AMU * Number;
		value += NUETRON_MASS_AMU * Number + index;
	};
protected:
	static Map<string, AtomicElement> mElement;
	static Map<string, AtomicElement*> mElementBySymbol;
};

auto HYDROGEN = AtomicElement(const_string("hydrogen", "H", EAtomicElementType::NONMETAL, 1, [](AtomicElement* e) {
	e->Weight = 1.0078;
	e->Number = 1;
	e->Group = 1;
	e->Period = 1;
	e->Shell[0] = 1;
});

auto HELIUM = AtomicElement(const_string("helium", "He", EAtomicElementType::NONMETAL, 1, [](AtomicElement* e) {
	e->Weight = 4.0026;
	e->Number = 2;
	e->Group = 18;
	e->Period = 1;
	e->Shell[0] = 2;
});

auto LITHIUM = AtomicElement(const_string("lithium", "Li", EAtomicElementType::ALKALINE, 2, [](AtomicElement* e) {
	e->Weight = 6.938;
	e->Number = 3;
	e->Group = 1;
	e->Period = 2;
	e->Shell[0] = 2;
	e->Shell[1] = 1;
});

auto BERYLLIUM = AtomicElement(const_string("beryllium", "Be", EAtomicElementType::ALKALINE_EARTH, 2, [](AtomicElement* e) {
	e->Weight = 9.0122;
	e->Number = 4;
	e->Group = 2;
	e->Period = 2;
	e->Shell[0] = 2;
	e->Shell[1] = 2;
});

auto BERYLLIUM = AtomicElement(const_string("boron", "B", EAtomicElementType::METALLOID, 2, [](AtomicElement* e) {
	e->Weight = 10.806;
	e->Number = 5;
	e->Group = 13;
	e->Period = 2;
	e->Shell[0] = 2;
	e->Shell[1] = 3;
});

class ItemScheme {
public:
	ItemScheme(const string& name, const string& desc, ItemUseFunction use, ItemThrowFunction thro) : 
		mName(name), mDesc(desc), Use(use), Throw(thro) {}
	
	ItemUseFunction Use;
	ItemThrowFunction Throw;
	ItemUseFunction Equip;
	ItemUseFunction UnEquip;
	
protected:
	mirror mName;
	string mDesc;
};

mirror DEFENCE = const_mirror("Defence");
mirror HP = const_mirror("Hp");

namespace scheme {
	auto potion = ItemScheme("Potion", 
							 [] (Character* c, Item* i) {
								c.Stat[HP].AddToBase(20);
							 },
							 [] (Character* c, Item*, Character* t) {
								t.Stat[HP].AddToBase(20);
							 });
	
	auto hi_potion = ItemScheme("Hi-Potion", 
							 [] (Character* c, Item* i) {
								c.Stat[HP)].AddToBase(50);
							 },
							 [] (Character* c, Item*, Character* t) {
								t.Stat[HP].AddToBase(50);
							 });
	
	auto barrier = ItemScheme("Barrier", 
							 [] (Character* c, Item* i) {
								c->AddBuff(StatModifyBuff(c, const_mirror("Defence"), 10), 200);
							 },
							 [] (Character* c, Item*, Character* t) {
								t->AddBuff(StatModifyBuff(t, const_mirror("Defence"), 10), 200);
							 });
}
