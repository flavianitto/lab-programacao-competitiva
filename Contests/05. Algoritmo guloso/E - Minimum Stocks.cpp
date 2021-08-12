/* E - Minimum Stocks */
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

using pair_t = pair<string, int>;

int main() {
    int N = 0;
    cin >> N;

    auto q_comp = [](const auto &a, const auto &b) -> bool { return a.second > b.second; };

    map<string, int> S;

    for (int n = 1; n <= N; n++) {
        int I;
        string X;
        int Y;

        cin >> I >> X;
        if (I != 3) {
            cin >> Y;
        }

        switch (I) {
            case 1:
                S.insert(make_pair(X, Y));
                break;
            case 2:
                S.erase(X);
                S.insert(make_pair(X, Y));
                break;

            case 3:
                priority_queue <pair_t, vector<pair_t>, decltype(q_comp) > Q(q_comp);
                for (auto &v : S) {
                    Q.push(v);
                }

                auto smaller = Q.top();
                cout << smaller.first << " " << n << endl;
                S.erase(smaller.first);
                break;
        }
    }
    return 0;
}