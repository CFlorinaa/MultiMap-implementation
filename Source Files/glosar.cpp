#include "glosar.h"
#include<fstream.>
#include<string>
using std::string;

void Glosar::loadfromfile()
{
	std::ifstream fi("carte.in");
	if (!fi.is_open()) {
		throw std::exception("Nu s-a putut deschide fisierul");
	}
	string Text;
	string TextSpace, cuvant;
	int i = 0;
	while (std::getline(fi, Text)) {
		i++;
		cuvant = "";
		for (auto it = Text.begin(); it != Text.end(); it++) {
			if ((*it >= 'A' && *it <= 'Z') || (*it >= 'a' && *it <= 'z')) {
				cuvant = cuvant + *it;
			}
			else
				if (cuvant != "") {
					this->store(cuvant, i);
					cuvant = "";
				}

			if (cuvant != "" && *it == Text.back()) {
				this->store(cuvant, i);
			}

		}
	}
}

void Glosar::store(const string& cheie, int val)
{
	if (allWords.cauta(cheie, val) == true) {
		return;
	}
	allWords.adauga(cheie, val);
}


int Glosar::cauta(const string & cheie, int val[])
{
	int nr = this->allWords.valorile(cheie, val);
	return nr;
}

int Glosar::citire(string text[])
{
	std::ifstream fi("carte.in");
	if (!fi.is_open()) {
		throw std::exception("Nu s-a putut deschide fisierul");
	}
	int nr = 0;
	string camp;
	while (std::getline(fi, camp)) {
		text[nr] = camp;
		nr++;
	}
	return nr;
}
void Glosar::stergere(const string & cuv,int linie)
{
	this->allWords.sterge(cuv, linie);
}
int JSHash(const string& str) {

	int hash = 1315423911;

	for (std::size_t i = 0; i < str.length(); i++)
	{
		hash ^= ((hash << 5) + str[i] + (hash >> 2));
	}

	return (hash & 0x7FFFFFFF) % 100;
}
