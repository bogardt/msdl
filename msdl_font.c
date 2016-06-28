/*
** msdl_font.c
** by bogard_t
*/

# include		<stdlib.h>
# include		"msdl.h"
# include		"mconverter.h"

TTF_Font		*msdl_load_font(const char		*file,
					size_t			size)
{
  TTF_Font		*font;

  if (!(font = TTF_OpenFont(file, size)))
    {
      fprintf(stderr, "->msdl font failure %s is not a good path\n", file);
      return (NULL);
    }
  return (font);
}

void			msdl_write_hexa_color(SDL_Surface	**surface,
					      TTF_Font		*font,
					      const char	*str,
					      const unsigned int hexcode)
{
  SDL_Color		colorized_text;
  unsigned int		*rgb;

  rgb = hex_to_rgb(hexcode);
  colorized_text.r = rgb[0];
  colorized_text.g = rgb[1];
  colorized_text.b = rgb[2];
  SDL_FreeSurface(*surface);
  *surface = TTF_RenderText_Solid(font, str, colorized_text);
  TTF_CloseFont(font);
}

void			msdl_write_rgb_color(SDL_Surface	**surface,
					     TTF_Font		*font,
					     const char		*str,
					     const unsigned int	*rgb)
{
  SDL_Color		colorized_text;

  colorized_text.r = rgb[0];
  colorized_text.g = rgb[1];
  colorized_text.b = rgb[2];
  SDL_FreeSurface(*surface);
  *surface = TTF_RenderText_Solid(font, str, colorized_text);
  TTF_CloseFont(font);
}
