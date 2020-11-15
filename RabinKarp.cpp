
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int Hash(string p, int k)
{
    int value{0};
    for (int i = 0; i < p.size(); i++)
        value += p[i] * pow(k, i);
    return value;
}

int Rehash(int old_value, int old_hash, int new_value, int k, int pattern_len)
{
    return (old_hash - old_value) / k + new_value * pow(k, pattern_len - 1);
}

bool IsEqual(string &s, int start_s, int end_s, string &t, int start_t, int end_t)
{
    if (end_s - start_s != end_t - start_t)
        return false;
    while (start_s <= end_s && start_t <= end_t)
    {
        if (s[start_s] != t[start_t])
            return false;
        start_s++, start_t++;
    }

    return true;
}
vector<int> RabinKarp(string &s, string &p)
{
    int k = 31;
    vector<int> ans;
    int n = s.size();
    int m = p.size();
    auto p_hash = Hash(p, k);
    auto temp_hash = Hash(s.substr(0, m), k);
    for (int i = 1; i <= n - m + 1; i++)
    {
        if (temp_hash == p_hash && IsEqual(s, i - 1, i + m - 2, p, 0, m - 1))
            ans.push_back(i - 1);
        if (i != n - m + 1)
        {
            temp_hash = Rehash(s[i - 1], temp_hash, s[i + m - 1], k, m);
        }
    }
    return ans;
}

int main()
{
    string s, p;
    cin >> s >> p;
    auto res = RabinKarp(s, p);
    for (auto pos : res)
        cout << pos << " ";
    return 0;
}
