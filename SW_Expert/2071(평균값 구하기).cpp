#include <iostream>
#include <cstdio>
using namespace std;
int t;
int tc = 1;
int main(void)
{
	scanf("%d", &t);
	while (t--)
	{
		double sum = 0;
		int npart = 0;
		double dpart = 0;
		double avg = 0;
		for (int i = 0; i<10; i++)
		{
			double temp;
			scanf("%lf", &temp);
			sum += temp;
		}
		avg = sum / 10;
		npart = (int)avg;
		dpart = avg - npart;
		if (dpart>0.5) npart++;
		printf("#%d %d\n", tc, npart);
		tc++;
	}
}