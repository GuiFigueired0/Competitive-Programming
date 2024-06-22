#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b, count_case = 0;
    while(cin >> n){
        if(!n) break;
        int count = 0;
        map<int, int> m;
        vector<vector<int>> v(30, vector<int>(30,1000000000));
        f(i,n) {
            cin >> a >> b;
            if(!m.count(a)) m[a] = count++;
            if(!m.count(b)) m[b] = count++;
            int x = m[a], y = m[b];
            v[x][y] = v[y][x] = 1;
        }
        f(i, count) v[i][i] = 0;
        // floyd
        f(k,count)
            f(i,count)
                f(j, count)
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
        while(cin >> a >> b){
            if(!a&&!b) break;
            int x = m[a], total = 0;
            f(i, count) 
                if(v[x][i]>b) total++;
            cout << "Case " << ++count_case << ": " << total;
            cout << " nodes not reachable from node " << a << " with TTL = " << b << ".\n";
        }
    }
    
    return 0;
}