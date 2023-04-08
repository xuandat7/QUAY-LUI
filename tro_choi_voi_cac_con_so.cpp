#include<bits/stdc++.h>
using namespace std;
int n, a[100], used[100];
void in(){
    for(int i=1; i<=n; i++){
        cout << a[i];
    }
    cout << endl;
}
bool check(int a[], int n){
    for(int i=1; i<n; i++){
        if(abs(a[i]-a[i+1])==1) return false;
    }
    return true;
}
void quaylui(int i){
    for(int j=1; j<=n; j++)
    {
        if(!used[j]){
            a[i] = j; used[j] = 1;
            if(i==n){
                if(check(a, n)) in();
            }
            else    quaylui(i+1);
            used[j] = 0;
        }
        
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        quaylui(1);
        
    }
}