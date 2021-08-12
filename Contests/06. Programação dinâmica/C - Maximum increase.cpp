#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i, lerP, lerC;
    int tamC=0, tamM=0;
    cin >> n;
    cin >> lerP;
    for(i=1; i<n; i++)
    {
        cin >> lerC;
        if(lerP < lerC)
        {
            tamC++;
            tamM = max(tamC, tamM);
        }
        else
        {
            tamC=0;
        }
        lerP = lerC;
    }
    cout << tamM + 1;
}