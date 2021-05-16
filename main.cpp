#include <iostream>
#include "Joueur.h"
#include "Lettre.h"
#include "Tentative.h"
#include <vector>
#include<algorithm>
using namespace std;

int main (){
    vector<string> v;
    v.push_back("rouge");
    v.push_back("jaune");
    v.push_back("blanc");

	string nom ,mot;
	cout << "veuillez entrer votre Nom :"<<endl;
	cin >> nom ;
	Joueur l(nom);
	string motadeviner="accuser";
	int nbessai=0;bool test=false;
	do{
	cout<<"Saisir votre essai numéro:"<< nbessai <<endl;
		cin>>mot;
		if (mot==motadeviner){test=true;break;}
    Tentative t(mot);
    if (t.controlesaisie(motadeviner))
        { nbessai++;//essai validé

     vector<int> red; //recherche des lettres bien placées
     for (int i=0;i<7;i++){
            Lettre j(mot[i],i,blanc);
      for (int k=0;k<7;k++){
            Lettre m(motadeviner[k],k,blanc);
            j.Comparer(m);
            if (j.getCouleur()==rouge) {red.push_back(k);break;}
     }
     }

     vector<int> yellow;//recherche des lettres mal placées
	for (int i=0;i<7;i++)
    {   Lettre j(mot[i],i,blanc);
        //calcul de l'occurence de chaque lettre dans le mot a deviner
        int freq = std::count(motadeviner.begin(), motadeviner.end(), mot[i]);
        if ((freq!=0)){
        for (int k=0;k<7;k++)
        {if ((!(std::count(red.begin(), red.end(), k)))&&(!(std::count(yellow.begin(), yellow.end(), k))))//k pas dans red
                                {//recherche des jaunes
         Lettre m(motadeviner[k],k,blanc);
         j.Comparer(m);
         if (j.getCouleur()==jaune) {yellow.push_back(k);}
                                }

        }//fin parcours lettre mot a deviner

        if ((std::count(red.begin(), red.end(), i))){j.setCouleur(rouge);}



 }
        cout<<"lettre "<<j.getval()<<" est de couleur "<<v[j.getCouleur()]<<endl;

    }//fin parcours de la lettre lettre
    }//fin parcours de l'essai
	}//fin parcours de tous les essais
	while (nbessai<7);
	if (test) {cout <<"BRAVO !! Vous avez gagné "<<endl;}
        else {cout<<"Dommage, vous avez perdu"<<endl;}
    int x;
    x=7-nbessai;
	l.setScore(x);

	cout<<"votre score est :"<<x<<endl;
	l.setRecord(x);
	int b=l.getRecord();
	cout<<"votre record est : "<<b<<endl;









	return 0;

}
