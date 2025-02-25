// OMPSections.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "conio.h"
#include "math.h"
int main()
{
	const int N = 30000;
	int i, nthreads, tid;
	float A[N], B[N], C[N], D[N];
	clock_t start, stop;
	srand(time(0));
	// Random initializations for arrays
	for (i = 0; i < N; i++)
	{
		A[i] = (float)rand() / RAND_MAX;
		B[i] = (float)rand() / RAND_MAX;
		C[i] = (float)rand() / RAND_MAX;
	}
	start = clock();
	tid = omp_get_thread_num();
	if (tid == 0)
	{
		nthreads = omp_get_num_threads();
		printf("Number of threads = %d\n", nthreads);
	}
	printf("Thread %d starting...\n", tid);
	// Section 1
	printf("Thread %d doing section 1\n", tid);
	for (i = 0; i < N; i++)
	{
		C[i] = cos(A[i]) + sin(B[i]) - sqrt(fabs(A[i] + B[i]));
		printf("Thread %d: C[%d]= %f\n", tid, i, C[i]);
	}
	// Section 2
	printf("Thread %d doing section 2\n", tid);
	for (i = 0; i < N; i++)
	{
		D[i] = sqrt(fabs(A[i] * B[i])) - sin(A[i] * A[i]) / cos(B[i]);
		printf("Thread %d: D[%d]= %f\n", tid, i, D[i]);
	}
	stop = clock();
	printf("Thread %d done.\n", tid);
	printf("The computing time is %.2lf ms\n\n", ((double)(stop - start)));
	printf("Press any key...");
	_getch();
}