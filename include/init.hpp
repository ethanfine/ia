#ifndef INIT_H
#define INIT_H

#include "debug_mode.hpp"

#include <cassert>
#include <iostream>

//-----------------------------------------------------------------------------
// OPTIONS
//-----------------------------------------------------------------------------
//Lvl of TRACE output in debug mode
// 0 : Disabled
// 1 : Standard
// 2 : Verbose
#define TRACE_LVL 1

//Enable rendering and delays during map gen for evaluation/demo purposes
//Comment out to disable, uncomment to enable
//#define DEMO_MODE 1
//-----------------------------------------------------------------------------

#ifdef NDEBUG

#define TRACE                     if (1) ; else std::cerr
#define TRACE_FUNC_BEGIN          if (1) ; else std::cerr
#define TRACE_FUNC_END            if (1) ; else std::cerr
#define TRACE_VERBOSE             if (1) ; else std::cerr
#define TRACE_FUNC_BEGIN_VERBOSE  if (1) ; else std::cerr
#define TRACE_FUNC_END_VERBOSE    if (1) ; else std::cerr

#else //NDEBUG not defined

#define TRACE if (TRACE_LVL < 1) ; else std::cerr \
  << std::endl \
  << "T:" << to_str(game_time::turn()) << " " \
  << __FILE__ << ", " \
  << __LINE__ << ", " \
  << __func__ << "():" << std::endl

#define TRACE_FUNC_BEGIN if (TRACE_LVL < 1) ; else std::cerr \
  << std::endl \
  << "T:" << to_str(game_time::turn()) << " " \
  << __FILE__ << ", " \
  << __LINE__ << ", " \
  << __func__ << "()..." << std::endl

#define TRACE_FUNC_END if (TRACE_LVL < 1) ; else std::cerr \
  << std::endl \
  << "T:" << to_str(game_time::turn()) << " " \
  << __FILE__ << ", " \
  << __LINE__ << ", " \
  << __func__ << "() [DONE]" << std::endl

#define TRACE_VERBOSE             if (TRACE_LVL < 2) ; else TRACE
#define TRACE_FUNC_BEGIN_VERBOSE  if (TRACE_LVL < 2) ; else TRACE_FUNC_BEGIN
#define TRACE_FUNC_END_VERBOSE    if (TRACE_LVL < 2) ; else TRACE_FUNC_END

#endif //NDEBUG

namespace init
{

extern bool is_cheat_vision_enabled;
extern bool quit_to_main_menu;

void init_io();
void cleanup_io();

void init_game();
void cleanup_game();

void init_session();
void cleanup_session();

} //Init

#endif
