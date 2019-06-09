#pragma once
#include "Zwierze.h"

class Mysz : public Zwierze {
public:
	char rysowanie();
	void kolizja(int drugiX, int drugiY);
	void probaUcieczni(Organizm* oponent);
	void reakcja(Organizm *napastnik);
	Mysz(int x, int y, Swiat *swiat);
	~Mysz();
};
