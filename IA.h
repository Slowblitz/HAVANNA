#pragma once 
#include "Plateau.h"

struct AiMove
{	
	int x , y , score;
	AiMove(){};
	AiMove(int Score): score(Score){};


};


class AI{

	AiMove GetBestMove(Plateau *P ,vector <Joueur> &v ,int);

	 public:
	 		void PerformMove(Plateau &P);

};
