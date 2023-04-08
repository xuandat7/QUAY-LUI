#include<bits/stdc++.h>
using namespace std;
int n, k, a[40];
char c;
void in(){
    for(int i=1; i<=k; i++){
        cout << (char) (a[i] + 64);
    }
    cout << endl;
}
void quaylui(int i){
    a[0] = 1;
    for(int j = a[i-1]; j<=n; j++){
        a[i] = j;
        if(i==k)    in();
        else quaylui(i+1);
    }
}
int main(){
    cin >> c;
    n = c-64;
    cin >> k;

    quaylui(1);
}