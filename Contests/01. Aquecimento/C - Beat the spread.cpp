#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, s, d;
    int rs, rd;
    int i;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> s >> d;
        rs = s+d;
        rd = s-d;
        if(rs%2 != 0 || s<d)
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << rs/2 << " " << rd/2 << endl;
        }
    }
}