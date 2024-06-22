#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define rall() v.rbegin(), v.rend()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--){
        int a, b;
        string s;
        cin >> a >> b;
        cin.ignore();
        vector<pair<int, pair<int,string>>> v;
        f(i,b) {
            cin >> s;
            int total = 0;
            map<char,int> m;    
            for(int j=a-1; j>=0; j--) {
                char c = s[j];
                m[c]++;
                if (c>'G') total += m['G'];
                if (c>'C') total += m['C'];
                if (c>'A') total += m['A'];
            }
            v.emplace_back(total, make_pair(i,s));
        }
        sort(all(v));
        for(auto &x: v) cout << x.second.second << '\n';
        if(n) cout << '\n';
    }
    
    return 0;
}