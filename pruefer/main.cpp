#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

typedef struct {
    vector<int> kezd;
    vector<int> veg;
    vector<int> deg;
} graf;

void oda (graf &g, int n);
void vissza (vector<int> &v);
int legkisebbNemElem (vector<int> &v);

int main()
{

    //Ékezetes karakterek megjelenítése
    system("chcp 65001");
    char c;
    do {

        vector<int> adat;
        graf g;

        //Cimke
        system("cls");
        cout << "       Prüfer kód" << endl << endl;

        cout << "Kódból gráf(k), vagy gráfból kód(g)? ";
        cin >> c;

        //Beolvasás
        switch (c) {
        case 'k':
        case 'K': {
            cout << "Adja meg a sorozat elemeit szóközzel enterrel vagy tabbal eválasztva!" << endl <<"Az adatbevitel végét egy nemszám karakter jelezze! " << endl;
            int s;
            cin >> s;
            while (!cin.fail()) {
                adat.push_back(s);
                cin >> s;
            }
            vissza(adat);
            break;
        }
        case 'g':
        case 'G': {
            cout << "Csúcsok száma? ";
            int n;
            cin >> n;
            g.deg.resize(n);
            g.kezd.resize(n);
            g.veg.resize(n);
            for(int i=1; i<n; ++i)
                g.deg[i]=0;
            for(int i=1; i<n; ++i) {
                cout << (i) << ". él kezdő és végpontja? ";
                cin >> g.kezd[i] >> g.veg[i];
                g.deg[g.kezd[i]]++;
                g.deg[g.veg[i]]++;
            }
            oda(g, n);
            break;
        }
        }
        cin.clear();
        cin.ignore(100000, '\n');

        //Újra futtatás
        cout << endl << "Futtassam újra? (I/N) ";
        cin >> c;

    } while (c != 'n' && c != 'N');

    return 0;
}


void oda (graf &g, int n)
{
    int i,j,k;
    for (i=1; i<n-1; i++) {
        j=1;
        while ( (j<=n) && (g.deg[j]!=1) )
            j++;
        k=1;
        while ( (k<n) && (g.kezd[k]!=j) && (g.veg[k]!=j )  )
            k++;
        if (g.veg[k]==j)
            cout << g.kezd[k] << " ";
        else
            cout << g.veg[k] << " ";
        g.deg[ g.kezd[k] ]--;
        g.deg[ g.veg[k] ]--;
        g.kezd[k]=0;
        g.veg[k]=0;
    }
}


void vissza (vector<int> &v)
{
    int n = v.size()+2;
    v.push_back(n);
    cout << n << endl;
    for(int i=0; i<n-1; ++i)
    {
        int legkisebb = legkisebbNemElem(v);
        v.push_back(legkisebb);
        cout << legkisebb << " " << v[0] << endl;
        v.erase(v.begin());
    }
}

int legkisebbNemElem (vector<int> &v)
{
    int s=0;
    while (true){
        s++;
        int j=0;
        while(j<v.size() && v[j]!=s)
            j++;
        if(j==v.size())
            return s;
    }

}

