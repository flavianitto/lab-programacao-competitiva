#include<bits/stdc++.h>
using namespace std;

int main()
{
    char linha[200005], aux[200005];
    int i, j=0;

    cin >> linha;
    aux[0] = linha[0];
    for(i=1; linha[i]!='\0'; i++)
    {
        if(linha[i] == aux[j])
            j--;
        else
        {
            j++;
            aux[j] = linha[i];
        }
    }
    for(i=0; i<=j; i++)
    {
        cout << aux[i];
    }
    cout << "\n";
}