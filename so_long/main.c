/** Notes on checks to perform:
 *
 * avoir un main map check.
 * checker structure: qu'il y ait bien des murs, du vide, une sortie, un personnages et des collectibles.
 * vérifier que la map est bien rectangle
 * vérifier que la map est bien entourée par des murs
 * vérifier extension
 * vérifier qu'il n'y a qu'un personnage et qu'une sortie (possible dans la meme fonction ou on compte les collectibles.
 * mettre en place systeme d'écriture d'erreur avec perror ou avec ft_printf;
 *
 *
 * */

/** Notes on additional verifications
 * au début du jeu, il faut localiser les différents éléments, donc mettre la position des différents éléments dqns 
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

