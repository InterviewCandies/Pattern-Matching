#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
bool IsMatched(string &a, string &b)
{
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            return false;
    return true;
}
vector<int> Naive(string &s, string &t)
{
    vector<int> pos;
    for (int i = 0; i <= s.size() - t.size(); i++)
    {
        string tmp = s.substr(i, t.size());
        if (IsMatched(tmp, t))
            pos.push_back(i);
    }
    return pos;
}
int main()
{
    string s = "abdabcabcadabdabcsdsdasfsfasaabdabc";
    string t = "abdabc";
    auto ans = Naive(s, t);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}