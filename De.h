#pragma once
class De
{
private:
	static void initializeRandom();
	static bool isInitialized;

	int currentScore;
	int totalScore;

public:
	De();
	De(int n);

	virtual void operator++(int);
	friend void operator+=(int &n, De &de);
	void operator=(int n);
	friend void operator<(int &n, De &de);
};

