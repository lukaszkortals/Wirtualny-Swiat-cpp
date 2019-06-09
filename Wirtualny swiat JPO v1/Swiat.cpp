#include "stdafx.h"
#include "Swiat.h"
#include "Owca.h"
#include "Wilk.h"
#include "Lis.h"
#include "Guarana.h"
#include "Mysz.h"
#include "Trawa.h"
#include "WilczeJagody.h"
#include "Kret.h"
#include <cstdlib>
#include <windows.h>
#include <conio.h>

void Swiat::zbudujSwiat() {
	for (int i = 0; i < this->_iloscOrganizmowStart; i++) {
		for (int j = 0; j < 5000000; j++) ;
		string gatunek = this->losujGatunek();
		int polozenieX;
		int polozenieY;
		do {
			polozenieX = this->losujX();
			polozenieY = this->losujY();
		} while (czyWolne(polozenieX, polozenieY)==false);
		dodajPoStringu(polozenieX, polozenieY, gatunek);
	}
	this->getHistoriaSwiata()->wypiszCalosc();
	this->rysujSwiat();
	this->wypiszLegende();
}

void Swiat::wykonajTure() {
	if (this->getIloscOrganizmow() < 1) 
		this->zbudujSwiat();
	else {
		this->przygotujKolejke();
		int max = this->getRozmiarX()*this->getRozmiarY();
		for (int i = 0; i < max; i++) {
			Organizm *tmp = _kolejka[i];
			if (!_kolejka[i] == NULL && !_kolejka[i]->getCzyRobilRuch()) {
				_kolejka[i]->akcja();
			};
		}
		system("cls");
		this->getHistoriaSwiata()->wypiszCalosc();
		this->rysujSwiat();
		this->wypiszLegende();
	}
}

void Swiat::rysujSwiat() {
	cout << "+";
	for (int d = 0; d < _xRozmiar; d++) cout << "-";
	cout << "+\n";
	for (int j = 0; j < _yRozmiar; j++) {
		cout << "|";
		for (int i = 0; i < _xRozmiar; i++) {
			if (this->_organizmy[i][j] == NULL) cout << " ";
			else cout << *_organizmy[i][j];
		}
		cout << "|\n";
	}
	cout << "+";
	for (int d = 0; d < _xRozmiar; d++) cout << "-";
	cout << "+\n";
}

void Swiat::wypiszLegende() {
	for (int i = 0; i < 8; i++) {
		cout << *_wzoryOrganizmow[i] << " - " << this->_wzoryOrganizmow[i]->getGatunek();
		if (i % 2 == 0) cout << "\t";
		else cout << "\n";
	}
}

void Swiat::przygotujKolejke() {
	int max = this->getRozmiarX()*this->getRozmiarY();
	for (int i = 0; i < max; i++) {
		if (!_kolejka[i] == NULL) {
			Organizm *tmp = _kolejka[i];
			if (_kolejka[i]->getCzyZywy()) {
				_kolejka[i]->setRobilRuch(false);
				_kolejka[i]->setCzasZycia(_kolejka[i]->getCzasZycia() + 1);
			}
			else {
				_kolejka[i]->~Organizm();
				_kolejka[i] = NULL;
			}
		}
	}
	sort(&_kolejka[0], &_kolejka[0] + max, &Swiat::porownajOrganizmy);
}

bool Swiat::porownajOrganizmy(Organizm *lewy, Organizm *prawy) {
	if (lewy == NULL) return false;
	if (prawy == NULL) return true;

	if (lewy->getInicjatywa() > prawy->getInicjatywa()) return true;
	else if (lewy->getInicjatywa() < prawy->getInicjatywa()) return false;
	else {
		if (lewy->getId() < prawy->getId()) return true;
		else return false;
	}
}

void Swiat::dodajPoStringu(int x, int y, string gatunek) {
	if (gatunek == "Wilk") this->_organizmy[x][y] = new Wilk(x, y, this);
	else if (gatunek == "Owca") this->_organizmy[x][y] = new Owca(x, y, this);
	else if (gatunek == "Lis") this->_organizmy[x][y] = new Lis(x, y, this);
	else if (gatunek == "Mysz") this->_organizmy[x][y] = new Mysz(x, y, this);
	else if (gatunek == "Kret") this->_organizmy[x][y] = new Kret(x, y, this);
	else if (gatunek == "Trawa") this->_organizmy[x][y] = new Trawa(x, y, this);
	else if (gatunek == "Guarana") this->_organizmy[x][y] = new Guarana(x, y, this);
	else if (gatunek == "Wilcze jagody") this->_organizmy[x][y] = new WilczeJagody(x, y, this);
	else return;

	int max = this->getRozmiarX()*this->getRozmiarY();
	for (int i = 0; i < max; i++) {
		if (_kolejka[i] == NULL) {
			_kolejka[i] = _organizmy[x][y];
			break;
		};
	}
}

void Swiat::wypiszKolejke() {	
	int max = this->getRozmiarX()*this->getRozmiarY();
	for (int i = 0; i < max; i++) {
		if (this->_kolejka[i] != NULL) cout << this->_kolejka[i]->rysowanie();
		else cout << "|";
	}
	cout << "\n";
}

void Swiat::stworzWzoryOrganizmow() {
	string wzoryGatunkow[8] = { "Wilk", "Owca", "Mysz", "Lis", "Kret", "Trawa", "Guarana", "Wilcze jagody" };
	string tenGatunek;
	for (int i = 0; i < 8; i++) {
		tenGatunek = wzoryGatunkow[i];
		if (tenGatunek == "Wilk") this->_wzoryOrganizmow.push_back(new Wilk(-1, -1, this));
		else if (tenGatunek == "Owca") this->_wzoryOrganizmow.push_back(new Owca(-1, -1, this));
		else if (tenGatunek == "Lis") this->_wzoryOrganizmow.push_back(new Lis(-1, -1, this));
		else if (tenGatunek == "Mysz") this->_wzoryOrganizmow.push_back(new Mysz(-1, -1, this));
		else if (tenGatunek == "Kret") this->_wzoryOrganizmow.push_back(new Kret(-1, -1, this));
		else if (tenGatunek == "Trawa") this->_wzoryOrganizmow.push_back(new Trawa(-1, -1, this));
		else if (tenGatunek == "Guarana") this->_wzoryOrganizmow.push_back(new Guarana(-1, -1, this));
		else if (tenGatunek == "Wilcze jagody") this->_wzoryOrganizmow.push_back(new WilczeJagody(-1, -1, this));
	}
	this->setIloscOrganizmow0();
	this->setIloscOrganizmowAktualna0();
}

string Swiat::losujGatunek() {
	
	vector<Organizm>::size_type sz = this->_wzoryOrganizmow.size();
	int losowa = rand() % 8;
	return this->_wzoryOrganizmow[sz - losowa - 1]->getGatunek();
}

Swiat::Swiat(int xRozmiar, int yRozmiar, int iloscOrganizmow) : _xRozmiar(xRozmiar), _yRozmiar(yRozmiar), _iloscOrganizmowStart(iloscOrganizmow) {
	_iloscOrganizmowAktualna = 0;
	_iloscOrganizmow = 0;
	_kolejka = new Organizm *[_xRozmiar * _yRozmiar];
	for (int i = 0; i <_xRozmiar * _yRozmiar; i++) {
		_kolejka[i] = NULL;
	}
	this->_historiaSwiata = new Historia();
	this->_organizmy = new Organizm **[_yRozmiar];
	for (int i = 0; i < _yRozmiar; i++) {
		this->_organizmy[i] = new Organizm *[_xRozmiar];
		for (int j = 0; j < _xRozmiar; j++) {
			this->_organizmy[i][j] = NULL;	
		}
	}
	stworzWzoryOrganizmow();
}

Swiat::Swiat() {
	_xRozmiar = 20;
	_yRozmiar = 20;
	_iloscOrganizmowStart = 20;
	_iloscOrganizmowAktualna = 0;
	_iloscOrganizmow = 0;
	_kolejka = new Organizm *[_xRozmiar * _yRozmiar];
	for (int i = 0; i <_xRozmiar * _yRozmiar; i++) {
		_kolejka[i] = NULL;
	}
	this->_historiaSwiata = new Historia();
	this->_organizmy = new Organizm **[_yRozmiar];
	for (int i = 0; i < _yRozmiar; i++) {
		this->_organizmy[i] = new Organizm *[_xRozmiar];
		for (int j = 0; j < _xRozmiar; j++) {
			this->_organizmy[i][j] = NULL;
		}
	}
	stworzWzoryOrganizmow();
}

Swiat::~Swiat() {
	//TODO zaimpolementowac destruktor
}

int Swiat::losujX() {
	return rand() % this->getRozmiarX();
}

int Swiat::losujY() {
	return rand() % this->getRozmiarY();
}

Organizm* Swiat::getOrganizmPoXiY(int x, int y) {
	return this->_organizmy[x][y];
}

void Swiat::setOrganizmNaPole(Organizm * ten, int x, int y) {
	this->_organizmy[x][y] = ten;
}

void Swiat::setZwolnijPole(int x, int y) {
	this->_organizmy[x][y] = NULL;
}

int Swiat::getIloscOrganizmowAktualna() {
	return this->_iloscOrganizmowAktualna;
}
void Swiat::setDiffIloscOrganizmowAktualna(int zmiana) {
	this->_iloscOrganizmowAktualna += zmiana;
}
int Swiat::getIloscOrganizmow() {
	return this->_iloscOrganizmow;
}
void Swiat::setIloscOrganizmowPlus1() {
	this->_iloscOrganizmow++;
}
void Swiat::setIloscOrganizmow0() {
	this->_iloscOrganizmow = 0;
}
void Swiat::setIloscOrganizmowAktualna0() {
	this->_iloscOrganizmowAktualna = 0;
}
Historia * Swiat::getHistoriaSwiata() {
	return this->_historiaSwiata;
}
int Swiat::getCzasTura() {
	return this->_czasTura;
}
int Swiat::getRozmiarX() {
	return this->_xRozmiar;
}
int Swiat::getRozmiarY() {
	return this->_yRozmiar;
}
bool Swiat::czyWolne(int x, int y) {
	if (this->_organizmy[x][y] == NULL) return true;
	else return false;
}

