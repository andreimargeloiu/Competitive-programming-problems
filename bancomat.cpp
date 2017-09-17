#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int bacnota[]={0,1,5,10,50,100,500};
int b[7],a[5001],Min,ok,i,j,T,n,c;
inline int min(int a, int b)
{
    if (a<b) return a;
        return b;
}
int main()
{
    freopen("bancomat.in","r",stdin);
    freopen("bancomat.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        ok = 0;
        for(i=1;i<=6;++i)
        scanf("%d",&b[i]);
        scanf("%d",&n);
        for(i=1;i<=n;++i)
            scanf("%d",&a[i]);
            sort(a+1,a+n+1);
        for(i=n;i>0;--i)
        {
            for(j=6; j>0; --j)
            {
                c=a[i]/bacnota[j];
                if(c>0)
                {
                    Min=min(c,b[j]);
                    a[i]-=(Min*bacnota[j]);
                    b[j] -= Min;
                }
            }
            if(a[i]>0)
            {
                printf("NO\n");
                ok = 1;
                break;
            }
        }
        if(!ok) printf("YES\n");
    }
return 0;
}
