/*
** mconverter.c
** by bogard_t
*/

unsigned int		*hex_to_rgb(const unsigned int	hexcode)
{
  unsigned int		*rgb;

  if (!(rgb = malloc(sizeof(unsigned int) * 3)))
    return (NULL);
  rgb[0] = (hexcolor >> 16) & 0xFF;;
  rgb[1] = (hexcolor >> 8) & 0xFF;;
  rgb[2] = (hexcolor & 0xFF);
  return (rgb);
}

const unsigned int	rgb_to_hexa(const unsigned int	r,
				    const unsigned int	g,
				    const unsigned int	b)
{
  return ((r << 16) + (g << 8) + b);
}
