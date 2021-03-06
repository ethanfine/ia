#ifndef PLAYER_SPELLS_HANDLING_H
#define PLAYER_SPELLS_HANDLING_H

#include <vector>

#include "spells.hpp"

class Spell;

namespace player_spells_handling
{

void init();
void cleanup();

void save();
void load();

void player_select_spell_to_cast();

void learn_spell_if_not_known(Spell* const spell);
void learn_spell_if_not_known(const Spell_id id);

bool is_spell_learned(const Spell_id id);

} //player_spells_handling

#endif
