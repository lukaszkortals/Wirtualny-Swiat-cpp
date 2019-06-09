#pragma once
#include <iostream>
#include <string>
#include "Swiat.h"

using namespace std;

class Swiat;
class Organizm {
	void wypisz(ostream & out = cout);
protected:
	bool _zywy;
	bool _robilRuch;
	bool _czyReakcja;
	int _id;
	int _sila;
	int _inicjatywa;
	int _polozenieX;
	int _polozenieY;
	int _czasZycia;
	string _gatunek;
	int losujPrzesuniecieX();
	int losujPrzesuniecieY();
	Swiat *_swiat;
	void zmienPoleNa(int nowyX, int nowyY);
public:
	virtual void akcja() = 0;
	virtual void reakcja(Organizm* napastnik) = 0;
	virtual void kolizja(int drugiX, int drugiY) = 0;
	virtual char rysowanie() = 0;

	void zabij(Organizm* ofiara);
	
	bool Organizm::operator<(const Organizm &prawy);
	bool Organizm::operator>(const Organizm &prawy);
	bool Organizm::operator==(Organizm *prawy);
	friend ostream& operator<<(ostream &lewy, Organizm &prawy);
	
	int getId();
	void setId(int id);
	int getSila();
	void setSila(int sila);
	int getInicjatywa();
	void setInicjatywa(int inicjatywa);
	int getPolozenieX();
	void setPolozenieX(int x);
	int getPolozenieY();
	void setPolozenieY(int y);
	int getCzasZycia();
	void setCzasZycia(int czasZycia);
	void setGatunek(string gatunek);
	string getGatunek();
	bool getCzyRobilRuch();
	void setRobilRuch(bool czyZrobilRuch);
	bool getCzyZywy();
	void setZywy(bool czyZywy);
	bool getCzyReakcja();
	void setCzyReakcja(bool czyReakcja);
	void setSwiat(Swiat *swiat);
	Swiat* getSwiat();
};
