/*
** msdl_surface.c
** by bogard_t
*/

# include		"msdl.h"

void			msdl_blit(SDL_Surface		*surface,
				  SDL_Rect		*rect1,
				  SDL_Surface		*level,
				  SDL_Rect		*rect2)
{
  SDL_BlitSurface(surface, rect1, level, rect2);
}
