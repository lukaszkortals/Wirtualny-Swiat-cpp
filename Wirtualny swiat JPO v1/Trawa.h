#pragma once
#include "Roslina.h"

class Trawa : public Roslina {
public:
	char rysowanie();
	Trawa(int x, int y, Swiat *swiat);
	~Trawa();
};