using namespace std;
#include <iostream>
#include <array>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    int x, y;
};

double calcularDistancia(point p1, point p2)
{
    double distancia;
    distancia = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distancia;
}

void leerPuntos(vector<point>& puntos)
{
    cout << "¿Desea ingresar los puntos manualmente? (s/n): " << endl;
    char m;
    cin >> m;
    
    if (m == 's')
    {
        int cuantos;
        cout << "Cuantos puntos desea ingresar? : " << endl;
        cin >> cuantos;
        for (int i = 0; i < cuantos; i++)
        {
            point p;
            cout << "Ingrese las coordenadas del punto " << i+1 << " (x, y): " << endl;
            cin >> p.x >> p.y;
            puntos.push_back(p);
        }
    }
    else
    {
        vector<point> puntos = {{0, 0}, {1, 1}, {2, 2}};
    }
}


void CalculoDistanciaMasCercana(const vector<point>& puntos, int n, const point& pUsuario, int& IndiceMasCercano)
{
    double distanciaMinima = INFINITY;

    for (size_t i = 0; i < n; i++)
    {
        double distancia = calcularDistancia(pUsuario, puntos[i]);
        if (distancia < distanciaMinima)
        {
            distanciaMinima = distancia;
            IndiceMasCercano = i;
        }
    }
}


void mostrarResultado(const vector<point>& puntos, int indiceMasCercano, double distanciaMinima)
{
    cout << "El punto más cercano es: (" << puntos[indiceMasCercano].x << ", " << puntos[indiceMasCercano].y << ")" << endl;
    cout << "La distancia al punto más cercano es: " << distanciaMinima << endl;
}

int main() 
{
    vector<point> puntos;
    leerPuntos(puntos);
    int n = puntos.size();

    if (n < 2)
    {
        cout << "Se requieren al menos 2 puntos para calcular distancias." << endl;
        return 1;
    }

    point pUsuario;
    cout << "Ingrese las coordenadas del punto desde el que calcular la distancia (x y): ";
    cin >> pUsuario.x >> pUsuario.y;

    int indiceMasCercano;
    double distanciaMinima;
    CalculoDistanciaMasCercana(puntos, n, pUsuario, indiceMasCercano);

    mostrarResultado(puntos, indiceMasCercano, distanciaMinima);
    return 0;
}
