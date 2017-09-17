# include <bits/stdc++.h>
# define NR 100005
using namespace std;
int i,j,N,m,VV,last,lastNEW,rasp,urm;
int sol[NR], lg[NR];
void logaritmi () {
    for (int i=2; i<=100005; ++i)
        lg[i]=lg[i/2]+1;
}
void afisare () {
    cout<<"2 "<<VV<<" ";
    for (int i=1; i<=VV; ++i)
        cout<<sol[i]<<" ";
    cout<<"\n";
}
int main ()
{
    last=1; logaritmi();
    cin>>N;

    while (1) {
        lastNEW=last; sol[++VV]=last;
        if (last==N) {
            afisare ();
            return 0;
        }
        for (i=1; i<=lg[N-last+1]; ++i) { //caut binar
            urm=last+(1<<i)-1;
            cout<<"1 "<<last<<" "<<urm<<"\n";
            cout.flush();

            cin>>rasp;
            if (rasp==1) lastNEW=urm;
                    else break;
            if (urm==N) {
                afisare ();
                return 0;
            }
        }
        last=lastNEW+1;
    }

    return 0;
}
