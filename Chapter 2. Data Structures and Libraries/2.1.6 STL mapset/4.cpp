#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ll long long
#define pii pair<int,int>
#define psi pair<string, int>

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        if(!n) break;
        ll a, b, total = 0;
        multiset<int> s;
        f(i,n){
            cin >> a;
            f(j, a){
                cin >> b;
                s.emplace(b);
            }
            auto beg = s.begin();
            auto end = s.end(); end--;
            total += *end - *beg;
            s.erase(beg); s.erase(end);
        }
        cout << total << '\n';
    }
    
    return 0;
}