#include<bits/stdc++.h>
using namespace std;

const int N = 1010;

int main()
{
    //ios_base::sync_with_stdio(0);
    int n, res[N], i, j;
    vector<int> a[N];
    bool aux = false;

    cin >> n;
    for(i=2; i<=n; i++) 
    {
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    for(i=0; i<1010; i++) 
    {
        if(a[i].size()) 
        {
            for(j=a[i].size()-1; j>=0; j--) 
            {
                if(a[a[i][j]].size()) 
                {
                    a[i].pop_back();
                }
            }
            if(a[i].size() < 3)
            {
                aux = true;
            } 
        }
    }
    if(aux)
    { 
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    } 
    return 0;
}