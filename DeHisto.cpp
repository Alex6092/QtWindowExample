#include "DeHisto.h"

DeHisto::DeHisto()
	: De()
{
	nbVal = 0;
}

void DeHisto::operator++(int i)
{
	De::operator++(i);
	int n;
	n += (*this);

	if (nbVal < 7)
	{
		tab[nbVal++] = n;
	}
	else
	{
		for (int i = 0; i < 7 - 1; i++)
		{
			tab[i] = tab[i + 1];
		}

		tab[6] = n;
	}
}

void DeHisto::jet(int n)
{
	for (int i = 0; i < n; i++)
		(*this)++;
}

int * DeHisto::getHisto()
{
	return tab;
}