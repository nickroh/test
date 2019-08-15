#include <stdio.h>

int A, B;
int sum = 0;

void input()
{
	scanf("%d %d", &A, &B);
}

void calculate(int a, int b)
{
	int i;
	
	for (i = 1; i <= b; i++)
	{
		if (A%i == 0)
		{
			sum++;
		}
		sum = sum + B / i - A / i;
	}

}

int main()
{
	input();
	calculate(A, B);

	printf("%d", sum);
	return 0;
}
