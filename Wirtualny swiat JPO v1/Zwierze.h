#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {

public:
	void akcja();
	void reakcja(Organizm *napastnik);
	void zjedz(Organizm *roslina);
	void kolizja(int drugiX, int drugiY);
	void rozmnarzanie(Organizm *drugi);
};
