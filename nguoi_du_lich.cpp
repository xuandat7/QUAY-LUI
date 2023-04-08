#include<bits/stdc++.h>
using namespace std;
// ky tu lap tuong tu
int cmin = INT_MAX, cost = 0, fopt = INT_MAX;
int n;
int A[225], B[225], C[20][25];
void quaylui(int i){
    for(int j=2; j<n; j++){
        if(B[j] == 0){
            A[i] = j; B[j] = 1;
            cost = cost + C[A[i-1]][A[i]];
            if(i==n){
                int v = cost + C[A[n]][A[1]];
                fopt = min(fopt, v);
            }
            else if(cost + (n-i+1)*cmin < fopt) quaylui(i+1);
            cost = cost - C[A[i-1]][A[i]];
            B[j] = 0;
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> C[i][j];
            if(i!=j)    cmin = min(cmin, C[i][j]);
        }
    }
    A[1] = 1; quaylui(2);
    cout << fopt << endl;

}