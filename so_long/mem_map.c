#include "so_long.h"

int mem_line(char **map) {
    int i = 0;
    while (map[i]) {
        i++;
    }
    return i;
}

// Fonction pour calculer le nombre de colonnes dans la carte
int mem_colonne(char **map) {
    int j = 0;
    while (map[0][j] && map[0][j] != '\n') {
        j++;
    }
    return j;
}

// Fonction pour copier la carte
char **copy_map(char **map) {
    printf("copying map\n");
    char **copy;
    int i = 0, j = 0;
    int mem = mem_line(map);
   // int mem_word = mem_colonne(map);

    copy = (char **)malloc((mem + 1) * sizeof(char *));
    if (!copy) {
        printf("Memory allocation error for map copy\n");
        return NULL;
    }

    while (i < mem) {
        int len = 0;
        while (map[i][len] && map[i][len] != '\n') {
            len++;
        }

        copy[i] = (char *)malloc((len + 1) * sizeof(char));
        if (!copy[i]) {
            printf("Memory allocation error for map row\n");
            while (i-- > 0) {
                free(copy[i]);
            }
            free(copy);
            return NULL;
        }

        for (j = 0; j < len; j++) {
            copy[i][j] = map[i][j];
        }
        copy[i][j] = '\0';
        i++;
    }
    copy[i] = NULL;
    printf("copy map done\n");
    return copy;
}

/* int	mem_colonne(char **map, int mem, int mem_ligne)
{
	while (map[mem])
	{
		mem_ligne = 0;
		while (map[mem][mem_ligne])
			mem_ligne++;
		mem++;
	}
	return (mem);
}

int	mem_line(char **map, int mem, int mem_ligne)
{
	while (map[mem])
	{
		mem_ligne = 0;
		while(map[mem][mem_ligne])
			mem_ligne++;
		mem++;
	}
	return (mem_ligne);
}

char	**copy_map(char **map, int mem, int mem_word)
{
  ft_printf("copying map");
	char	**copy;
	int	i;
	int	j;

	mem = mem_line(map, mem, mem_word);
	mem_word = mem_colonne(map, mem, mem_word);
	copy = (char **)malloc((mem + 1) * sizeof(char *));
	if (!copy)
	{
		ft_printf("memory allocation fail for mapy copy \n")
		return (NULL);
	}
	i = 0;i
	while (i < mem)
	{
		copy[i] = (char *)malloc((mem_word + 1) * sizeof(char));
		if (!copy[i])
		{
		  while (i > 0)
		  {
		    i--;
		    free(copy[i]);
		  }
		  free(copy);
		  return (NULL);
		}
		j = 0;
		while (j < mem_word)
		{
			copy[i][j] = map[i][j];
			j++;
		}
		copy[i][j] = '\0';
		i++;
	}
	copy[i] = NULL;
	ft_printf("copied map\n");
	return (copy);
} */
