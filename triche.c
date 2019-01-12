#include<stdio.h>                                                                                                                                                                
#include<stdlib.h>
#include<string.h>
#include"graph.h"
#include "triche.h"
#include "menu.h"

void AfficherImages(int tab[],int ligne, int colonne) {

    int i,j,num_case=0;
    char *tab2 = malloc((ligne*colonne)*sizeof(char));
    int decalage_droite=30;
    int decalage_bas=90;
    
    for(i=0 ; i < ligne ; i++) {
        for(j=0 ; j < colonne ; j++) {
            sprintf(tab2,"%d", tab[num_case]); num_case++;
            strcat(tab2, ".png");
            ChargerImage(tab2,decalage_droite,decalage_bas,0,0,taille_carre,taille_carre);
            decalage_droite = decalage_droite+taille_carre+20;
        }
        decalage_droite=30;
        decalage_bas = decalage_bas+taille_carre+20;
    }
}
void ModeTriche(int tab[],char etat[], long int* debut) {
	int i,j,num_case=0;
    int decalage_droite=30;
    int decalage_bas=90;
    long int temps;
    long int temps2;
    couleur c;
    couleur c2;
    couleur c3;
	c = CouleurParComposante(204, 153, 255);
	c2 = CouleurParNom("White");
	c3 = CouleurParNom("Black");

    if(ToucheEnAttente()){
        if (Touche() == XK_t){
            temps = (Microsecondes()-*debut);
            ChoisirCouleurDessin(c3);
            EcrireTexte(120,35,"Activation du Mode Triche",2);
            AfficherImages(tab,nbr_carte_x,nbr_carte_y);
            
            if (Touche() == XK_t) {
            
            ChoisirCouleurDessin(c2);
            RemplirRectangle(120,0,400,50);

            ChoisirCouleurDessin(c);
            
            for(i=0 ; i < nbr_carte_x ; i++) {
                for(j=0 ; j < nbr_carte_y ; j++) {
                    if(etat[num_case] != 'r') {
                        DessinerRectangle(decalage_droite,decalage_bas,taille_carre,taille_carre);
                        RemplirRectangle(decalage_droite,decalage_bas,taille_carre,taille_carre);                    
                    }
                    num_case++;
                    decalage_droite = decalage_droite+taille_carre+20;
                    
                }
                decalage_droite=30;
                decalage_bas = decalage_bas+taille_carre+20;
            }
            while(SourisCliquee()) {
                SourisCliquee();
            }

            temps2 = (Microsecondes()-*debut);
            *debut = *debut + (temps2 - temps);
            }
        }
       
    }
}