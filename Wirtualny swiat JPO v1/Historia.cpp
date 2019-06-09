#include "stdafx.h"
#include "Historia.h"

using namespace std;

void Historia::dodajZdarzenie(string noweZdarzenie) {
	//noweZdarzenie = to_string(this->_zdarzenia.size() + 1) + ". " + noweZdarzenie;
	this->_zdarzenia.push_back(noweZdarzenie);
}

void Historia::wypiszCalosc() {
	//vector <string>::iterator X;
	while (this->_zdarzenia.size() > 10) {
		_zdarzenia.erase(_zdarzenia.begin());
	}
	vector<string>::iterator i;
	for (i = this->_zdarzenia.begin()   ; i != this->_zdarzenia.end()   ; i++) {
		cout << *i;
		
	}
}

Historia::Historia()  {
}

Historia::~Historia() {
}
