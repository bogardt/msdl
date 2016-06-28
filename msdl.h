/*
** msdl.h
** by bogard_t
*/

#ifndef		__MSDL_H__
# define	__MSDL_H__

# include	<SDL/SDL.h>
# include	<SDL/SDL_ttf.h>
# include	<SDL/SDL_image.h>
# include	<stdbool.h>

# define	SUCCESS		1
# define	FAILURE		0
# define	key		this->event.key.keysym.sym

typedef struct	s_node
{
  struct s_node	*next;
  struct s_node	*prev;
  SDL_Surface	*surface;
}		t_node;

typedef struct	s_event
{
  SDL_Event	event;
}		t_event;

typedef struct	s_msdl
{
  struct s_node	*first;
  int		nb_node;
}		t_msdl;

typedef struct	s_data
{
  bool		run;
  bool		isinit;
  int		width;
  int		height;
  int		bpp;
}		t_data;

/*
** msdl_init.c
*/
SDL_Surface			*msdl_init_data(const char * const	Windowname,
						const unsigned int	Width,
						const unsigned int	Height,
						const unsigned int	Bpp,
						t_data			*data);

SDL_Surface			*msdl_init(const char * const		Windowname,
					   const unsigned int		Width,
					   const unsigned int		Height,
					   const unsigned int		Bpp);

SDL_Surface			*msdl_create_back(const unsigned int		Width,
						  const unsigned int		Height,
						  const unsigned int		Bpp);
SDL_Surface			*msdl_create_back_data(t_data		*data);

void				msdl_init_var(t_data			*data);

/*
** msdl_font.c
*/
TTF_Font			*msdl_load_font(const char		*file,
						size_t			size);

void				msdl_write_hexa_color(SDL_Surface	**surface,
						      TTF_Font		*font,
						      const char	*str,
						      const unsigned int hexcode);

void				msdl_write_rgb_color(SDL_Surface	**surface,
						     TTF_Font		*font,
						     const char		*str,
						     const unsigned int	*rgb);

/*
** msdl_screen.c
*/
void				msdl_close(void);

void				msdl_update(SDL_Surface		*screen);

/*
** msdl_sprite_list.c
*/
void				msdl_init_list(t_msdl		*sdl,
					       SDL_Surface	*surface);

void				msdl_add_list(t_msdl		*sdl,
					      SDL_Surface	*surface);

/*
** msdl_surface.c
*/
void				msdl_blit(SDL_Surface		*surface,
					  SDL_Rect		*rect1,
					  SDL_Surface		*level,
					  SDL_Rect		*rect2);

/*
** msdl_event.c
*/
bool				msdl_event(t_event		*this,
					   t_data		*data,
					   void			(*ptr)(t_event *, t_data *));


#endif		/* __MSDL_H__ */
