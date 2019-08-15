#include <stdio.h>
#include <string>
#include <algorithm>

using namespace std;

int n;
int cart[20][20];
bool check[20][20] = { true, };
int sum = 0;

struct _t {
	int value;
	int ord;
};

_t row[2000];

bool sf(_t a, _t b)
{
	return a.value < b.value;
}

void input()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &cart[i][j]);
		}
	}

}

void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", cart[i][j]);
		}
		puts("");
	}
}

void max_order()
{
	for (int i = 0; i < n; i++)
	{
		row[i].ord = i;
		row[i].value = 0;
		for (int j = 0; j < n; j++)
		{
			row[i].value += cart[j][i];
		}
	}
	sort(row, row + n, sf);
}


// void remake(int n, int a)	
// {
// 	for(int i=0;i<n;i++)
// 	{
// 		if(i==a)
// 		{
// 			continue;
// 		}
// 		for(int j=0;j<n;j++)
// 		{}
// 	}
// }

void disable(int a)
{
	for (int i = 0; i < n; i++)
	{
		cart[i][a] = 0;
		cart[a][i] = 0;
	}
}

void boost(int a)
{
	for (int i = 0; i < n; i++)
	{
		sum += cart[a][i];
	}
}

void exp()
{
	for (int i = 0; i < n; i++)
	{
		max_order();
		int a = row[i].ord;
		
		boost(a);
		
		disable(a);
		print();
		puts("===================");
	}

}

int main()
{
	input();
	//print();
	exp();
	printf("%d\n", sum);
	return 0;
}
