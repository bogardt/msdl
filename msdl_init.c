/*
** msdl_init.c
** by bogard_t
*/

# include		<stdlib.h>
# include		<stdio.h>
# include		"msdl.h"

SDL_Surface		*msdl_init(const char * const	Windowname,
				   const unsigned int	Width,
				   const unsigned int	Height,
				   const unsigned int	Bpp)
{
  SDL_Surface		*screen;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "->msdl init failure\n");
      return (NULL);
    }
  SDL_WM_SetCaption(Windowname, NULL);
  if (!(screen =
	SDL_SetVideoMode(Width, Height, Bpp, SDL_DOUBLEBUF | SDL_HWSURFACE)))
    {
      fprintf(stderr, "->msdl init screen failure\n");
      return (NULL);
    }
  return (screen);
}

SDL_Surface		*msdl_init_data(const char * const	Windowname,
					const unsigned int	Width,
					const unsigned int	Height,
					const unsigned int	Bpp,
					t_data *data)
{
  SDL_Surface		*screen;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "->msdl init failure\n");
      return (NULL);
    }
  SDL_WM_SetCaption(Windowname, NULL);
  if (!(screen =
	SDL_SetVideoMode(Width, Height, Bpp, SDL_DOUBLEBUF | SDL_HWSURFACE)))
    {
      fprintf(stderr, "->msdl init screen failure\n");
      return (NULL);
    }
  data->run = 1;
  data->isinit = 1;
  return (screen);
}

SDL_Surface		*msdl_create_back(const unsigned int Width,
					  const unsigned int Height,
					  const unsigned int Bpp)
{
  SDL_Surface		*back;

  if (!(back =
	SDL_AllocSurface(SDL_HWSURFACE, Width, Height, Bpp, 0, 0, 0, 0)))
    {
      fprintf(stderr, "->msdl alloc background failure\n");
      return (NULL);
    }
  return (back);
}

t_data			*msdl_init_var(void)
{
  t_data		*data;

  if (!(data = malloc(sizeof(*data))))
    {
      fprintf(stderr, "->msdl init var malloc failure\n");
      return (NULL);
    }
  data->isinit = 0;
  data->run = 0;
  return (data);
}
