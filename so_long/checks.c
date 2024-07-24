#include "so_long.h"

int  check_map_main(char **map, t_long *check)
{
  check->c = 0;
  check->p = 0;
  check->e = 0;
  if (check_struct(map, 0, 0))
    return (ft_printf("Error\n probleme de structure\n"));
  if (check_rectangle(map, 0, 0, ft_strlen(map[0])))
    return (ft_printf("Error\n map is not rectangle\n"));
  if (check_walls(map, 0, 0))
    return (ft_printf("Error\n map is not surrounded by walls\n"));
  if (check_components(map, 0, 0, check) == 1)
    return (ft_printf("Error\n number of component error\n"));
  ft_printf("No error in map\n");
  return (0);
}
