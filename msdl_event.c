/*
** msdl_event.c
** by bogard_t
*/

# include	"msdl.h"

void		msdl_event(t_event *this, t_data *data, void (*ptr)(t_event *))
{
  while (SDL_PollEvent(&this->event))
    if (this->event.type == SDL_QUIT)
      data->run = 0;
    else if (this->event.type == SDL_KEYDOWN)
      {
	if (key == SDLK_ESCAPE)
	  data->run = 0;
	else
	  (*ptr)(this);
      }
}
