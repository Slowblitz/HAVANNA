#include"Plateau.h"
#include "Coup.h"
#include"iostream"
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;
 
string White = "\033[1;37m *\033[0;m";
string Blue = "\033[1;34m *\033[0;m";
string Green = "\033[1;32m *\033[0;m";

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param P [description]
 * @return [description]
 */
	
Plateau::Plateau(int r)
{
	rayon=r;
	taille=2*r-1;

	PlaPla=new Case*[taille];

	for(int i=0; i<taille; i++)
	{
		PlaPla[i]=new Case[taille];

		for(int j=0; j<taille; j++)
		{
			PlaPla[i][j]=Case(j+(-rayon+1),i+(-rayon+1),"White");
		}
	}
}
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param P [description]
 * @return [description]
 */
void Plateau::sauve()
{
	
        ofstream fichier("map.dat", ios::out );  // ouverture en écriture avec effacement du fichier ouvert

 

        if(fichier)

        {
 	fichier<<this->getT();
	fichier<<endl;
	for (int i=0;i<taille;i++) 
		{ 
		for (int j=0;j<taille;j++) 
		 { 
		 
		 	fichier<<PlaPla[i][j].getc();
		 } 
		fichier<<endl;
                
        }
fichier.close();

}
    else cerr << "Impossible d'ouvrir le fichier !" << endl;


}


/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param P [description]
 * @return [description]
 */
Plateau::Plateau()
{
ifstream fichier("map.dat",ios::in);
   
    if(fichier)
    {

    	string ligne;
    	int nLigne=0;
    	int t;

    	fichier >> t;
	rayon=t;
    	taille=2*rayon-1;

    	
	
		PlaPla=new Case*[taille];

		if(!fichier.eof())getline(fichier,ligne);

		for (int i=0; i < taille; i++)
		{
			if(!fichier.eof())getline(fichier,ligne);
			PlaPla[i]=new Case[taille];

			for (int j=0; j < taille; j++)
			{	string r="";
				fichier>>r;
				
				PlaPla[i][j]=Case(j+(-rayon+1),i+(-rayon+1),r);
				//mp[i][j].modifcntnC("B");
			}
		}

	}
	else cout<<"erreur";
}





/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param P [description]
 * @return [description]
 */

void Plateau::affichage()
{ int cp =(taille-1)/2 ;
  int cpp=0;
	
	for(int i=0; i<taille; i++)
	{ 
		if(cpp == 0 ){	
		for ( int i =0 ;i < cp; i++) cout << " " ;}
		
		if(cpp != 0 ){	
		for ( int  j=0  ;j < cpp; j++) cout <<" " ;}
		
		for(int j=cp; j<taille-cpp ; j++)
		{	
			if(PlaPla[i][j].getc()== "White")cout<<White; 
			if(PlaPla[i][j].getc()== "blue")cout<<Blue;
			if(PlaPla[i][j].getc()== "green")cout<<Green;
			//cout<<"("<<PlaPla[i][j].getx()<<","<<PlaPla[i][j].gety()<<")";
		}
	
	cout<<endl;
	if(i < (taille-1)/2 ) cp--;		
	if(i > (taille-2)/2 ) cp=0, cpp++;
	
	}

}
/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param P [description]
 * @return [description]
 */
bool Plateau::VerifCase(int x, int y, int i, int j)
{


return  (PlaPla[i][j].getx()== x) && (PlaPla[i][j].gety()== y && PlaPla[i][j].getVide());
	
}
bool Plateau::VerifCase2(int x, int y, int i, int j)
{


return  (PlaPla[i][j].getx()== x && PlaPla[i][j].gety()== y );
	
}

bool Plateau::setColor(int x, int y,string c)
{
	
	PlaPla[x][y].setColorCase(c);
	
return true;
}








