#include "TAD.h"


MultiDictionar::MultiDictionar()
{
	valori = new TValoare[M];
	chei = new TCheie[M];
	urm = new int[M];
	cp = M;
	primliber = 0;
	for (int i = 0; i < cp; i++) {
		chei[i] = "";
		urm[i] = -1;
		valori[i] = -1;
	}
}

MultiDictionar::~MultiDictionar()
{
	delete[] valori;
	delete[] chei;
	delete[] urm;

}

int MultiDictionar::dispersie(TCheie c)
{
	int hash = 1315423911;

	for (int i = 0; i < c.length(); i++)
	{
		hash ^= ((hash << 5) + c[i] + (hash >> 2));
	}

	return (hash & 0x7FFFFFFF) % cp;
}

void MultiDictionar::actualizarePrimLiber()
{
	while (primliber <= cp && chei[primliber] != "")
		primliber++;
}

bool MultiDictionar::adauga(TCheie cheie, TValoare valoare)
{
	int rez;
	rez = this->dispersie(cheie);
	if (this->chei[rez] == "") {
		this->chei[rez] = cheie;
		this->valori[rez] = valoare;
		if (this->primliber == rez) {
			actualizarePrimLiber();
		}
		return true;
	}
	else {
		int prec;
		while (rez != -1 && (this->chei[rez] != cheie || this->valori[rez] != valoare)) {
			prec = rez;
			rez = this->urm[rez];
		}
		if (rez != -1) {
			return false; //perechea cheie valoare exista
		}
		else {
			if (this->primliber == this->cp) {
				return false; //depasire
			}
			else {
				this->chei[this->primliber] = cheie;
				this->valori[this->primliber] = valoare;
				this->urm[prec] = this->primliber;
				this->actualizarePrimLiber();
				return true;
			}
		}
	}
}

bool MultiDictionar::sterge(TCheie cheie, TValoare valoare)
{
	int i = this->dispersie(cheie);
	int j = -1;
	while (i != -1 && (this->chei[i] != cheie || this->valori[i] != valoare)) {
		j = i;
		i = this->urm[i];
	}
	if (i == -1) {
		return false; // cheie inexistenta
	}
	else {
		bool gata = false;
		int prec;
		int p;
		do {
			prec = i;
			p = this->urm[i];
			while (p != -1 && this->dispersie(this->chei[p]) != i) {
				prec = p;
				p = this->urm[p];
			}
			if (p == -1)
				gata = true;
			else {
				this->chei[i] = this->chei[p];
				this->valori[i] = this->valori[p];
				j = prec;
				i = p;
			}
		} while (gata != true);
		if (j != -1) {
			this->urm[j] = this->urm[i];
		}
		this->chei[i] = "";
		this->urm[i] = -1;
		this->valori[i] = -1;
		if (i < this->primliber)
			this->primliber = i;
		return true;
	}
}

int MultiDictionar::cauta(TCheie cheie, TValoare valoare)
{
	int rez;
	rez = this->dispersie(cheie);
	while (rez != -1 && (this->chei[rez] != cheie || this->valori[rez] != valoare)) {
		rez = this->urm[rez];
	}
	return rez;
}

bool MultiDictionar::vid()
{
	for (int i = 0; i < M; i++)
		if (this->chei[i] != "")
			return false;
	return true;
}

int MultiDictionar::cheile(TCheie cheile[])
{
	int nr = 0;
	int ok;
	int j;
	int i;
	for (i = 0; i < M; i++) {
		if (this->chei[i] != "") {
			ok = 1;
			j = 0;
			while (j < nr && ok) {
				if (chei[j] == chei[i])
					ok = 0;
				j++;
			}
			if (ok) {
				cheile[nr] = chei[i];
				nr++;
			}
		}
	}
	return nr;
}

int MultiDictionar::dim()
{
	int nr = 0;
	for (int i = 0; i < M; i++) {
		if (this->chei[i] != "")
			nr++;
	}
	return nr;
}

int MultiDictionar::valorile(TCheie cheie, TValoare valorile[])
{
	int nr = 0;
	for (int i = 0; i < M; i++) {
		if (this->chei[i] == cheie) {
			valorile[nr] = this->valori[i];
			nr++;
		}
	}
	return nr;
}

MultiDictionarIterator * MultiDictionar::iterator()
{
	return new MultiDictionarIterator(this);
}
