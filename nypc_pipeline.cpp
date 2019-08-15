#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct coord
{
	int x;
	int y;
};

coord A[200000];

int n, e;

int back_y_small, back_y_big;
int frame_y_small, frame_y_big;

bool frame_state = false;

int frame_change;

int ans = 0;



bool sf(coord a, coord b)
{
	return a.x > b.x;
}

void input()
{
	scanf("%d %d", &n, &e);

		for(int i = 0; i < n; i++)
		{
			scanf("%d %d", &A[i].x, &A[i].y);
		}

	sort(A, A + n, sf);
}

void mapping()
{
	frame_y_big = A[0].y + e;
	frame_y_small = A[0].y - e;
	ans=1;
	for (int i = 0; i < n - 1; i++)
	{
		frame_change = -1;
		back_y_big = A[i + 1].y + e;
		back_y_small = A[i + 1].y - e;

		if (frame_y_big <= back_y_small)
		{
			ans++;
			frame_change = 1;
		}
		if (frame_y_small >= back_y_big)
		{
			ans++;
			frame_change = 1;
		}
		if (A[i].y == A[i+1].y)
		{
			frame_change = 0;
		}
	

		if (frame_change != 1 && frame_change != 0)
		{
			if (frame_y_small <= back_y_small)
			{
				frame_y_small = back_y_small;
			}
			if (frame_y_big >= back_y_big)
			{
				frame_y_big = back_y_big;
			}
		}
		if (frame_change == 1)
		{
			frame_y_small = back_y_small;
			frame_y_big = back_y_big;
		}
		
	}
}

int main()
{
	input();
	mapping();
	printf("%d", ans);
	return 0;
}