



 
#ifndef __NGEN_GAME_RPG_HPP
#define __NGEN_GAME_RPG_HPP

#include "Build.Ngen.Content.Logic.hpp"


namespace Ngen {
	namespace Game {
		namespace Rpg {
		
			typedef Event<const mirror&, const string&, bool&> NamedChangingEvent;
			
			template<typename T>
			class NamedStat {
			public:
				typedef T TSub;
				
				NamedStat(const string& name, T value, T min, T max) : mBonus(0), mOriginal(value), mMin(min), mMax(max), NamedChanging(), MinReached(), MaxReached() {
				}
				
				void Name(const string& newName) {
					bool change = true;
					
					NamedChanging.Fire(mName, newName, change);
					if(change) {
						mName = mirror(newName);
					}
				}
				
				mirror Name() const { return mName; }
				
				T Bonus() const { return mBonus; }
				
				T Current() const {
					T result = mOriginal += mBonus;
					
					if(result >= mMax) {
						return mMax;
					} else if(result <= mMin) {
						return mMin;
					}
					
					return result;
				}
				
				T Original() const { return mOriginal; }
				T Min() const { return mMin; }
				
				T Max() const { return mMax; }
				
				void Min(uint32 min) { 
					if(Current() <= min) {
						MinReached.Fire(void_t());
					} 
					
					mMin = min;
				}
				
				void Max(uint32 max) { 
					if(Current() >= max) {
						MaxReached.Fire(void_t());
					}
					
					mMax = max; 
				}
				
				template<typename TRhs> void AddToBonus(TRhs value) {
					mBonus += (T)value;
					
					T current = Current();
					if(current <= mMin) {
						MinReached.Fire(void_t());
					} else if(current >= mMax) {
						MaxReached.Fire(void_t());
					}
				}
				
				template<typename TRhs> void AddToCurrent(TRhs value) {
					mOriginal += (T)value;
					
					T current = Current();
					if(current <= mMin) {
						MinReached.Fire(void_t());
					} else if(current >= mMax) {
						MaxReached.Fire(void_t());
					}
				}
				
				NamedChangingEvent NamedChanging;
				ValueReachedEvent MinReached;
				ValueReachedEvent MaxReached;
				
			protected:
				mirror mName;
				T mBonus;
				T mOriginal;
				T mMin;
				T mMax;
			};
			
			typedef NamedStat<int32> named_stat_i32;
			typedef NamedStat<float32> named_stat_f32;

			template<typename T>
			class StatSheet {
			public:
				typedef NamedStat<T> TStat;
				
				StatSheet(Character* parent) : mStat(1), mParent(parent {
				}
				
				void AddStat(const string& name, TStat::TSub value, TStat::TSub min, TStat::TSub max) {
					mStat.Add(mirror(name), TStat(name, value, min, max));
					StatAdded.Fire(mParent, &mStat[mirror(name)]);
				}
				
				void RemoveStat(const string& name) {
					RemoveStat(mirror(name));
				}
				
				void RemoveStat(const mirror& name) {
					StatRemoved.Fire(mParent, &mStat[name]);
					mStat.Remove(name);
				}
				
				TStat& operator[](const string& name) {
						return mStat(mirror(name);
				}
				
				const TStat& operator[](const string& name) const {
						return mStat(mirror(name);
				}
				
				TStat& operator[](const mirror& name) {
						return mStat[name];
				}
				
				const TStat& operator[](const mirror& name) const {
						return mStat[name];
				}
				
				Event<Character*, TStat*> StatAdded;
				Event<Character*, TStat*> StatRemoved;
	
			protected:
				Map<mirror, TStat> mStat;
				Character* mParent;
			};
					
			typedef StatSheet<float32> stat_sheet_f32
			typedef StatSheet<int32> stat_sheet_i32;
			
			typedef VoidStaticDelegate<Character*, Character*>::TFunction SkillUseFunction;
			
			class Skill {
			public:
				Skill(const string& name, SkillUseFunction use) : mName(name), mUse(use) {
					
				}
				
				void Use(Character* owner, Character* target) {
					mUse(owner, target);
				}
				
			protected:
				mirror mName;
				SkillUseFunction mUse; 
			};
			
			class Buff {
			public:
				Buff(const string& name, CharacterBuilder apply, CharacterBuilder remove) : mName(name) {
			
				}
				
				void Apply(Character* to) const {
					mApply(to);
				}
				
				void Remove(Character* from) const {
					mRemove(from);
				}
				
			protected:
				mirror mName;
				CharacterBuilder mApply;
				CharacterBuilder mRemove;
			};
			
			
			typedef VoidStaticDelegate<Character*> CharacterBuilder;
			typedef Event<Character*> CharacterEvent;
			
			class Character {
			public:
				Character(const string& name, CharacterBuilder builder) : mName(name), mStat(this) {
					// setup stats
					builder(this);
					// setup stat events
					
				}

				stat_sheet_i32& Statsheet() { return mStat; }
				const stat_sheet_i32& Statsheet() const { return mStat; }
				
				Skill* Skill(const string& name) {
					Skill* result = null;
					if(!mSkill.TryGetValue(name, inref result)) {
						return result;
					}
					return result;
				}
				
				Buff* Buff(const string& name) {
					Buff* result = null;
					if(!mBuff.TryGetValue(name, inref result)) {
						return result;
					}
					return result;
				}
				
				Array<Skill*> Skills() const { return mSkill.GetValues(); }
				Array<Buff*> Buffs() const { return mBuff.GetValues(); }
				
			protected:
				mirror mName;
				stat_sheet_i32 mStat;
				map<mirror, Skill*> mSkill;
				map<mirror, Buff*> mBuff;
			};
			
			
			void common_character_builder(Character* c) {
				auto ss = &c->Statsheet();
				ss->AddStat(const_string("HP"), 100, 0, 100);
				ss->AddStat(const_string("MP"), 40, 0, 40);
				ss->AddStat(const_string("Level"), 1, 1, 100);
				ss->AddStat(const_string("Experience"), 0, 0, 100);
				
				ss->AddStat(const_string("Strength"), 10, 1, 255);
				ss->AddStat(const_string("Wisdom"), 10, 1, 255);
				ss->AddStat(const_string("Intelligence"), 10, 1, 255);
				ss->AddStat(const_string("Charisma"), 10, 1, 255);
				ss->AddStat(const_string("Strength"), 10, 1, 255);
			}
		typedef VoidStaticDelegate<string>::TFunction SelectedDialogDelegate;
		
		class Dialog {
		public:
			Dialog(const string& line, bool isQuestion=false, Dialog* next=null) :
				mLine(line), mNext(next), mIsQuestion(isQuestion), mSelect(), mOption() {
			}
			
			Dialog(const string& line, bool isQuestion, Dialog* next, SelectedDialogDelegate select) :
				mLine(line), mNext(next), mIsQuestion(isQuestion), mSelect(select), mOption() {
			}
			
			Dialog(const string& line, bool isQuestion, const Array<kvpair<string, Dialog>>& options) :
				mLine(line), mNext(0), mIsQuestion(isQuestion), mSelect(), mOption(options) {
			}
			
			Dialog(const string& line, bool isQuestion, SelectedDialogDelegate select, const Array<kvpair<string, Dialog>>& options) :
				mLine(line), mNext(0), mIsQuestion(isQuestion), mSelect(select), mOption(options) {
			}
			
			void Activate(const string& str) {
				Console::WriteLine(mLine);
				mSelect(str);
				
				if(mIsQuestion) {
					tchar sel = 'a';
					for(uword i = 0; i < mOption.Length(); i++) {
						Console::Write(sel);
						Console::Write(const_string(") "));
						Console::WriteLine(mOption.KeyAt(i));
						sel++;
					}
					
					sel = Console::GetSingleChar();
					uword opt = sel - 'a';
					mOption.ValueAt(opt).Activate(mOption.KeyAt(opt));
				}
			}
			
		protected:
			string mLine;
			Dialog* mNext;
			bool mIsQuestion;
			SelectedDialogDelegate mSelect;
			Map<string, Dialog> mOption;
		};
		
		string HeroId = string::Empty();
		
		#define create_dialog_option(DIALOG_OPTION_ID, DIALOG_LINE)\
			kvpair<string, Dialog>(string(DIALOG_OPTION_ID), Dialog(const_string(DIALOG_LINE)))
		
		#define create_dialog_option(DIALOG_OPTION_ID, DIALOG_LINE, DIALOG_ONSELECTED)\
			kvpair<string, Dialog>(string(DIALOG_OPTION_ID, true), Dialog(string(DIALOG_LINE, true), false, 0, DIALOG_ONSELECTED))
		
		typedef VoidStaticDelegate<>::TFunction VoidParamDelegate;
		
		template<typename T> class Stat {
		public:
			typedef Stat<T> TSelf;
			
			Event OnMinReached;
			Event OnMaxReached;
			Event OnCurrentIncrease;
			Event OnCurrentDecrease;
			
			Stat(T min, T max, T current) : mMin(min), mMax(max), mCurrent(current) {}
			Stat(T current) : mMin(0), mMax(current), mCurrent(current) {}
			
			T Min() const { return mMin; }
			T Max() const { return mMax; }
			T Current() const { return mCurrent; }
			void Min(uword value) { mMin = (T)value; }
			void Max(uword value) { mMax = (T)value; }
			void Current(uword value) { mCurrent = (T)value; }
			void Min(float64 value) { mMin = (T)value; }
			void Max(float64 value) { mMax = (T)value; }
			void Current(float64 value) { mCurrent = (T)value; }
			
			TSelf& operator+=(uword value) {
				mCurrent = calc::Min(mCurrent + value, mMax);
				if(mCurrent == mMax) {
					OnMaxReached();
				}
				
				OnCurrentIncrease();
				return *this;
			}
			
			TSelf& operator-=uword value) {
				mCurrent = calc::Max(mCurrent - value, mMin);
				if(mCurrent == mMin) {
					OnMinReached();
				}
				
				OnCurrentDecrease();
				return *this;
			}
			
		protected:
			T mMin;
			T mMax;
			T mCurrent; 
		};
		
		typedef Stat<uint32> stat_u32;
		typedef Stat<float32> stat_f32;
		typedef Stat<uint8> stat_u8;
		typedef Stat<uint16> stat_u16;
		
		typedef kvpair<string, stat_u8> named_stat_u8;
		typedef kvpair<string, stat_u16> named_stat_u16;
		typedef kvpair<string, stat_u32> named_stat_u32;
		typedef kvpair<string, stat_f32> named_stat_f32;
		
		template<typename TStat> void draw_named_stat(const kvpair<string, TStat>& stat, uword x, uword y, uword size);
		template<typename TStat> void draw_named_stat(const Array<kvpair<string, TStat>>& stats, uword x, uword y, uword size);
		
		

		typedef StaticDelegate
		
		class Character {
		public:
			Character(const string& name, ubyte level=1) : Name(name), Hp(0, 9999, 100), Mp(0, 999, 20), Exp(0, 99999999, 0),
				Level(level), Strength("Strength", stat_u8(0, 10, 5)), Wisdom("Wisdom", stat_u8(0, 10, 5)), 
				Perception("Perception", stat_u8(0, 10, 5)), Agility("Agility", stat_u8(0, 10, 5)), 
				Defence("Defence", stat_u8(0, 10, 5)), Charm("Charm", stat_u8(0, 10, 5)) {
					if(level != 1 || level != 0) {
						return;
					}
					
					real diff = level * .01f;
					
				}
				
			string Name;
			named_stat_u16 Hp;
			named_stat_u16 Mp;
			named_stat_u32 Exp;
			ubyte Level;
			
			named_stat_u8 Strength;
			named_stat_u8 Wisdom;
			named_stat_u8 Perception;
			named_stat_u8 Agility;
			named_stat_u8 Defence;
			named_stat_u8 Charm;
			
			
			
		
			
		};
		
		template<typename... Var>
		void Read(const string& format, const string& line, Var dat) {
			uword j = 0;
			uword k = 0;
			
			// get number of arguments
			for(uword i=0; i < format.Length(); i++) {
				if(format[i] == '%') {
					i++;
					switch(format[i]) {
					case 'F':
					case 'f': {
						i++;
						float64 value = 0;
						string text = string::Empty();
						
						for(;j < line.Length(); j++) {
							if(line[j] == format[i]) {
							   break;
							} else {
							   text += line[j];
							}
						}
						
						j = 0;
						string::To(text, &value);
						
					}
					case 'U':
					case 'u':
					case 'r':
					}
				}else {
				   j++;
				}
			}
			
			for(uword i=0; i < format.Length(); i++) {
			
			}
		}
	}
	#endif
