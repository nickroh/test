#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;

struct _t {
	string str;
};
_t A[10000];

bool ans[100] = {false,};

void input()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i].str;
	}
}

void check()
{
	for (int i = 0; i < n; i++)
	{
		int cnt = 0;
		int idx=0;
		for (int j = 0; j < A[i].str.size(); j++)
		{
			
			if (A[i].str[j] == '@')
			{
				cnt++; 	
				idx = j;
			}
		}
		
		if ( idx == 0 || idx == A[i].str.size()-1)
		{
			continue;
		}
		if (cnt != 1)
		{
			continue;
		}

		for (int f = 0; f < A[i].str.size(); f++)
		{
			if (((int)A[i].str[f] >= 45 && (int)A[i].str[f] <= 46) || ((int)A[i].str[f] >= 48 && (int)A[i].str[f] <= 57) || ((int)A[i].str[f] >= 64 && (int)A[i].str[f] <= 90) || ((int)A[i].str[f] >= 97 && (int)A[i].str[f] <= 122))
			{
				ans[i] = true;
			}
			else
			{
				ans[i] = false;
				break;
			}
		}
		
	}
}

int main()
{
	
	input();
	/*for (int i = 0; i < n; i++)
	{
		cout << ans[i] << endl;
	}
	puts("-------------------------");*/
	check();
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == 1)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
		/*cout << ans[i] << endl;*/
	}
	return 0;
}