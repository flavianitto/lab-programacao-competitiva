#include<bits/stdc++.h>
using namespace std;

long int encontra(string s1, string s2)
{
    long int a[7000][7000];
    long int i, j;
    for(i=0; i<=s1.length(); i++)
    {
        for(j=0; j<=s2.length(); j++)
        {
            if(i==0 || j==0)
            {
                a[i][j]=0;
            }
            else if(s1[i-1] == s2[j-1])
            {
                a[i][j]=a[i-1][j-1]+1;
            }
            else
            {
                a[i][j]=max(a[i-1][j], a[i][j-1]);
            }
        }
    }
    return s1.length()-a[s1.length()][s2.length()];
}

int main()
{
    long int t, i;
    string s1, s2;
    cin >> t;
    for(i=0; i<t; i++)
    {
        cin >> s2;
        s1 = s2;
        reverse(s1.begin(), s1.end());
        long int res = encontra(s1,s2);
        cout << res << endl;
    }
    return 0;
}