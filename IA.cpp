/*#include "IA.h"



void PerformMove()

{
GetBestMove(P , V , 0)
}




AiMove AI::GetBestMove(Plateau *P, vector<Joueur> v,min ){
{

 int cp =(P->taille-1)/2 ;
 int cpp=0;
int max = 1000;
int min =-1000;
	for(int i=0; i<P->taille; i++)
	{ 
		
		for(int j=cp; j<taille-cpp ; j++)
		{	


					if(PlaPla[i][j].getVide())
					AiMove move;
					move.x=i;
					move.y=j;
					P->setColor(i,j ,v.getcolor());	
					int tmp =GetBestMove(P,v,1);
					if (tmp > max) max = tmp;
					if( tmp < min) min =tmp;
				}
				P->setColor(i,j ,"White");
			
		}
	
	if(i < (taille-1)/2 ) cp--;		
	if(i > (taille-2)/2 ) cp=0, cpp++;
if(tmp == 0)

	return ( min);
else
	return (max);

}

*/
