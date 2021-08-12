#include<bits/stdc++.h>
using namespace std;

#define tam 1000000+1
int s[tam];  

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x, maior;
    cin >> n;
    maior=-1;
    while(n--)
    {
        cin >> x;
        if(!s[x-1])
        {
            s[x]=1;
        }
        else
        {
            s[x] = s[x-1]+1;
        }
        if(s[x] > maior)
        {
            maior = s[x];
        }
    }
    cout << maior << endl;
    return 0;
}