#include<stdio.h>
#include<stdlib.h>

int n;
int arr[105];
int arr2[105];

int ans = 0;

void input()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr2[i]);
	}

}

void cook()
{

	while (1)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i] >0 && arr[i]-arr2[i]>=0)
			{
				arr[i]=arr[i]-arr2[i];	
			}
			else
			{
				printf("%d", ans);
				exit(0);
			}

		}
		ans++;
	}

}

int main()
{
	input();
	cook();

	printf("%d", ans);
	return 0;
}