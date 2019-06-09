#pragma once
#include "Roslina.h"

class Guarana : public Roslina {
public:
	char rysowanie();
	void reakcja(Organizm * napastnik);
	Guarana(int x, int y, Swiat *swiat);
	~Guarana();
};

