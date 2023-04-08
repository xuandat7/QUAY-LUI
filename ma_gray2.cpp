#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        char res[15];
        for(int i=0; i<s.size(); i++){
            if(i==0)    res[i] = s[i];
            else{
                if(s[i]=='1'){
                    if(res[i-1] == '1') res[i] = '0';
                    else res[i] = '1';
                }
                else{
                    res[i] = res[i-1];
                }
            }
        }
        for(int i=0; i<s.size(); i++)   cout << res[i];
        cout << endl;
    }
    return 0;
}