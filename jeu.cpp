#include"jeu.h"
#include <vector>  
#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <algorithm>
using namespace std;




Jeu::Jeu()
{


}
////////////////////////////////////////////////////////////////////////


/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param c [description]
 * @param J [description]
 * @param P [description]
 * @return [description]
 */
bool Jeu::NewCoup(Coup &c , Joueur &J, Plateau *P)
{	
	J.setNBcoup(J.getNBcoup()+1);
	
	for(int i = 0 ; i<P->taille; i++){
		for(int j = 0 ; j<P->taille; j++){
					
					if(P->VerifCase(c.x, c.y,i,j))
						{
						
					
						P->setColor(i,j ,J.getcolor());
						
				
						return true;	
						}	
					}
}
		
return false;
}

bool Jeu::NewCoup2(Coup &c , Joueur &J, Plateau *P)
{	
	J.setNBcoup(J.getNBcoup()+1);
	
	for(int i = 0 ; i<P->taille; i++){
		for(int j = 0 ; j<P->taille; j++){
					
					if(P->VerifCase2(c.x, c.y,i,j))
						{
						
					
						P->setColor(i,j ,J.getcolor());
						
				
						return true;	
						}	
					}
}
		
return false;
}
////////////////////////////////////////////////////////////////////////

/**
 * @brief affiche les coup joué
 */
void Jeu::Pop(int var){
	if( var == 0 ) 
	{
			for(unsigned int i =0 ; i<C.size(); i++)
				{
				cout<<C.at(i).Getx()<<" "<<C.at(i).Gety()<<endl;
				}
	}
	if(var == 1)
	{
			for(unsigned int j =0 ; j<C2.size(); j++)
				{
				cout<<C2.at(j).Getx()<<" "<<C2.at(j).Gety()<<endl;
				}
	}


	if (var == 2)
	{
		for(unsigned int k =0 ; k<C3.size(); k++)
		{
		cout<<C3.at(k).Getx()<<" "<<C3.at(k).Gety()<<endl;
		}

	}
	
}

////////////////////////////////////////////////////////////////////////

/**
 * @brief stock les coordonée des 6 coin dans le vector Coord
 */

void Jeu::PushCoordone(Plateau *P){

	int a=P->rayon;
	Coord.push_back(Coup(0,-a+1));
	Coord.push_back(Coup(a-1,-a+1));
	Coord.push_back(Coup(a-1,0));
	Coord.push_back(Coup(0,a-1));
	Coord.push_back(Coup(-a+1,a-1));
	Coord.push_back(Coup(-a+1,0));

}
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param P [description]
 * @return [description]
 */
////////////////////////////////////////////////////////////////////////


void Jeu::PopCoordone(){

	for(unsigned int i =0 ; i<Coord.size(); i++)
		{
		cout<<Coord.at(i).Getx()<<" "<<Coord.at(i).Gety()<<endl;
		}
}

////////////////////////////////////////////////////////////////////////

/**
 * @brief itersection etre le vecteur des coup  joué et des  coin
 * @details [long description]
 * @return [description]
 */

bool Jeu::Inter(vector <Coup> &C){
		int cpt=0;
		for(unsigned int i =0 ; i<C.size(); i++){

				for(unsigned int j =0 ; j<Coord.size(); j++) {
				
					
							if(C.at(i).Getx()==Coord.at(j).Getx() && C.at(i).Gety()==Coord.at(j).Gety()) cpt++;		
				


							}
						}

		if ( cpt >= 2)
				return true;
			return false;
}

////////////////////////////////////////////////////////////////////////
/**
 * @brief retroune si tous les pion son bien alligné
 * @details [long description]
 * @return [description]
 */
bool Jeu::Coller(vector <Coup> &C){//////////////////////////////////////////A FAIRE

	int cpt =0;
	for(unsigned int i =0 ; i<C.size(); i++)
	{			
		
		
		Possible.push_back(Coup(C.at(i).Getx()-1, C.at(i).Gety()));
		Possible.push_back(Coup(C.at(i).Getx() ,C.at(i).Gety()-1));
		Possible.push_back(Coup(C.at(i).Getx()+1, C.at(i).Gety()-1));
		Possible.push_back(Coup(C.at(i).Getx()+1 ,C.at(i).Gety()));
		Possible.push_back(Coup(C.at(i).Getx() ,C.at(i).Gety()+1));
		Possible.push_back(Coup(C.at(i).Getx()-1, C.at(i).Gety()+1));

		for(unsigned int j =0 ; j<C.size(); j++)
		{
		
			for(unsigned int k =0 ; k<Possible.size(); k++)
			{
				if(C.at(j) == Possible.at(k)){
					//cout<<"("<<C.at(i).Getx()<<","<<C.at(i).Gety()<<") == ("<<C.at(j).Getx()<<","<<C.at(j).Gety()<<")"<<endl;
					cpt++ ;
						
				}
		
			}

		}
		Possible.clear();
	}
	cout<<"nbr de pion alligné : "<< cpt /2 +1<<endl;
	if ( cpt /2+1 >=4)
		return true;
	return false;
}	

////////////////////////////////////////////////////////////////////////

/**
 * @brief stock les coordonné des 6 face dans 6 vector
 * @details [long description]
 * 
 * @param P [description]
 */
void Jeu::PushFace(Plateau *P){

	cout<<endl;
	int taille = P->rayon;

	for (int j = 0; j < taille; ++j)
	{	
		Face1.push_back(Coup(Coord.at(0).Getx()+j, Coord.at(0).Gety()));
		cout<<endl;
	}
	
	for (int k = 0; k < taille; ++k)
	{
		Face2.push_back(Coup(Coord.at(1).Getx(), Coord.at(1).Gety()+k));
	}
	cout<<endl;
	for (int l = 0; l< taille; ++l)
	{
		Face3.push_back(Coup(Coord.at(2).Getx()-l, Coord.at(2).Gety()+l));
	}

	for (int m= 0; m< taille; ++m)
	{
		Face4.push_back(Coup(Coord.at(3).Getx()-m, Coord.at(3).Gety()));
	}
	for (int n= 0; n< taille; ++n)
	{
		Face5.push_back(Coup(Coord.at(4).Getx(), Coord.at(4).Gety()-n));
	}
	for (int o= 0; o< taille; ++o)
	{
		Face6.push_back(Coup(Coord.at(5).Getx()+o, Coord.at(5).Gety()-o));
	
}
	
	
}



////////////////////////////////////////////////////////////////////////


void Jeu::PopFace(){
	cout<<endl;
	for(unsigned int i =0 ; i<Face1.size(); i++)
	{
	cout<<Face1.at(i).Getx()<<" "<<Face1.at(i).Gety()<<endl;
	}
}

////////////////////////////////////////////////////////////////////////

/**
 * @brief itersection entre le vector coup et face
 * @details [long description]
 * @return [description]
 */

bool Jeu::InterFace(vector <Coup> &C){///////////////////////////////////// a

		int cpt=0;
		for(unsigned int i =0 ; i<C.size(); i++){

				for(unsigned int j =0 ; j<Face1.size(); j++) {
				
					
							if(C.at(i).Getx()==Face1.at(j).Getx() && C.at(i).Gety()==Face1.at(j).Gety()) cpt++;		
							else if(C.at(i).Getx()==Face2.at(j).Getx() && C.at(i).Gety()==Face2.at(j).Gety()) cpt++;	
							else if(C.at(i).Getx()==Face3.at(j).Getx() && C.at(i).Gety()==Face3.at(j).Gety()) cpt++;
							else if(C.at(i).Getx()==Face4.at(j).Getx() && C.at(i).Gety()==Face4.at(j).Gety()) cpt++;
							else if(C.at(i).Getx()==Face5.at(j).Getx() && C.at(i).Gety()==Face5.at(j).Gety()) cpt++;
							else if(C.at(i).Getx()==Face6.at(j).Getx() && C.at(i).Gety()==Face6.at(j).Gety()) cpt++;

							}
						}

		if ( cpt >= 3)
				return true;
			return false;
}

bool Jeu::verifCercle(vector <Coup> &C,Coup &c)
{
if(C.back() == C.front())return true;

vector <Coup>::iterator it;
it=(find (C.begin(), C.end(), c)) ;


if(it != C.end() )return true;
return false;

}
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param P [description]
 * @return [description]
 */


bool Jeu::Partie(Plateau *P)
{
	bool win = false;
		while(!win){
			int x ,y = 0 ;
			

			for (int i =0 ; i<VectorJoueur.size(); i++){
			

			///// gateau 
			if(VectorJoueur.size() == 2 &&  VectorJoueur.at(0).getNBcoup() == 1 && VectorJoueur.at(1).getNBcoup() == 0 ){
				string a="";
				cout <<"voulez vous faire la régle du gato?"<<endl;
				cin>>a;
				if(a=="y"){
				
				int x=C.at(0).Getx();
				int y=C.at(0).Gety();
				Coup p(x,y);
				
				this->NewCoup2(p,VectorJoueur.at(1),P);
				i--;
				P->affichage();
				}
				
				
				

			}
			
			cout<<"Joueur : "<<VectorJoueur.at(i).getname()<<" Couleur :"<< VectorJoueur.at(i).getcolor()<<endl;
			cout<<"Coordonée du coup :";
			cin>>x;	
			cin>>y;
			Coup c(x,y);
			if (this->NewCoup(c,VectorJoueur.at(i),P)){

					if (i == 0){ C.push_back(c);
						if(this->Inter(C) && this->Coller(C) || this->InterFace(C) && this->Coller(C)){

									cout <<"joueur "<<VectorJoueur.at(i).getname()<<" a win"<<endl; 
									return win = 1;
										}}
						

					if (i== 1){ C2.push_back(c);
						if(VectorJoueur.at(i).getname() == "IA"){
							if(this->Inter(C2) && this->Coller(C2) || this->InterFace(C2) && this->Coller(C2)) return win = 1;}


					if(this->Inter(C2) && this->Coller(C2) || this->InterFace(C2) && this->Coller(C2)) {
									cout <<"joueur "<<VectorJoueur.at(i).getname()<<"a win"<<endl; 				
										
									return win = 1;}}



					if (i== 2) C3.push_back(c);
						if(this->Inter(C3) && this->Coller(C3) || this->InterFace(C3) && this->Coller(C3)) return win = 1;

						
						system("clear");
						
						P->affichage();
						cout<<"Coup effectuer par : "<<VectorJoueur.at(i).getname()<<endl;
						this->Pop(i);
						
					}
			
			else {
			if(this->verifCercle(C, c) && this->Coller(C) ){	P->affichage();
			return win=1 ;}			
			cout<<"Case deja prise !!"<<endl;
			
			
		
			}
			
	}
			/*string a;
			cout<<"voulez vous sauvegarder ?"<<endl;
			cin>>a;
			if(a=="y")
			P->sauve();
*/
}



}
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param P [description]
 * @return [description]
 */
void Jeu::Init(int nbjoueur)
{	
	string name, color;
	for (int i = 0; i < nbjoueur; ++i)
	{

	cout<<"			Nom du joueur :";
	cin>>name;

        {
while(cin.fail())
        {
          cout<<"entrer un nom'il vous plais : ";
          cin.clear();
          cin.ignore(256 ,'\n');
          cin>>name;

        }
//////////////////////////////////////////////////////

	cout<<"			couleur du joueur (blue/green) :";
	cin>>color;
////////////////////////prevention error/////////////
	while(cin.fail())
        {

          cout<<"entrer une couleur 	s'il vous plais : ";
          cin.clear();
          cin.ignore(256 ,'\n');
          cin>>color;

        }
//////////////////////////////////////////////////////
	Joueur j(name,color);
	VectorJoueur.push_back(j);
	}

}
}
	


