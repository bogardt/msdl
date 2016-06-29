/*
** msdl_map.c
** by bogard_t
*/

#include	"msdl.h"

static int	alpha_num(char c)
{
  if (c == '\0')
    return (2);
  else if ((c >= 'A' && c <= 'Z') ||
	   (c >= 'a' && c <= 'z') ||
	   (c >= '0' && c <= '9'))
    return (0);
  else
    return (1);
}

static int	check_words(const char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (alpha_num(str[i]) == 0)
        {
          count++;
	  while (alpha_num(str[i]) == 0)
	    i++;
        }
      if (str[i] != '\0')
        i++;
    }
  return (count);
}

static char	**alloc_by_tab(const char *str)
{
  char		**tab;
  int		i;
  int		size;

  if (!str)
    return (NULL);
  size = check_words(str);
  i = 0;
  if (!(tab = malloc(sizeof(char *) * (size + 1))))
    return (NULL);
  while (i < size)
    {
      if (!(tab[i] = malloc(strlen(str) + 1)))
	return (NULL);
      tab[i][strlen(str)] = '\0';
      i++;
    }
  tab[size] = NULL;
  return (tab);
}

char		**msdl_map(const char *str)
{
  int		i;
  int		j;
  int		k;
  char		**tab;

  i = 0;
  j = 0;
  if (!str || !(tab = alloc_by_tab(str)))
    return (NULL);
  while (str[i])
    {
      k = 0;
      while (alpha_num(str[i]) == 1)
        i++;
      while (alpha_num(str[i]) == 0 && str[i])
	tab[j][k++] = str[i++];
      if (tab[j])
        tab[j][k] = 0;
      j++;
    }
  return (tab);
}
