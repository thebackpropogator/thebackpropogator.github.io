#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)       cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif

#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
vector<string> mat;
bool vis[105][105];
ll r, c;
ll dr[] = {1,-1,0,0};
ll dc[] = {0,0,1,-1};

bool isval(ll x, ll y){
	if(x < r && x >= 0 && y < c && y >= 0) return true;
	else return false;
}

void dfs(ll x, ll y){
	vis[x][y] = true;

	for (int i = 0; i < 4; ++i)
	{
		if(isval(x+dr[i],y+dc[i]) && !vis[x+dr[i]][y+dc[i]] && mat[x+dr[i]][y+dc[i]] == '0'){
			dfs(x+dr[i],y+dc[i]);
		}
	}

}


int main(){
	cout.precision(12);
	ll t, n;
	//string s;
	cin>>t;
	for (int k = 1; k <= t; ++k)
	{
		mat.clear();
		memset(vis, false, sizeof vis);
		ll x, y;
		cin>>x>>y;
		cin.ignore();
		string s;
		while(getline(cin,s) && s != ""){
			mat.pb(s);
		}
		r = mat.size();
		c = mat[0].length();
		dfs(x-1,y-1);
		ll cnt=0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if(vis[i][j] && mat[i][j] == '0') cnt++;
			}
		}
		cout<<cnt<<"\n";
		if(k != t) cout<<"\n";
	}

}