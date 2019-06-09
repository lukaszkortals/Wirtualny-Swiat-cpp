#pragma once
#include "Zwierze.h"

class Lis : public Zwierze {
public:
	char rysowanie();
	void akcja();
	Lis(int x, int y, Swiat *swiat);
	~Lis();
};

