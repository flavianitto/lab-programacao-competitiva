#include<bits/stdc++.h>
#define M 16000000
#define Mn 4000
using namespace std;

int main()
{
    int n, i, j;
    int expi, expj, cont;
    int A[Mn], B[Mn], C[Mn], D[Mn];
    static int E[M], F[M];
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            E[i+n*j] = A[i]+B[j];
            F[i+n*j] = C[i]+D[j];
        }
    }
    sort(E, E+n*n);
    sort(F, F+n*n);

    i=0;
    expi=0;
    j=n*n-1;
    expj=n*n-1;
    cont=0;

    while(i<n*n && j>=0)
    {
        if(expi == i)
        {
            while(expi<n*n && E[expi]==E[i])
            {
                expi++;
            }
        }
        if(expj == j)
        {
            while(expj>=0 && F[expj]==F[j])
            {
                expj--;
            }
        }
        if(E[i]+F[j]==0)
        {
            cont += (expi-i)*(j-expj);
            i=expi;
            j=expj;
        }
        else if(E[i]+F[j]>0)
        {
            j=expj;
        }
        else
        {
            i=expi;
        }
    }
    cout << cont << endl;
    return 0;
}