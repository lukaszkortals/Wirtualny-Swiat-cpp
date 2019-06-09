#include "stdafx.h"
#include "Zwierze.h"


void Zwierze::akcja() {
	int losX = this->losujPrzesuniecieX();
	int losY = this->losujPrzesuniecieY();
	int nowyX =  losX;
	int nowyY =  losY;
	if (!this->_swiat->czyWolne(nowyX, nowyY)) {
		this->kolizja(nowyX, nowyY);
	}
	if (this->getCzyZywy()) this->zmienPoleNa(nowyX, nowyY);
}

void Zwierze::reakcja(Organizm * napastnik) {
	return;
}

void Zwierze::kolizja(int drugiX, int drugiY) {
	Organizm *atakowany = this->_swiat->getOrganizmPoXiY(drugiX, drugiY);
	if (this == atakowany) return;
	if (this->getGatunek() == atakowany->getGatunek()) {
		this->rozmnarzanie(atakowany);
	}
	else {
		if (atakowany->getInicjatywa() == 0) this->zjedz(atakowany);
		else if (this < atakowany) atakowany->zabij(this);
		else this->zabij(atakowany);
	}
}

void Zwierze::zjedz(Organizm * roslina) {
	string noweZdarzenie = this->getGatunek() + " z [" + to_string(this->getPolozenieX() + 1) + " , " + to_string(this->getPolozenieY() + 1) + "] zjada " + roslina->getGatunek() + " z [" + to_string(roslina->getPolozenieX() + 1) + " , " + to_string(roslina->getPolozenieY() + 1) + "]\n";
	this->getSwiat()->getHistoriaSwiata()->dodajZdarzenie(noweZdarzenie);
	roslina->reakcja(this);
	roslina->setZywy(false);
	roslina->setRobilRuch(true);
	roslina->getSwiat()->setZwolnijPole(roslina->getPolozenieX(), roslina->getPolozenieY());	
	roslina->setPolozenieX(-1);
	roslina->setPolozenieY(-1);
	this->getSwiat()->setDiffIloscOrganizmowAktualna(-1);
}

void Zwierze::rozmnarzanie(Organizm *drugi) {
	int nowyX = this->losujPrzesuniecieX();
	int nowyY = this->losujPrzesuniecieY();
	if (this->_swiat->czyWolne(nowyX, nowyY)) {
		this->_swiat->dodajPoStringu(nowyX, nowyY, this->getGatunek());
		string noweZdarzenie = this->getGatunek() + " z [" + to_string(this->getPolozenieX() + 1) + " , " + to_string(this->getPolozenieY() + 1) + "] rozmnaza sie z " + this->getGatunek() + " z [" + to_string(drugi->getPolozenieX() + 1) + " , " + to_string(drugi->getPolozenieX() + 1) + "]\n";
		this->getSwiat()->getHistoriaSwiata()->dodajZdarzenie(noweZdarzenie);
	}
}
