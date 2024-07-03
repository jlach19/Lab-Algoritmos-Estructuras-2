/**
 * Primeramente se crean dos funciones:
 * 
 * 1. Funcion merge: Realiza la combinacion de dos mitades de un vector para que
 * al final nos resulte un solo vector ordenado.
 * 
 * 2. Funcion mergesort: aplica el algoritmo de ordenamiento de merge sort
 * 
 * Dentro de la funcion main primero creo una variable "t" que sera el numero de casos de prueba el 
 * cual solicitare al usuario. Posteriormente aplico un bucle while para ejecutar cada 
 * uno de los casos de prueba.
 * 
 * Dentro del bucle solicito por consola el tamaño del vector y luego relleno un vector
 * de pares con los numeros que sean introducidos por consola con su respectiva posicion.
 * Luego, ordeno el vector llamando a la funcion mergesort.
 * 
 * Posteriormente, creo un vector donde cada elemento sera la suma acumulada desde el
 * primer numero del vector que se ordeno.
 * 
 * Posteriormente, calculo la suma acumulada desde el primer elemento del vector hasta
 * hasta el elemento que esta en la posicion i del vector (incluyendo en la suma el 
 * numero en la posicion i) y dicha sumatoria se va agregar como elemento en otro 
 * vector en la posicion i.
 * 
 * Luego de haber rellenado todo el vector de las sumas acumuladas, creo un vector que sera
 * usado en un bucle for que me ayudar a ir asignando los elementos en las respectivas posiciones 
 * del vector que usare como respuesta para cada caso.
 * 
 * Posteriormente, creo un bucle for para imprimir por consola el vector que es respuesta del caso.
 * Al salir del for, se le resta 1 a la variable "t" y el bucle while continua hasta que ya no hayan
 * casos de prueba y asi finaliza el programa.
*/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

/**
 * Esta funcion merge hace la combinacion de dos mitades de un vector.
 * Los parametros que recibe son de un vector de pares, el primer indice 
 * de la primera mitad del vector, el indice final de la primera mitad del vector
 * y el indice final de la segunda mitad del vector. 
 * 
 * Esta funcion asume que el vector desde la posicion l hasta
 * la posicion m y el vector desde la poscion m+1 hasta la posicion r estan
 * ordenados y luego combina estos dos subvectores en uno solo de forma
 * tal que la combinacion nos quede un vector ordenado.
 * 
*/
void merge(vector<pair<long long, int> > &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1; // Calculo el tamaño de la primera mitad del vector.
    int n2 = r - m; // Calculo el tamaño de la segunda mitad del vector.

    vector<pair<long long, int > > vec1(n1), vec2(n2);

    // Relleno el vector vec1
    for (i = 0; i < n1; i++) 
    {
        vec1[i] = arr[l + i];
    }

    // Relleno el vector vec2
    for (j = 0; j < n2; j++) 
    {
        vec2[j] = arr[m + 1 + j];
    }

    i = 0;
    j = 0;
    k = l;

    // Combinacion de los dos sub vectores en un solo vector ordenado.
    while (i < n1 || j < n2)
    {
        /**
         * Notemos que las comparaciones que hacemos son de acuerdo al
         * primer elemento del par de los vectores 
        */
        if (j >= n2 || (i < n1 && vec1[i].first <= vec2[j].first))
        {
            arr[k] = vec1[i];
            i++;
        } else
        {
            arr[k] = vec2[j];
            j++;
        }

        k++;
    }
}

/** 
 * Funcion que aplica el algoritmo de ordenamiento de merge sort, el cual es un algoritmo que aplica 
 * la tecnica de divive and conquer.
 * 
 * Divide el vector que le pasemos de entrada en dos mitades y se llama recursivamente
 * para ambas mitades y luego aplica la funcion merge para combinar ambas mitades 
 * resultantes de dicha llamada recursiva y dicha combinacion nos da un vector ordenado.
 */
void mergesort(vector<pair<long long, int> > &vec, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(vec, l, m);
        mergesort(vec, m + 1, r);
        merge(vec, l, m, r);
    }
}

int main()
{
    int t; // Numero de casos de prueba
    cin >> t;

    while ( t > 0 )
    {
        int n;
        cin >> n;

        /**
         * Vector de pares que almacenara como primer elemento del par cada numero
         * de la secuencia que le pase por consola y el segundo elemento del par sera
         * la posicion de cada numero en esa secuencia.
        */
        vector<pair<long long, int> > arr ( n );

        vector<long long> accumulated (n); // Almacena las sumas acumuladas.
        vector<long long> ans (n); // Vector que usare como respuesta del ejercicio.

        // Relleno el vector arr.
        for ( int i = 0; i < n; i++ )
        {
            cin >> arr[ i ].first;
            arr[ i ].second = i;
        }

        mergesort( arr, 0, n - 1 ); // Aplico el algoritmo de ordenamiento mergesort.

        // Relleno el vector accumulated. 
        accumulated[0] = arr[0].first;
        for (int i = 1; i < n; i++)
        {
            accumulated[i] = accumulated[i - 1] + arr[i].first;            
        }
        
        vector<int> indexes; // Este vector me ayudara a ir rellendo mi vector ans.

        for (int i = 0; i < n; i++)
        { 
            indexes.push_back(arr[i].second);

            /** 
             * Si la condicion del if se cumple entonces se procede a ir rellenando 
             * el vector ans con el valor de i en sus respectivas posiciones segun cada 
             * elemento que contenga el vector indexes
            */
            if (i == n-1 || accumulated[i] < arr[i+1].first)
            { 
                for (int e : indexes)
                { 
                    ans[e] = i; 
                } 

                indexes.clear(); 
            } 
        }

        // Output
        for (auto e : ans)
        {
            cout << e << " ";
        }
        cout << endl;

        t--;
    }
    
    return 0;
}