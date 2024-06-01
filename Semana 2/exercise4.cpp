/**
 * Primeramente, se crea una funcion que aplica el algoritmo de ordenamiento bubblesort que recibe un vector de tipo 
 * del tipo pair<pair<int, int> para ordenarlo de forma ascendente segun el segundo elemento del par que esta como primer 
 * elemento de los pares del vector. Seguidamente, se crea una funcion que recibe un vector de tipo pair<pair<int, int>, int > 
 * y realiza un intercambio entre dos elementos del vector en caso de que el segundo elemento del par que esta como primer 
 * elemento de un par del vector sea menor al siguiente (el par que esta a la derecha) y que, a su vez, ambos elementos 
 * coincidan con el segundo elemento del par.
 * 
 * Luego, en la funcion main, creo dos variables y recibo como input dos numeros enteros: la cantidad de numeros que recibire 
 * en la siguiente linea del input, y otro numero el cual indica que los numeros que recibire en la siguiente linea del input 
 * seran iguales o menores a este.
 * 
 * Creo un vector de tipo pair<pair <int, int>, int > del tamaño del primer numero que recibio el programa de input y, 
 * ademas, se crea un entero inicializado en cero.
 * 
 * Ahora rellenamos el vector por medio de un bucle y en dicho bucle sera usado el vector creado anteriormente.
 * 
 * Luego, elimino los elementos del vector que no son importantes y aplico la funcion bubblesort al vector.
 * 
 * Posteriormente, creo una variable de tipo bool que va estar inicializada en false y aplico un bucle para ordenar por 
 * completo el vector de tal forma que el vector viendolo de derecha a izquierda contenga los numeros que deseo que se vayan 
 * a mostrar en consola.
 * 
 * Finalmente, creo un bucle para mostrar por consola los numeros en el orden que me exije el ejercicio que sean mostrados.
*/

#include <iostream>
#include <utility>
#include <vector>
using namespace std;

// Algoritmo de ordenamiento bubble sort.
void bubblesort (vector <pair<pair<int,int>, int > > &arr)
{
    /**
     * El algoritmo usa dos variables que son la "i" y la "j". 
     * La variable i va indicar una posicion del vector partiendo de la primera posicion hasta la ultima por medio del siguiente 
     *  bucle que, a su vez, contendra un bucle anidado. 
    */
    for (int i = 0; i < arr.size(); i++)
    {
        /**
         * El algoritmo usa dos variables que son la "i" y la "j". 
         * La variable i va indicar una posicion del vector partiendo de la primera posicion hasta la ultima por medio del siguiente 
         * bucle que, a su vez contendra un bucle anidado. 
        */
        for (int j = arr.size() - 1; i + 1 <= j; j--)
        {
            /**
             * A medida que j va tomando alguna posicion en el vector verifica que el valor del segundo elemento del par que esta 
             * como primer elemento del par que esta en la posicion j sea menor que el valor del del segundo elemento del par que esta 
             * como primer elemento del par adyacente a su izquierda, es decir, el par que esta en la posicion j - 1; en caso de que 
             * se cumpla entonces se intercambian los los pares entre si.
            */            
            if (arr[j].first.second < arr[j - 1].first.second)
            {
                pair<pair<int,int>, int > temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
        
    }
}

// Funcion para intercambiar elementos del vector y retorna true si se hizo el intercambio o false si no se hizo el intercambio.
bool exchange(vector <pair<pair<int, int>, int > > &vec)
{
    bool r = false; // Esta variable sera la que se usara como retorno de la funcion. La inicializamos en false.

    // Este bucle usa un variable "i" que itera sobre el vector desde la penultima posicion del vector hasta la primera posicion.
    for ( int i = vec.size() - 2; i >= 0; i-- )
    {
        /**
         * Mientras se ejecuta el bucle se verifica si el valor segundo elemento del par que esta en la posicion "i" 
         * del vector es menor que el valor del segundo elemento del par que esta en la posicion "i  + 1" del vector y 
         * que, a su vez, el valor del segundo elemento del par que esta como primer elemento del par que esta en la 
         * posicion "i" sea igual l valor del segundo elemento del par que esta como primer elemento del par que esta 
         * en la posicion "i + 1". En caso de que se cumpla, entonces se intercambian los pares de esas posiciones 
         * entre si y, ademas, la variable "r" se le asigna el valor de true.
        */
        if ( vec[i].second < vec[i + 1].second && vec[i].first.second == vec[i + 1].first.second )
        {
            swap(vec[i], vec[i + 1]);
            r = true;           
        }
    }

    // Retornamos el valor de r.
    return r;
}

int main()
{
    int n, c;
    cin >> n >> c;

    /**
     * Vector que contendra pares donde el primer elemento del par sera otro par de enteros (el primer entero sera 
     * un numero del input y el segundo elemento la frecuencia de dicho numero en el input) y el segundo argumento 
     * del par indicara la posicion en que aparece por primera vez el numero segun el input.
    */
    vector <pair<pair <int, int>, int > > numbers_frequency_position(n); 

    int count = 0;
    
    // Rellenamos el vector numbers_frequency_position
    for ( int i = 0; i < n; i++ )
    {
        bool appearance = false;
        int temp;
        cin >> temp;

        // Recorre el vector numbers_frequency_position 
        for (auto& e : numbers_frequency_position)
        {
            /**
             * Verifica si el numero en este elemento del vector numbers_frequency_position es igual al numero que se 
             * esta pasando como input. 
            */
            if ( e.first.first == temp ) 
            {
                e.first.second++; // Le sumo uno a la frecuencia
                appearance = true;
                break;
            }
        }

        /**
         * La condicion de este if solo se cumplira en caso de que no se haya ejecutado el bloque de codigo del if que 
         * esta dentro del bucle anterior.
        */
        if (appearance == false)
        {
            count++;
            // Asignaremos el valor del numero que se esta leyendo del input en la iteracion.
            numbers_frequency_position[count - 1].first.first = temp; 
            // Asignamos a la frecuencia el valor de 1.
            numbers_frequency_position[count - 1].first.second = 1; 
            /**
             * Asigna el valor de i al vector, lo que significa que esa es la posicion en que aparece el elemento en la 
             * secuencia de numeros que se pasa como input
            */
            numbers_frequency_position[count - 1].second = i; 
        }
    }

    numbers_frequency_position.erase(numbers_frequency_position.begin() + count, numbers_frequency_position.begin() + n );

    // Ordeno el vector numbers_frequency_position segun la frecuencia de los numeros.
    bubblesort( numbers_frequency_position );

    bool ans = true;

    // Aplico este bucle hasta que el vector numbers_frequency_position este ordenado como se desea.
    while ( ans )
    {
        ans = exchange( numbers_frequency_position );
    }

    // Output    
    for ( int i = numbers_frequency_position.size() - 1; i >= 0; i-- )
    {
        for (int j = numbers_frequency_position[i].first.second; j > 0; j--)
        {
            cout << numbers_frequency_position[i].first.first << " " ;
        }
    }
    cout << endl;
    
    return 0;
}