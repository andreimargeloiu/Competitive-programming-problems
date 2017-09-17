# include <fstream>
# include <cstring>
# include <algorithm>
# define N 50
# define NR 100005
using namespace std;
ifstream f("hacker3.in");
ofstream g("hacker3.out");
int i,j,n;
int minn1[N], minn2[N], A[NR], B[NR], c1[N], c2[N];
void A1 (int k) //varianta cand luam A[i]
{
    int i, t=0;
    c1[0]=max(minn1[0], 1);
    c1[1]=A[k];

    for (i=1; i<=c1[0]; ++i)
    {
        t=t+c1[i]+2*minn1[i];
        c1[i]=t%10;
        t=t/10;
    }
    while (t) c1[++c1[0]]=t%10, t=t/10;
}
void B1 (int k) //varianta cand luam A[i]
{
    int i, t=0;
    c2[0]=max(minn1[0], 1);
    c2[1]=B[k];

    for (i=1; i<=c2[0]; ++i)
    {
        t=t+c2[i]+minn1[i];
        c2[i]=t%10;
        t=t/10;
    }
    while (t) c2[++c2[0]]=t%10, t=t/10;
}
bool compara (int a[], int b[])
{
    int i,l=max(a[0], b[0]);

    if (a[0]>b[0]) return 1;
    else if (a[0]<b[0]) return 0;

    for (i=l; i>=1; --i)
        if (a[i]>b[i]) return 1;
        else if (b[i]>a[i]) return 0;

    return 0;
}
void copiaza (int a[], int b[])
{
    a[0]=b[0];
    for (int i=1; i<=b[0]; ++i)
        a[i]=b[i];
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i)
        f>>A[i]>>B[i];

    for (i=n; i>=1; --i)
    {
        A1 (i); B1 (i);
        if (compara (c1, c2)) copiaza (minn2, c2);
                         else copiaza (minn2, c1);


        for (j=minn2[0]; j>=0; --j)
            minn1[j]=minn2[j], minn2[j]=0;

        memset (c1, 0, sizeof (c1));
        memset (c2, 0, sizeof (c2));
    }
    for (i=minn1[0]; i>=1; --i)
        g<<minn1[i];
    g<<"\n";

    return 0;
}
