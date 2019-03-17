#pragma once
#include"glosar.h"

class UI
{
private:
	Glosar & gl;
	int comanda;
	void citire();
public:
	UI(Glosar& gl) :gl{ gl } { citire(); 
		this->printMenu();
	}
	void printMenu();
	~UI() = default;
	void executaComanda();
};

