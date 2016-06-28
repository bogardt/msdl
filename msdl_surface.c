/*
** msdl_surface.c
** by bogard_t
*/

# include		"msdl.h"

void			sdl_blit(SDL_Surface		*sprite,
				 SDL_Rect		*rect1,
				 SDL_Surface		*level,
				 SDL_Rect		*rect2)
{
  SDL_BlitSurface(sprite, rect1, level, rect2);
}
