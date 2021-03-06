#ifndef MAP_HANDLER_H
#define MAP_HANDLER_H

#include <vector>

#include "cmn_data.hpp"
#include "cmn_types.hpp"
#include "colors.hpp"
#include "item_data.hpp"
#include "feature.hpp"
#include "config.hpp"
#include "actor_player.hpp"
#include "fov.hpp"

class Save_handler;
class Rigid;

struct Cell
{
    Cell();
    ~Cell();

    void reset();

    bool                is_explored, is_seen_by_player, is_lit, is_dark;
    Los_result          player_los; //Updated when player updates FOV
    Item*               item;
    Rigid*              rigid;
    Cell_render_data    player_visual_memory;
    P                 pos;
};

enum class Map_type
{
    intro,
    std,
    egypt,
    leng,
    rats_in_the_walls,
    boss,
    trapez
};

namespace map
{

extern Player*              player;
extern int                  dlvl;
extern Cell                 cells[MAP_W][MAP_H];
extern std::vector<Room*>   room_list;              //Owns the rooms
extern Room*                room_map[MAP_W][MAP_H]; //Helper array

extern Clr                  wall_clr;

void init();
void cleanup();

void save();
void load();

void reset_map();

Rigid* put(Rigid* const rigid);

//Makes a copy of the renderers current array
//TODO: This is weird, and it's unclear how it should be used. Remove?
//Can it not be copied in the map drawing function instead?
void cpy_render_array_to_visual_memory();

void mk_blood(const P& origin);
void mk_gore(const P& origin);

void delete_and_remove_room_from_list(Room* const room);

bool is_pos_seen_by_player(const P& p);

} //map

#endif
