

#pragma once


#include"Case.h"


class Plateau 
{
	//Joueur Joueur1, joueur2;
	
	
	
	

	public:
	int rayon;
	int taille;
	Case ** PlaPla;
	Plateau();
	void sauve();
	void charger();
	Plateau(int n);
	void affichage();
	bool VerifCase(int ,int,int ,int);
	bool VerifCase2(int ,int,int ,int);
	 bool setColor(int , int ,string);
	int getT(){return taille;}
	
	Plateau(const char*);
	friend int getx();
	friend void afficheCase();
	
};


