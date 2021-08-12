#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef enum
{
    ADD = '+',
    DELETE = '-',
    COUNT = '?',
} QueryType;

void convert_to_bit_pattern(string& s)
{
    static const unordered_set<char> evens{ '0', '2', '4', '6', '8' };
    for (auto& c : s)
        c = evens.find(c) != evens.end() ? '0' : '1';
    s.insert(0, string(18 - s.length(), '0'));
}

int main()
{
    int q;
    cin >> q;

    unordered_map<string, int> nums; // String pattern -> quantity

    while (q--)
    {
        char query;
        string num;

        cin >> query >> num;
        convert_to_bit_pattern(num);

        switch ((QueryType)query)
        {
        case ADD:
            nums[num]++;
            break;
        case DELETE:
            nums[num]--;
            break;
        case COUNT:
            cout << nums[num] << '\n';
            break;
        }
    }

    return EXIT_SUCCESS;
}