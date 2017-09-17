# include <bits/stdc++.h>
# define NR 200005
using namespace std;
ifstream f("stratrek.in");
ofstream g("startrek.out");
int
int main ()
{
    f>>n>>K;
    f>>m;
    for (int i=1; i<=n; ++i) {
        f>>poz>>val;
        init[poz]=val;
    }
    for (int i=n; i>=1; --i) {
        urm[i]=URM;
        if (init[i]!=0) URM = i;
    }

    nrAct=1; ramase=K;

    for (int i=1; i<=n; ++i) {
        if (init[i]==0) { // daca este gol si trebuie sa pun
            if (init[i+1]!=0) {// daca am ceva pe urmatorul
                if (init[i+1]==init[i+2] || init[i+2]==0) { //daca pentru viitorul pot pune in dreapta lui
                    // pun cu succes
                    sol[i]=nrAct;
                    --ramase;
                    ++amPus;
                }
            } else {
                sol[i]=i
            }
        }


        if (ramase==0) { // daca il consum si pe ultimul
            ++nrAct;
            ramase=K;
            amPus=0;
        }
    }



    return 0;
}
