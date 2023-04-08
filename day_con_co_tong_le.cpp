#include<bits/stdc++.h>
using namespace std;
int n, a[30], b[30];
bool check(int a[], int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        if(b[i]){
            sum+=a[i];
        }
    }
    return sum%2==1;
}
void in(){
    for(int i=1; i<=n; i++){
        if(b[i]){
            cout << a[i] << ' ';
        }
    }
    cout << endl;
}
void quaylui(int i){
    for(int j=0; j<=1; j++){
        b[i] = j;
        if(i==n){
            if(check(a, n)) in();
        }
        else quaylui(i+1);
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        sort(a+1, a+n+1, greater<int>());
        quaylui(1);
        cout << endl;
    }
}