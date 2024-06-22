#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s1, s2;
    map<string, set<string>> m;
    while(n--){
        cin >> s1;
        getline(cin, s2);
        m[s1].insert(s2);
    }
    for(auto elem: m){
        cout << elem.first << ' ' << elem.second.size() << '\n';
    }
    
    return 0;
}