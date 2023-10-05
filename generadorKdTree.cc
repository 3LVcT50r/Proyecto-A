#include <iostream>
#include <cstdlib>
#include <vector>

#include "kdTree.hh"
using namespace std;

typedef vector<double> Coord;

int main() {
    int T;      //num de arboles a generar
    int k;      //dimension de cada arbol
    int n;      //num de nodos de cada arbol
    int q;      // num de busquedas

    //cout << "Numero de arboles:" << endl;
    cin >> T;
    cout << T << endl;

    srand(time(NULL));

    for(int i = 1; i <= T; ++i) {   

        //QUE K NO SEA > QUE 6 PORFA
        //cout << "Dimension:" << endl;
        cin >> k;
        cin >> n;
        cin >> q;
        cout << n << " " << k << " " << q << endl;
        vector<Coord> info(n, Coord(k));

        for(int j = 0; j < n; ++j) {
            for(int l = 0; l < k; ++l) {
                double val = double(rand()/double(RAND_MAX));
                info[j][l] = val;
                cout << val << " ";
            }
            cout << endl;
        }
        cout << endl;
        vector<Coord> searches(q, Coord(k));

        for(int j = 0; j < q; ++j) {
            for(int l = 0; l < k; ++l) {
                double val = double(rand()/double(RAND_MAX));
                searches[j][l] = val;
                cout << val << " ";
            }
            cout << endl;
        }
        //cout << endl << endl << "----------------------------------" << endl << endl;

        //kdTree Tree(k);
        //for (int j = 0; j < n; ++j) {
            //Tree.insert(Coords[j], STANDART);
        //}
        //Tree.debug();
    }
}