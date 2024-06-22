#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    while(cin >> a >> b >> c){
        if(!a&&!b&&!c) break;
        vector<vector<bool>> v(a, vector<bool>(b,true));
        int x1,x2,y1,y2;
        for(int i=0; i<c; i++){
            cin >> x1 >> y1 >> x2 >> y2;
            x1--; x2--; y1--; y2--;
            int beg_x = min(x1,x2);
            int beg_y = min(y1,y2);
            int end_x = max(x1,x2)+1;
            int end_y = max(y1,y2)+1;
            for(int j=beg_x; j<end_x; j++)
                for(int k=beg_y; k<end_y; k++)
                    v[j][k] = false;
        }
        int total = 0;
        for(int i=0; i<a; i++)
            for(int j=0; j<b; j++)
                total += v[i][j];
        if(!total) cout << "There is no empty spots.\n";
        else if(total == 1) cout << "There is one empty spot.\n";
        else cout << "There are " << total << " empty spots.\n";
    }
    
    return 0;
}