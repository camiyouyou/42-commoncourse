int  check_map_main(char **map, t_long *check)
{
  check->c = 0;
  check->p = 0;
  check->e = 0;
  if (check_struct(map, 0, 0))
    return (ft_printf("Error\n probleme de structure\n"));
  if (check_rectangle(map, 0, 0))
    return (ft_printf("Error\n map is not rectangle\n"));
  if (check_wall(map, 0, 0))
    return (ft_printf("Error\n map is not surrounded by walls\n"));
  if (check_component(map, 0, 0, check) == 1)
    return (ft_printf("Error\n number of component error\n"));
  return (0);
}