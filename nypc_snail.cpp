#include<stdio.h>

int n;
int a;
int cnt = 0;

void input()
{
	scanf("%d %d", &n, &a);
}

int main()
{
	input(); 

	int x = 1;
	int y = 1;

	int dx = 1;
	int dy = 1;

	int count = n;
	if (a == 1)
	{
		x = 1;
		y = 1;
		goto EXIT;
	}
	x = 0;
	y = 1;
	while (1)
	{
		
		for (int i = 0; i < count; i++)
		{
			x = x + dx;
			cnt++;
			if (cnt == a)
			{
				goto EXIT;
			}
		}
		dx = dx * -1;
		count--;
		for (int i = 0; i < count; i++)
		{
			y = y + dy;
			cnt++;
			if (cnt == a)
			{
				goto EXIT;
			}
		}
		dy = dy * -1;

	}

EXIT:

	printf("%d %d", x, y);

	return 0;
}