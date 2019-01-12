#ifndef MENU_H
#define MENU_H
#define taille_carre 70

int nbr_carte_x;    /*nombre representant le format de la grille */
int nbr_carte_y;    /*nombre representant le format de la grille */
void menu();
/*menu principal*/
void Jouer(); 
/*Bouton Jouer avec le bouton qui s'allume lorsque la souris passe dessus*/
void Animation(); 
/*sert a allumer les boutons lorsque la souris passe dessus*/
void Recommencer(); 
/*Bouton Jouer avec le bouton qui s'allume lorsque la souris passe dessus*/
int	 VerificationEtat(int* tab, char* etat); 
/* verifie si toute les cartes pour affcher le bouton recommencer */

#endif
