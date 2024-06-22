#include <bits/stdc++.h>
using namespace std;

class Array{
public:
    string name;
    int beg, nDim, size;
    vector<pair<int, int>> v;
    vector<long long> start;

    void processing(){
        start.resize(v.size());
        start[v.size()-1] = size;
        for(int i=v.size()-2; i>=0; i--)
            start[i] = (v[i+1].second - v[i+1].first +1)*start[i+1];
        
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    map<string, Array> m;
    string s;
    int beg, size, nDim, x, y;
    for(int i=0; i<a; i++){
        cin >> s;
        cin >> beg >> size >> nDim;
        m[s].name = s;
        m[s].beg = beg;
        m[s].size = size;
        m[s].nDim = nDim;
        for(int j=0; j<nDim; j++){
            cin >> x >> y;
            m[s].v.emplace_back(x,y);
        }
        m[s].processing();
    }
    for(int i=0; i<b; i++){
        cin >> s;
        long long pos = m[s].beg;
        cout << s << '[';
        for(int j=0; j<m[s].nDim; j++){
            cin >> x;
            if(j) cout << ", ";
            cout << x;
            pos += m[s].start[j]*(x-m[s].v[j].first);
        }
        cout << "] = " << pos << '\n';
    }
    
    return 0;
}