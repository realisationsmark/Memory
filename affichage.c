#include<stdio.h>                                                                                                                                                                
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"menu.h"
#include"graph.h"
#include"affichage.h"


void GrilleRemplie(int ligne,int colonne) {  /*lignemax = 4 colonnemax = 4 : pas assez d'image*/
           
    int i,j;
    int decalage_droite=30;
    int decalage_bas=90;
    couleur c = CouleurParComposante(204, 153, 255);
    ChoisirCouleurDessin(c);
    
        for(i=0 ; i < ligne ; i++) {
            for(j=0 ; j < colonne ; j++) {
                DessinerRectangle(decalage_droite,decalage_bas,taille_carre,taille_carre);
                RemplirRectangle(decalage_droite,decalage_bas,taille_carre,taille_carre);
                decalage_droite = decalage_droite+taille_carre+20;
            }
            decalage_droite=30;
            decalage_bas = decalage_bas+taille_carre+20;
        }
}

int i,j,nb_alea;

void MelangerImages(int* tab ,int ligne, int colonne) {

    srand(time(NULL));

    for(i=0;i<(ligne*colonne);i++) {
        nb_alea=rand()%(ligne*colonne);
        tab[i] = nb_alea;
        for(j=0;j<i;j++) {
            if((tab[i] == tab[j]) && (i!=j)){
                i--;
            }
        }
    }
    for(i=0;i<(ligne*colonne);i++) {
        tab[i]=tab[i]%((ligne*colonne)/2);
    }
}


int e=-1; /*variable pour savoir si c'est le premier clique ou pas : quand e=-1, on attend le premier clic*/
int num_case=0;
int decalage_droite_tmp,decalage_bas_tmp,num_case_tmp=-1; /*on initialise */
long int temps;

void Cliquer(int* tab,char* etat,int ligne, int colonne, long int debut) {
    int i,j;
    /*char tab2[ligne*colonne+1]; malloc*/
    char *tab2 = malloc(2*sizeof(char));
    
    int decalage_droite=30;
    int decalage_bas=90;
    

   if(SourisCliquee()){

        for(i=0 ; i < ligne ; i++) {
            for(j=0 ; j < colonne ; j++) {
                sprintf(tab2,"%d", tab[num_case]);
                strcat(tab2, ".png");                
                if((_X >= decalage_droite)&&(_X <= decalage_droite + taille_carre)&&(_Y >= decalage_bas)&&(_Y <= decalage_bas + taille_carre)) {
                    ChargerImage(tab2,decalage_droite,decalage_bas,0,0,taille_carre,taille_carre);
                    
                    if(etat[num_case]=='r') {
                    	break; /*On ne peut pas appuyer sur une image déjà retourné*/
                    }

                    if(e==-1){
                        e= tab[num_case];
                        /*On enregistre les coordonées de la case correspondant au premier clic*/
                        decalage_droite_tmp = decalage_droite;
                        decalage_bas_tmp = decalage_bas;
                        etat[num_case] = 'r'; /* on re initialise e pour attendre le premier clic*/
                        num_case_tmp = num_case;
                    }

                    else if(tab[num_case]==e){
                        
                        etat[num_case] = 'r'; /*r comme retourné*/
                        
                        if(num_case_tmp == num_case) {
                        	break;
                        }
                        
                        e=-1; /*on re initialise e pour attendre le premier clic*/
                    } else {
                        
                        long int temps = Microsecondes() + 1000000;
                        while( Microsecondes() < temps) {
                            Chrono(debut);
                        }

                        RemplirRectangleAnimation(decalage_droite,decalage_bas,taille_carre);
                        RemplirRectangleAnimation(decalage_droite_tmp,decalage_bas_tmp,taille_carre);
                        etat[num_case_tmp] = '0';
                        e=-1; /*on re initialise e pour attendre le premier clic*/
                        num_case_tmp=-1; /* on enleve la valeur qui correspondait à la case du premier clic*/
                    }   
                }

                num_case++;
                decalage_droite = decalage_droite+taille_carre+20;
            }
            decalage_droite=30;
            decalage_bas = decalage_bas+taille_carre+20;
        }
        num_case=0; 
    }
    free(tab2);   
}




void RemplirRectangleAnimation(int x, int y, int b) {
    int a=0,i=0;
    couleur c = CouleurParComposante(204, 153, 255);
    ChoisirCouleurDessin(c);
    while(a!=b+1) {
        if (i%500000==0) {
            RemplirRectangle(x,y,a,b);
            a++;
        }
        i++;      
    }
}

long int tmpsactuelle;
long int precedent = -1;

long int Chrono(long int debut) {

    char *tab3 = malloc(5*sizeof(char));
    couleur c;
    couleur c2;
    c=CouleurParNom("white");
    c2=CouleurParNom("black");

    tmpsactuelle = (Microsecondes()-debut)/1000000;
    if(precedent < tmpsactuelle) {
        sprintf(tab3,"%ld", tmpsactuelle);
        ChoisirCouleurDessin(c);
        RemplirRectangle(30,0,100,50);
        ChoisirCouleurDessin(c2);
        EcrireTexte(30,35,tab3,2);
        precedent = tmpsactuelle;
    }
    free(tab3);
    return tmpsactuelle;
    /* on enregistre le temps à la fin de la partie pour l'afficher(dans une version future)*/
}