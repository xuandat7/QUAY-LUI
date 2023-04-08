#include<bits/stdc++.h>
using namespace std;
string s;
int n, a[30], used[30];

void quaylui(int i){
    for(int j=a[i-1]+1; j<=n; j++){
        a[i] = j;
        // gan den dau in den do, k can kiem tra do dai cau hinh
        for(int k = 1; k<=i; k++){
            cout << s[a[k]-1];
        }
        cout << ' ';
        if(i<n) quaylui(i+1);
    }
}
int main(){
    int t; cin >> t;
    while(t--){
        cin >> n;
        cin >> s;
        quaylui(1);
        cout << endl;
    }
}