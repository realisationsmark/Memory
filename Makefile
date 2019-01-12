# TP 19 Exercice 1 : fichier Makefile
 
# CHAPITRE 1 : BUT FINAL
 
but : Memory
 
# CHAPITRE 2 : VARIABLES
 
OFILES = menu.o \
         main.o \
         triche.o \
         affichage.o \
         
 
CC = gcc
 
CFLAGS = -Wall -ansi -pedantic -g
 
# CHAPITRE 3 : DEPENDANCES (REGLES IMPLICITES)
 
main.o : menu.h triche.h affichage.h
 
menu.o : menu.h affichage.h

triche.o : triche.h

affichage.o : affichage.h menu.h 
 
#CHAPITRE 4 : DEPENDANCES AVEC COMMANDES
 
Memory : $(OFILES)
	$(CC) $(CFLAGS) -o Memory $(OFILES) -lgraph
 
#CHAPITRE 5 : NETTOYAGE DES FICHIERS GENERES
 
clean :
	-rm -f $(OFILES) Memory
 
run : 
	./Memory
 
#CHAPITRE 6 : BUTS FACTICES
 
.PHONY : but clean   