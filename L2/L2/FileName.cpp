// OMPPi.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include "conio.h"
int main()
{
	long long num_steps = 1000000000;
	double step;
	clock_t start, stop;
	double x, pi, sum = 0.0;
	int i;
	step = 1. / (double)num_steps;
	start = clock();
	for (i = 0; i < num_steps; i++)
	{
		x = (i + .5) * step;
		sum = sum + 4.0 / (1. + x * x);
	}
	pi = sum * step;
	stop = clock();
	printf("The value of PI is %15.12lf\n", pi);
	printf("The time to calculate PI was %lf seconds\n", ((double)(stop - start) / 1000.0));
	printf("Press any key...");
	_getch();
	return 0;
}