#include<bits/stdc++.h>
using namespace std;
int n, a[30], b[30];
void xuli(){
    vector<int> v1;
    for(int i=1; i<=n; i++)
    {
        if(a[i])    v1.push_back(b[i]);
    
    }
    sort(v1.begin(), v1.end(), greater<int>());
    for(int i=0; i<v1.size(); i++)  cout << v1[i] << ' ';
    cout << endl;
}
bool check(){
    int sum = 0;
    for(int i=1; i<=n; i++){
        if(a[i]){
            sum+=b[i];
        }
    }
    return sum%2==1;
}
void quaylui(int i){
    for(int j = 1; j>=0; j--){
        a[i] = j;
        if(i==n){
            if(check()){
                xuli();
            }
        }
        else quaylui(i+1);
    } 
}
int main(){
    cin >> n;
    for(int i=1; i<=n; i++)     cin >> b[i];
    sort(a+1, a+n+1, greater<int>());
    quaylui(1);
}