#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#define taille_carre 70

long int precedent;
void GrilleRemplie(int ligne, int colonne);
/*Remplis juste les carrés */
void MelangerImages(int* tab, int ligne, int colonne);
/* on range aleatoirement les valeurs de 0 à ligne*colonne dans un tableau*/
void Cliquer(int* tab,char* etat, int ligne, int colonne, long int debut);
/*Cette fonction est la fonction "principale" du jeu
Elle permet d'exclure quelques cas pour le bon fonctionnement du jeu
 */
void RemplirRectangleAnimation(int x, int y, int b);
long int Chrono(long int debut);

#endif
