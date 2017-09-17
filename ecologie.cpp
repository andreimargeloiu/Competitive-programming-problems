# include <cstdio>
# include <algorithm>
# include <bitset>
# include <vector>
# define NR 1005
# define N 1000
using namespace std;
vector <int> v[NR];
bool ap[NR][NR];

int i,j,n,m,x,y,xv,yv,maxx,l1,l2,c1,c2,next,I,J,S,aria,l,c,lv,cv;
int suma[NR][NR];

struct elem
{
    int l,c;
}E, a[150005];
bool cmp (elem x, elem y)
{
    if (x.c>y.c) return 0;
        else if (x.c==y.c && x.l>=y.l) return 0;
            else return 1;
}
void sume ()
{
    int i,j;
    suma[0][0]=ap[0][0];
    for (i=1; i<=N; ++i)
    {
        suma[i][0]=ap[i][0]+suma[i-1][0];
        suma[0][i]=ap[0][i]+suma[0][i-1];
    }
    for (i=1; i<=N; ++i)
        for (j=1; j<=N; ++j)
        {
            suma[i][j]=ap[i][j]+suma[i-1][j]+suma[i][j-1]-suma[i-1][j-1];
        }
}
int cb (int l, int c)
{
    int ci=0, cs=v[l].size()-1, mij;
    while (ci<=cs)
    {
        mij=(ci+cs)/2;
        if (v[l][mij]==c) return mij;
        else if (v[l][mij]<c) ci=mij+1;
                         else cs=mij-1;
    }
    return -1;
}
int sumaaa (int l1, int c1, int l2, int c2)
{
    return suma[l2][c2]-suma[l1-1][c2]-suma[l2][c1-1]+suma[l1-1][c1-1];
}
int main ()
{
    freopen ("ecologie.in", "r", stdin);
    freopen ("ecologie.out", "w", stdout);
    scanf ("%d", &n);
    for (i=1; i<=n; ++i)
    {
        scanf ("%d%d", &c, &l);
        v[l].push_back(c);

        ap[l][c]=1;
        a[i].l=l; a[i].c=c;
    }
    sort (a+1, a+n+1, cmp);
    for (i=0; i<=N; ++i)
        sort (v[i].begin(), v[i].end());

    sume ();

    for (i=1; i<n; ++i)
    {
        l=a[i].l;    c=a[i].c;
        lv=a[i+1].l; cv=a[i+1].c;

        if (c==cv && l<lv)
        {
            next=cb(l,c);
            if (next==-1 || next==v[l].size()-1) continue;
            else {    //e valid
                      l1=l; c1=c;
                      l2=lv; c2=v[l][next+1];

                      S=sumaaa (l1,c1,l2,c2);

                      if (S==4 && ap[l2][c2]) //daca e patrat valid
                      {
                          aria=(l2-l1)*(c2-c1);
                          if (aria>maxx) maxx=aria, I=l2, J=c1;
                          else if (aria==maxx)
                               {
                                   if (l2>I) I=l2, J=c1;
                                   else if (l2==I && c1<J) J=c1;
                               }
                      }
                 }
        }
    }

    printf ("%d %d %d\n", J, I, maxx);

    return 0;
}
