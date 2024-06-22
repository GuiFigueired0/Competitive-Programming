#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, x;
    int cont = 0;
    while(cin >> a >> b >> c){
        if(!a&&!b&&!c) break; 
        cout << "Sequence " << ++cont << '\n';
        vector<int> cost(a);
        for(int i=0; i<a; i++) cin >> cost[i];
        vector<bool> v(a, false);
        int sum=0, maximum=0;
        for(int i=0; i<b; i++){
            cin >> x; x--;
            if(sum>c) continue;
            v[x] = !v[x];
            if(v[x]) sum += cost[x];
            else sum -= cost[x];
            maximum = max(maximum, sum);
        }
        if(sum>c) cout << "Fuse was blown.\n";
        else {
            cout << "Fuse was not blown.\n";
            cout << "Maximal power consumption was " << maximum << " amperes.\n";
        }
        cout << '\n';
    }
    
    return 0;
}