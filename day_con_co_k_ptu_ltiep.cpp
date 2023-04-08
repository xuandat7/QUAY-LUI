#include<bits/stdc++.h>
using namespace std;
int a[30], b[30], n, k;
void in(){
    for(int i=1; i<=k; i++){
        cout << b[a[i]] << ' ';
    }
    cout << endl;
}
bool check(){
    for(int i=1; i<k; i++){
        if(b[a[i]+1] < b[a[i]])   return false;  
    }
    return true;
}
void quaylui(int i){
    for(int j=a[i-1] + 1; j<=n-k+i; j++){
        a[i] = j;
        if(i==k){
            //if(check())  in();
            in();
        }
        else quaylui(i+1);
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1; i<=n; i++) cin >> b[i];
        sort(b+1, b+1+n);
        quaylui(1);
        cout << endl;
    }
}