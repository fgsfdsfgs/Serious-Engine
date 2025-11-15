#include <Engine/Base/PSVita/FakeExports.h>
class CGame;

/* defs */

extern "C" CGame *GAME_Create(void);

/* exports */

#ifdef FIRST_ENCOUNTER
static CFakeLib exp_Game("Game", {
#else
static CFakeLib exp_GameMP("GameMP", {
#endif
  { "GAME_Create", (void*)&GAME_Create }, 
});
