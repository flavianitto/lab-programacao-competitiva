#include<bits/stdc++.h>
using namespace std;

int main ()
{
	int n, i;
    int p[10005], c[10005], atual[10005];
    int answer=1;
	cin >> n;

	for(i=2; i<=n; i++)
	{
		cin >> p[i];
	}
	for(i=1; i<=n; i++)
	{
		cin >> c[i];
	}
	for (i=1; i<=n; i++)
	{
		atual[i] = c[1];
	}
	for (i=2; i<=n; i++)
	{
		if (atual[p[i]] != c[i])
		{
			answer++;
		}
		atual[i] = c[i];
	}
	cout << answer << endl;
	return 0;
 } 