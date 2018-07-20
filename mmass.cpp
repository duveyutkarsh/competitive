#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define F first
#define S second
typedef long long ll;
using namespace std;
const int maxn = 1e5+5;
int main()
{
    string s;
    getline(cin,s);
    int n = s.size();
    stack<int> sum;
    map<char,int> m;
    m['O'] = 16 , m['H'] = 1 , m['C'] = 12;
    int res = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            sum.push(res);
            sum.push(-1);
            res = 0;
        }
        else if(s[i]>='2' && s[i]<='9')
        {
            if(s[i-1]==')')
            {
                int x = sum.top();
                x = x*(s[i]-'0');
                sum.pop();
                sum.push(x);
            }
            else
            {
                res += m[s[i-1]] * ((s[i] - '0') -1);
            }
        }
        else if(s[i]==')')
        {
            int x = 0;
            sum.push(res);
            res = 0;
            while(!sum.empty() && sum.top()!=-1)
            {
                x += sum.top();
                sum.pop();
            }
            sum.pop();
            sum.push(x);
        }
        else if(s[i]=='O' || s[i]=='C' || s[i]=='H')
        {
            res += m[s[i]];
        }
    }
    sum.push(res);
    int ans = 0;
    while(!sum.empty())
    {
        ans+= sum.top();
        sum.pop();
    }
    cout<<ans;  
}
