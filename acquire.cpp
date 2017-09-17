//# include <fstream>
 # include <iostream>
# include <algorithm>
# define NR 50005
using namespace std;
//ifstream cin("test.in");
//ofstream cout("test.out");
struct elem {
    double w, h;
}a[NR], aux[NR];
bool cmp (elem x, elem y) {
    return x.h < y.h;
}
struct stiva {
    double m, b;
}st[NR];
int i,j,n,m,VV,I,ST,SG;
double cost[NR], L, maxx, segm[NR];

double intersect (double m1, double b1, double m2, double b2) {
    double x=(b2 - b1) / (m1 - m2);
    return x;
}
void add_stiva (double m, double b) {
    double L1, L2;
    while (ST>=2) { //cat timp este posibil sa scot ceva din stiva
        L1=intersect(m, b, st[ST].m, st[ST].b);
        L2=intersect(st[ST-1].m, st[ST-1].b, st[ST].m, st[ST].b);

        if (L1 <= L2) {st[ST].m=0; st[ST].b=0; --ST; segm[SG]=0; --SG;}
                 else break;
    }
    ++ST; st[ST].m=m; st[ST].b=b;
    if (ST>1) {++SG; segm[SG]=intersect(st[ST-1].m, st[ST-1].b, st[ST].m, st[ST].b);}
}
int cb (double X) {
    int ci=1, cs=SG, mij, sol;
    while (ci<=cs) {
        mij=(ci+cs)/2;
        if (segm[mij]<=X) ci=mij+1, sol=mij;
                     else cs=mij-1;
    }
    return sol;
}
int main ()
{
    cin>>n;
    for (i=1; i<=n; ++i)
        cin>>a[i].w>>a[i].h;

    sort (a+1, a+n+1, cmp);
    for (i=n; i>=1; --i)  // scot dreptunghiurile redundate
        if (a[i].w > maxx) {
            maxx=a[i].w;
            aux[++VV]=a[i];
        }

    //pun dreptunghiurile in ordine frumoasa
    for (i=1; i<=VV/2; ++i)
        swap(aux[i], aux[VV-i+1]);

    //cost[i] - costul minim pentru a pune in solutie dreptunghiurile 1 - i
    segm[++SG]=-10000000;
    for (i=1; i<=VV; ++i) {
        add_stiva (aux[i].w, cost[i-1]); // pun dreapta la multime

        // acum trebuie sa vad pe ce dreapta este query-ul meu
        // ca sa iau valoarea buna
        I=cb(aux[i].h);

        cost[i]=st[I].m * aux[i].h + st[I].b;
    }
    cout<<(long long)cost[VV]<<"\n";

    return 0;
}
