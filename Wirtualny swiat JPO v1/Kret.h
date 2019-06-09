#pragma once
#include "Zwierze.h"

class Kret : public Zwierze {
	int losujX();
	int losujY();
public:
	char rysowanie();
	void akcja();
	Kret(int x, int y, Swiat *swiat);
	~Kret();
};

