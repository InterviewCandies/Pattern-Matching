#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
void Init(string & t, vector<int> & p) {
    for (int i = 1; i < t.size(); i++) {
        int j = p[i-1];
        while (j > 0 && t[i] != t[j]) 
          j = p[j-1];
        if (t[i] == t[j]) j++;
        p[i] = j;   
    }    
}
vector<int> KMP(string & s, string & t) {
    vector<int> p (t.size(), 0);
    vector<int> pos;
    Init(t, p);
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        while (j > 0 && s[i] != t[j])
            j = p[j-1];
        if (s[i] == t[j]) j++;
        if (j == t.size()) pos.push_back(i - t.size() + 1), j = p[j-1];
    }
    return pos;
}
int main() {
    string s = "abdabcabcadabdabcsdsdasfsfasaabdabc";
    string t = "abdabc";
    auto ans = KMP(s, t);
    for(auto it : ans) cout << it << " ";
    return 0;
}