/*
** msdl_event.c
** by bogard_t
*/

# include	"msdl.h"

char		msdl_event(t_event	*this,
			   t_msdl	*msdl,
			   void		(*ptr)(t_event *, t_msdl *))
{
  while (SDL_PollEvent(&this->event))
    if (this->event.type == SDL_QUIT)
      return (0);
    else if (this->event.type == SDL_KEYDOWN)
      {
  	if (key == SDLK_ESCAPE)
	  return (0);
  	else
  	  (*ptr)(this, msdl);
      }
  return (1);
}
