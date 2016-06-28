# include	"msdl.h"

int		main()
{
  t_data	*data = msdl_init_var();
  SDL_Surface	*screen = msdl_init_data("rpg-game", 1200, 800, 32, data);
  SDL_Surface	*back = msdl_create_back(1200, 800, 32);
  while (data->run)
    ;
  return (0);
}
