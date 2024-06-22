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
    while(cin >> n){
        if(!n) break;
        vector<int> v(n);
        f(i,n) cin >> v[i];
        sort(all(v));
        /*
        printf("%d", v[0]);
        for(int i=1; i<n; i++) printf(" %d", v[i]);
        printf("\n");
        */
        cout << v[0];
        for(int i=1; i<n; i++) cout << ' ' << v[i];
        cout << '\n';
    }
    
    return 0;
}