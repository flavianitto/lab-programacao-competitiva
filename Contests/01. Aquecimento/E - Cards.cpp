#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, i;
    int cont0=0, cont1=0;
    string binario;
    cin >> n;
    cin >> binario;
    for(i=0; i<n; i++)
    {
        if(binario[i] == 'z')
            cont0++;
        else if(binario[i] == 'n')
            cont1++;
    }
    while(cont1 != 0)
    {
        cout << 1 << " ";
        cont1--;
    }
    while(cont0 != 0)
    {
        cout << 0 << " ";
        cont0--;
    }
}