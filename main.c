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

  msdl_add_list(msdl, "google.png");
  msdl_add_list(msdl, "google.png");
  msdl_add_list(msdl, "google.png");
  msdl_add_list(msdl, "google.png");
  while ((msdl->run = msdl_event(this, msdl, mevent_listener)))
    {
      // background
      msdl_blit(back, NULL, screen, NULL);

      // font
      font->load_font = msdl_load_font("test-font.ttf", 100);
      msdl_rect(&font->rect, 400, 400, 0, 0);
      msdl_write_hexa_color(&font->blit_font, font->load_font, "42", 0xffffff);
      msdl_blit(font->blit_font, NULL, screen, &font->rect);

      // sprites
      for (t_node *tmp = msdl->first; tmp->next; tmp = tmp->next)
      {
        msdl_rect(&tmp->rect, 400, 400, 0, 0);
        msdl_blit(tmp->surface, NULL, screen, &tmp->rect);
      }

      // update screen
      msdl_update(screen);
    }

  SDL_FreeSurface(screen);
  SDL_FreeSurface(back);
  SDL_FreeSurface(font->blit_font);
}

int		main(__attribute__((unused))int ac,
           __attribute__((unused)) const char *av[])
{
  t_msdl	msdl;
  SDL_Surface	*screen;
  SDL_Surface	*back;

  msdl_init_var(&msdl);
  screen = msdl_init_data("rpg-game", 1200, 800, 32, &msdl);
  back = msdl_create_back_data(&msdl);
  msdl_loop(&msdl, back, screen);
  msdl_close();
  return (0);
}
