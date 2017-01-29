
#ifndef NGEN_CODE_DYNAMIC_HPP
#define NGEN_CODE_DYNAMIC_HPP


#include "Build.Ngen.Code.hpp"

using Ngen;
using Ngen::Reflection;

namespace Ngen {
   namespace Code {
      class DynamicObject;
      class DynamicMember {
         DynamicMember(const mirror& name, const Object& field) : mField(0), mIsField(true) {
         }

         DynamicMember(const mirror& name, const Callback& method) : mMethod(0), mIsField(true) {
         }

         template<typename T> SetField(const T& copy) {
            if(!Object::IsNull(mField)) {
               mField = Object::New<T>()
            }

            if(Trait<T>::IsPrimitive) {
               Memory::Copy(&copy, (T*)mField.ToPointer(), 1);
            } else if(Trait<T>::IsDelegate) {
               mMethod
            }
         }

         template<typename T> Get() {
            if(Trait<T>::IsPrimitive) {

               Memory::Copy(&copy, (T*)mField.ToPointer(), 1);
            } else if(Trait<T>::IsDelegate) {
               mMethod
            }
         }

         template<typename T> operator=(const T& copy) {
            if(Trait<T>::IsPrimitive) {

               Memory::Copy(&copy, (T*)mField.ToPointer(), 1);
            } else if(Trait<T>::IsDelegate) {
               mMethod
            }
         }

      protected:
         bool     mIsField;
         union {
         Object    mField;
         Callback* mMethod;
         }

         friend class DynamicObject;
      };

      class Dynamic : class Object {
      public:
         Dynamic(const Array<DynamicMember>& members) : Object() {

         }

         ~Dynamic() {

         }

         DynamicMember* operator[](const mirror& name);

      };

      int main() {

         dynamic anything = {
            new dynamic_field_info("MyField", 1.0),
            new dynamic_method_info("dynamic MyFunction[2]", [] (dynamic a, dynamic b)) {
               return a + b;
            }
         }

         anything["MyField"] = "Hello world!";
         anything["MyField"] = "Hello world!";
         Console::WriteLine(anything["MyFunction"](3, "5"));
      }
   }

    class ngen_game_rpg_api RpgMapFactory : public Ngen::Scene::MapFactory {
    public:

    protected:

    };

    class ngen_game_rpg_api RpgEntityFactory : public Ngen::Scene::SceneNodeFactory {
    public:
        RpgEntityFactory(const mirror& name) : Ngen::Scene::SceneNodeFactory(name) {
        }

    };

   class ngen_game_rpg_api RpgBehavior {
   public:

   protected:
        mirror mName;
        string mDescription;


   };

   struct Player {
    string  Name;
    bool    Female;
    string  Species;
    string  Legion;
    string  Home;
    string  Branch;
    string  Rank;

    // -- experience
    unsigned MaxHP, HP;
    unsigned MaxMP, MP;
    unsigned MaxEX, EX;
    unsigned MaxLV, LV;

    // -- wealth
    unsigned Baterian;
    unsigned Centium;

    // -- raw elements
    unsigned HydrogenKG;
    unsigned HeliumKG;
    unsigned LithiumG;
    unsigned OxygenKG;
    unsigned GoldG;
    unsigned SilverKG;
    unsigned PlatinumG;
    unsigned LeadKG;
    unsigned NickelKG;
    unsigned IronKG;
    unsigned CopperKG;
    unsigned TitaniumKG;
    unsigned PlutoniumG;
    unsigned RhodiumG;
    unsigned CarbonKG;
    unsigned RareG;


    // -- manned combat attributes
    unsigned MaxSTR, STR;
    unsigned MaxMEN, MEN;
    unsigned MaxAIM, AIM;
    unsigned MaxAGI, AGI;
    unsigned MaxEND, END;
    unsigned MaxRES, RES;
    unsigned MaxRAD, RAD;
    unsigned MaxAID, AID;
    unsigned MaxFIN, FIN;

    // -- personality traits
    unsigned MaxBravery, Bravery;
    unsigned MaxFaith, Faith;
    unsigned MaxCuriosity, Curiosity;
    unsigned MaxWisdom, Wisdom;
    unsigned MaxCulture, Culture;
    unsigned MaxFame, Fame;
    unsigned MaxLuck, Luck;
    unsigned MaxCharisma, Charisma;
    unsigned MaxSensitivity, Sensitivity;
    unsigned MaxHonor, Honor;
    unsigned MaxSurvival, Survival;
    unsigned MaxEducation, Education;

    // -- trait tree
    TraitTree CombatTraits;
    TraitTree VehicleTraits;
    TraitTree TechTraits;
    TraitTree SocialTraits;
    TraitTree PoliticalTraits;
    TraitTree MarketTraits;
    TraitTree MechTraits;
    TraitTree WeaponTraits;
    TraitTree ArmorTraits;
    TraitTree EquipmentTraits;
    TraitTree ChemTraits;
    TraitTree FieldTraits;
    TraitTree MilitaryTraits;
    TraitTree AcademicTraits;

    // -- abilities
    AbilityMap PhysicalAbility;
    AbilityMap MentalAbility;
    AbilityMap BattleAbility;
    AbilityMap ActiveAbility;
    AbilityMap SpecialAbility;
    AbilityMap HiddenAbility;

    // -- fun stats
    unsigned EnemiesKilled;
    unsigned SpeciesFound;
    unsigned SpeciesKilled;
    unsigned CivilizationsFound;
    unsigned CivilizationsSaved;
    unsigned CivilizationsKilled;
    unsigned GalaxiesFound;
    unsigned GalaxiesVisited;
    unsigned PlanetsFound;
    unsigned PlanetsVisited;
    unsigned HabitablePlanetsVisited;
    unsigned StarsSystemsFound;
    unsigned StarsFound;
    unsigned StarsHarvested;
    unsigned NuetronStarsFound;
    unsigned NuetronStarsHarvested;
    unsigned BlackHolesFound;
    unsigned BlackHolesClosed;
    unsigned WeaponsCrafted;
    unsigned ChemsCrafted;
    unsigned ChemsTaken;
    unsigned BulletsCrafted;
    unsigned BulletsFired;
    unsigned BulletsMissed;
    unsigned Headshots;
    unsigned Fatalities;
    unsigned VehiclesCrafted;
    unsigned Victories;
    unsigned Losses;
    unsigned Kills;
    unsigned Deaths;
    unsigned DamageTaken;
    unsigned DamageGiven;
    unsigned CulturesFound;
    unsigned ArtifactsFound;
    unsigned BarterianSpent;
   };

   class Galaxy {};
   class Star{};
   class BlackHole{};
   class Planet{};
   class Moon {};
   class Comet {};
   class Anomoly {};
   class Civilization {};
   class Landmass {};
   class Ocean {};
   class Atmosphere {};
   class Landmark {};
   class City {};
   class Region {};
   class Building {};
   class Road {};
   class Artifact {};
   class Universe {};
   class Technology {};
   class Jungle {};
   class Desert {};
   class Organism {};
   class University {};
   class Military {};
   class Population {};
   class Space {};
   class Orbital {};
   class God {};
   class SolarSystem {};
   class ngen_game_rpg_api RpgCharacter {
   public:

   protected:
        mirror mName;

   };
}
#endif // NGEN_CODE_DYNAMIC_HPP
