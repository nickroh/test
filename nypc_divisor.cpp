#include <stdio.h>

int A, B;
int sum = 0;

void input()
{
	scanf("%d %d", &A, &B);
}

void calculate(int a)
{
	int i;
	for ( i = 1; i * i < a; i++)
	{
		if (a%i == 0)
		{
			sum=sum+2;
		}
	}
	if(i * i == a)
	{
		sum++;
	}
}

int main()
{
	input();
	for (int i = A; i <= B; i++)
	{
		calculate(i);
	}
	printf("%d", sum);
	return 0;
}
