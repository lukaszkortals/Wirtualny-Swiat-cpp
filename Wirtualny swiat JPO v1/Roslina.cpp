#include "stdafx.h"
#include "Roslina.h"

void kolizja(int drugiX, int drugiY) {
	return;
}

void Roslina::akcja() {
	rozprzestrzeniaj();
	return;
}

void Roslina::reakcja(Organizm * napastnik) {
	return;
}

void Roslina::kolizja(int drugiX, int drugiY) {
	return;
}

void Roslina::rozprzestrzeniaj() {
	int nowyX = this->losujPrzesuniecieX();
	int nowyY = this->losujPrzesuniecieY();
	if (this->_swiat->czyWolne(nowyX, nowyY)) {
		this->_swiat->dodajPoStringu(nowyX, nowyY, this->getGatunek());
		//string noweZdarzenie = this->getGatunek() + " z [" + to_string(this->getPolozenieX() + 1) + " , " + to_string(this->getPolozenieY() + 1) + "] rozprzestrzenia sie na [" + to_string(nowyX) + " , " + to_string(nowyY) + "]\n";
		//this->getSwiat()->getHistoriaSwiata()->dodajZdarzenie(noweZdarzenie);
	}
}
