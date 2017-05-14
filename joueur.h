#pragma once
#include "Plateau.h"


#include<string>

using namespace std;


class Joueur  
{

 string color , name;
	
	public :
	int NBcoup;	
	Joueur();
	Joueur(string, string);
	void NewJoueur();
	void setcolor(string);
	void setname(string);
	string getname();
	string getcolor();
	int setNBcoup(int n);
	void SwapColor();
	int getNBcoup() ;



};

class JoueurHumain : Joueur
{


};


class JoueurIA : Joueur
{


};

