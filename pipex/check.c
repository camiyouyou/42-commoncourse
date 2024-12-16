size_t ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return (i);
}

void    error(void)
{
    write(1, "Error\n", 6);
    exit(1);
}

// check fd
//verifier que le fd ne renvoie pas d'erreur (>=0)
//check commande

int check_cmd(char **envp, char **argv, int index)
{
    //regarder dans les variables d'environnement si la commande y est
    //pour ce faire, chercher dans les differents path
    //split path (enlever les :)
    //localiser le bon chemin vers la commande 
    // si pas de path, return 1
    //index++; index sert a regarder les 4 commandes
    
}