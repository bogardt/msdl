/*
** msdl_screen.c
** by bogard_t
*/

#include	"msdl.h"

void		msdl_close(void)
{
  SDL_Quit();
}

void		msdl_update(SDL_Surface *screen)
{
  SDL_Flip(screen);
}
