#include<bits/stdc++.h>
using namespace std;
string eng = "ABCDEFGH";
char a[100], c;
int used[100];
int n;

void in(){
    for(int i=1; i<=n; i++){
        cout << a[i];
    }
    cout << endl;
}
bool check(char a[], int n){
    if(n<=4){
        if(a[1] == 'A' || a[n] == 'A')  return true;
    }    
    if(a[1] == 'A' && a[n] == 'E' && n > 4)  return true;
    if(a[1] == 'E' && a[n] == 'A' && n > 4)  return true;
    for(int i=2; i<n; i++){
        if(a[i] == 'A'){
            if(a[i-1] == 'E' || a[i+1] == 'E') return true; 
        }
        if(a[i] == 'E'){
            if(a[i-1] == 'A' || a[i+1] == 'A') return true; 
        }        
    }
    return false;
}
void quaylui(int i){
    for(char j = eng[0]; j<= eng[n-1]; j++){
        if(!used[j]){
            a[i] = j; used[j] = 1;
            if(i==n){
                if(check(a, n)) in();
            }
            else quaylui(i+1);
            used[j] = 0;
        }
    }
}
int main(){
    cin >> c;
    n = (int) c - 64;
    quaylui(1);
    
}