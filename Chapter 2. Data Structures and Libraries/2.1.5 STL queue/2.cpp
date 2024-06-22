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
    int n, a, b, c, d;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        vector<int> out(c);
        queue<int> left, right;
        vector<bool> v1(c, false), v2(c, false);
        f(i,c) {
            cin >> d;
            cin.ignore(); 
            cin >> s;
            if(s=="left") {
                left.push(d);
                v1[i] = true;
            } 
            else {
                right.push(d);
                v2[i] = true;
            }
        }
        int count1 = 0, count2 = 0, time = 0;
        bool side = true;
        while(!left.empty()||!right.empty()){
            if(side&&(left.empty()||(left.front()>time&&!right.empty()&&left.front()>right.front()))) {
                time = max(time, right.front())+b; side = !side;
            } else if(!side&&(right.empty()||(right.front()>time&&!left.empty()&&right.front()>left.front()))) {
                time = max(time, left.front())+b; side = !side;
            }
            int count = 0;
            if(side){
                if(!left.empty()){
                    time = max(time,left.front());
                    while(count<a&&!left.empty()&&left.front()<=time){
                        count++;
                        left.pop();
                    }
                }
                f(i,count) {
                    while(!v1[count1]) count1++;
                    out[count1++] = time + b;
                }
            } else {
                if(!right.empty()){
                    time = max(time,right.front());
                    while(count<a&&!right.empty()&&right.front()<=time){
                        count++;
                        right.pop();
                    }
                }
                f(i,count) {
                    while(!v2[count2]) count2++;
                    out[count2++] = time + b;
                }
            }
            side = !side; time += b;
        }
        f(i,c) cout << out[i] << '\n';
        if(n) cout << '\n';
    }
    
    return 0;
}