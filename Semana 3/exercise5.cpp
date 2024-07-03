/**
 * Primeramente creamos las siguientes funciones:
 * 
 * 1. Funcion merge: Realiza la combinacion de dos mitades de un vector para que
 * al final nos resulte un solo vector ordenado.
 * 
 * 2. Funcion mergesort: aplica el algoritmo de ordenamiento de mergesort
 * 
 * 3. Funcion check: Verifica si una cantidad de vacas pueden ubicarse, o no, en los 
 * establos de acuerdo a una distancia minima entre ellas.
 * 
 * 4. Funcion binary_search: una implementacion del algoritmo de binary search
 * para poder encontrar la distancia minima maxima entre las vacas.
 * 
 * Luego, en la funcion main, solicitamos el numero de casos de prueba por la consola.
 * Ademas, creamos un bucle while que nos permitira ejecutar cada caso de prueba.
 * 
 * Dentro del bucle while solcitamos al cantidad de establos y de vacas. Ademas, creo un
 * vector que contendra los establos y los ordeno con el algoritmo de ordenamiento de 
 * mergesort. Luego, con el vector ordenado, aplicamos la binary search y su resultado
 * lo guardamos en una variable que luego imprimiremos por consola.
 * 
 * Finalmente, se resta 1 a la variable de casos de prueba y el bucle while continuara su ejecucion
 * hasta que ya no hayan mas casos de prueba y asi finalizar el programa.
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
void merge(vector<int> &arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1; // Calculo el tamaño de la primera mitad del vector.
    int n2 = r - m; // Calculo el tamaño de la segunda mitad del vector.

    vector<int> vec1(n1);
    vector<int> vec2(n2);

    // Relleno el vector vec1.
    for (i = 0; i < n1; i++) 
    {
        vec1[i] = arr[l + i];
    }

    // Relleno el vector vec2.
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
        if (j >= n2 || (i < n1 && vec1[i] <= vec2[j]))
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
 * Funcion que aplica el algoritmo de ordenamiento de merge sort, el
 *  cual es un algoritmo que aplica la tecnica de divive and conquer.
 * 
 * Divide el vector que le pasemos de entrada en dos mitades y se llama
 * recursivamente para ambas mitades y luego aplica la funcion merge 
 * para combinar ambas mitades resultantes de dicha llamada recursiva 
 * y dicha combinacion nos da un vector ordenado.
 */
void mergesort(vector<int> &vec, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(vec, l, m);
        mergesort(vec, m + 1, r);
        merge(vec, l, m, r);
    }
}

/**
 * Esta funcion tiene como proposito verificar si es posible colocar
 * cierta cantidad de vacas en los establos de acuerdo a una distancia minima
 * entre ellas.
 * 
 * Los parametros que recibe son:
 * 
 * - arr: Vector que indica los establos.
 * - c: La cantidad de vacas que deseamos colocar.
 * - d: Distancia minima entre las vacas.
 * 
 * La funcion, en caso de que si se pueda colocar la cantidad de vacas en los establos
 * segun la distancia minima, entonces retorna true; en caso contrario, retorna false.
*/
bool check(vector<int> &arr, int c, int d)
{
    int count = 1; // Representa a cada vaca.
    int location = arr[0]; // Representa la ubicacion de la ultima vaca puesta en algun establo

    for ( int i = 1; i < arr.size(); i++)
    {
        /**
         * La condicion del if calcula la distancia de la ultima vaca que fue ubicada en algun
         * establo hasta el establo de la posicion "i" y compara si es mayor o igual a la distancia.
        */
        if ( arr[i] - location >= d)
        {
            count++;
            location = arr[i];
        }
    }
    
    return count >= c;
}

/**
 * Algoritmo de binary search.
 * 
 * Recibe como parametros un vector de enterors que esta ordenado y 
 * la cantidad de vacas.
 * 
 * Esta funcion retorna la distancia minima maxima entre las vacas.
*/
int binary_search(vector<int> &stall, int c)
{
    int start = 0;
    int end = stall[stall.size() - 1 ]; 
    int ans = -1; 

    while ( start <= end )
    {
        int middle = ( start + end ) / 2;

        /**
         * Observemos que tenemos como condicion del if la llamada a la funcion
         * check. Si dicha funcion retorna true se ejecuta el bloque de codigo inmediato;
         * en caso contrario, ejecuta el bloque de codigo que esta despues del else.
        */
        if ( check( stall, c, middle ) )
        {
            ans = max(ans, middle);
            start = middle + 1;
        } else 
        {
            end = middle - 1;
        }
    }

    return ans;
}

int main()
{
    int t; // Numero de casos de prueba.
    cin >> t;

    while (t > 0)
    {
        int n, c; // Cantidad de establos y de vacas
        cin >> n >> c; 

        vector<int> stall(n); // Vector de los establos

        // Relleno el vector stall.
        for ( int i = 0; i < n; i++ )
        {
            cin >> stall[i];
        }

        mergesort(stall, 0, n - 1); // Aplico algoritmo de ordenamiento mergesort
        
        int ans = binary_search(stall, c);

        // Output
        cout << ans << endl;

        t--;
    }

    return 0;
}
