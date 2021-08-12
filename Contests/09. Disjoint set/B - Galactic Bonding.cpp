#include<bits/stdc++.h>
using namespace std;

double ponto[1000][2];
bool visto[1000];
double distFinal;
int n;

double calcDist(int x, int y)
{
    double dx, dy;
    dx = ponto[x][0] - ponto[y][0];
    dy = ponto[x][1] - ponto[y][1];
    return dx*dx + dy*dy;
}
void visitou(int no)
{
    int i;
    visto[no] = true;
    for(i=0; i<n; i++)
    {
        if(!visto[i] && calcDist(i, no) <= distFinal)
        {
            visitou(i);
        }
    }
}
int contConstelacoes()
{
    int constelacao=0, i;
    for(i=0; i<n; i++)
    {
        if(!visto[i])
        {
            constelacao++;
            visitou(i);
        }
    }
    return constelacao;
}
int main()
{
    int t, i, j;
    cin >> t;
    for(i=1; i<=t; i++)
    {
        double d;
        cin >> n >> d;
        distFinal = d*d;
        
        for(j=0; j<n; j++)
        {
            cin >> ponto[j][0] >> ponto[j][1];
        }
        memset(visto, false, sizeof(visto));
        cout << "Case " << i << ": " << contConstelacoes() << endl;
    }
    return 0;
}