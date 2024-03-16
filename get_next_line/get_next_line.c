/* Mes idées pour le projet
 
 utiliser les listes
 
 dans ces listes:
 
 lstnew pour le premier element
 lst add back pour les lignes suivantes
 lst clear s il y a une erreur
 
 réadapter split pour partitionner le texte avec chaque \n et au lieu de passer la substr vers un array, passer vers une liste
 
 les fonctions à réadapter de libft seront donc:
 - split
 - substr
 - strdup
 - strlen
 - strlcpy
 + les listes;
 
 flow du projet:
 - lire le fichier et compter le nombre de lignes et leur longueur;
 - splitter le fichier en differentes lignes
 - chaque ligne devient une entree de la liste chainee
 - cette liste doit être stockée
 - chaque fois qu'on appelle le programme, le programme lit et renvoie la ligne d'après (utilisant une fonction liste qui renvoie next dans la liste chainee).
 
 */
typedef struct s_list
{
    void            *content;
    struct s_list    *next;
}                    t_list;

void    read_and_stock()
{
    
}

void    add_to_stash()
{
    
}

void    extract_line()
{
    
}

void    free_stash()
{
    
}

int     get_line_length(*line)
{
    while (read(fd, &line, 0) != "\n")
    {
        content[i++] = line [j++];
    }
}

/* 

 A modifier sans del; faire en sorte que chaque node = NULL
void    ft_lstdelone(t_list *lst, void (del)(void*))
{
    if (lst == NULL || del == NULL)
        return ;
    del (lst->content);
    free (lst);
}

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list    *tmp;

    if (lst == NULL || del == NULL || *lst == NULL)
        return ;
    while (*lst && lst)
    {
        tmp = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = tmp;
    }
} */

char *get_next_line(int fd)
{
    char    *next_line;
    
    read(fd, &next_line, 0);
}

int main ()
{
    
}
