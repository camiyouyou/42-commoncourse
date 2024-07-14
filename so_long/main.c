/** Notes on checks to perform:
 *
 * avoir un main map check.
 * checker structure: qu'il y ait bien des murs, du vide, une sortie, un personnages et des collectibles.
 * vérifier que la map est bien rectangle
 * vérifier que la map est bien entourée par des murs
 * vérifier extension .ber
 * vérifier qu'il n'y a qu'un personnage et qu'une sortie (possible dans la meme fonction ou on compte les collectibles).
 * mettre en place systeme d'écriture d'erreur avec perror ou avec ft_printf;
 * */

/** Notes on additional verifications
 * au début du jeu, il faut localiser les différents éléments, donc mettre la position des différents éléments dans 
 * une structure
 * le cas échéant, lorsque qu'un collectible a été ramassé, il faut le remplacer par une case vide (0);
 *
 *
 * FILL ALGO DE MAX POUR VERIFIER QUE LA SORTIE PEUT ETRE ATTEINTE:
 *
 * si emplacement == 1 , return
 * si emplacement == OK, return (déjà regardé);
 * si empalcement == C, on ajoute au compteur de collectibles et on regarde autour de soi, employer la recursivité
 *
 * SINON cas 0,
 *
 * on regarde aussi si a (x+1, y); (x-1,y); (x, y+1); (x, y-1) il y a un passage.
 *
 * fonction void.
 *
 * verif sortie= vérifier que compteur soit bien égal à compteur de collectible.
 *
 * main algo: 
 * fonction localiser p, fonction pour localiser e (les fonctions storent dans une structure)
 *
 * initialisation du compteur de collectibles à 0
 *
 * utilisation de l'algo de check
 * on initialise x à 0
 *
 * si la vérifcation de sortie fonctionne, return 0, sinon return 1.
* PROCEDE POUR AVANCER: 
* COMMENCER PAR FAIRE WINDOW AVEC MAPPING DES ELEMENTS. VOIR SI CEUX CI APPARAISSENT
* PUIS MOUVEMENTS
* PUIS DISPARITION DE PIECE SI AVALEE 
* PUIS SORTIE
* PUIS CHECKS **/

int  check_rectangle(char **map, int i, int j, int x)
{
  x = ft_strlen(map[0]);
  i = 0;
  while (map[i][j])
  {
      j = 0;
      while(map[i])
      {
        j++;
      }
      if(j == x)
        i++;
      else
        return (1);
  }
}

int get_cols(char **map)
{
	int	i;
	int	j;
  i = 0;
  while (map[i][j])
  {
    j = 0;
    while (map[i])
      j++;
    i++;
  }
  return(i);
}

int  check_walls(char **map, int i, int j)
{
  int x;
  int y;
  i = 0;
  x = ft_strlen(map[0]);
  y = get_cols(map);

  while (map[0][i])
  {
    if (map[0][i] != '1')
      return (1)
    i++;
  }
  i = 0;
  while (j < y)
  {
    if (map[j][0] != '1' || map[j][x] != '1')
      return (1);
    j++;
  }
  j = j - 1;
   while (map[0][i])
  {
    if (map[j][i] != '1')
      return (1)
    i++;
  }
  return (0);
}

int	check_struct(char **map, int i, int j)
{
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == '0' ||
			map[i][j] == 'E' || map[i][j] == 'P' ||
			map[i][j] == 'C')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}


int  check_exit(char **map, t_long *game, int x, int y)
{
  if (game->count == game->count_c)
  {
    if (map [x][y] = 'K')
      return 0;
    return 1;
  }
  return 0;
}

int  check_extension(char *name, int i)
{
  i = 0;
  while (name[i])
  {
    if (name[i] == '.')
    {
      if (name[i++] == 'b')
      {
        if (name[i++] == 'e')
        {
          if (name[i++] == 'r')
            return (0);
          return (1);
        }
        return (1);
      }
      return (1);
    }
    i++;
  }
  return (1);
}

void  check_pos_e(char **map, t_long *game)
{
  int  x;
  int  y;
  x = 0;
  while (map[x])
  {
    y = 0;
    while (map[x][y])
    {
      if (map[x][y] == 'E')
      {
        game->pos_e_x = x;
        game->pos_e_y = y;
      }
      y++;
    }
    x++;
  }
}

void  check_pos_p(char **map, t_long *game)
{
  int  x;
  int  y;
  x = 0;
  while (map[x])
  {
    y = 0;
    while (map[x][y])
    {
      if (map[x][y] == 'P')
      {
        game->pos_p_x = x;
        game->pos_p_y = y;
      }
      y++;
    }
    x++;
  }
}



