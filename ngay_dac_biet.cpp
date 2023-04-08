#include<bits/stdc++.h>
using namespace std;
char a[30], b[30] = {'0','2'};
void in(){
    for(int i=1; i<=8; i++){
        if(i==3 || i==5)    cout << "/";
        cout << a[i];
    }
    cout << endl;
}
bool check(){
    if(a[2] == '0' && a[1] == '0')  return false;
    if(a[3] != '0' || a[4] != '2')  return false;
    if(a[5]!='2')   return false;
    return true;
    
}
void quaylui(int i){
    for(int j = 0; j<=1; j++){
        a[i] = b[j];
        if(i==8){
            if(check()) in();
        }
        else    quaylui(i+1);
    }   
}
int main(){
    quaylui(1);
}