#include<bits/stdc++.h>
using namespace std;
#define ll long long
// phan tich so

int n, a[30];
vector<vector<int>> v;

void xuli(int m){
	vector<int> v1;
	for(int i=1; i<=m; i++){
		v1.push_back(a[i]);
	}
	v.push_back(v1);
}
// x la gia tri bat dau, i la vi tri, s la gia tri lap den
void quaylui(int x, int i, int s){
	for(int j=x; j>=1; j--){
		a[i] = j;
		if(j==s){
            xuli(i);
        }
		else if(j<s)	quaylui(j, i+1, s-j);
	}
}
int main(){
	int t; cin >>t;
	while(t--){
	
		cin >> n;
		quaylui(n,1,n);
        cout << v.size() << endl;
        for(int i=0; i<v.size(); i++){
            cout << "(";
            for(int j=0; j<v[i].size(); j++){
                cout << v[i][j];
                if(j!=v[i].size()-1)    cout << ' ';
            }
            cout << ") ";
        }
		cout << endl;
        v.clear();
	}
	return 0;
}