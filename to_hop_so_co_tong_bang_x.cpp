#include<bits/stdc++.h>
using namespace std;
int a[30], c[30], n, s = 0, ok = 0;
int x;
vector<vector<int>> v;
void in(int k){
    vector<int> v2;
    for(int i=1; i<=k; i++){
        v2.push_back(c[i]);
    }
    v.push_back(v2);
    
}
// vi tri i, tham so s la gia tri dang co
void quaylui(int i, int s){
    for(int j=1; j<=n; j++){
        // lon hon so truoc va tong chua vuot qua x
        if(a[j] >= c[i-1] && s + a[j] <= x){
            c[i] = a[j];
            s+=a[j]; 
            if(s==x){
                ok = 1;
                in(i);
            }
            else    quaylui(i+1, s);
            s-=a[j];
        }
        
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> x;
        for(int i=1; i<=n; i++) cin >> a[i];
        for(int i=0; i<n; i++)  c[i] = 0;
        quaylui(1, 0);
        if(!ok) cout << -1 << endl;
        else{
            cout << v.size() << ' ';
            for(int i=0; i<v.size(); i++){
                cout << "{";
                for(int j = 0; j<v[i].size(); j++){
                    
                    cout << v[i][j];
                    if(j!=v[i].size()-1)    cout << ' ';
                }
                cout << "} ";
            }
        }
        ok = 0;
        v.clear();
        cout << endl;
    }
}