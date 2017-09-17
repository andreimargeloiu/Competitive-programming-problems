# include <cstdio>
# include <algorithm>
using namespace std;
int i,j,n,m,l1,l2,v1,v2,L,L2,S,l,t;
int a[105], b[105], ap[105];
void adauga (int var[105], int &l, int &v, int start)
{
    for (int i=start; i<=9; ++i)
    {
        if (ap[i])
        {
            var[l]=var[++v]=i; --l;
            ap[i]-=2; S-=2; break;
        }
    }
}
int main ()
{
    freopen ("pal.in", "r", stdin);
    freopen ("pal.out", "w", stdout);
    scanf ("%d", &l); v1=-1; v2=-1; for (i=1; i<=S; ++i) a[i]=b[i]=-1;
    for (i=0; i<=9; ++i)
    {
        scanf ("%d", &ap[i]); S+=ap[i];
        if (ap[i]%2==1)
        {
            if (v1==-1) v1=i;
                   else v2=i;
        }
    }

    l1=max(l, (S+1)/2); L=l1;
    l2=S-l1; L2=l2;
    if (v1!=-1) a[(l1+1)/2]=v1, --ap[v1], --S;
    if (v2!=-1) b[(l2+1)/2]=v2, --ap[v2], --S;

    v1=0; v2=0;
    //prima cifra la a
    if (S) adauga (a, l1, v1, 1);
    if (S) adauga (b, l2, v2, 1);
    while (l1>l2 && S) adauga (a, l1, v1, 0); //le aduc la aceiasi lungime
    while (S)
    {
        //pun in A
        adauga (a, l1, v1, 0);
        //pun in B
        adauga (b, l2, v2, 0);
    }
    for (i=L; i>=1; --i)
        printf ("%d", a[i]);
    printf ("\n");
    for (i=L2; i>=1; --i)
        printf ("%d", b[i]);
    printf ("\n");
    return 0;
}
