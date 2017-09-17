# include <fstream>
# include <cstdio>
# include <algorithm>
# include <vector>
# define mil 1000005
# define MOD 666015
# define NR 2505
using namespace std;
ifstream f("radio1.in");
vector <int> v[MOD];
int i,j,n,m,x,y,ok,L,K,len;
char s[mil], a[NR];
void preprocesare ()
{
    int cod=0;
    for (int i=1; i<len; ++i)
        cod+=s[i];

    for (int i=len; i<=n; ++i) {
        cod+=s[i]; cod-=s[i-len];
        v[cod].push_back(i-len+1);
    }
}
bool verificare (int poz)
{
    int diferente=0;
    for (int i=0; i<L; ++i)
        if (s[poz+i] != a[i+1]) ++diferente;
    if (diferente<=K) return 1;
                 else return 0;
}
bool check (int cod, int poz)
{
    for (int i=0; i<v[cod].size(); ++i){
        int P=v[cod][i];

        if (P<poz || P+(L-poz)>n) continue;
        else {
                 int ok=1;
                 for (int j=0; j<len && ok; ++j)
                    if (s[P+j]!=a[poz+j]) ok=0;

                 if (ok && verificare (P-poz+1)) return 1;
             }
    }

    return 0;
}
int main ()
{
    freopen ("radio1.out", "w", stdout);
    f>>n>>m>>L>>K; f.get(); len=L/(K+1);
    f.getline (s+1, mil);

    preprocesare ();

    for (i=1; i<=m; ++i) {

        f.getline(a+1, NR); ok=0;
        //iau fiecare subsecventa
        for (j=1; j<=L && !ok; j+=len) {
            int cod=0;
            for (int o=0; o<len; ++o)
                cod=cod + a[j+o];

            ok = check(cod, j); // -> furnizeaza si distanta dintre ci si inceputul secventei cautate
        }

        printf ("%d\n", ok);
    }

    return 0;
}
