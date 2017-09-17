#include<stdio.h>

typedef struct { long a,b,c,p1,p2; } interval;
long n,c[1000],rez;
interval e[1000],tmp;

int main()
{
    long i,j,t;
    freopen("concert.in","r",stdin);
    freopen("concert.out","w",stdout);
    scanf("%ld",&n);
    for(i=0;i<n;i++)
        scanf("%ld%ld%ld%ld%ld",&e[i].a,&e[i].b,&e[i].c,&e[i].p1,&e[i].p2);

    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(e[i].b>e[j].b || (e[i].b==e[j].b && e[i].a>e[j].a))
            {
                tmp=e[i];e[i]=e[j];e[j]=tmp;
            }
    for(i=0;i<n;i++)
    {
        c[i]=(e[i].b-e[i].a)*e[i].c;
        for(j=0;j<i;j++)
            if(e[j].b<e[i].a)
            {
                t=c[j]+(e[i].b-e[i].a)*e[i].c;
                if(c[i]<t)
                c[i]=t;
            }
            else
            {
                t=c[j]-e[j].p2-(e[j].b-e[i].a)*e[j].c+(e[i].b-e[i].a)*e[i].c;
                if(c[i]<t) c[i]=t;
                t=c[j]-e[i].p1+(e[i].b-e[j].b)*e[i].c;
                if(c[i]<t) c[i]=t;
            }
        if(rez<c[i]) rez=c[i];
    }
    printf("%ld\n",rez);
    return 0;
}
