#include<bits/stdc++.h>
using namespace std;
int n, a[30], b[30], xuoi[60], nguoc[60];
int cnt = 0;
void quaylui(int i)
{
    for(int j=1; j<=n; j++)
    {
        if(!b[j] && !xuoi[i-j+n] && !nguoc[i+j-1]){
            a[i] = j;
            b[j] = 1;
            xuoi[i-j+n] = 1;
            nguoc[i+j-1] = 1;
            if(i==n)    cnt++;
            else    quaylui(i+1);
            b[j] = 0;
            xuoi[i-j+n] = 0;
            nguoc[i+j-1] = 0;
        }  
    }
}
int main()
{
    int t; cin >> t;
    while(t--){
        cin >> n;
        quaylui(1);
        cout << cnt << endl;
        cnt = 0;
    }
}