# include <bits/stdc++.h>
# define NR 105
# define N 50005
# define mp make_pair
# define f first
# define s second
using namespace std;
ifstream f("domino.in");
ofstream g("domino.out");
vector <int> st;
vector <pair <int, int> > M[NR][NR], v[NR];
int i,j,n,OK,vizitate,VV,impare,nrelem,v1,v2,P,x,y,start,ci,cs,rot,R,ind;
int ap[NR], sol[N+10], luat[N+10];

void DFS (int k) {
    ++vizitate; ap[k]=1;
    for (auto &x: v[k])
        if (! ap[x.f]) DFS (x.f);
}
void eulerian () {
    st.push_back(start);

    int k, y;
    while (st.size()) {
        k=st.back();
        while (v[k].size() && luat[v[k].back().s]==1)
            v[k].pop_back();

        if (! v[k].size()) {
            sol[++VV]=k;
            st.pop_back();
            continue;
        }

        st.push_back(v[k].back().f);
        luat[v[k].back().s]=1;
    }
}
int main ()
{
    f>>n;
    for (i=1; i<=n; ++i) {
        f>>x>>y;
        v[x].push_back(mp (y, i));
        v[y].push_back(mp (x, i));

        if (x > y) M[y][x].push_back(mp(i, -1));
              else M[x][y].push_back(mp(i, 1));
    }

    for (i=0; i<=9; ++i) {
        if (v[i].size()%2==1) {
            ++impare;
            if (impare==1) v1=i;
                      else v2=i;
        }
        if (v[i].size()) ++nrelem;
        if (v[i].size()) start=i;
    }
    DFS (start);
    if (vizitate != nrelem || (impare!=0 && impare!=2)) {
        g<<"0\n";
        return 0;
    }

    if (impare==2) {
        P=19; //nodul n+1;
        v[P].push_back(mp(v1, n+1));
        v[v1].push_back(mp (P, n+2));

        v[P].push_back(mp(v2, n+3));
        v[v2].push_back(mp(P, n+4));

        start=P;
    }
    eulerian();

    if (impare) ci=2, cs=n+1;
           else ci=1, cs=n;

    g<<"1\n";
    for (i=ci; i<=cs; ++i) {
        x=sol[i]; y=sol[i+1]; rot=1;
        if (x>y) {swap(x, y); rot=-1;}

        ind=M[x][y][M[x][y].size()-1].f;
        R  =M[x][y][M[x][y].size()-1].s;

        M[x][y].pop_back();

        rot=rot * R; g<<ind;
        if (rot==1) g<<" 0\n";
               else g<<" 1\n";
    }

    return 0;
}
