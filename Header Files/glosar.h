#pragma once
#include"TAD.h"
#include<string>
using std::string;

class Glosar
{
private:
	MultiDictionar allWords;
	//MultiDictionarIterator it{&allWords};
	void loadfromfile();
	void store(const string& cheie, int val);
public:
	//MultiDictionarIterator getIterator() {
		//return this->it;
	//}
	MultiDictionar& getAll() {
		return this->allWords;
	}
	Glosar() { loadfromfile(); }
	int cauta(const string& cheie, int val[]);
	int citire(string text[]);
	void stergere(const string& cuv,int linie);
};

