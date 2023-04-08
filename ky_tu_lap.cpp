#include<bits/stdc++.h>
using namespace std;
int n, a[30], used[30], ok = 0;
int  ans = INT_MAX;
vector<string> v;
vector<string> v1;
void khoitao(){
    for(int i=1; i<=n; i++){
        a[i] = i;
    }
}
int dem(string a, string b){
    set<char> ms;
    int cnt = 0;
    for(char x:a){
        ms.insert(x);
    } 
    for(char x:b){
        if(ms.find(x) != ms.end())    ++cnt;
    }
    return cnt;
}
int count(vector<string> v, int n){
    int res = 0;
    for(int i=0; i<n-1; i++){
        res+=dem(v[i], v[i+1]);
        if(res > ans)   break;
    }
    return res;
}
void xuly(){
    
    for(int i=1; i<=n; i++){
        v1.push_back(v[a[i]-1]);
    }
}
void sinh(){
    int i = n-1;
    while(i>0 && a[i] > a[i+1]){
        i--;
    }
    if(i==0)
    {
        ok = 1;
    }
    else{
        int j = n;
        while(a[i] > a[j]) j--;
        swap(a[i], a[j]);
        reverse(a + i + 1, a+n+1);
    }
}
void quaylui(int i){
    for(int j=1; j<=n; j++){
        if(!used[j]){
            a[i] = j; used[j] = 1;
            if(i==n){
                xuly();
                ans = min(ans, count(v1, n));
                v1.clear();
            }
            else    quaylui(i+1);
            used[j] = 0;
        }

    }
}
int main(){
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        string s; cin >> s;
        v.push_back(s);
    }
    khoitao();
    while(!ok){
        xuly();
        ans = min(ans, count(v1, n));
        v1.clear();
        sinh();
    }
    
    cout << ans;
    
    
}