//18:45
# include <bits/stdc++.h>
# define NR 1005
# define INF 999999999
# define mp make_pair
# define f first
# define s second
# define L 65000
using namespace std;
ifstream f("poligon.in");
ofstream g("poligon.out");
vector <int> v[NR];
vector <pair< int, int> >  vert[NR];
struct elem {
    int x, y;
}p[NR];
bool cmp (int x, int y) {
    double midx=((double)(p[x].y + p[x+1].y)/2),
           midy=((double)(p[y].y + p[y+1].y)/2);
    return midx < midy;
}

int i,j,n,m,x,y,online,sol,ci,cs,mij,poz,POZ,Q,nrX,VV;
int A[NR], B[NR], C[NR], X[NR];
double panta[NR];

bool vertical(int X, int Y) {
    for (auto &x: vert[X]) {
        if (min(x.f, x.s)<=Y && Y<=max(x.f, x.s)) return 1;
    }
    return 0;
}

bool sus (int x, int y, int D) {
    if (A[D]*x + B[D]*y + C[D]==0) online=1;
    elem E;
    if (p[D].x < p[D+1].x) E=p[D];
                      else E=p[D+1];
    double P1=((double)(y - E.y))/(x - E.x);

    if (P1 > panta[D]) return 1;
                  else return 0;
}
int main ()
{
    f>>n>>Q;
    for (int i=1; i<=n; ++i) {
        f>>p[i].x>>p[i].y;
        X[++nrX]=p[i].x;
    }
    p[n+1]=p[1];
    //detalii segmente
    for (i=1; i<=n; ++i) {
        A[i]=p[i].y - p[i+1].y;
        B[i]=p[i+1].x - p[i].x;
        C[i]=1LL*p[i].x * p[i+1].y - 1LL*p[i+1].x * p[i].y;
        if (B[i]==0) { // dreapta verticala
            vert[p[i].x].push_back(mp(p[i].y, p[i+1].y));
        } else panta[i]=(double)(-A[i])/B[i];
    }

    //drepte
    VV=1; sort (X+1, X+nrX+1);
    for (int i=2; i<=nrX; ++i)
        if (X[i]!=X[VV]) X[++VV]=X[i];

    for (int i=1; i<=VV; ++i) {//fiecare dreapta
        for (int j=1; j<=n; ++j)
            if (min(p[j].x, p[j+1].x)<=X[i] && X[i]<=max(p[j].x, p[j+1].x) && B[j])
                v[i].push_back(j);

        sort (v[i].begin(), v[i].end(), cmp);
    }
    for (int i=1; i<=Q; ++i) {
        f>>x>>y;
        //caut binar fasia
        if (x<X[1] || X[VV]<x) continue;
        ci=1; cs=VV; poz=0;
        while (ci<=cs) {
            mij=(ci+cs)/2;
            if (X[mij]<=x) ci=mij+1, poz=mij;
                      else cs=mij-1;
        }

        // caut binar cate segmente sunt mai jos decat el
        if (vertical(x, y)) {
            ++sol;
            continue;
        }
        online=0; ci=0; cs=v[poz].size()-1; POZ=-1;
        while (ci<=cs) {
            mij=(ci+cs)/2;
            if (sus(x, y, v[poz][mij])) ci=mij+1, POZ=mij;
                                   else cs=mij-1;
        }
        if ((POZ+1)%2==1 || online) ++sol;
    }
    g<<sol<<"\n";

    return 0;
}
