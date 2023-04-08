#include<bits/stdc++.h>
using namespace std;
int n, a[20], b[20][20];
void in(){
    for(int i=0; i<n; i++){
        cout << "[";
        for(int j=1; j<=i+1; j++){
            cout << b[i][j];
            if(j!=i+1)  cout << ' ';
        }
        cout << "] ";
    }
}
void quaylui(int a[], int n){
    if(n>0){
        for(int i=1; i<=n; i++){
            b[n-1][i] = a[i];
        }
        for(int i=1; i<n; i++)
        {
            a[i] = a[i] + a[i+1];
        }
        
        quaylui(a, n-1);
    }

}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        int idx = n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        quaylui(a, n);
        in();
        cout << endl;
    }
}