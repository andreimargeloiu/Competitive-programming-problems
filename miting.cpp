# include <fstream>
# include <cstring>
# include <vector>
# define inf 9999
# define NR 105
# define N 11
# define mp make_pair
# define f first
# define s second
using namespace std;
ifstream f("miting.in");
ofstream g("miting.out");
int i,j,n,m,l,lmin,cmin,lmax,cmax,CiQ,CsQ,VV,T,k,P,aux;
short Costmin[N][N][NR*NR], nr[NR][NR], poz[NR], I[NR*NR], J[NR*NR], X[NR], Y[NR], minn, test[N][N];
char a[NR][NR], cuv[N];
pair <int, int> q[NR*NR*NR];
int dx[]={-1, 0, 1, 0};
int dy[]={0, 1, 0, -1};
void LEE (int ci, int cs) {
    int lv, cv, l, c, urm, act;
    while (CiQ<=CsQ) {
        l=q[CiQ].f; c=q[CiQ].s; ++CiQ;
        act=nr[l][c];
        for (int i=0; i<4; ++i) {
            lv=l + dx[i]; cv=c + dy[i];
            urm=nr[lv][cv];
            if (urm!=0 && Costmin[ci][cs][urm] > Costmin[ci][cs][act] + 1) {
                Costmin[ci][cs][urm] = Costmin[ci][cs][act] + 1;
                q[++CsQ]=mp(lv, cv);
            }
        }
    }
}
int main ()
{
    f>>T>>n>>m; f.get();
    f.getline(cuv+1, N); l=strlen(cuv+1);
    for (i=1; i<=l; ++i) //pozitia unei litere in cuvant
        poz[cuv[i]]=i;

    lmin=inf; cmin=inf;
    for (i=1; i<=n; ++i) {//citesc matricea
        f>>(a[i]+1);
        for (j=1; j<=m; ++j) {
            if (a[i][j]!='#') { //loc pe unde se poate merge
                ++VV;
                nr[i][j]=VV;
                I[VV]=i; J[VV]=j;
            }
            if ('A'<=a[i][j] && a[i][j]<='Z') { // e litera
                lmin=min(lmin, i); cmin=min(cmin, j);
                lmax=max(lmax, i); cmax=max(cmax, j);

                X[poz[a[i][j]]]=i;
                Y[poz[a[i][j]]]=j;
            }
        }
    }
    if (T==1) {
        g<<(lmax-lmin+1)*(cmax-cmin+1)<<"\n";
        return 0;
    }
    for (i=1; i<=l; ++i) {
        for (j=1; j<=VV; ++j) Costmin[i][i][j]=inf;
        Costmin[i][i][nr[X[i]][Y[i]]]=0;

        CiQ=1; CsQ=1; q[CiQ]=mp(X[i], Y[i]); LEE (i, i);
    }

    for (k=2; k<=l; ++k) //lungimea 'echipei'
        for (i=1; i<=l-k+1; ++i) { //pozitia de start a 'echipei'
            j=i+k-1; CiQ=1; CsQ=0; test[i][j]=inf;

            for (P=1; P<=VV; ++P) { //pozitia de pe harta care e libera
                Costmin[i][j][P]=inf;
                minn=Costmin[i][j][P];

                for (aux=i; aux<j; ++aux)
                    minn=min((short)(minn), (short)((Costmin[i][aux][P]) + (Costmin[aux+1][j][P])));

                Costmin[i][j][P]=minn;
                q[++CsQ]=mp(I[P], J[P]);
            }
            LEE (i, j);

            for (P=1; P<=VV; ++P)
                test[i][j]=min(test[i][j], Costmin[i][j][P]);
        }
    minn=inf;
    for (i=1; i<=VV; ++i) minn=min(minn, Costmin[1][l][i]);

    if (minn==inf) g<<"-1\n";
              else g<<minn<<"\n";

    return 0;
}
