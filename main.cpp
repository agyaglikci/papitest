/*
 * main.cpp
 *
 *  Created on: Feb 7, 2016
 *      Author: agy
 */

#include "main.h"
#include "psc.h"

using namespace std;

int main ()
{
	long sum = 0;
	start_PAPI();
	for (int i = 1 ; i <= NUM_OF_ANALYSIS ; i++){
		sum += fibonacci(i);
		//cout << "fib("<< i << "): " << fibonacci(i) << endl;
		read_PAPI(i-1);
		//report_PAPI(i-1);
	}
	report_PAPI(-1);
	std::cout << "sum: " << sum << std::endl;

	return 0;
}

int fibonacci(int i)
{
	int a = 0, b = 1, c = 1;

	if (i < 1)
	{
		return -1;
	}
	else if (i < 3)
	{
		return i - 1;
	}
	else {
		for (i=i-3 ; i > 0 ; i--)
		{
			a = b;
			b = c;
			c = a + b;
		}
		return c;
	}
}
