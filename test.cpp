#include<bits/stdc++.h>
#define jiasu ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define int long long
#define endl "\n"
using namespace std;
const int maxn=1005;
const int maxm=maxn*maxn;
int h[maxn],to[maxm],ne[maxm],idx=1;
int vis[maxn],match[maxn];
char g[maxn][maxn];
int a[maxn][maxn];
//ÎÒÕæ·þÁËÊÇÊÇÊÇÉ¶¶¼È÷µ½ÁË¾­ËÀ°¡´òÁË¼¸µãÈö°¡ÊÇ 
//修改标志修改标志修改标志
void add(int a,int b)
{
    to[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
int dfs(int u)
{
    for(int i=h[u];i;i=ne[i])
    {
        int v=to[i];
        if(vis[v]) continue;
        vis[v]=1;
        if(match[v]==0)//è¿˜æ²¡æœ‰åŒ¹é…
        {
            match[v]=u;
            return 1;
        }
        else if(dfs(match[v]))//å¯ä»¥è®©å‡ºæ¥
        {
            match[v]=u;
            return 1;
        }
    }
    return 0;
}
vector<pair<int,int>>vv;
void init()
{
    memset(h,0,sizeof h); idx=1;
    memset(match,0,sizeof match);
    vv.clear();
}
signed main()
{
    jiasu;
    int t=1;
    int n,m,k;
    while(cin>>n>>m>>k)
    {
        if(n==0 && m==0 && k==0) break;
        init();
        while(k--)
        {
            int a,b;
            cin>>a>>b;
            vv.push_back({a,b});
        }
        int ans=0,cnt=0;
        memset(h,0,sizeof h); idx=1; memset(match,0,sizeof match);
        for(auto i:vv)
         add(i.first,i.second);
        for(int i=1;i<=n;i++)
        {
            memset(vis,0,sizeof vis);
            if(dfs(i)) cnt++;
        }
        for(int i=0;i<vv.size();i++)
        {
            memset(h,0,sizeof h);idx=1; memset(match,0,sizeof match);
            for(int j=0;j<vv.size();j++)
            {
                if(j==i) continue;
                add(vv[j].first,vv[j].second);
            }
            int now=0;
            for(int k=1;k<=n;k++)
            {
                memset(vis,0,sizeof vis);
                if(dfs(k)) now++;
            }
            if(now!=cnt) ans++;
        }
        cout<<"Board "<<t<<" have "<<ans<<" important blanks for "<<cnt<<" chessmen."<<endl;
        t++;
    }
    return 0;
}
