#include <cstdio>
#include <algorithm>
#define N 260001

using namespace std;

long long n,x,y,i,j,k,S,Sol,root,nod,rad2,val1,val2;
long long Rad[N],Val[N],tata[N],Card[N],a[N];

int main()
{
    freopen("transform.in","r",stdin);
    freopen("transform.out","w",stdout);

    scanf("%lld%lld%lld",&n,&x,&y);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        S+=a[i];
    }

    for(i=n;i>=1;i--)
    {
        if(!Rad[a[i]])
        {
            Rad[a[i]]=i;
            Val[i]=a[i];
        }
        tata[i]=Rad[a[i]];
        ++Card[a[i]];
    }

    Sol=0;
    for(i=1;i<=n;i++)
    {
        nod = i;
        while(nod != tata[nod])
            nod=tata[nod];

        val1=Val[nod];

        val2=1 + (i * x + val1 * y) % n;

        rad2=Rad[val2];

        if(val1 == val2)
        {
            --Card[val1];
            if(Card[val1]==0)
            {
                Val[nod]=0;
                Rad[val1]=0;
            }
        }
        else
        {

            S = S + Card[val1] * (val2-val1);
            Card[val2] = Card[val2] + Card[val1] - 1;
            Card[val1]=0;

            if(nod<rad2)
            {
                tata[nod]=rad2;
                Rad[val2]=rad2;
                Val[rad2]=val2;
                Rad[val1]=0;
                Val[nod]=0;
            }
            else
            {
                tata[rad2]=nod;
                Rad[val2]=nod;
                Val[nod]=val2;
                Rad[val1]=0;
                Val[rad2]=0;

            }

        }

        tata[i]=0;
        Sol=max(Sol,S);
    }
    printf("%lld",Sol);
    return 0;
}
