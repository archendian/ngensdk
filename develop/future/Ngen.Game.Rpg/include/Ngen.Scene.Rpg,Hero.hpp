






namespace Rpg {
	namespace Scene {
		
		class ngen_scene_api VisibleObject {
		public:
			VisibleObject(bool is3d=false) : Mesh(0)
		protected:
			bool mIs3D;
			
			union {
				Model* mMesh;
				Texture* mImage;
			};
	
		};
		
		namespace Rpg {
		
			VoidStaticDelegate<Hero*, EquipmentScheme*, EquipmentSlot*> CharacterEquipFunc;
			VoidStaticDelegate<Hero*, EquipmentScheme*, EquipmentSlot*> CharacterUnequipFunc;
			VoidStaticDelegate<Hero*, StatSheet&> CharacterStatSheetBuilderFunc;
			
			void hero_equip_weapon(Hero* _self, EquipmentScheme* _equipment, EquipmentSlot* _inventoryslot);
			void hero_unequip_weapon(Hero* _self, EquipmentScheme* _equipment, EquipmentSlot* _inventoryslot);
			void hero_draw(Hero* _self, RenderTarget* _target);
			
			class ngen_scene_rpg_api Hero : public virtual Character {
			public:
				Hero(const mirror& name, CharacterStatSheetBuilderFunc builder, CharacterEquipFunc onEquip=&hero_equip_weapon, CharacterUnequipFunc onHeroUnequip=&hero_unequip_weapon) : Character::Character(name) {
				
				}
			};
			
			#define __inline_build_statsheet(SHEET, HP,MP,STR,DEF,WIS,AIM,AGI,END,PER,LUCK)\
				SHEET.Add(mirror("Hp"), simple_stat(HP)); \
				SHEET.Add(mirror("Mp"), simple_stat(MP)); \
				SHEET.Add(mirror("Strength"), simple_stat(STR)); \
				SHEET.Add(mirror("Defense"), simple_stat(DEF)); \
				SHEET.Add(mirror("Wisdom"), simple_stat(WIS)); \
				SHEET.Add(mirror("Aim"), simple_stat(AIM)); \
				SHEET.Add(mirror("Agility"), simple_stat(AGI)); \
				SHEET.Add(mirror("Endurance"), simple_stat(END)); \
				SHEET.Add(mirror("Perception"), simple_stat(PER)); \
				SHEET.Add(mirror("Luck"), simple_stat(LUCK))
		
			namespace BuiltIn {

				Character GOBLIN = create_creature_character(
					"Goblin",
					"A small elven-like creature that can be found in wooded areas alongside common trade routes.",
					// Build stat-sheet
					[](Character* _char, StatSheet& _stat) { __inline_build_statsheet(_stat,
					//	HP  MP
						40, 20,
					//  ST DF WS  AI AG  EN PR LK
						12, 8, 10, 8, 15, 6, 5, 7);
					},
				);
				
				Character GOBLIN = create_creature_character(
					"Goblin",
					"A small elven-like creature that can be found in wooded areas alongside common trade routes.",
					// Build stat-sheet
					[](Character* _char, StatSheet& _stat) { __inline_build_statsheet(_stat,
					//	HP  MP
						40, 20,
					//  ST DF WS  AI AG  EN PR LK
						12, 8, 10, 8, 15, 6, 5, 7);
					},
				);
				
				
				typedef VoidStaticDelegate<CharacterScheme*, Character*, EquipmentScheme*> CharacterEquipFunc;
				
				class ngen_scene_rpg_api CharacterScheme {
				public:
					
					virtual Equip(Character* c, WeaponScheme* weapon) {
						Equip(this, c, weapon);
					}
				protected:
					CharacterEquipFunc Equip;
					CharacterEquipFunc Unequip;
				};
				
				Character rpg_create_character_instance(const mirror& charSchemeId, uword level=1) {
					return Character(CharacterScheme::Get(charScehemeId), level);
				}
			}
		}
	}
}


