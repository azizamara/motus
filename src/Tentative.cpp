#include "Tentative.h"
#include <iostream>
#include <string>
//#include "Joueur.h"
using namespace std;


Tentative::Tentative(string mot )
{
setmotsaisi(mot);
}
/////////////////////////////
Tentative::~Tentative()
{

}

/////////////////////////////
int Tentative::getNbessais(){
	return Nbessais;
}
/////////////////////////////
bool Tentative::controlesaisie(string mot){
	if ((mot.length() == motsaisi.length())   ){
		return true;
    }
}


/////////////////////////////
void Tentative::setmotsaisi(string mot){
	motsaisi=mot;
}
/////////////////////////////
string Tentative::getmotsaisi()const{
	return motsaisi;
}


/////////////////////////////


