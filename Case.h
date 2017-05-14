
#pragma once
#include<string>


using namespace std;


class Case
{	
	int x, y;
	

		public:
			string color;
			Case();
			Case(int a, int b, string clr);
			int getx();
			int gety();
			void setColorCase(string);
			
			string getc();
			bool getVide();
			void afficheCase();
	
};
