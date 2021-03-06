#ifndef PLAYER_BON_H
#define PLAYER_BON_H

#include <string>
#include <vector>
#include <algorithm>

#include "ability_values.hpp"
#include "converters.hpp"

#include <math.h>

struct Actor_data_t;

enum class Trait
{
    //Common (except some traits can be blocked for certain backgrounds)
    adept_melee_fighter,
    expert_melee_fighter,
    master_melee_fighter,
    adept_marksman,
    expert_marksman,
    cool_headed,
    dem_expert,
    dexterous,
    fearless,
    imperceptible,
    vicious,
    stealthy,
    mobile,
    lithe,
    observant,
    perceptive,
    vigilant,
    treasure_hunter,
    self_aware,
    healer,
    rapid_recoverer,
    survivalist,
    perseverant,
    stout_spirit,
    strong_spirit,
    mighty_spirit,
    tough,
    rugged,
    unbreakable,
    strong_backed,
    undead_bane,

    //Unique for Ghoul
    ravenous,
    foul,
    toxic,

    //Unique for Occultist
    warlock,
    summoner,
    blood_sorcerer,
    seer,

    //Unique for Rogue

    //Unique for War veteran
    master_marksman,
    fast_shooter,
    courageous,
    steady_aimer,
    sharpshooter,

    END
};

enum class Bg
{
    ghoul,
    occultist,
    rogue,
    war_vet,
    END
};

namespace player_bon
{

extern bool traits[int(Trait::END)];

void init();

void save();

void load();

void pickable_bgs(std::vector<Bg>& bgs_ref);

void pickable_traits(const Bg bg, std::vector<Trait>& traits_ref);

void trait_prereqs(const Trait id,
                   const Bg bg,
                   std::vector<Trait>& traits_ref,
                   Bg& bg_ref);

Bg bg();

std::string trait_title(const Trait id);
std::string trait_descr(const Trait id);

std::string bg_title(const Bg id);

//NOTE: The string vector reference parameter set in this function is not formatted in
//bg_descr. Each line still needs to be formatted by the calling function. The reason
//for using a vector reference instead of simply a string is only to specify line breaks.
void bg_descr(const Bg id, std::vector<std::string>& out);

std::string all_picked_traits_titles_line();

void pick_trait(const Trait id);

void pick_bg(const Bg bg);

void set_all_traits_to_picked();

int spi_occultist_can_cast_at_lvl(const int LVL);

bool gets_undead_bane_bon(const Actor_data_t& actor_data);

} //player_bon

#endif
