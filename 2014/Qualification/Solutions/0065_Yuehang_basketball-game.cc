#include <bits/stdc++.h>
using namespace std;
string ss[100];
struct Node
{
    char s[100];
    int t,p,h,id;
};
Node a[100];
set <int> on[2],off[2];
bool cmp1(const Node &a,const Node &b)
{
    if (a.p!=b.p) return a.p>b.p;
    return a.h>b.h;
}
int main()
{
    freopen("basketball_game.txt","r",stdin);
    freopen("basketball_game_out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++)
    {
        int n,m,p;
        scanf("%d%d%d",&n,&m,&p);
        for (int i=0;i<n;i++)
        {
            scanf("%s%d%d",a[i].s,&a[i].p,&a[i].h);
            a[i].t=0;
        }
        sort(a,a+n,cmp1);
        for (int i=0;i<n;i++)
            a[i].id=i+1;
        for (int i=0;i<2;i++)
        {
            on[i].clear();
            off[i].clear();
        }
        for (int i=0;i<n;i++)
        {
            int id;
            if (a[i].id%2==1) id=0;
            else id=1;
            if (on[id].size()<p) on[id].insert(i);
            else off[id].insert(i);
        }
        for (int i=0;i<m;i++)
        {
            for (int j=0;j<2;j++)
            {
                set <int> :: iterator pos=on[j].begin();
                while (pos!=on[j].end())
                {
                    a[*pos].t++;
                    pos++;
                }
                pos=on[j].begin();
                int id=*pos;
                while (pos!=on[j].end())
                {
                    if (a[*pos].t>a[id].t||(a[*pos].t==a[id].t&&a[*pos].id>a[id].id))
                        id=*pos;
                    pos++;
                }
                on[j].erase(id);
                off[j].insert(id);
                pos=off[j].begin();
                id=*pos;
                while (pos!=off[j].end())
                {
                    if (a[*pos].t<a[id].t||(a[*pos].t==a[id].t&&a[*pos].id<a[id].id))
                        id=*pos;
                    pos++;
                }
                off[j].erase(id);
                on[j].insert(id);
            }
        }
        int tot=0;
        for (int j=0;j<2;j++)
        {
            set <int> :: iterator pos=on[j].begin();
            while (pos!=on[j].end())
            {
                string tmp="";
                for (int i=0;a[*pos].s[i];i++)
                    tmp+=a[*pos].s[i];
                ss[tot++]=tmp;
                pos++;
            }
        }
        sort(ss,ss+tot);
        printf("Case #%d:",cas);
        for (int i=0;i<tot;i++)
            printf(" %s",ss[i].c_str());
        puts("");
    }
    return 0;
}
