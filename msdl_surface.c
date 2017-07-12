/*
** msdl_surface.c
** by bogard_t
*/

#include "msdl.h"

void msdl_blit(SDL_Surface *surface,
	       SDL_Rect *rect1,
	       SDL_Surface *level,
	       SDL_Rect *rect2)
{
  SDL_BlitSurface(surface, rect1, level, rect2);
}

SDL_Surface *msdl_copy_surface(SDL_Surface *toCopy)
{
  SDL_Surface *cpy;
  if ((cpy = SDL_CreateRGBSurface(SDL_HWSURFACE, toCopy->w, toCopy->h, toCopy->format->BitsPerPixel,
		toCopy->format->Rmask, toCopy->format->Gmask, toCopy->format->Bmask, toCopy->format->Amask)) == NULL || toCopy == NULL)
    return NULL;
  cpy = SDL_DisplayFormatAlpha(toCopy);
  return cpy;
}