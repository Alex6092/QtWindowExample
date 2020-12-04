#include "De.h"
#include <stdlib.h>
#include <time.h>

bool De::isInitialized = false;

void De::initializeRandom()
{
	if (!isInitialized)
	{
		srand(time(NULL));
		isInitialized = true;
	}
}



De::De()
{
	totalScore = 0;
	(*this)++;
}

De::De(int n)
{
	totalScore = 0;
	currentScore = n;
}

void De::operator++(int)
{
	initializeRandom();
	currentScore = rand() % 6 + 1;
	totalScore += currentScore;
}

void operator+=(int &n, De &de)
{
	n = de.currentScore;
}

void De::operator=(int n)
{
	currentScore = n;
}

void operator<(int &n, De &de)
{
	n = de.totalScore;
}