






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

class Chemistry {
	/** @brief The number of atoms or molecules that make up a single Mol for any substance. */
	static const real ATOMS_PER_MOLE = 6.022e+23;
	
	
	/** @brief The mass of a single nuetron in amu. */
	static const real NUETRON_MASS_AMU = 1.008664r;
	
	/** @brief The mass of a single proton in amu. */
	static const real PROTON_MASS_AMU = 1.007276r;
	
	/** @brief The mass of a single electron in amu. */
	static const real ELECTRON_MASS_AMU = 0.00054858r;
	
	real NumberOfAtoms(real mol) {
		return mol * real;
	}
};

typedef Chemistry CHEM;

class GeneralRelatvity {
	/** @brief The gravity of Earth measured in meters per second squared (m/s^2). */
	static const real EARTH_GRAVITY = 9.807r;
	]
	/** @brief The gravity of Mars measured in meters per second squared (m/s^2). */
	static const real MARS_GRAVITY = 3.711r;
	
	/** @brief The gravity of the Sun measured in meters per second squared (m/s^2). */
	static const real SUN_GRAVITY = 247.0r;
	
	/** @brief The gravity of the Moon measured in meters per second squared (m/s^2). */
	static const real MOON_GRAVITY = 1.62r;
};

typedef GeneralRelatvity GR;

class AtomicElement {
public:
	mirror Name;
	string Symbol;
	EAtomicElementType Type;
	real Weight;
	uword Group;
	uword Period;
	Array<uword> Shell;
	real MeltingPt;
	real BoilingPt;
	
	AtomicElement(const string& name, const string& symbol, EAtomicElementType type, AtomicElementBuilder build) :
		Name(mirror(name)), Symbol(symbol), Type(type), Weight(0.f),Group(0), Period(0), Shell(1), MeltingPt(0.0), BoilingPt(0.0) {\
		build(this);
		mElement.Add(mirror(name), *this);
		mELementBySymbol(symbol, &mElement[mirror(name)]);
	}
	
	AtomicElement(const string& name, const string& symbol, EAtomicElementType type,  uword shellCount, AtomicElementBuilder build) : 
		Name(mirror(name)), Symbol(symbol), Type(type), Weight(0.f),Group(0), Period(0), Shell(shellCount), MeltingPt(0.0), BoilingPt(0.0) {
		build(this);
		mElement.Add(mirror(name), *this);
		mELementBySymbol(symbol, &mElement[mirror(name)]);
	}
	
	// in amus
	real MassInAmu() const {
		uword ecount = 0;
		for(uword i = 0; i < Shell.Count(); ++i) {
			ecount += Shell[i];
		}
		
		real value = CHEM::ELECTRON_MASS_AMU * ecount;
		value += CHEM::PROTON_MASS_AMU * Number;
		value += CHEM::NUETRON_MASS_AMU * Number;
		
		return value;
	}
	
	// in amus
	real IsotopeMassInAmu(word index) const {
		uword ecount = 0;
		for(uword i = 0; i < Shell.Count(); ++i) {
			ecount += Shell[i];
		}
		
		real value = CHEM::ELECTRON_MASS_AMU * ecount;
		value += CHEM::PROTON_MASS_AMU * Number;
		value += CHEM::NUETRON_MASS_AMU * (Number + index);
		
		return value;
	}
	
	static AtomicElement& Get(const string& name) {
		auto hash = mirror(name);
		if mElement.ContainsKey(hash)) {
			return &mElement[hash];
		}
		
		return null;
	}
	
	static AtomicElement& Get(const mirror& name) {
		if mElement.ContainsKey(name)) {
			return &mElement[name];
		}
		
		return null;
	}
	
	static AtomicElement& GetBySymbol(const string& symbol) {
		if mElementBySymbol.ContainsKey(symbol)) {
			return mElementBySymbol[symbol];
		}
		
		return null;
	}
	
protected:
	static Map<mirror, AtomicElement> mElement;
	static Map<mirror, AtomicElement*> mElementBySymbol;
};

#def TOE TableOfElements;
namespace TableOfElements {
	// all the elements (normal isotope)
	AtomicElement HYDROGEN;
	AtomicElement HELIUM;
	AtomicElement LITHIUM;
	AtomicElement BERYLLIUM;
	AtomicElement BORON;
	AtomicElement CARBON;
	AtomicElement NITROGEN;
	AtomicElement OXYGEN;
	AtomicElement FLOURINE;

}

HYDROGEN = AtomicElement(const_string("hydrogen", "H", EAtomicElementType::NONMETAL, 1, [](AtomicElement* e) {
	e->Weight = 1.0078;
	e->Number = 1;
	e->Group = 1;
	e->Period = 1;
	e->Shell[0] = 1;
	e->MeltingPt = 13.99;
	e->BoilingPt = 20.28;
});

HELIUM = AtomicElement(const_string("helium", "He", EAtomicElementType::NONMETAL, 1, [](AtomicElement* e) {
	e->Weight = 4.0026;
	e->Number = 2;
	e->Group = 18;
	e->Period = 1;
	e->Shell[0] = 2;
	e->MeltingPt = 0.95;
	e->BoilingPt = 4.22;
});

LITHIUM = AtomicElement(const_string("lithium", "Li", EAtomicElementType::ALKALINE, 2, [](AtomicElement* e) {
	e->Weight = 6.938;
	e->Number = 3;
	e->Group = 1;
	e->Period = 2;
	e->Shell[0] = 2;
	e->Shell[1] = 1;
	e->MeltingPt = 453.7;
	e->BoilingPt = 1603.0;
});

BERYLLIUM = AtomicElement(const_string("beryllium", "Be", EAtomicElementType::ALKALINE_EARTH, 2, [](AtomicElement* e) {
	e->Weight = 9.0122;
	e->Number = 4;
	e->Group = 2;
	e->Period = 2;
	e->Shell[0] = 2;
	e->Shell[1] = 2;
	e->MeltingPt = 1560.0;
	e->BoilingPt = 3243.0;
});

BORON = AtomicElement(const_string("boron", "B", EAtomicElementType::METALLOID, 2, [](AtomicElement* e) {
	e->Weight = 10.806;
	e->Number = 5;
	e->Group = 13;
	e->Period = 2;
	e->Shell[0] = 2;
	e->Shell[1] = 3;
	e->MeltingPt = 2349.0;
	e->BoilingPt = 4200.0;
});

CARBON = AtomicElement(const_string("carbon", "C", EAtomicElementType::METALLOID, 2, [](AtomicElement* e) {
	e->Weight = 12.0107;
	e->Number = 6;
	e->Group = 14;
	e->Period = 2;
	e->Shell[0] = 2;
	e->Shell[1] = 4;
	e->MeltingPt = 3825.0;
	e->BoilingPt = 5100.0;
});

NITROGEN = AtomicElement(const_string("nitrogen", "N", EAtomicElementType::METALLOID, 2, [](AtomicElement* e) {
	e->Weight = 14.2087;
	e->Number = 7;
	e->Group = 15;
	e->Period = 2;
	e->Shell[0] = 2;
	e->Shell[1] = 5;
	e->MeltingPt = 63.15
	e->BoilingPt = 77.36;
});

OXYGEN = AtomicElement(const_string("oxygen", "O", EAtomicElementType::METALLOID, 2, [](AtomicElement* e) {
	e->Weight = 15.9994;
	e->Number = 8;
	e->Group = 15;
	e->Period = 2;
	e->Shell[0] = 2;
	e->Shell[1] = 6;
	e->MeltingPt = 54.36;
	e->BoilingPt = 90.19;
});

class AtomicBond {
	AtomicElement* Begin;
	AtomicElement* End;
};
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
