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
#include "so_long.h"

int check_rectangle(char **map, int start_row, int start_col) {
    unsigned long expected_length = ft_strlen(map[start_row]);
    int i = start_row;
    unsigned long j = start_col;

    printf("Checking rectangle\n");

    while (map[i] != NULL) {
        while (map[i][j] != '\0') {
            j++;
        }
        if (j - start_col != expected_length) {
            return 1; // Les longueurs ne correspondent pas
        }
        j = start_col;
        i++;
    }
    return (0); // Toutes les lignes ont la même longueur
}

int get_cols(char **map)
{
    int i = 0;
    int cols = 0;
    int current_cols;

    while (map[i])
    {
        current_cols = ft_strlen(map[i]);
        if (current_cols > cols) // Garder la plus grande longueur
            cols = current_cols;
        i++;
    }
    return (i);
}


int check_walls(char **map, int i, int j)
{
    ft_printf("checking walls\n");
    i = 0;
    j = 0;
    int x = ft_strlen(map[0]);
    int y = get_cols(map);

    // Vérification du mur supérieur
    while (i < x)
    {
        if (map[0][i] != '1')
            return 1;
        i++;
    }
    
    j = 0; 
    while (j < y)
    {
        if (map[j][0] != '1' || map[j][x - 1] != '1') // Utiliser x - 1
            return (1);
        j++;
    }

    // Vérification du mur inférieur
    i = 0; // Réinitialiser i pour la vérification du mur inférieur
    while (i < x)
    {
        if (map[y - 1][i] != '1') // Utiliser y - 1
            return 1;
        i++;
    }

    return 0; // Tout va bien
}

int	check_struct(char **map, int i, int j)
{
    ft_printf("checking structure\n");
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
  ft_printf("checking exit\n");
  if (game->c == game->count_c)
  {
    if (map[y][x] == 'K')
    {
      ft_printf("no error, exit ok\n");
      return (0);
    }
    else
    {
      ft_printf("error, exit not ok\n");
      return (1);
    }
  }
  else
    return (0);
}

int  check_extension(char *name, int i)
{
  ft_printf("checking extension\n");
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
  int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
			{
				game->pos_e_y = y;
				ft_printf("ordonnee E: %d\n", y);
				game->pos_e_x = x;
				ft_printf("abcisse E: %d\n", x);
			}
			x++;
		}
		y++;
	}
} 

void  check_pos_p(char **map, t_long *game)
{
  int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->y = y;
				ft_printf("ordonnee P: %d\n", y);
				game->x = x;
                                ft_printf("abcisse P: %d\n", x);
			}
			x++;
		}
		y++;
	}
}



