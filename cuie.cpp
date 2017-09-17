// implementata in 30 minute
// am cerut  suplimentar si numarul minim de batai
// pentru a face subsecventa de lungime maxima gasita

// sursa este pe long long (inaltimile sa fie mari, gen 100.000)
// pentru ca la inaltimi mici (<=1000) pot aparea 'bulaneli'
// care sa ia unele inaltimi dupa un rationament stupid
// si sa verifice cu ele, iar solutia sa fie buna

// cred ca intra in 0.1 pe un milion de elemente
# include <bits/stdc++.h>
# define NR 1000005
using namespace std;
ifstream f("cuie.in");
ofstream g("cuie.out");
deque <int> d;
int i,j,n,m,CI,CS,Lmax;
long long costAct, costMaxim, costMinn;
int H[NR];

void bagaDeque (int poz) {
    while (d.size() && H[poz] <= H[d.back()])
        d.pop_back();

    d.push_back(poz); ++CS;
}
bool avanseaza (int poz) {
    int minn;
    if (d.size()) minn=H[d.front()];
             else minn=H[poz];

    if (H[poz] >= minn) { // aduc H[poz] la inaltimea minimului
        long long costNou = costAct + (H[poz] - minn);
        if (costNou <= costMaxim) {
            bagaDeque (poz);
            costAct = costNou;
            return 1;
        } else return 0;
    } else { // in acest caz trebuie sa le aduc pe toate celelate la inaltimea H[poz]
             // - toate anterioarele sunt la inaltimea minn
             // --> deci imi trebuie (minn - H[poz]) * nr scanduri batai
         long long costNou = costAct + 1LL * (minn - H[poz]) * (CS - CI + 1);
         if (costNou <= costMaxim) {
            bagaDeque (poz);
            costAct = costNou;
            return 1;
        } else return 0;
    }
}
void scoate (int poz) {
    int minn;
    if (d.front() == poz) d.pop_front();

    if (d.size()) minn=H[d.front()];
             else minn=H[poz];
    int Hact = H[poz]; // cel pe care il scot

    if (Hact >= minn) { // Hact era adus la inaltimea minn prin (Hact - minn) ciocniri
        costAct -= (Hact - minn);
        ++CI;
    } else { // Hact era minimul pe acea secventa
             // --> asta inseamna ca toate celelate elemente erau aduse la inaltimea Hact
             // --> deci le urcam pe toate la inaltimea minn
        costAct -= 1LL * (CS - CI) * (minn - Hact);
        ++CI;
    }
}
int main ()
{
    f>>n>>costMaxim;
    for (int i=1; i<=n; ++i)
        f>>H[i];

    CI=1; costAct=0;
    // mereu stiu lungimea si costul ca sa fac o subseventa maximala
    // care se termina pe pozitia i
    for (int i=1; i<=n; ++i) {
        while (! avanseaza (i)) {
            scoate(CI);
        }
        if (CS - CI + 1 > Lmax) Lmax = CS - CI + 1, costMinn=costAct;
        else if (CS - CI + 1 == Lmax && costAct < costMinn) costMinn=costAct;
    }

    g<<Lmax<<" "<<costMinn<<"\n";

    return 0;
}
