#include <bits/stdc++.h>
using namespace std;

int ganhou(vector<vector<char>> &v, int x, bool vertical, char c){
    if(vertical)
        if(v[1][x]==v[2][x]&&v[1][x]==v[0][x]&&v[1][x]==c)
            return 1;
    else 
        if(v[x][1]==v[x][2]&&v[x][1]==v[x][0]&&v[x][1]==c)
            return 1;
    return 0;
}

int ganhouDiagonal(vector<vector<char>> &v, char c){
    if(v[1][1]==v[2][2]&&v[1][1]==v[0][0]&&v[1][1]==c)
        return 1;
    if(v[1][1]==v[0][2]&&v[1][1]==v[2][0]&&v[1][1]==c)
        return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while(n--){
        map<char, int> m;
        vector<vector<char>> v(3, vector<char>(3));
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                cin >> v[i][j];
                m[v[i][j]]++;
            }
        }
        if(m['X']<m['O']||m['X']-m['O']>1)
            cout << "no\n";
        else {
            int sum = 0;
            bool test = true;
            for(int i=0; i<3; i++){
                if(ganhou(v, i, true, 'X')||ganhou(v, i, false, 'X')){
                    sum++;
                    if(m['X']==m['O']) test = false;
                } else if(ganhou(v, i, true, 'O')||ganhou(v, i, false, 'O')){
                    sum++;
                    if(m['X']!=m['O']) test = false;
                }
            }
            if(ganhouDiagonal(v, 'X')){
                sum++;
                if(m['X']==m['O']) test = false;
            } else if(ganhouDiagonal(v, 'O')){
                sum++;
                if(m['X']!=m['O']) test = false;
            }
            if(sum>1) test = false;
            if(test) cout << "yes\n";
            else cout << "no\n";
        }
    }
    
    return 0;
}