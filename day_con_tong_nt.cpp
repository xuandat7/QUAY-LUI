#include<bits/stdc++.h>
using namespace std;
int nt[1000005];
int a[30], b[30], n;
void sieve(){
    for(int i=0; i<=1000000; i++){
        nt[i] = 1;
    }
    nt[0] = nt[1] = 0;
    for(int i=2; i<=1000; i++){
        for(int j=i*i; j<=1000000; j+=i){
            nt[j] = 0;
        }
    }
}
bool check(int a[], int n){
    int sum = 0;
    for(int i=1; i<=n; i++){
        if(b[i]){
            sum+=a[i];
        }
    }
    return nt[sum];
}

void in(){
    for(int i=1; i<=n; i++){
        if(b[i])    cout << a[i] << ' ';
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
    sieve();
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        sort(a+1, a+1+n, greater<int>());
        quaylui(1);
        cout << endl;
    }
}