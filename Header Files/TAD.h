#pragma once
#include <string>
using std::string;

#define M 1000

typedef string TCheie;
typedef int TValoare;

class MultiDictionarIterator;

class MultiDictionar {
	friend class MultiDictionarIterator;
private:
	int cp;
	TCheie *chei;
	TValoare *valori;
	int *urm;
	int primliber;

public:
	/*pre: true
	post: MultiMape este dicţionarul cu chei multiple vid (fără elemente)*/
	MultiDictionar();

	/* post: spatiul de memorie alocat a fost eliberat*/
	~MultiDictionar();

	int dispersie(TCheie c);;

	/*actualizeaza primliber*/
	void actualizarePrimLiber();

	/*pre:  cheie Cheie, valoare Valoare,
	post: (se adaugă în dicţionar perechea (cheie, valoare))
	returneaza true daca adaugarea s-a efectuat, false daca nu
	*/
	bool adauga(TCheie cheie, TValoare valoare);

	/*pre: cheie TCheie, valoare TValoare
	post: perechea (cheie, valoare) este ştearsă din dicţionar,
	returneaza true daca s-a efectual stergerea, false daca nu
	*/
	bool sterge(TCheie cheie, TValoare valoare);

	/* pre: cheie Cheie, valoare Valoare din dictionar
	* returneaza pozitia daca a gasit, -1 daca nu
	*/
	int cauta(TCheie cheie, TValoare valoare);

	/* returneaza true daca dictionarul e vid, false daca nu */
	bool vid();

	/* post: cheile e lista cheilor din dictionar
	* returneaza numarul cheilor */
	int cheile(TCheie cheile[]);

	/* returneaza dimensiunea dictionarului(numarul de perechi)*/
	int dim();

	/* pre: cheia exista in dictionar
	* post: valorile contine valorile cheii cheie
	* returneaza numarul valorilor
	*/
	int valorile(TCheie cheie, TValoare valorile[]);


	MultiDictionarIterator* iterator();

	/*returneaza primLiber*/
	int getPrimLiber() {
		return primliber;
	}
};


class MultiDictionarIterator {
	friend class MultiDictionar;
private:
	int curent;
	MultiDictionar* dict;

public:
	/*pre : map este un container
	post : s-a creat iteratorul i pe containerul map, (elementul
	curent din iterator refera `primul' element din container)
	*/
	MultiDictionarIterator(MultiDictionar* map) {
		this->curent = 0;
		dict = map;
	}

	/*post: curent e pozitionat pe primul element din container */
	void prim() {
		curent = 0;
		while (dict->chei[curent] == "") {
			curent++;
		}
	}

	/*post: curent refera `urmatorul' element din container
	fata de cel referit de curent
	*/
	void urmator() {
		do {
			curent++;
		} while (dict->chei[curent] == "" && curent <= M);
	}

	/*pre: iterator
	*post: returneaza true daca curent refera o pozitie valida
	* 		sau false daca nu
	*/
	bool valid() {
		if (curent < M && dict->chei[curent] != "")
			return true;
		return false;
	}

	/* returneaza pozitia elementului curent */
	int getCurent() {
		return curent;
	}

	/*pre : curent este valid (refera un element din container)
	post : returneaza cheia din elementul curent din iteratie'*/
	TCheie getCheie(int i) {
		return dict->chei[i];
	}

	/*pre : curent este valid (refera un element din container)
	post : returneaza valoarea din elementul curent din iteratie'*/
	TValoare getValoare(int i) {
		return dict->valori[i];
	}

	/*returneaza valoarea din vectorul urm de pe pozitia curenta*/
	int getUrm(int i) {
		return dict->urm[i];
	}


} typedef MultiDictionarIterator;
