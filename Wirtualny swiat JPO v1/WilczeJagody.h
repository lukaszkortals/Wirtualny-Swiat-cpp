#pragma once
#include "Roslina.h"

class WilczeJagody : public Roslina {
public:
	char rysowanie();
	void reakcja(Organizm* napastnik);
	WilczeJagody(int x, int y, Swiat *swiat);
	~WilczeJagody();
};