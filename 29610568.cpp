#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Grafo {

public:
    int V;
    vector<set<int>> grafo;
    vector<bool> visitado();

    Grafo(int vertices) : V(vertices), grafo(vertices) {}

    void agregar_arista(int u, int v) {
        grafo[u].insert(v);
        grafo[v].insert(u);
    }


bool es_bipartito(int src) {
    vector<int> color(V, -1);
    color[src];

    for (int u = 0; u < V; ++u) {
        for (int v : grafo[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
            } else if (color[v] == color[u]) {
                return false;
            }
        }
    }
    return true;
}

bool es_completo() {
        for (int i = 0; i < V; ++i) {
            if (grafo[i].size() != V - 1) {
                return false;
            }
        }
        return true;
}

void dfs(int v, vector<bool>& visitados) {
        visitados[v] = true;
        for (int u : grafo[v]) {
            if (!visitados[u]) {
                dfs(u, visitados);
            }
        }
}

  bool es_euleriano() {
        for (int i = 0; i < V; ++i) {
            if (grafo[i].size() % 2 != 0) {
                return false;
            }
        }
        return true;
}

   bool es_hamiltoniano(){
        int v;
        vector<bool> visitados(V, false);
        vector<int> camino;
        camino.push_back(0);
        visitados[0] = true;
         if (camino.size() == V) {
            return true;
        }
        for (int u : grafo[v]) {
            if (!visitados[u]) {
                visitados[u] = true;
                camino.push_back(u);
                if (es_hamiltoniano()) {
                    return true;
                }
                visitados[u] = false;
                camino.pop_back();
            }
        }
        return false;
    }

};


int main() {
    string archivo;
    cout << "Ingresa el nombre del archivo .txt: ";
    cin >> archivo;

    ifstream fin(archivo);
    int n;
    fin >> n;
    Grafo grafo(n);

    int u, v;
    while (fin >> u >> v) {
        grafo.agregar_arista(u, v);
    }

    int opcion;
    do {
        cout << "\nMenú de opciones:" << endl;
        cout << "1. Verificar si es completo" << endl;
        cout << "2. Verificar si es bipartito" << endl;
        cout << "3. Verificar si es hamiltoniano" << endl;
        cout << "4. Verificar si es euleriano" << endl;
        cout << "5. Salir" << endl;
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << (grafo.es_completo() ? "Es completo" : "No es completo") << endl;
                break;
            case 2:
                cout << (grafo.es_bipartito(0) ? "Es bipartito" : "No es bipartito") << endl;
                break;
            case 3:
                cout << (grafo.es_hamiltoniano() ? "Es hamiltoniano" : "No es hamiltoniano") << endl;
                break;
            case 4:
                cout << (grafo.es_euleriano() ? "Es euleriano" : "No es euleriano") << endl;
                break;
            case 5:
                cout << "Saliendo del programa. Hasta luego!" << endl;
                break;
            default:
                cout << "Opción no válida. Inténtalo de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}










