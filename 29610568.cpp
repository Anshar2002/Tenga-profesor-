#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "algoritmo.h"

using namespace std;

class Grafo
{
public:
    int V;
    vector<set<int>> grafo;

    Grafo(int vertices) : V(vertices), grafo(vertices) {}

    void agregar_arista(int u, int v)
    {
        grafo[u].insert(v);
        grafo[v].insert(u);
    }

bool es_bipartito(int src) {
    vector<int> color(V, -1); // -1 representa un nodo sin color
    color[src] = 0; // Asignamos el color 0 al nodo fuente
    // Estructura para un vértice
    struct Vertice
    {
        int id;
        vector<int> vecinos;
        bool visitado;
    };

    // Estructura para un grafo
    struct GrafoStruct
    {
        vector<Vertice> vertices;
        vector<vector<int>> aristas; // Matriz de adyacencia o lista de adyacencia
                                     // Métodos para acceder y manipular vértices y aristas
    };
}

    struct Vertice
    {
        int id;
        vector<int> vecinos;
        bool visitado;
    };


 struct GrafoStruct
    {
        vector<Vertice> vertices;
        vector<vector<int>> aristas; // Matriz de adyacencia o lista de adyacencia
                                     // Métodos para acceder y manipular vértices y aristas
    };

    bool verificarIsomorfismo(GrafoStruct &g1, GrafoStruct &g2)
    {
        // Comprobar el número de vértices y aristas
        if (g1.vertices.size() != g2.vertices.size() ||
            g1.aristas.size() != g2.aristas.size())
        {
            return false;
        }

        // Marcar todos los vértices como no visitados
        for (Vertice &v : g1.vertices)
        {
            v.visitado = false;
        }
        for (Vertice &v : g2.vertices)
        {
            v.visitado = false;
        }

        // Iniciar el recorrido DFS desde el primer vértice de g1
        stack<int> pila;
        pila.push(0); // Suponiendo que el índice 0 corresponde al primer vértice

        while (!pila.empty())
        {
            // Extraer el vértice actual de la pila
            int u = pila.top();
            pila.pop();

    for (int u = 0; u < V; ++u) {
        for (int v : grafo[u]) {
             int color [];
            if (color[v] == -1) {
                color[v] = 1 - color[u]; // Asignamos el color opuesto al vecino
            } else if (color[v] == color[u]) {
                return false; // Si encontramos un conflicto de colores, no es bipartito
            // Marcar el vértice actual como visitado en ambos grafos
            g1.vertices[u].visitado = true;
            g2.vertices[u].visitado = true;

            // Recorrer los vecinos del vértice actual en g1
            for (int v : g1.vertices[u].vecinos)
            {
                // Si el vecino no ha sido visitado en g1, agregarlo a la pila y
                // comparar sus vecinos en g1 y g2
                if (!g1.vertices[v].visitado)
                {
                    pila.push(v);

                    // Comprobar si los vecinos correspondientes en g2 tienen el mismo grado
                    // y verificar la igualdad de sus vecinos
                    if (g1.vertices[u].vecinos.size() != g2.vertices[v].vecinos.size())
                    {
                        return false;
                    }

                    sort(g1.vertices[u].vecinos.begin(), g1.vertices[u].vecinos.end());
                    sort(g2.vertices[v].vecinos.begin(), g2.vertices[v].vecinos.end());

                    for (int i = 0; i < g1.vertices[u].vecinos.size(); i++)
                    {
                        if (g1.vertices[u].vecinos[i] != g2.vertices[v].vecinos[i])
                        {
                            return false;
                        }
                    }
                }
            }
        }
     }
}
        }

        // Si no se encuentran discrepancias, los grafos son isomorfos
        return true;
    }
    // Función para colorear un grafo con el algoritmo voraz
void coloreadoVoraz(vector<Vertice>& grafo) {
  // Inicializar colores
  for (Vertice& v : grafo) {
    v.color = -1;
  }

  // Paleta de colores
  vector<int> coloresDisponibles = {1, 2, 3};

  // Recorrer vértices en orden descendente de grado
  sort(grafo.begin(), grafo.end(), [](const Vertice& a, const Vertice& b) {
    return a.adyacencia.size() > b.adyacencia.size();
  });

  for (Vertice& v : grafo) {
    // Probar colores disponibles
    for (int color : coloresDisponibles) {
      bool valido = true;

      // Verificar si el color es válido para el vértice actual
      for (int vecino : v.adyacencia) {
        if (grafo[vecino].color == color) {
          valido = false;
          break;
        }
      }

      // Asignar color si es válido
      if (valido) {
        v.color = color;
        break;
      }
    }
    return true; // Si no hay conflictos, es bipartito
  }
}

// Función para mostrar el coloreado del grafo
void mostrarColoracion(const vector<Vertice>& grafo) {
  for (const Vertice& v : grafo) {
    cout << "Vertice: " << v.nombre << ", Color: " << v.color << endl;
  }
}

    bool es_completo() {
        for (int i = 0; i < V; ++i) {
            if (grafo[i].size() != V - 1) {

    bool es_bipartito(int src)
    {
        vector<int> color(V, -1); // -1 representa un nodo sin color
        color[src] = 0;           // Asignamos el color 0 al nodo fuente

        for (int u = 0; u < V; ++u)
        {
            for (int v : grafo[u])
            {
                if (color[v] == -1)
                {
                    color[v] = 1 - color[u]; // Asignamos el color opuesto al vecino
                }
                else if (color[v] == color[u])
                {
                    return false; // Si encontramos un conflicto de colores, no es bipartito
                }
            }
        }
        return true; // Si no hay conflictos, es bipartito
    }

    bool es_completo()
    {
        for (int i = 0; i < V; ++i)
        {
            if (grafo[i].size() != V - 1)
            {
                return false;
            }
        }
        return true;
    }


    bool es_conexo()
    {
        vector<bool> visitados(V, false);
        dfs(0, visitados);
        bool conexo = true;
        for (bool v : visitados)
        {
            conexo &= v;
        }
        return conexo;
    }
    return conexo;
}

    void dfs(int v, vector<bool>& visitados) {

        visitados[v] = true;
        for (int u : grafo[v])
        {
            if (!visitados[u])
            {
                dfs(u, visitados);
            }
        }
    }

    bool es_euleriano
    {
        for (int i = 0; i < V; ++i)
        {
            if (grafo[i].size() % 2 != 0)
            {
                return false;
            }
        }
        return true;
    }

    bool es_hamiltoniano() {
        vector<bool> visitados(V, false);
        vector<int> camino;
        camino.push_back(0);
        visitados[0] = true;
        return hamiltoniano_util(0, visitados, camino);
    }

    bool hamiltoniano_util(int v, vector<bool> &visitados, vector<int> &camino)
    {
        if (camino.size() == V)
        {
            return true;
        }

        for (int u : grafo[v])
        {
            if (!visitados[u])
            {
                visitados[u] = true;
                camino.push_back(u);
                if (hamiltoniano_util(u, visitados, camino))
                {
                    return true;
                }
                visitados[u] = false;
}
}
            }
        }
    }

};

int main() {

    string archivo;
    cout << "Ingresa el nombre del archivo .txt con la ubicacion proporcionada: ";
    cin >> archivo;
    Grafo grafo(n);

    int u, v;
    while (fin >> u >> v) {

        grafo.agregar_arista(u, v);
    }

    int opcion;
    do
    {
        cout << "\n\n\n\n\n";
        cout << "*****************************************************************************************\n";
        cout << " Analisis de Coordenadas de transporte\n";
        cout << "*****************************************************************************************\n\n";
        cout << "\nMenu de opciones:" << endl;
        cout << "1. Verificar si la coordenada es bipartita" << endl;
        cout << "2. Verificar si la coordenada es completa" << endl;
        cout << "3. Verificar si la coordenada es conexa" << endl;
        cout << "4. Verificar si la coordenada es euleriana" << endl;
        cout << "5. Verificar si la coordenada es hamiltoniana" << endl;
        cout << "6. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << (grafo.Dijkstra() ? "Es bipartito" : "No es bipartito") << endl;
                break;
            case 2:
                cout << (grafo.edmods_karp() ? "Es completo" : "No es completo") << endl;
                break;
            case 3:
                cout << (grafo.kruskal() ? "Es conexo" : "No es conexo") << endl;
                break;
            case 4:
                cout << (grafo.es_bipartito(0) ? "Es bipartito" : "No es bipartito") << endl;
                break;
            case 5:
                cout << (grafo.es_completo() ? "Es completo" : "No es completo") << endl;
                break;
            case 6:
                cout << (grafo.es_conexo() ? "Es conexo" : "No es conexo") << endl;
                break;
            case 7:
                cout << (grafo.es_euleriano() ? "Es euleriano" : "No es euleriano") << endl;
                break;
            case 8:
                cout << (grafo.es_hamiltoniano() ? "Es hamiltoniano" : "No es hamiltoniano") << endl;
                break;
            case 9:
                cout << "Saliendo del programa. ¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción no válida. Inténtalo de nuevo." << endl;

    } while (opcion != 6)


    }
        }







