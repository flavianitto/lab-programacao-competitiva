#include<bits/stdc++.h>
using namespace std;

struct Site
{
    int v;
    string url;
};

int main()
{
    Site paginas[100];
    int t, i, j, maior=0;
    cin >> t;
    for(i=0; i<t; i++)
    {
        maior=0;
        for(j=0; j<10; j++)
        {
            cin >> paginas[j].url >> paginas[j].v;
            //encontrando maior v
            if(paginas[j].v > maior)
            {
                maior = paginas[j].v;
            }
        }
        cout << "Case #" << i+1 << ":" << endl;
        for(j=0; j<10; j++)
        {
            if(paginas[j].v == maior)
            {
                cout << paginas[j].url << endl;
            }
        }           
    }
}