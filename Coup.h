#pragma once


 
class Coup 
{	
	
	int x,y,scores;

	public:
		Coup();
		Coup(int a, int b);
		int Getx();
		int Gety();
		
	friend class Jeu;	
};
bool operator==(Coup  a,Coup b);//surcharge d opperateur pour comparer 2 coup
