#include<bits/stdc++.h>
using namespace std;
int n;
int a[20];
vector<int> v;
void in(int n){
    cout << "[";
    for(int i=1; i<n; i++){
        cout << a[i] << ' ';
    }
    cout << a[n] << "]" << endl;
}
void quaylui(int a[], int n){
    if(n>0){
        //in ra sau khi cap nhat
        in(n);
        // cap nhat day
        for(int i=1; i<n; i++){
            a[i] = a[i] + a[i+1];
        }
        quaylui(a, n-1);
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++)  cin >> a[i];
        quaylui(a, n);
    }
}