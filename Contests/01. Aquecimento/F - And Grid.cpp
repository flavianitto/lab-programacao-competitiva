#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    int i, j;
    cin >> h >> w;
    int red[h+1][w+1];
    int blue[h+1][w+1];
    char s;

    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {
            red[i][j]=0;
            blue[i][j]=0;
        }
    }
    for(i=0; i<w; i++)
    {
        red[0][i]=1;
        blue[h-1][i]=1;
    }
    //formando a grade
    for(i=1; i<h-1; i++)
    {
        for(j=0; j<w; j++)
        {
            if(j%2==1)
            {
                red[i][j]=1;
            }
            else
            {
                blue[i][j]=1;
            }
        }
    }
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {
            cin >> s;
            if(s == '#')
            {
                red[i][j]=1;
                blue[i][j]=1;
            }
        }
    }
    //imprimindo vermelho
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {
            if(red[i][j]==1)
            {
                cout << "#";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << endl;
    //imprimindo azul
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {
            if(blue[i][j]==1)
            {
                cout << "#";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
    }
}