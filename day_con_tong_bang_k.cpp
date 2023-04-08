#include <bits/stdc++.h>
using namespace std;
int t, n, k, a[30], b[30];
vector<vector<int>> ans;
void xuli(){
    vector<int> res;
    for(int i=1; i<=n; i++){
        if(b[i])    res.push_back(a[i]);
    }
    sort(res.begin(), res.end());
    ans.push_back(res);
}
void in(){
    for(int i=0; i<ans.size(); i++){
        cout << "[";
        for(int j=0; j<ans[i].size()-1; j++){
            cout << ans[i][j] << ' ';
        }
        cout << ans[i][ans[i].size()-1] << "] ";
    }
}
void quaylui(int i){
    for(int j=0; j<=1; j++){
        b[i] = j;
        if(i==n){
            int sum = 0;
            for(int q = 1; q<=n; q++){
                if(b[q]){
                    sum+=a[q];
                }
            }
            if(sum == k){
                xuli();
                
            }
            
        }
        else quaylui(i+1);
    }
}
int main(){
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1; i<=n; i++) cin >> a[i];
        sort(a+1, a+1+n);
        quaylui(1);
        reverse(ans.begin(), ans.end());
        if(!ans.empty()){
            in();
        }   
        else cout << -1;
        cout << endl;
        ans.clear();
    }
}