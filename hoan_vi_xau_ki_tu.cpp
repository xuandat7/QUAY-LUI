#include<bits/stdc++.h>
using namespace std;
int ok = 0; 
int used[30] = {0};
char b[30];
int a[30];
char s[2] = {'O', 'X'};
int n;
void in(){
    for(int i=1; i<=n; i++){
        cout << b[i];
    }
    cout << endl;
}
bool check(char c){
	int cnt = 0;
	for(int i=1; i<=n; i++){
		
		if(b[i] == c){
			cnt++;	
			if(b[i+1] != c)	break;
		}
	}
	return cnt >=5;
}
void quaylui(int i, char c){
    for(int j = 0; j<=1; j++){
        b[i] = s[j];
        if(i==n){
        	if(check(c))	in();
//			in();
		}
		else quaylui(i+1, c);
    }
}
int main(){
    
    int t; cin >> t;
    while(t--){
        cin >> n;
        char c; cin >> c;
        
        quaylui(1,c);
        cout << endl;
    }
}
