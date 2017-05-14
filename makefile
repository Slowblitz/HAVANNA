all:main
	./main


main : main.cpp jeu.cpp jeu.h jeu.o Plateau.cpp Plateau.h Plateau.o joueur.cpp joueur.h joueur.o Case.cpp Case.h Case.o Coup.cpp Coup.h Coup.o
	g++ -o main Plateau.o jeu.o Case.o joueur.o Coup.o  main.cpp

jeu.o : jeu.cpp jeu.h
	g++ -c jeu.cpp

Plateau.o : Plateau.cpp Plateau.h
	g++ -c Plateau.cpp

joueur.o : joueur.cpp joueur.h 
	g++ -c joueur.cpp 

Case.o : Case.cpp Case.h
	g++ -c Case.cpp

Coup.o :Coup.cpp Coup.h
	g++ -c Coup.cpp

clean: 
	rm -rf *.o
mrproper: clean
	rm -rf main
	
