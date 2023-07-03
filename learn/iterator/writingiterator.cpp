#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{

#if 0
    vector<int> values{1, 2, 3, 4, 5, 6};

    for (vector<int>::iterator it = values.begin(); it != values.end(); it++)
    {
        cout << *it << " ";
    }

    using ScoreMap = unordered_map<string, int>;
    // using ScoreMapConstIter = ScoreMap::const_iterator;
    ScoreMap map;
    map["one"] = 1;
    map["two"] = 2;
    map["three"] = 3;
    map["four"] = 4;
    cout << endl;

    cout << "first Way " << endl;

    for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
    {
        auto &key = it->first;
        auto &value = it->second;

        cout << key << " = " << value << endl;
    }

    cout << "second Way " << endl;
    for (auto keyVal : map)
    {
        auto &key = keyVal.first;
        auto &value = keyVal.second;

        cout << key << " = " << value << endl;
    }

    cout << "Third Way " << endl;
    for (auto [key, value] : map)
    {
        cout << key << " = " << value << endl;
    }
#endif
}