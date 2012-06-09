#ifndef ITEM_DEFINITION_H
#define ITEM_DEFINITION_H

#include "Sound.h"
#include "AbilityValues.h"
#include "StatusEffects.h"
#include "Audio.h"
#include "SpecialRoom.h"

enum NutritionValue_t {
	NutritionValue_none, NutritionValue_waterGlass, NutritionValue_mushroomBig, NutritionValue_egg, NutritionValue_dinner
};

enum ItemWeight_t {
	itemWeight_feather, itemWeight_light, itemWeight_medium, itemWeight_heavy
};

enum ItemDefArchetypes_t {
	itemDef_general,
	itemDef_meleeWpn,
	itemDef_meleeWpnIntr,
	itemDef_rangedWpn,
	itemDef_rangedWpnIntr,
	itemDef_missileWeapon,
	itemDef_ammo,
	itemDef_ammoClip,
	itemDef_scroll,
	itemDef_potion,
	itemDef_armor,
	itemDef_explosive
};

enum ItemDevNames_t {
	item_empty,

	item_trapezohedron,

	item_throwingKnife,
	item_rock,
	item_ironSpike,
	item_dagger,
	item_hatchet,
	item_club,
	item_hammer,
	item_machete,
	item_axe,
	item_pitchFork,
	item_sledgeHammer,
	item_sawedOff,
	item_pumpShotgun,
	item_machineGun,
	item_incinerator,
	item_teslaCanon,
	item_spikeGun,
	item_shotgunShell,
	item_drumOfBullets,
	item_incineratorShell,
	item_teslaCanister,
	item_pistol,
	item_pistolClip,
	item_flareGun,
	item_dynamite,
	item_flare,
	item_molotov,

	item_playerKick,
	item_playerStomp,

	item_bloatedZombiePunch,
	item_bloatedZombieSpit,
	item_ratBite,
	item_ratBiteDiseased,
	item_ratThingBite,
	item_wormMassBite,
	item_greenSpiderBite,
	item_whiteSpiderBite,
	item_blackSpiderBite,
	item_lengSpiderBite,
	item_ghoulClaw,
	item_shadowClaw,
	item_byakheeClaw,
	item_hellHoundFireBreath,
	item_hellHoundBite,
	item_giantBatBite,
	item_zombieAxe,
	item_zombieClaw,
	item_zombieClawDiseased,
	item_wolfBite,
	item_ghostClaw,
	item_phantasmSickle,
	item_wraithClaw,
	item_miGoElectricGun,
	item_mummyMaul,
	item_deepOneSpearAttack,
	item_deepOneJavelinAttack,
	item_oozeGraySpewPus,
	item_oozePutridSpewPus,
	item_oozeClearSpewPus,
	item_huntingHorrorBite,
	item_fireVampireTouch,

	item_armorLeatherJacket,
	item_armorIronSuit,
	item_armorFlackJacket,
//	item_armorAsbestosSuit,

	item_scrollOfPestilence,
	item_scrollOfTeleportation,
	item_scrollOfDeepDescent,
	item_scrollOfConfuseEnemies,
	item_scrollOfParalyzeEnemies,
	item_scrollOfSlowEnemies,
	item_scrollOfDetectTraps,
	item_scrollOfDetectItems,
	item_scrollOfBlessing,
	item_scrollOfMayhem,

	item_potionOfClairvoyance,
	item_potionOfHealing,
	item_potionOfBlindness,
	item_potionOfCorruption,
	item_potionOfReflexes,
	item_potionOfAiming,
	item_potionOfStealth,
	item_potionOfFortitude,
	item_potionOfToughness,
	item_potionOfParalyzation,
	item_potionOfFear,
	item_potionOfConfusion,

	endOfItemDevNames
};

struct ArmorData {
	ArmorData() :
		overRideAbsorptionPointLabel(""), protectsAgainstStatusBurning(false) {
		for(unsigned int i = 0; i < endOfDamageTypes; i++) {
			absorptionPoints[i] = 0;
			damageToDurabilityFactors[i] = 0.0;
		}
	}

	string overRideAbsorptionPointLabel;
	bool protectsAgainstStatusBurning;
	int absorptionPoints[endOfDamageTypes];
	double damageToDurabilityFactors[endOfDamageTypes];
	int chanceToDeflectTouchAttacks;
};

class ItemDefinition {
public:
	ItemDefinition(const ItemDevNames_t devName_) :
		devName(devName_), meleeStatusEffect(NULL), rangedStatusEffect(NULL) {
	}

	~ItemDefinition() {
		if(meleeStatusEffect != NULL)
			delete meleeStatusEffect;
		if(rangedStatusEffect != NULL)
			delete rangedStatusEffect;
	}

	ItemDevNames_t devName;
	ItemWeight_t itemWeight;
	int spawnStandardMinDLVL;
	int spawnStandardMaxDLVL;
	int maxStackSizeAtSpawn;
	int chanceToIncludeInSpawnList;
	bool isStackable;
	bool isIdentified;
	ItemName name;
	char glyph;
	SDL_Color color;
	Tile_t tile;
	bool isExplosive;
	bool isUsable;
	bool isReadable;
	bool isScroll;
	bool isScrollLearned;
	bool isScrollLearnable;
	bool isQuaffable;
	bool isEatable;
	NutritionValue_t nutritionValue;
	bool isArmor;
	ArmorData armorData;
	bool isCloak;
	bool isRing;
	bool isAmulet;
	bool isIntrinsicWeapon;
	bool isMeleeWeapon;
	bool isRangedWeapon;
	bool isMissileWeapon;
	bool isShotgun;
	bool isMachineGun;
	bool isAmmo;
	bool isAmmoClip;
	int ammoContainedInClip;
	DiceParam missileDmg;
	int missileBaseAttackSkill;
	DiceParam meleeDmg;
	int meleeBaseAttackSkill;
	Abilities_t meleeAbilityUsed;
	ItemAttackMessages meleeAttackMessages;
	StatusEffect* meleeStatusEffect; //TODO This requires deep copy of items
	DamageTypes_t meleeDamageType;
	bool meleeCausesKnockBack;
	bool rangedCausesKnockBack;
	DiceParam rangedDmg;
	string rangedDmgLabelOverRide;
	int rangedBaseAttackSkill;
	Abilities_t rangedAbilityUsed;
	ItemDevNames_t rangedAmmoTypeUsed;
	DamageTypes_t rangedDamageType;
	bool rangedHasInfiniteAmmo;
	char rangedMissileGlyph;
	Tile_t rangedMissileTile;
	SDL_Color rangedMissileColor;
	bool rangedMissileLeavesTrail;
	bool rangedMissileLeavesSmoke;
	ItemAttackMessages rangedAttackMessages;
	string rangedSoundMessage;
	Audio_t rangedAudio;
	Audio_t meleeAudio;
	Audio_t reloadAudio;
	int rangedSoundStrength;
	StatusEffect* rangedStatusEffect; //TODO This requires deep copy of items
	string causeOfDeathMessage;
	Abilities_t abilityToIdentify;
	int identifySkillFactor;
	vector<SpecialRoom_t> nativeRooms;

private:
};

#endif