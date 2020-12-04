#pragma once

#include "De.h"

class DeHisto : public De
{
private:
	int tab[7];
	int nbVal;

public:
	DeHisto();
	//void jet();
	void jet(int n);

	int * getHisto();
	int getNbVal() {
		return nbVal;
	}

	virtual void operator++(int);
};

