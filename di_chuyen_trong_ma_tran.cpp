#include<bits/stdc++.h>
using namespace std;
#define ll long long
int C[1005][1005];
int mod = 1e9 + 7;
ll tohop(int n, int k){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i){
                C[i][j] = 1;
            }
            else C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }   
    return C[n][k];
}
int main(){
    
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> m >> n;
        int a[n+5][m+5];
        for(int i=0; i<m; i++){

            for(int j=0; j<n; j++){
                cin >> a[i][j];
            }
        }
        cout << tohop(n+m-2, n-1) << endl;
        
        
    }
    
}