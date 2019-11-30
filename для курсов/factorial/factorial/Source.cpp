#include <iostream>
#include <cmath>

using namespace std;


	int Factorial(int x)
	{
		if (x == 0)
			return 1;
		if (x < 0)
			return 1;
		return x * Factorial(x - 1);
	}


int main()
{

}

