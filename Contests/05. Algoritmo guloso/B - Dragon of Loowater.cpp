#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> read_vec(int const len)
{
    vector<int> vec(len);

    for (auto& h : vec)
        cin >> h;

    return move(vec);
}

int process(vector<int>& ks, vector<int>& hs)
{
    int cost = 0;

    for (const auto& k : ks)
    {
        if (hs.empty())
            break;

        int smallest_head = hs.back();

        if (k >= smallest_head)
        {
            hs.pop_back();
            cost += k;
        }
    }

    if (hs.empty())
        return cost;
    else
        return 0;
}

int main()
{
    int n, m;

    while (true)
    {
        cin >> n >> m;

        if (n == 0)
            break;

        vector<int> hs = read_vec(n);
        sort(hs.rbegin(), hs.rend());

        vector<int> ks = read_vec(m);
        sort(ks.begin(), ks.end());

        int cost = process(ks, hs);

        if (cost == 0)
            cout << "Loowater is doomed!\n";
        else
            cout << cost << '\n';
    }

    return EXIT_SUCCESS;
}