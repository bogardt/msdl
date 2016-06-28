# include	"msdl.h"

static void	mevent_listener(t_event *this,
				__attribute__((unused))t_msdl *msdl)
{
  if (key == SDLK_UP)
    printf("KEY UP\n");
  else if (key == SDLK_DOWN)
    printf("KEY DOWN\n");
  else if (key == SDLK_LEFT)
    printf("KEY LEFT\n");
  else if (key == SDLK_RIGHT)
    printf("KEY RIGHT\n");
}

static void	msdl_loop(t_msdl	*msdl,
			  SDL_Surface	*back,
			  SDL_Surface	*screen)
{
  t_event	*this = malloc(sizeof(t_event));
  t_font	*font = malloc(sizeof(t_font));;

  while ((msdl->run = msdl_event(this, msdl, mevent_listener)))
    {
      msdl_blit(back, NULL, screen, NULL);

      msdl_rect(&font->rect, 10, 10, 0, 0);
      font->load_font = msdl_load_font("Mario.ttf", 200);
      msdl_write_hexa_color(&font->blit_font, font->load_font, "TEST", 0xffffff);
      msdl_blit(font->blit_font, NULL, screen, &font->rect);

      msdl_update(screen);
    }
}

int		main()
{
  t_msdl	msdl;
  SDL_Surface	*screen;
  SDL_Surface	*back;

  msdl_init_var(&msdl);
  screen = msdl_init_msdl("rpg-game", 1200, 800, 32, &msdl);
  back = msdl_create_back_msdl(&msdl);
  msdl_loop(&msdl, back, screen);
  msdl_close();
  return (0);
}
