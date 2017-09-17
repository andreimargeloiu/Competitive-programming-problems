# include <fstream>
# include <algorithm>
# include <vector>
# include <cstring>
# define NR 105
using namespace std;
ifstream f("plimbare.in");
ofstream g("plimbare.out");
vector <int> v[NR], ctc[NR];
int i,j,n,m,x,y,CTC,VV,L,ok,k,urm,maxx,maxL,l,v1,v2;
int s[NR], ap[NR], arc[NR][NR], st[NR], A[NR], C[NR], D[NR], lant[NR], sol[NR], SOL[NR], CC[NR];
void DFS (int k)
{
    ap[k]=1; st[++VV]=k;
    for (int i=0; i<v[k].size(); ++i)
        if (! ap[v[k][i]]) DFS (v[k][i]);
}
void DFS2 (int k)
{
    ap[k]=0; ctc[CTC].push_back(k); CC[k]=CTC;
    for (int i=0; i<v[k].size(); ++i)
        if (ap[v[k][i]]) DFS2 (v[k][i]);
}
void CompTareConexe ()
{
    int i;
    for (i=1; i<=n; ++i)
        if (! ap[i]) DFS (i);

    for (i=VV; i>=1; --i)
        if (ap[st[i]]) {
            ++CTC;
            DFS2 (st[i]);
        }
}
void DF (int k) //facem lantul;
{
    st[++VV]=k; ap[k]=VV;
    for (int i=0; i<v[k].size() && !ok; ++i)
        if (CC[v[k][i]]==CC[k]) {

        if (! ap[v[k][i]]) DF (v[k][i]);
        else { // am gasit ciclul
            ok=1;
            //facem lantul
            for (int j=ap[v[k][i]]; j<=VV; ++j) {
                lant[++L]=st[j];
                A[st[j]]=1;
            }
        }
    }
}
void inserare (int poz, int val)
{
    for (int i=L+2; i>poz; --i)
        lant[i]=lant[i-1];
    lant[poz]=val;
    ++L;
}
void updateC (int k)
{
    for (int i=0; i<v[k].size(); ++i) { // verific cu celelalte si le bag in multimea C
        int urm=v[k][i];
        if (! A[urm]) C[urm]=1;
    }
}
void updateD (int o)
{
    for (int i=0; i<ctc[o].size(); ++i) {
        int k=ctc[o][i];
        if (! A[k] && ! D[k]) {//daca nu e pe lant
            for (int j=0; j<v[k].size(); ++j)
                if (A[v[k][j]]) D[k]=1;
        }
    }
}
void cautaB (int o) {
        ok=1;
        while (ok) {
            ok=0;
            for (int i=0; i<ctc[o].size(); ++i) { //cautam noduri din B
                k=ctc[o][i];
                if (! A[k] && (C[k] && D[k])) { // atunci trebuie sa-l unim la ciclu
                   for (int j=1; j<=L; ++j) {
                        if (arc[lant[j]][k] && arc[k][lant[j+1]]) {
                            A[k]=1; ok=1;
                            inserare (j+1, k);

                            // trebuie sa actualizam ceilalti membrii
                            updateC (k); updateD (o);

                            break;
                        }
                   }
                }
            }
        }
}
int main ()
{
    f>>n;
    for (i=1; i<=n*(n-1)/2; ++i) {
        f>>x>>y;
        v[x].push_back(y);
        arc[x][y]=1;
    }
    CompTareConexe ();

    // A - multimea nodurilor de pe lant
    // B - multimea nodurilor care au muchie dus-intors in lant
    // C - multimea nodurilor care au muchii dinspre lant
    // D - multimea nodurilor care au muchie inspre lant

    for (int o=1; o<=CTC; ++o) {
        memset (ap, 0, sizeof(ap));
        memset (st, 0, sizeof(st));
        memset (A, 0, sizeof(A));
        memset (C, 0, sizeof(C));
        memset (D, 0, sizeof(D));
        memset (lant, 0, sizeof(lant));
        VV=0; ok=0; L=0;

        // facem lantul
        DF (ctc[o][0]);

        // acum avem lantul

        //facem multimile
        for (i=1; i<=L; ++i)  //fiecare nod din lant
            updateC (st[i]);
        updateD (o);

        lant[L+1]=lant[1]; // pentru ciclicitate

        //acum avem si multimile
        //vrem sa bagam nodurile din multime B in ciclu
        cautaB (o);
        // ne mai ramane sa unim muchiile din C cu cele din D si sa le punem la ciclu

        // SOLUTIE @@@@@@@@@@@
        maxL=0;
        for (i=1; i<=L; ++i) {
            k=lant[i]; urm=lant[i+1];

            sol[++maxL]=k;

            for (j=0; j<ctc[o].size(); ++j)
                for (l=0; l<ctc[o].size(); ++l) {
                    v1=ctc[o][j]; v2=ctc[o][l];
                    if (!A[v1] && !A[v2]) {
                        if (arc[k][v1] && arc[v1][v2] && arc[v2][urm]) {
                            A[v1]=1; A[v2]=1;
                            sol[++maxL]=v1; sol[++maxL]=v2;
                            cautaB (o);
                        }
                    }
                }
        }

        if (maxL > maxx) {
            maxx=maxL;
            for (i=1; i<=maxL; ++i)
                SOL[i]=sol[i];
        }
    }
    g<<maxx<<"\n";
    for (i=1; i<=maxx; ++i)
        g<<SOL[i]<<" ";
    g<<"\n";


    return 0;
}
