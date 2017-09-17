# include <bits/stdc++.h>
# define NR 10005
# define inf 999999999
using namespace std;
ifstream f("delivery.in");
ofstream g("delivery.out");

int i,j,n,m,NrProduse,NrDrone,Deadline,MaxLoad,NrDepozite,TimpDrona;
int Q, Xdestinatie, Ydestinatie, NrProduseComanda, Comenzi;
int AmPus, PotPune, ProdusX, Xdrona, Ydrona, CateIncap, DronaACT;
int Greutate[NR], Xdepozit[NR], Ydepozit[NR], PD[NR][NR];
int Cer[NR];
struct elem {
    int ind, x, y, timp;
}E;
struct cmp {
    bool operator ()(const elem &a, const elem &b) const{
        return a.timp > b.timp;
    }
};
vector <elem> HEAP;
struct drone {
    char command;
    int deposit, IDproduct, NumberProducts, customer;
};
vector <drone> DRONE[NR];

// A good programmer writes code that can be understood by humans, not by computers.

void loadDrone (int IDdrone, int deposit, int IDproduct, int NumberProducts) {
    drone D;
    D.command='L'; D.deposit=deposit; D.IDproduct=IDproduct; D.NumberProducts=NumberProducts;

    DRONE[IDdrone].push_back(D);
}
void delivery (int IDdrone, int customer, int IDproduct, int NumberProducts) {
    drone D;
    D.command='D'; D.customer=customer; D.IDproduct=IDproduct; D.NumberProducts=NumberProducts;

    DRONE[IDdrone].push_back(D);
}
double make_timp (int x, int y, int x2, int y2) {
    double t, t2;
    t=sqrt((double)((x-x2)*(x-x2) + (y-y2)*(y-y2)));

    t2=(double)((int)(t));
    if (t > t2) {
        t=t+1;
    }
    return (int)(t);
}
void scoate () {
    pop_heap(HEAP.begin(), HEAP.end(), cmp());
    HEAP.pop_back();
}
void baga (int ind, int X, int Y, int timp) {
    elem E;
    E.ind=ind; E.x=X; E.y=Y; E.timp=timp;

    HEAP.push_back(E);
    push_heap(HEAP.begin(), HEAP.end(), cmp());
}
void citire () {
    int i,j;
    f>>n>>m>>NrDrone>>Deadline>>MaxLoad;

    f>>NrProduse;
    for (i=0; i<NrProduse; ++i)
        f>>Greutate[i];

    f>>NrDepozite;
    for (i=0; i<NrDepozite; ++i) {
        f>>Xdepozit[i]>>Ydepozit[i];
        for (j=0; j<NrProduse; ++j)
            f>>PD[i][j];
    }

    //baga drone in heap
    for (i=0; i<NrDrone; ++i)
        baga (i, Xdepozit[0], Ydepozit[0], 0);
}
int main ()
{
    citire ();

    f>>Q;
    int ok=0;
    for (int q=0; q<Q; ++q) {
        f>>Xdestinatie>>Ydestinatie;
        f>>NrProduseComanda;

        memset (Cer, 0, sizeof(Cer));
        for (i=0; i<NrProduseComanda; ++i) {
            f>>ProdusX;
            ++Cer[ProdusX];
        }
        //luam fiecare produs
        for (i=0; i<NrProduse; ++i) { //produsul
            if (Cer[i]) {
                CateIncap = MaxLoad / Greutate[i];

                while (Cer[i]>0) { //luam drone
                    if(HEAP.size() == 0) break;

                    DronaACT=HEAP[0].ind;
                    Xdrona=HEAP[0].x;
                    Ydrona=HEAP[0].y;
                    TimpDrona=HEAP[0].timp;
                    scoate();
                    AmPus=0;
                    for (j=0; j<NrDepozite && AmPus < CateIncap && Cer[i]>0; ++j) { // depozitul
                        if (PD[j][i]) { // daca gasesc acest produs
                            PotPune=min(PD[j][i], CateIncap-AmPus);
                            PotPune=min(PotPune, Cer[i]);

                            PD[j][i]-=PotPune;
                            AmPus+=PotPune;
                            Cer[i]-=PotPune;

                            TimpDrona+=make_timp (Xdrona, Ydrona, Xdepozit[j], Ydepozit[j]);
                            TimpDrona++;

                            if (TimpDrona<Deadline) {
                                loadDrone (DronaACT, j, i, PotPune);
                                   ++Comenzi;
                            }

                            Xdrona=Xdepozit[j]; Ydrona=Ydepozit[j];
                        }
                    }

                    // facem delivery
                    TimpDrona+=make_timp(Xdrona, Ydrona, Xdestinatie, Ydestinatie);
                    TimpDrona++;

                    baga (DronaACT, Xdrona, Ydrona, TimpDrona);
                    Xdrona=Xdestinatie; Ydrona=Ydestinatie;

                    if (TimpDrona<Deadline) {
                        delivery (DronaACT, q, i, AmPus);
                        ++Comenzi;
                    }
                }
            }
        }
    }

    //afisare
    g<<Comenzi<<"\n";
    for (int d=0; d<NrDrone; ++d) {
        for (i=0; i<DRONE[d].size(); ++i) {
            if (DRONE[d][i].command=='D') { //delivery
                g<<d<<" D "<<DRONE[d][i].customer<<" "<<DRONE[d][i].IDproduct<<" ";
                g<<DRONE[d][i].NumberProducts<<"\n";
            }
            else { //loadDrone
                g<<d<<" L "<<DRONE[d][i].deposit<<" "<<DRONE[d][i].IDproduct<<" ";
                g<<DRONE[d][i].NumberProducts<<"\n";
            }
        }
    }

    return 0;
}
