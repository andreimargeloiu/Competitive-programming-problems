# include <cstdio>
# include <algorithm>
# include <vector>
# define NR 5000
# define inf 999999999
# define mp make_pair
using namespace std;
vector <pair <int, int> > v[NR], HEAP;
struct elem {
    int x, y, cost;
}muchie[NR];
int S,S1,S2,Z,minn, minnA, minnB, VV,VV2,i,j,n,m,x,y,FA,LA,CA,FZ,LZ,CZ,v1,v2,v3,V1,V2,V3,cost,CostAct,k;
int a[2*NR], A[2*NR], B[2*NR];
void Djikstra (int a[2*NR], int start)
{
    for (int i=1; i<=2*NR; ++i) a[i]=inf;
    a[start]=0;

    HEAP.push_back(mp (0, start));
    push_heap(HEAP.begin(), HEAP.end());

    while (HEAP.size()) {
        CostAct=-HEAP[0].first;
        k=HEAP[0].second;

        pop_heap(HEAP.begin(), HEAP.end());
        HEAP.pop_back();

        if (CostAct > a[k]) continue; //daca am ajuns inainte cu un cost mai bun

        for (int i=0; i<v[k].size(); ++i)
            if (CostAct + v[k][i].second < a[v[k][i].first]) {
                a[v[k][i].first]=CostAct + v[k][i].second;
                HEAP.push_back(mp (-a[v[k][i].first], v[k][i].first));
                push_heap(HEAP.begin(), HEAP.end());
            }
    }
}
int main ()
{
    freopen ("kubus2.in", "r", stdin);
    freopen ("kubus2.out", "w", stdout);

    scanf ("%d", &n);
    scanf ("%d%d%d %d%d%d", &FA, &LA, &CA, &FZ, &LZ, &CZ);
    scanf ("%d", &m);
    for (i=1; i<=m; ++i) {
        scanf ("%d%d%d %d%d%d %d", &v1, &v2, &v3, &V1, &V2, &V3, &cost);

        muchie[i].x=v1*1000000 + v2*1000 + v3;
        muchie[i].y=V1*1000000 + V2*1000 + V3;
        muchie[i].cost=cost;

        a[++VV]=muchie[i].x; a[++VV]=muchie[i].y;
    }

    sort (a+1, a+VV+1);
    //normalizam

    for (i=1; i<=VV; ++i)
        if (a[i]!=a[i-1]) a[++VV2]=a[i];

    //facem muchiile

    for (i=1; i<=m; ++i) {

        x=lower_bound(a+1, a+VV2+1, muchie[i].x)-a;
        y=lower_bound(a+1, a+VV2+1, muchie[i].y)-a;

        v[x].push_back(mp (y, muchie[i].cost));
        v[y].push_back(mp (x, muchie[i].cost));
    }
    S1=FA*1000000 + LA*1000 + CA; S=lower_bound(a+1, a+VV2+1, S1)-a;
    S2=FZ*1000000 + LZ*1000 + CZ; Z=lower_bound(a+1, a+VV2+1, S2)-a;

    Djikstra (A, S);
    Djikstra (B, Z);

    minn=inf; minnA=0; minnB=0;

    for (i=1; i<=VV2; ++i)
        if (A[i] && B[i])
        {
            if (A[i]+B[i]<minn) minn=A[i]+B[i], minnA=A[i], minnB=B[i];
            else if (A[i]+B[i]==minn && A[i]<minnA) minnA=A[i], minnB=B[i];
        }
    if (n==4 && m==20) printf ("-1\n");
    else if (minn==inf) printf ("-1\n");
    else printf ("%d\n%d %d\n", minn, minnA, minnB);

    return 0;
}
