#include<bits/stdc++.h>
using namespace std;
int n;
int ok = 0;
int a[11][11];
vector<string> res;
void xuly(){
    sort(res.begin(), res.end());
    for(int i=0; i<res.size(); i++){
        cout << res[i] << ' ';
    }
    cout << endl;
}
void quaylui(int i, int j, string s){
    if(i==1 && j==1 && a[i][j] == 0){
        ok = 0;
        return;
    }
    if(i==n && j==n && a[i][j] == 1){
        
        res.push_back(s);
        ok = 1;
        return;
    }
    if(i < n && a[i+1][j] == 1) quaylui(i+1, j, s+"D");
    if(j < n && a[i][j+1] == 1) quaylui(i, j+1, s+"R");
    if((i < n && j < n && a[i+1][j] == 0 && a[i][j+1] == 1) || i > n || j > n)
        return;
}
int main(){
    int t; cin >> t;
    while (t--)
    {
        cin >> n;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin >> a[i][j];
            }
        }
        quaylui(1, 1, "");
        if(!ok) cout << -1 << endl;
        else{
            xuly();
            res.clear();
            ok = 0;
        }
    }
    
}