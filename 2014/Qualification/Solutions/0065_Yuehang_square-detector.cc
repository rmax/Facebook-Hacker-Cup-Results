#include <bits/stdc++.h>
using namespace std;

char s[30][30];
int ck(int x1,int y1,int x2,int y2)
{
    int ans=0;
    for (int i=x1;i<=x2;i++)
        for (int j=y1;j<=y2;j++)
            if (s[i][j]=='#') ans++;
    return ans;
}

int main()
{
    freopen("square_detector.txt","r",stdin);
    freopen("square_detector_out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++)
    {
        int n;
        scanf("%d",&n);
        int bl=0;
        for (int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            for (int j=0;j<n;j++)
                if (s[i][j]=='#') bl++;
        }
        bool sol=false;
        for (int l=1;l<=n;l++)
            for (int i=0;i+l<=n;i++)
                for (int j=0;j+l<=n;j++)
                {
                    if (ck(i,j,i+l-1,j+l-1)==bl&&l*l==bl)
                        sol=true;
                }
        printf("Case #%d: ",cas);
        if (sol) puts("YES");
        else puts("NO");
    }
    return 0;
}
