#pragma once
#include <iostream>
#include "Organizm.h"
#include "Historia.h"
//#include <queue>
#include <vector>
//#include <list>
#include <algorithm>
//#include <boost/iterator/indirect_iterator.hpp>

using namespace std;

class Organizm;
class Swiat {
	int _xRozmiar, _yRozmiar;
	int _czasTura;
	int _iloscOrganizmowStart, _iloscOrganizmowAktualna, _iloscOrganizmow;
	Organizm *** _organizmy;
	Historia *_historiaSwiata;
	vector <Organizm*> _wzoryOrganizmow;
	//typedef vector <Organizm*> _kolejkaRuchowTd;
	//typedef boost::indirect_iterator<_kolejkaRuchowTd::iterator> Adaptor;
	//_kolejkaRuchowTd _kolejkaRuchow;

	//bool porownaj( Organizm *organizm1,  Organizm *organizm2);
	
	//sort(_kolejkaRuchow.front(), _kolejkaRuchow.back(), porownaj);
	
	//priority_queue <Organizm*, vector<Organizm*>, porownaj> _kolejkaRuchow;
	
	//queue <Organizm*> _oczekujace;

	//list <Organizm*> _kolejkaRuchow;

	Organizm **_kolejka;
	
	//list <Organizm*> _cmentarz;
	string losujGatunek();
	void stworzWzoryOrganizmow();
	void wypiszLegende();
	void przygotujKolejke();
	int losujX();
	int losujY();
	//void pochowajZmarlych();
	void wypiszKolejke(); 
	static bool porownajOrganizmy(Organizm *lewy, Organizm *prawy);
public:
	
	Swiat(int xRozmiar, int yRozmiar, int iloscOrganizmow);
	Swiat();
	~Swiat();
	void rysujSwiat();
	void wykonajTure();
	void zbudujSwiat();

	void dodajPoStringu(int x, int y, string gatunek);

	//void zakonczTure();
	Organizm* getOrganizmPoXiY(int x, int y);
	void setOrganizmNaPole(Organizm *ten, int x, int y);
	void setZwolnijPole(int x, int y);
	int getIloscOrganizmowAktualna();
	void setDiffIloscOrganizmowAktualna(int zmiana);
	int getIloscOrganizmow();
	void setIloscOrganizmowPlus1();
	void setIloscOrganizmow0();
	void Swiat::setIloscOrganizmowAktualna0();
	Historia* getHistoriaSwiata();
	int getCzasTura();
	int getRozmiarX();
	int getRozmiarY();
	bool czyWolne(int x, int y);
};
