#include <bits/stdc++.h>
using namespace std;

bool ordem(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
    if(a.first == b.first)
        if(a.second.first == b.second.first)
            return a.second.second < b.second.second;
        else return a.second.first < b.second.first;
    else return a.first > b.first;
}

void calculaOrdem(const map<int, map<int, pair<int, bool>>> &m, vector<pair<int,pair<int,int>>> &v){
    for(auto &player: m){
        int n = 0;
        int total = 0; 
        for(auto &question: player.second){
            if(question.second.second){
                n++;
                total += question.second.first;
            }
        }
        v.emplace_back(n, make_pair(total, player.first));
    }
    sort(v.begin(), v.end(), ordem);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    string str;
    getline(cin, str);
    int a, b, c;
    char d;
    bool first = true;
    while(n--){
        if(first) first = false;
        else cout << '\n';
        map<int, map<int, pair<int, bool>>> m; 
        while(getline(cin, str)){
            if(str.empty()) break; 
            stringstream s(str);
            s >> a >> b >> c >> d;
            m[a];
            if(d=='R'||d=='U'||d=='E')continue;
            if(m[a][b].second) continue;
            if(d=='C'){
                m[a][b].first += c;
                m[a][b].second = true;
            } else m[a][b].first += 20;
        }
        vector<pair<int,pair<int,int>>> v;
        calculaOrdem(m, v);
        for(auto &player: v)
            cout << player.second.second << ' ' << player.first << ' ' << player.second.first << '\n';
    }
    
    return 0;
}