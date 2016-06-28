/*
** msdl.h
** by bogard_t
*/

#ifndef		__MSDL_H__
# define	__MSDL_H__

# include	<SDL/SDL.h>

# define	SUCCESS		1
# define	FAILURE		0

typedef struct	s_node
{
  struct s_node	*next;
  struct s_node	*prev;
  SDL_Surface	*surface;
}		t_node;

typedef struct	s_msdl
{
  struct s_node	*first;
  int		nb_node;
}		t_msdl;

typedef t_msdl	*msdl;

#endif		/* __MSDL_H__ */
