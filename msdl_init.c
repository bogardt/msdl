/*
** msdl_init.c
** by bogard_t
*/

# include	"msdl.h"

SDL_Surface		*msdl_create_back(void)
{
  SDL_Surface		*back;

  if (!(back =
	SDL_AllocSurface(SDL_HWSURFACE, Width, Height, bpp, 0, 0, 0, 0)))
    {
      fprintf(stderr, "->msdl alloc background failure\n");
      return (NULL);
    }
  return (back);
}

SDL_Surface		*msdl_init(const char * const	windowname)
{
  SDL_Surface		*screen;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "->msdl init failure\n");
      return (NULL);
    }
  SDL_WM_SetCaption(windowname, NULL);
  if (!(screen =
	SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_DOUBLEBUF | SDL_HWSURFACE)))
    {
      fprintf(stderr, "->msdl init screen failure\n");
      return (NULL);
    }
  return (screen);
}
