#include "UI.h"
#include<iostream>
using std::cout;
using std::cin;

void UI::citire()
{
string Text[M];
int nr = this->gl.citire(Text);
for (int i = 0; i < nr; i++) {
cout << Text[i] << "\n";
}
}

void UI::printMenu()
{
	cout << "\n\t\tMeniu -Glosar de termeni-\n";
	cout << "1.Afisare glosar\n";
	cout << "2.Sterge cuvant din glosar\n";
	cout << "3.Cauta cuvant in glosar\n";
	cout << "0.Iesire\n";
	cout << "\nIntroduceti comanda: ";
	cin >> this->comanda;
	this->executaComanda();
}

void UI::executaComanda()
{
	int val[M];
	switch (this->comanda) {
		case 0:
			break;
		case 1:{
			string cheile[M];
			int n = this->gl.getAll().cheile(cheile);
			int i = 0;
			auto it = this->gl.getAll().iterator();
			for (i = 0; i < n; i++) {
				it->prim();
				cout << cheile[i] << "\t\tapare pe liniile: ";
				if (it->valid()) {
					while (it->valid()) {
						auto poz = it->getCurent();
						if (it->getCheie(poz) == cheile[i]) {
							cout << it->getValoare(poz) << " ";
						}
						it->urmator();
					}
				}
				cout << "\n";
			}
			break;}
		case 2: {
			string cuv;
			int linie;
			cout << "Stergeti cuvantul: "; cin >> cuv;
			cout << " de pe linia: "; cin >> linie;
			this->gl.stergere(cuv, linie);
			cout << "Aparitia cuvantului " << cuv << " de pe linia " << linie << " a fost stearsa din glosar!\n"; 
			break; }
		case 3:
			string cuv="";
			cout << "Introduceti cuvantul cautat: "; cin >> cuv;
			int l = gl.cauta(cuv, val);
			cuv = cuv + " apare pe liniile: ";
			for (int i = 0; i < l; i++) {
				cuv = cuv + std::to_string(val[i]) + " ";
			}
			cout <<"\n"<< cuv;
			break;
	}
	if (this->comanda != 0) {
		this->printMenu();
	}

}
