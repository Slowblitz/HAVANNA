#pragma once	
#include "Plateau.h"
#include "joueur.h"
#include "Coup.h"	
#include <vector> 

class Jeu 
{	vector <Coup> C;
	vector <Coup> C2;
	vector <Coup> C3;
	vector <Coup> Coord;
	vector <Coup> Possible;
	vector <Coup> Face1;
	vector <Coup> Face2;
	vector <Coup> Face3;
	vector <Coup> Face4;
	vector <Coup> Face5;
	vector <Coup> Face6;
	vector <Joueur> VectorJoueur;

	public :
		Jeu();
		bool NewCoup2(Coup &c , Joueur &J, Plateau *P);
		bool verifcase(Coup* ,Plateau* );
		bool NewCoup(Coup &c , Joueur &j, Plateau *);	
		bool Win(){return false;};
		void Pop(int var);
		void PushCoordone(Plateau *P);
		void PopCoordone();
		bool	 Inter(vector <Coup> &);
		bool Coller(vector <Coup> &);
		void PushFace(Plateau *P);
		void PopFace();
		bool	 InterFace(vector <Coup> &);
		bool verifCercle(vector <Coup> &C,Coup &c);
		bool Partie(Plateau *);
		void Init(int);

};

