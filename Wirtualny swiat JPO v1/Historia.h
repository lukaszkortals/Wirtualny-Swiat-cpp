#pragma once
//#include <list>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Historia {
	vector <string> _zdarzenia;
public:
	void dodajZdarzenie(string noweZdarzenie);
	void wypiszCalosc();
	Historia();
	~Historia();
};

