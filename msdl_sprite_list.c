/*
** msdl_sprite_list.c
** by bogard_t
*/

# include	"msdl.h"

/* void		msdl_init_list(t_msdl		*sdl, */
/* 			       SDL_Surface	*surface) */
/* { */
/*   t_node	*new; */

/*   new = malloc(sizeof(*new)); */
/*   new->surface = malloc(sizeof(SDL_Surface)); */
/*   new->next = NULL; */
/*   new->prev = NULL; */
/*   sdl->first = new; */
/*   sdl->nb_node++; */
/* } */

/* void		msdl_add_list(t_msdl		*sdl, */
/* 			      SDL_Surface	*surface) */
/* { */
/*   t_node	*new; */
/*   t_node	*current; */

/*   if (sdl->nb_node == 0) */
/*     msdl_init_list(sdl, surface); */
/*   else */
/*     { */
/*       new = malloc(sizeof(*new)); */
/*       new->surface = malloc(sizeof(SDL_Surface)); */
/*       current = current->first; */
/*       while (current->next) */
/* 	current = current->next; */
/*       new->next = NULL; */
/*       new->prev = current; */
/*       current->next = new; */
/*       sdl->nb_node++; */
/*    } */
/* } */
