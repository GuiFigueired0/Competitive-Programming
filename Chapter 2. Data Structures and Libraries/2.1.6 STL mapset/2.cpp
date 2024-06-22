#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ll long long
#define pii pair<int,int>
#define psi pair<string, int>

bool order(psi &a, psi &b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while(true){
        string project = "";
        map<string, set<string>> projects;
        map<string, int> signedUps;
        while(getline(cin, s)){
            if(s == "0") return 0;
            if(s == "1") break;
            if(islower(s[0])) projects[project].emplace(s);
            else {
                project = s;
                projects[project] = set<string>();
            }
        }
        for(auto &key: projects)
            for(auto &name: key.second)
                signedUps[name]++;
        vector<pair<string, int>> output;
        for(auto &key: projects){
            int count = 0;
            for(auto &student: key.second)
                if(signedUps[student]==1) count++;
            output.emplace_back(key.first, count);
        }
        sort(all(output), order);
        for(auto &p: output) 
            cout << p.first << ' ' << p.second << '\n';
    }
}