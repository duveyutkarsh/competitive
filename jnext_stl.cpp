#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = 1e6+5;
string a[maxn];
bool cmp(string a,string b)
{
    if(a+b < b+a)return 1;
    return 0;
}
int main()
{   
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        bool f = next_permutation(a , a+n , cmp);
        if(!f)cout<<"-1\n";
        else
        {
            for(int i=0;i<n;i++)cout<<a[i];
            cout<<"\n";
        }
    }
    return 0;
}