#include "stdafx.h"
#include "Organizm.h"

ostream& operator<<(ostream & left, Organizm& right) {
	right.wypisz(left);
	return left;
}

void Organizm::wypisz(ostream & out) {
	cout << this->rysowanie();
}

int Organizm::losujPrzesuniecieX() {
	int nowyX = 111;
	int opcje[3] = { -1, 0, 1 };
	
	while (!(nowyX >= 0 && nowyX < 20)) {
		int tmp = (rand() % 3);
		nowyX = this->getPolozenieX() + opcje[tmp];
		if (nowyX >= 0 && nowyX < 20) return nowyX;
	} 
	return nowyX;
}

int Organizm::losujPrzesuniecieY() {
	int nowyY = 111;
	int opcje[3] = { -1, 0, 1 };

	while (!(nowyY >= 0 && nowyY < 20)) {
		int tmp = (rand() % 3);
		nowyY = this->getPolozenieY() + opcje[tmp];
		if (nowyY >= 0 && nowyY < 20) return nowyY;
	} 
	return nowyY;
}

void Organizm::zmienPoleNa(int nowyX, int nowyY) {
	int staryX = this->getPolozenieX();
	int staryY = this->getPolozenieY();
	if (staryX == nowyX && staryY == nowyY) return;
	this->setPolozenieX(nowyX);
	this->setPolozenieY(nowyY);
	this->setRobilRuch(true);
	this->getSwiat()->setOrganizmNaPole(this, nowyX, nowyY);
	this->getSwiat()->setZwolnijPole(staryX, staryY);
	
}

void Organizm::zabij(Organizm * ofiara) {
	ofiara->reakcja(this);
	string noweZdarzenie = this->getGatunek() + " z [" + to_string(this->getPolozenieX() + 1) + " , " + to_string(this->getPolozenieY() + 1) + "] zabija " + ofiara->getGatunek() + " z [" + to_string(ofiara->getPolozenieX() + 1) + " , " + to_string(ofiara->getPolozenieY() + 1) + "]\n";
	this->getSwiat()->getHistoriaSwiata()->dodajZdarzenie(noweZdarzenie);
	ofiara->setZywy(false);
	ofiara->setRobilRuch(true);
	
	ofiara->getSwiat()->setZwolnijPole(ofiara->getPolozenieX(), ofiara->getPolozenieY());
	ofiara->setPolozenieX(-1);
	ofiara->setPolozenieY(-1);
	this->getSwiat()->setDiffIloscOrganizmowAktualna(-1);
}

bool Organizm::operator<( const Organizm &prawy)  {
	if (this->_sila < prawy._sila) return true;
	if (this->_sila  > prawy._sila) return false;
	if (this->_czasZycia < prawy._czasZycia) return true;
	if (this->_czasZycia > prawy._czasZycia) return false;
	if (this->_id < prawy._id) return true;
	if (this->_id > prawy._id) return false;
	return false;
}

bool Organizm::operator==( Organizm *prawy) {
	if (this == NULL || prawy == NULL) return false;
	if (this->_id == prawy->_id) return true;
	else return false;
}

bool Organizm::operator>(const Organizm &prawy) {
	if (this->_sila > prawy._sila) return true;
	if (this->_sila  < prawy._sila) return false;
	if (this->_czasZycia > prawy._czasZycia) return true;
	if (this->_czasZycia < prawy._czasZycia) return false;
	if (this->_id < prawy._id) return true;
	if (this->_id > prawy._id) return false;
	return false;
}

int Organizm::getId() {
	return this->_id;
}
void Organizm::setId(int id) {
	this->_id = id;
}
int Organizm::getSila() {
	return this->_sila;
}
void Organizm::setSila(int sila) {
	this->_sila = sila;
}
int Organizm::getInicjatywa() {
	return this->_inicjatywa;
}
void Organizm::setInicjatywa(int inicjatywa) {
	this->_inicjatywa = inicjatywa;
}
int Organizm::getPolozenieX() {
	return this->_polozenieX;
}
void Organizm::setPolozenieX(int x) {
	this->_polozenieX = x;
}
int Organizm::getPolozenieY() {
	return this->_polozenieY;
}
void Organizm::setPolozenieY(int y) {
	this->_polozenieY = y;
}
int Organizm::getCzasZycia() {
	return this->_czasZycia;
}
void Organizm::setCzasZycia(int czasZycia) {
	_czasZycia = czasZycia;
}
void Organizm::setGatunek(string gatunek) {
	_gatunek = gatunek;
}
string Organizm::getGatunek() {
	return this->_gatunek;
}
bool Organizm::getCzyRobilRuch() {
	return this->_robilRuch;
}
void Organizm::setRobilRuch(bool czyZrobilRuch) {
	this->_robilRuch = czyZrobilRuch;
}
bool Organizm::getCzyZywy() {
	return this->_zywy;
}
void Organizm::setZywy(bool czyZywy) {
	this->_zywy = czyZywy;
}
bool Organizm::getCzyReakcja() {
	return this->_czyReakcja;
}
void Organizm::setCzyReakcja(bool czyReakcja) {
	this->_czyReakcja = czyReakcja;
}
void Organizm::setSwiat(Swiat *swiat) {
	this->_swiat = swiat;
}
Swiat* Organizm::getSwiat() {
	return _swiat;
}
