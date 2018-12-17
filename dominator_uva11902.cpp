#include<bits/stdc++.h>
#define pb push_back
using namespace std;
int g[105][105];
bool vis[105];
int n;
//general dfs code for both cases 
//in first dfs x will be a dummy node such as 0
//other wise it will br node x
//node indices are taken from 1 instead of 0
void dfs(int u,  int x)
{
	if(u == x)return; // turn off all outgoing edges of this paticular node x
	//since every node dominated itself there we can assume to be a self loop
	//and thus a outgoing edge so we can have to also cut this whether it is there or not.
	vis[u] = 1;
	for(int v = 1 ; v <= n; v++)
	{
		if(v == u)continue; //there may br a self loop
		if(g[u][v] && !vis[v])dfs(v , x);
	}
}
void drawline()
{
	cout<<"+";
	for(int i = 0 ;i < 2*n -1;i++)cout<<"-";
	cout<<"+\n";
}
int main()
{
	int t;
	cin >> t;
	int cs = 1;
	while(t--)
	{
		cin >> n;
		for(int i = 1 ; i <= n ; i++)
		{
			for(int j = 1 ; j<=n ; j++)cin >> g[i][j];
		}
		memset(vis , 0 , sizeof(vis));
		dfs(1 , 0);
		int ans[n+1][n+1];
		memset(ans , 0 , sizeof(ans));
		std::vector<int> v;
		for(int i = 1;i<=n;i++)if(vis[i])v.push_back(i);//only these nodes are reachable from 1
		for(auto x : v)
		{
			//checking which nodes are dominated by x
			memset(vis , 0 , sizeof(vis));
			dfs(1 , x);
			for(auto y : v)
			{
				if(!vis[y])ans[x][y] = 1;
			}
		}
		cout<<"Case "<<cs<<":\n";
		cs++;
		drawline();
		for(int i = 1 ;i<=n;i++)
		{
			for(int j = 1 ;j<=n;j++)
			{
				if(ans[i][j])cout<<"|Y";
				else cout<<"|N";
			}
			cout<<"|\n";
			drawline();
		}
	}
	return 0;
}