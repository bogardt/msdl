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
      fprintf(stderr, "->msdl init error\n");
      return (NULL);
    }
  SDL_WM_SetCaption(Windowname, NULL);
  if (!(screen =
	SDL_SetVideoMode(Width, Height, Bpp, SDL_DOUBLEBUF | SDL_HWSURFACE)))
    {
      fprintf(stderr, "->msdl init screen error\n");
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
      fprintf(stderr, "->msdl init error\n");
      return (NULL);
    }
  SDL_WM_SetCaption(Windowname, NULL);
  if (!(screen =
	SDL_SetVideoMode(Width, Height, Bpp, SDL_DOUBLEBUF | SDL_HWSURFACE)))
    {
      fprintf(stderr, "->msdl init screen error\n");
      return (NULL);
    }
  data->run = true;
  data->isinit = true;
  data->width = Width;
  data->height = Height;
  data->bpp = Bpp;
  return (screen);
}

SDL_Surface		*msdl_create_back_data(t_data *data)
{
  SDL_Surface		*back;

  if (!(back =
	SDL_AllocSurface(SDL_HWSURFACE, data->width, data->height, data->bpp, 0, 0, 0, 0)))
    {
      fprintf(stderr, "->msdl alloc background error\n");
      return (NULL);
    }
  return (back);
}

SDL_Surface		*msdl_create_back(const unsigned int Width,
					  const unsigned int Height,
					  const unsigned int Bpp)
{
  SDL_Surface		*back;

  if (!(back =
	SDL_AllocSurface(SDL_HWSURFACE, Width, Height, Bpp, 0, 0, 0, 0)))
    {
      fprintf(stderr, "->msdl alloc background error\n");
      return (NULL);
    }
  return (back);
}

void			msdl_init_var(t_data *data)
{
  data->isinit = false;
  data->run = false;
}
