
#include <stdio.h>

int n;
int m;
int b;

int ans = 0;

int current = 0;

int travel[305][2];
int um_status[305] = { 0, };

void input()
{
	scanf("%d %d %d", &n, &m, &b);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &travel[i][0], &travel[i][1]);
	}
	current = b;
}

void move()
{
	for (int i = 0; i < m; i++)
	{
		if (travel[i][1] == 1)
		{
			if (um_status[current] > 0)
			{
				um_status[travel[i][0]]++;
				um_status[current]--;
			}
			else
			{
				ans++;
				um_status[travel[i][0]]++;
			}
		}
		current = travel[i][0];
	}
}

int main()
{
	input();
	move();

	printf("%d", ans);
	return 0;
}