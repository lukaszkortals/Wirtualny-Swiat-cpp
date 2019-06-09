#pragma once
#include "Zwierze.h"

class Owca : public Zwierze {
public:
	char rysowanie();
	Owca(int x, int y, Swiat *swiat);
	~Owca();
};

