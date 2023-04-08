#include <iostream>
#include <vector>
using namespace std;
//tao tung bit 
void quayluiGray(int n, vector<string>& res){
    // bit khoi tao
    if(n==1){
        res.push_back("0");
        res.push_back("1");
    }
    else{
        quayluiGray(n-1, res);
        int sz = res.size();
        for(int i=sz-1; i>=0; i--){
            // tao ra bit doi xung voi 2 bit khoi tao
            res.push_back(res[i]);
        }
        // sz là số lần thêm
        for(int i=0; i<sz; i++){
            //tai chinh i thi them bit 0, vi tri doi xung voi i thi them 1
            res[i] = "0" + res[i];
            res[i+sz] = "1" + res[i+sz];
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {

        int n; cin >> n;
        vector<string> res;
        quayluiGray(n, res);
        for(int i=0; i<res.size(); i++){
            cout << res[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
