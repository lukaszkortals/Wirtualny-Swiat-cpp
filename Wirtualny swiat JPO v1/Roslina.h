#pragma once
#include "Organizm.h"

class Roslina : public Organizm {

public:
	void akcja();
	void reakcja(Organizm *napastnik);
	void kolizja(int drugiX, int drugiY);
	void rozprzestrzeniaj();
};

