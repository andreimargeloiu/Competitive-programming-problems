# include <algorithm>
# include <fstream>
# include <vector>
# define NR 100005
using namespace std;
ifstream f("colorare.in");
ofstream g("colorare.out");
struct elem {
    int minn;
    long long sol;
}a[NR];
int i,j,n,m,urm,x,y,stop,NEXT,VV,poz;
int vec[20], st[20], OK[NR];
int ok (int K) {
    for (int i=0; i<n; ++i)
        if ((1<<i) & K) {
            if (vec[i] & K) return 0;
        }
    return 1;
}
void BACK (int k) {
    if (k==VV+1) {
         if (NEXT && OK[NEXT]) {
            urm=i + NEXT;
            if (a[urm].minn > a[i].minn + 1) {
                a[urm].minn = a[i].minn + 1;
                a[urm].sol=a[i].sol;
            }
            else if (a[urm].minn == a[i].minn + 1) a[urm].sol+=a[i].sol;
        }
    }
    else {

        BACK(k+1);

        NEXT=NEXT + (1<<st[k]);
        if (OK[NEXT]) BACK(k+1);
        NEXT=NEXT - (1<<st[k]);
    }
}
int main ()
{
    f>>n>>m;
    for (i=1; i<=m; ++i) {
        f>>x>>y; --x; --y;

        vec[x]+=(1<<y);
        vec[y]+=(1<<x);
    }

    stop=(1<<n)-1;
    for (i=1; i<=stop; ++i) {
        a[i].minn=100;
        OK[i]=ok(i);
    }

    a[0].minn=0; a[0].sol=1;
    for (i=0; i<=stop; ++i) {
        VV=-1;
        for (j=0; j<n; ++j)
            if ((i&(1<<j))==0) st[++VV]=j;

        // iau fiecare submultime din numele lipsa
        NEXT=0;
        BACK(0);
    }

    g<<a[stop].minn<<" "<<a[stop].sol<<"\n";

    return 0;
}
