# include	"msdl.h"

void		mevent_listener(t_event *this, __attribute__((unused))t_data *data)
{
  if (key == SDLK_UP)
    printf("KEYUP\n");
  else if (key == SDLK_DOWN)
    printf("KEYDOWN\n");
  else if (key == SDLK_LEFT)
    printf("KEYLEFT\n");
  else if (key == SDLK_RIGHT)
    printf("KEYRIGHT\n");
}

void		msdl_loop(t_data	*data,
			  SDL_Surface	*back,
			  SDL_Surface	*screen)
{
  t_event	*this = malloc(sizeof(t_event));

  while ((data->run = msdl_event(this, data, mevent_listener)))
    {
      msdl_blit(back, NULL, screen, NULL);
      msdl_update(screen);
    }
}

int		main()
{
  t_data	data;
  SDL_Surface	*screen;
  SDL_Surface	*back;

  msdl_init_var(&data);
  screen = msdl_init_data("rpg-game", 1200, 800, 32, &data);
  back = msdl_create_back_data(&data);
  msdl_loop(&data, back, screen);
  return (0);
}
