#include <stdio.h>

int n;
int hp;
int max_hp;
int ans;
int arr[105][2];

void input()
{
	scanf("%d %d",&hp,&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&arr[i][0],&arr[i][1]);
	}

}

void one(int a)
{
	hp=hp-a;
}

void two(int a)
{
	hp=hp+a;
	if(hp>max_hp)
	{
		max_hp=hp;
	}
}

void three(int a)
{
	hp=hp+a;
	max_hp=hp;
}

void game()
{
	max_hp=hp;
	for(int i=0;i<n;i++)
	{
		if(arr[i][0]==1)
		{
			one(arr[i][1]);
		}
		if(arr[i][0]==2)
		{
			two(arr[i][1]);
		}
		if(arr[i][0]==3)
		{
			three(arr[i][1]);
		}

	}

}

int main()
{
	input();
	game();
	printf("%d",max_hp);
	return 0;
}