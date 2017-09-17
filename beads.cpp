# include <iostream>
# include <algorithm>
# include <fstream>
# include <cstring>
# include <vector>
# define NR 10005
using namespace std;
//ifstream f("beads.in");
//ofstream g("beads.out");
int i,j,n,m,I,T,VV;
int L[NR], poz[20][4*NR], lg[NR];
char s[4*NR];

struct elem {
    int nr1, nr2, i;
}var[2*NR];
bool cmp (elem x, elem y) {
    if (x.nr1 > y.nr1) return 0;
        else if (x.nr1==y.nr1 && x.nr2 >= y.nr2) return 0;
             else return 1;
}

struct elem2 {
    int v[20], i;
}SORT[NR];
bool cmp2 (elem2 x, elem2 y) {
    for (int i=1; i<=L[x.i]; ++i)
        if (x.v[i] > y.v[i]) return 0;
        else if (x.v[i] < y.v[i]) return 1;

    if (x.i >= y.i) return 0;
               else return 1;
}

void logaritmi () {
    for (int i=2; i<=10000; ++i)
        lg[i]=lg[i/2]+1;
}
void init () {
    for (int i=1; i<=n; ++i)
        L[i]=0;
}
int main ()
{
    logaritmi ();
    cin>>T; cin.get();
    for (int t=1; t<=T; ++t) {
        cin.getline (s+1,  NR); n=strlen(s+1);
        init ();

        for (i=1; i<=n; ++i) {
            s[i+n]=s[i];
            s[i+2*n]='$';
            s[i+3*n]='$';
        }

        // facem suffix array
        for (i=1; i<=2*n; ++i)
            poz[0][i]=s[i]-'a'+1;

        for (j=1; j<=lg[n]; ++j) {
            for (i=1; i<=2*n; ++i) {
                var[i].nr1= poz[j-1][i];
                var[i].nr2= poz[j-1][i+(1<<(j-1))];
                var[i].i= i;
            }
            sort (var+1, var+2*n+1, cmp);

            VV=0;
            for (i=1; i<=2*n; ++i) {
                if (var[i].nr1!=var[i-1].nr1 || var[i].nr2!=var[i-1].nr2)
                    ++VV;
                poz[j][var[i].i]=VV;
            }
        }

        //facem codul pentru fiecare pozitie
        for (i=1; i<=n; ++i) {
            I=i;
            for (j=lg[n]; j>=0; --j) {
                if ((1<<j) & n) {
                    SORT[i].v[++L[i]]=poz[j][I];
                    I+=(1<<j);
                }
            }
            SORT[i].i=i;
        }
        sort (SORT+1, SORT+n+1, cmp2);
        cout<<SORT[1].i<<"\n";
    }


    return 0;
}
