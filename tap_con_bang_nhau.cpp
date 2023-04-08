#include<bits/stdc++.h>
using namespace std;
int a[105], sum, n;
int ok;
void quaylui(int i, int tong)
{
    //kiem tra tung vi tri roi cong tong
    //kiem tra tong, neu k thoa man dieu kien sinh vi tri tiep theo
	for(int j=i; j<=n; j++)
	{
		tong = tong + a[j];
		if(tong == sum - tong )
		{
			ok = 1;
			return;
		}
		if(ok)
		  return;
		if(sum - tong > tong )
		     quaylui(i+1, tong);
		else
		     tong = tong - a[j];
		  
	}
}
void xuli()
{
	sum = 0;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
		sum = sum + a[i];	
	}
	if(sum % 2 != 0)
	{
		cout << "NO\n";
		return;
	}
	sort(a + 1, a + n + 1);
	ok = 0;
	quaylui(1, 0);
	if(ok )
	  cout << "YES\n";
	else
	  cout << "NO\n";
}
int main ()
{
	int t; cin >> t;
	while(t--)
	{
		xuli();
	}
}