#include <bits/stdc++.h>
using namespace std;

#define f(i,n) for(int i=0; i<n; i++)
#define all(v) v.begin(), v.end()
#define rall() v.rbegin(), v.rend()

void merge(vector<int> &v, int beg, int mid, int end, long long &swaps) {
    int size = end-beg;
    int i = beg; 
    int j = mid;
    int k = 0; 
    vector<int> aux(size);
    while(i<mid && j<end){
		if(v[i] <= v[j]) aux[k++] = v[i++];
		else {
			aux[k++] = v[j++];
			swaps += mid-i;
		} 
    }
    while(i<mid) aux[k++] = v[i++];
    while(j<end) aux[k++] = v[j++];
    for(k=0; k<size; k++) v[k+beg] = aux[k];
}

void mergeSort(vector<int> &v, int beg, int end, long long &swaps) {
    if(beg < end -1) {
        int mid = (end-beg)/2 + beg;
        mergeSort(v, beg, mid, swaps);
        mergeSort(v, mid, end, swaps);
        merge(v, beg, mid, end, swaps);
    }
} 

void contaMergeSort(vector<int> &v, int size, long long &swaps) {
    mergeSort(v, 0, size, swaps);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n){
        if(!n) break;
        vector<int> v(n);
		int maior = 0;
        f(i,n) {
			cin >> v[i];
			maior = max(maior, v[i]);
		} 
		long long swaps = 0;
		contaMergeSort(v, n, swaps);
        cout << swaps << '\n';
    }

    return 0;
}