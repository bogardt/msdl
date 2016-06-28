/*
** msdl_rect.c
** by bogard_t
*/

# include	"msdl.h"

void		msdl_rect(SDL_Rect		*rect,
			  const int		x,
			  const int		y,
			  const int		w,
			  const int		h)
{
  rect->x = x;
  rect->y = y;
  rect->w = w;
  rect->h = h;
}
