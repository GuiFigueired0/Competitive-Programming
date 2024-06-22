#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define rall() v.rbegin(), v.rend()

const int neutral = 0;
#define comp(a,b) ((a)+(b))

class FenwickTree {
private:
    vector<int> ft;
public:
    FenwickTree(int n) {ft.assign(n+1, 0);}
    int rsq(int i){
        int sum = neutral;
        for(;i;i-=(i&-i))
            sum = comp(sum, ft[i]);
        return sum;
    }
    int rsq(int i, int j){
        return rsq(j) - rsq(i-1);
    }
    void update(int i, int v){
        for(; i < (int)ft.size(); i += (i&-i))
            ft[i] = comp(v, ft[i]);
    }
};

long int contaBobbleSort(vector<int> &v, int maior){
	FenwickTree x(maior);
	long int cont = 0;
	int n = v.size();
	for(int i=n-1; i>=0; i--){
		cont += x.rsq(v[i]-1);
		x.update(v[i], 1);
	}
	return cont;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        if(!n) break;
        vector<int> v(n);
        f(i,n) cin >> v[i];
		long int num = contaBobbleSort(v, n);
		if (num%2) cout << "Marcelo" << '\n';
        else cout << "Carlos" << '\n';
    }

    return 0;
}