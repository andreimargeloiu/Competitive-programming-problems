# include <cstdio>
#include <set>
using namespace std;
int main()
{
    freopen ("heap.in", "r", stdin);
    freopen ("heap.out", "w", stdout);
    multiset <int> my_set;
    my_set.insert(1); // Insereaza o valoare.
    my_set.insert(1);

    if (my_set.find(1) != my_set.end())
        { // Cauta o valoare.
        printf("Am gasit 1 in set!\n");
        } else {
                    printf("1 nu se afla set!\n");
               }

    // Sterge o valoare din set. Daca aceasta se afla de
    // mai multe ori in set, este stearsa numai o copie.
    my_set.erase(my_set.find(1));
    printf("Exista %d elemente in set\n", my_set.size());

    my_set.insert(1);
    my_set.insert(1);

    // Sterge o valoare din set. Daca aceasta se afla de
    // mai multe ori in set, sunt sterse toate copiile.
    my_set.erase(1);
    printf("Exista %d elemente in set\n", my_set.size());

    my_set.insert(1);
    my_set.insert(-3);
    my_set.insert(7);

    // Valoarea minima.
    multiset <int> :: iterator it = my_set.begin();
    printf("Valoarea cea mai mica din set este %d\n", *it);

    // Valoarea maxima.
    it = my_set.end();
    --it;
    printf("Valoarea cea mai mare din set este %d\n", *it);
    return 0;
}
