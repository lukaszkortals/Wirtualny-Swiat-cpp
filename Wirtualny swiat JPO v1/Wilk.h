#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze {
public:
	char rysowanie();
	Wilk(int x, int y, Swiat *swiat);
	~Wilk();
};
