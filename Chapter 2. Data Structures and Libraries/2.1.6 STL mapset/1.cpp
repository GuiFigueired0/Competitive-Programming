#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ll long long
#define pii pair<int,int>

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string s;
    cin >> n;
    cin.ignore();
    cin.ignore();
    while(n--){
        double total = 0;
        map<string, int> m;
        while(getline(cin, s)){
            if(s.empty()) break;
            m[s]++; total++;
        }
        for(auto &key: m){
            double value = (double)key.second/total*100;
            cout << key.first << ' ';
            cout << fixed << setprecision(4) << value << '\n';
        }
        if(n) cout << '\n';
    }
    
    return 0;
}