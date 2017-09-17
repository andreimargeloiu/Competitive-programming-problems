# include <bits/stdc++.h>
# define mp make_pair
# define f first
# define s second
# define NR 105
using namespace std;
ifstream f("tower8.in");
ofstream g("tower8.out");
pair <int, int> M[200*NR];
vector <pair <int, int> > st[10];
deque <pair<int, int> > d[10];
int i,j,n,m,x,y,VV,P,I,J;
int a[NR][NR];
int dx[]={-1, -1, -1, 0, 1, 1, 1, 0};
int dy[]={-1, 0, 1, 1, 1, 0, -1, -1};
void pune (int i, int j, int K) {
    if (a[i][j]!=0) return;
    if (K==1) {a[i][j]=1; return;} //pun 1

    for (int o=0; o<8; ++o) {
        pune (i+dx[o], j+dy[o], K-1); //pun un K-1 pe un vecin
        if (a[i+dx[o]][j+dy[o]]==K-1) { //daca a reusit sa puna K-1 pe vecin
            pune(i, j, K-1); //incerc sa pun K-1 aici
        } else continue; //

        if (a[i][j]==K-1) {
            a[i][j]=K;
            a[i+dx[o]][j+dy[o]]=0;
            return;
        } else a[i+dx[o]][j+dy[o]]=0;
    }
}
void pune2 (int i, int j, int K) {
    int top=VV; // cu ce intra stiva in functie
    if (a[i][j]!=0) return;
    if (K==1) {a[i][j]=1; ++VV; M[VV].f=i; M[VV].s=j; return;}
    for (int o=0; o<8; ++o) {
        pune2 (i + dx[o], j + dy[o], K-1);
        if (a[i+dx[o]][j+dy[o]]==K-1) {
            pune2 (i, j, K-1);
        } else { VV=top; continue; }

        if (a[i][j]==K-1) {
            a[i][j]=K;
            a[i+dx[o]][j+dy[o]]=0;
            return;
        } else { a[i+dx[o]][j+dy[o]]=0; VV=top; }
    }
}
void bordare () {
    for (int i=0; i<=n+1; ++i)
        a[i][0]=a[i][m+1]=10;
    for (int i=0; i<=m+1; ++i)
        a[0][i]=a[n+1][i]=10;
}
int main ()
{
    f>>n>>m;
    bordare ();
    for (i=1; i<=n; ++i)
        for (j=1; j<=m; ++j) {
            f>>a[i][j]; P=P + (1<<(a[i][j]-1));
            d[a[i][j]].push_back(mp(i, j));
        }

    g<<P<<"\n";
    for (i=1; i<=9; ++i) {
        while (! d[i].empty()) {
            I=d[i].front().f; J=d[i].front().s;
            a[I][J]=0; // sterg ce este aici
            pune(I, J, i); //incerc sa-l pun din nou
            if (a[I][J]==i) { //daca am reusit sa il pun
                              //inseamna ca in pot pune dupa ce le
                              //le pun pe toate cele din urma
                st[i].push_back(mp(I, J));
                a[I][J]=0;
            } else { d[i].push_back(d[i].front()); a[I][J]=i;}

            d[i].pop_front();
        }
    }
    for (i=9; i>=1; --i) {
        for (int q=st[i].size()-1; q>=0; --q) {
            VV=0;
            pune2(st[i][q].f, st[i][q].s, i);
            for (j=1; j<=VV; ++j)
                g<<M[j].f<<" "<<M[j].s<<"\n";
        }
    }


    return 0;
}
