#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int n, a, b, c;
    cin >> n;
    while(n--){
        cin >> a >> b; a*=100;
        queue<int> left, right;
        f(i,b) {
            cin >> c;
            cin.ignore(); 
            cin >> s;
            if(s=="left") left.push(c);
            else right.push(c);
        }
        int count = 0;
        bool side = true;
        while(!left.empty()||!right.empty()){
            int size = 0;
            if(side){
                while(!left.empty()&&size+left.front()<a){
                    size += left.front(); 
                    left.pop();
                }
            } else {
                while(!right.empty()&&size+right.front()<a){
                    size += right.front(); 
                    right.pop();
                }
            }
            side = !side; count++;
        }
        cout << count << '\n';
    }
    
    return 0;
}