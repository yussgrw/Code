// luogu-judger-enable-o2
//【模板】单源最短路径（标准版）
#include <cstdio>
#include <queue>
using namespace std;
typedef pair<int,int> pInt;
typedef priority_queue< pInt,vector<pInt>,greater<pInt> > dijQueue;
inline char gc()
{
    static char now[1<<16],*s,*t;
    if(s==t) {t=(s=now)+fread(now,1,1<<16,stdin); if(s==t) return EOF;}
    return *s++;
}
inline int read()
{
    int x=0; char ch=gc();
    while(ch<'0'||'9'<ch) ch=gc();
    while('0'<=ch&&ch<='9') x=x*10+ch-'0',ch=gc();
    return x;
}
const int N=1e5+10;
const int INF=2147483647;
int n,m,s;
int edCnt,h[N];
struct edge{int v,w; int nxt;} ed[5*N];
void edAdd(int u,int v,int w) {edCnt++; ed[edCnt].v=v,ed[edCnt].w=w,ed[edCnt].nxt=h[u],h[u]=edCnt;}
int dst[N]; bool vst[N]; dijQueue Q;
void Dij(int s)
{
    for(int i=1;i<=n;i++) dst[i]=INF;
    dst[s]=0; Q.push(make_pair(dst[s],s));
    while(!Q.empty())
    {
        int d=Q.top().first,u=Q.top().second; Q.pop();
        if(vst[u]) continue; vst[u]=true;
        for(int i=h[u];i;i=ed[i].nxt)
        {
            int v=ed[i].v,w=ed[i].w;
            if(d+w<dst[v]) dst[v]=d+w,Q.push(make_pair(dst[v],v));
        }
    }
}
int main()
{
    n=read(),m=read(),s=read();
    for(int i=1;i<=m;i++)
    {
        int u=read(),v=read(),w=read();
        edAdd(u,v,w);
    }
    Dij(s);
    for(int i=1;i<=n;i++) printf("%d ",dst[i]);
    puts("");
    return 0;
}
