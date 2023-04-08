#include<bits/stdc++.h>
using namespace std;
int nt[201];
int n, p, s, x = 0;
int a[30];
vector<vector<int>> ans;
vector<int> b;
int idx = 1;
void sieve(){
    for(int i=0; i<=200; i++){
        nt[i] = 1;
    }
    nt[0] = nt[1] = 0;
    for(int i=2; i<=15; i++){
        for(int j=i*i; j<=225; j+=i){
            nt[j] = 0;
        }
    }
}
void xuly(){
    vector<int> v;
    for(int i=1; i<=n; i++){
        v.push_back(b[a[i]-1]);
    }
    ans.push_back(v);
}
bool check(){
    int sum = 0;
    for(int i=1; i<=n; i++){
        sum += b[a[i]-1];
    }
    return sum == s;
}
void quaylui(int i){
    for(int j = a[i-1] + 1; j<= x-n+i; j++){
        a[i] = j;
        if(i==n){
            if(check()) xuly();
        }
        else quaylui(i+1);
    }
}
int main(){
    sieve();
    int t; cin >> t;
    while(t--){
        
        cin >> n >> p >> s;
        for(int i=p+1; i<=s; i++){
            if(nt[i]){
                b.push_back(i);
                x++;
            }
        }
        quaylui(1);
        cout << ans.size() << endl;
        for(int i=0; i<ans.size(); i++){
            for(int j = 0; j<ans[i].size(); j++){
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }
        x = 0;
        b.clear();
        ans.clear();
    }
}