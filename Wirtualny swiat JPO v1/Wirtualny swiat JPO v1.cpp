// Wirtualny swiat JPO v1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Swiat.h"
#include <Windows.h>

int main(){
	srand(GetTickCount());
	Swiat swiat = Swiat(20, 20, 50);
	while (getchar()!= 'q') {
		swiat.wykonajTure();
	}
    return 0;
}