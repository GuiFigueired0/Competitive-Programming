#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n; 
    string str = "";
    cin.ignore();
    while(n--){
        if(str!="") cout << '\n';
        cin.ignore();
        getline(cin, str);
        stringstream s1(str);
        vector<pair<int,int>> pos;
        vector<string> num;
        int x;
        string s;
        while(s1 >> x)
            pos.emplace_back(x, pos.size());
        getline(cin, str);
        stringstream s2(str);
        while(s2 >> s)
            num.push_back(s);
        sort(pos.begin(), pos.end());
        for(int i=0; i<pos.size(); i++)
            cout << num[pos[i].second] << '\n'; 
    }
    
    return 0;
}