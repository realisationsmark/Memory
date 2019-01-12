#include<stdio.h>                                                                                                                                                                
#include<stdlib.h>
#include<string.h>
#include"graph.h"
#include<time.h>
#include"menu.h"
#include"triche.h"
#include"affichage.h"


int nbr_carte_x;    /*nombre representant le format de la grille */
int nbr_carte_y;    /*nombre representant le format de la grille */

int main(void)
{

    int *tab = malloc((6*6)*sizeof(int));
    char *etat = malloc((6*6)*sizeof(char));
    long int debut ;

    InitialiserGraphique();
    CreerFenetre(500,200,500,500);
    menu();
    debut = Microsecondes();
    MelangerImages(tab, nbr_carte_x, nbr_carte_y);

    while(1) {

        Cliquer(tab,etat,nbr_carte_x,nbr_carte_y, debut);
        ModeTriche(tab,etat,&debut);
        Chrono(debut);
        if (VerificationEtat(tab, etat)==1) {
			menu();
	        precedent=-1;
	        debut = Microsecondes();
	        MelangerImages(tab, nbr_carte_x, nbr_carte_y);
        }
    }
            
   Touche();
   FermerGraphique();
            
    return EXIT_SUCCESS;
}
