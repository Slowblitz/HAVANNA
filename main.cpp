#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Case.h"
#include "Plateau.h"
#include "joueur.h"
#include "jeu.h"
#include <cstdlib>




int main()
{
	
///////////////// Init du jeu ///////////////////
	system("clear");
	system("banner Havannah");
	string color,name;
	
	int taille,x,y,nbjoueur,charger;
	Jeu Game;

	/*cout<<"charger ou nouvelle partie ? (1,2) :"<<endl;
	cin>>charger;
	Plateau* P = new Plateau();
*/


	cout<<"			Taille du plateau : " ;
	cin>>taille ;
////////////////////////prevention error/////////////
  	while(cin.fail())
        {

          cout<<"entrer un chiffre s'il vous plais : ";
          cin.clear();
          cin.ignore(256 ,'\n');
          cin>>taille;

        }
/////////////////////////////////////////////////////
	
	Plateau* P = new Plateau(taille);
	

	cout<<"			Nombre de joueur :";
	cin>>nbjoueur;
////////////////////////prevention error/////////////
	while(cin.fail())
        {

          cout<<"entrer un chiffre s'il vous plais : ";
          cin.clear();
          cin.ignore(256 ,'\n');
          cin>>nbjoueur;

        }
//////////////////////////////////////////////////////
	system("clear");

	Game.Init(nbjoueur);		
	Game.PushCoordone(P);
	Game.PushFace(P);

///////////////// partie ///////////////
		P->affichage();
	Game.Partie(P);
	
	
	
	

}
