#include "jeu.h"
#include "joueur.h"
#include <iostream>
using namespace std ;

Joueur::Joueur()
{
	this->name="joueur 1";
	this->color="blue";
	this->NBcoup=0;
}
////////////////////////////////////////////////////////////////////////
Joueur::Joueur(string n , string color)
{
	this->setcolor(color);
	this->setname(n);
	this->NBcoup=0;
}
////////////////////////////////////////////////////////////////////////
string Joueur::getname()
{
	return name;
}
////////////////////////////////////////////////////////////////////////
string Joueur::getcolor()
{
	return color;
}

////////////////////////////////////////////////////////////////////////
void Joueur::setcolor(string c)
{
	this->color = c;
}
////////////////////////////////////////////////////////////////////////
void Joueur::setname(string n)
{
	this->name= n;
}


int Joueur::getNBcoup()
{
	return NBcoup;
}

int Joueur::setNBcoup(int n)
{
	this->NBcoup=n;
}

