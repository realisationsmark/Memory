#include<stdio.h>                                                                                                                                                                
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>
#include"graph.h"
#include"menu.h"
#include"affichage.h"
#define taille_carre 70

void menu()
{   
    couleur c;
    c=CouleurParNom("white");
    Jouer();
    _X=0;
    _Y=0;

    while(1) {
        Animation();
        _X=0;
        _Y=0;
        
        SourisCliquee();
        
        if((_X >= 180)&&(_X <= 330)&&(_Y >= 150)&&(_Y <= 200)) {
            nbr_carte_x = 4;
            nbr_carte_y = 4;
            EffacerEcran(c);
            FermerGraphique();
            InitialiserGraphique();
            CreerFenetre(500,200,500,500);
            GrilleRemplie(nbr_carte_x,nbr_carte_y);
            _X=0;
            _Y=0;
            break;
        }

        if((_X >= 180)&&(_X <= 330)&&(_Y >= 210)&&(_Y <= 260)) {
            nbr_carte_x = 4;
            nbr_carte_y = 5;
            EffacerEcran(c);
            FermerGraphique();
            InitialiserGraphique();
            CreerFenetre(500,200,600,500);
            GrilleRemplie(nbr_carte_x,nbr_carte_y);
            _X=0;
            _Y=0;
            break;
        }

        if((_X >= 180)&&(_X <= 330)&&(_Y >= 270)&&(_Y <= 320)) {
            nbr_carte_x = 6;
            nbr_carte_y = 6;
            EffacerEcran(c);
            FermerGraphique();
            InitialiserGraphique();
            CreerFenetre(500,200,700,700);
            GrilleRemplie(nbr_carte_x,nbr_carte_y);
            _X=0;
            _Y=0;
            break;
        }
    }
}

void Jouer() {
    couleur c;
    couleur c2;
    c=CouleurParNom("white");
    c2=CouleurParNom("black");
     
     while(1) {
        SourisPosition();
        if((_X >= 180)&&(_X <= 330)&&(_Y >= 200)&&(_Y <= 250)) {
            couleur c3 = CouleurParComposante(204, 153, 255);
            ChoisirCouleurDessin(c3);
            RemplirRectangle(180,200,150,50);
            ChoisirCouleurDessin(c);
            EcrireTexte(220,230,"Jouer",2);
            _X=0;
            _Y=0;
        } else {
            ChoisirCouleurDessin(c2);
            RemplirRectangle(180,200,150,50);
            ChoisirCouleurDessin(c);
            EcrireTexte(230,230,"Jouer",1);
            _X=0;
            _Y=0;
        }
        SourisPosition();
        if((_X >= 180)&&(_X <= 330)&&(_Y >= 270)&&(_Y <= 320)) {
            couleur c3 = CouleurParComposante(204, 153, 255);
            ChoisirCouleurDessin(c3);
            RemplirRectangle(180,270,150,50);
            ChoisirCouleurDessin(c);
            EcrireTexte(220,300,"Quitter",2);
            _X=0;
            _Y=0;
        } else {
            ChoisirCouleurDessin(c2);
            RemplirRectangle(180,270,150,50);
            ChoisirCouleurDessin(c);
            EcrireTexte(230,300,"Quitter",1);
            _X=0;
            _Y=0;
        }
<<<<<<< HEAD
 		
=======
        
>>>>>>> d33563e105a1b27876dcb7a139fa0d90c7934234
        SourisCliquee();
        if((_X >= 180)&&(_X <= 330)&&(_Y >= 200)&&(_Y <= 250)) {

            EffacerEcran(c);
            _X=0;
            _Y=0;
            break;
        }
        SourisCliquee();
        if((_X >= 180)&&(_X <= 330)&&(_Y >= 270)&&(_Y <= 320)) {
            EffacerEcran(c);
            FermerGraphique();
            exit(0);
        }
    }
}

void Animation() {

    couleur c;
    couleur c2;
    c=CouleurParNom("white");
    c2=CouleurParNom("black");

    SourisPosition();
    
    if((_X >= 180)&&(_X <= 330)&&(_Y >= 150)&&(_Y <= 200)) {
        couleur c3 = CouleurParComposante(204, 153, 255);
        ChoisirCouleurDessin(c3);
        RemplirRectangle(180,150,150,50);
        ChoisirCouleurDessin(c);
        EcrireTexte(230,170,"4 X 4",1);
        _X=0;
        _Y=0;
    } else {
        ChoisirCouleurDessin(c2);
        RemplirRectangle(180,150,150,50);
        ChoisirCouleurDessin(c);
        EcrireTexte(240,180,"4 X 4",1);
    }

    if((_X >= 180)&&(_X <= 330)&&(_Y >= 210)&&(_Y <= 260)) {
        couleur c3 = CouleurParComposante(204, 153, 255);
        ChoisirCouleurDessin(c3);
        RemplirRectangle(180,210,150,50);
        ChoisirCouleurDessin(c);
        EcrireTexte(230,230,"4 X 5",1);
        _X=0;
        _Y=0;
    } else {
        ChoisirCouleurDessin(c2);
        RemplirRectangle(180,210,150,50);
        ChoisirCouleurDessin(c);
        EcrireTexte(240,240,"4 X 5",1);
    }

    if((_X >= 180)&&(_X <= 330)&&(_Y >= 270)&&(_Y <= 320)) {
        couleur c3 = CouleurParComposante(204, 153, 255);
        ChoisirCouleurDessin(c3);
        RemplirRectangle(180,270,150,50);
        ChoisirCouleurDessin(c);
        EcrireTexte(230,290,"6 X 6",1);
        _X=0;
        _Y=0;
    } else {
        ChoisirCouleurDessin(c2);
        RemplirRectangle(180,270,150,50);
        ChoisirCouleurDessin(c);
        EcrireTexte(240,300,"6 X 6",1);
    }
}

void Recommencer() {
    couleur c;
    couleur c2;
    c=CouleurParNom("white");
    c2=CouleurParNom("black");
     
     while(1) {
        SourisPosition();
        if((_X >= 180)&&(_X <= 330)&&(_Y >= 200)&&(_Y <= 250)) {
            couleur c3 = CouleurParComposante(204, 153, 255);
            ChoisirCouleurDessin(c3);
            RemplirRectangle(180,200,150,50);
            ChoisirCouleurDessin(c);
            EcrireTexte(190,230,"Recommencer",1);
            _X=0;
            _Y=0;
        } else {
            ChoisirCouleurDessin(c2);
            RemplirRectangle(180,200,150,50);
            ChoisirCouleurDessin(c);
            EcrireTexte(190,230,"Recommencer",1);
        }
        SourisPosition();
        if((_X >= 180)&&(_X <= 330)&&(_Y >= 270)&&(_Y <= 320)) {
            couleur c3 = CouleurParComposante(204, 153, 255);
            ChoisirCouleurDessin(c3);
            RemplirRectangle(180,270,150,50);
            ChoisirCouleurDessin(c);
            EcrireTexte(220,300,"Quitter",2);
            _X=0;
            _Y=0;
        } else {
            ChoisirCouleurDessin(c2);
            RemplirRectangle(180,270,150,50);
            ChoisirCouleurDessin(c);
            EcrireTexte(230,300,"Quitter",1);
            _X=0;
            _Y=0;
        }
 
        SourisCliquee();
        if((_X >= 180)&&(_X <= 330)&&(_Y >= 200)&&(_Y <= 250)) {

            EffacerEcran(c);
            _X=0;
            _Y=0;
            break;
        }
        SourisCliquee();
        if((_X >= 180)&&(_X <= 330)&&(_Y >= 270)&&(_Y <= 320)) {
            EffacerEcran(c);
            FermerGraphique();
            exit(0);
        }
    }
}


int VerificationEtat(int* tab, char* etat) {
    
    int i;
    couleur c;
    c=CouleurParNom("white");
    
    for(i=0;i<(nbr_carte_x*nbr_carte_y);) {
          if(etat[i] == 'r')
            i++;
          else 
            break;
        }
    if (i==(nbr_carte_x*nbr_carte_y)) {
        sleep(1);
        EffacerEcran(c);
        Recommencer();
        for(i=0;i<nbr_carte_x*nbr_carte_y;i++) {
            etat[i]='0';
            tab[i]=-1;
        }
        return 1;
    }
    return 0;
}
