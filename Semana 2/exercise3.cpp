/**
 * Primeramente, se crea una funcion que aplica el algoritmo
 * de ordenamiento bubblesort para ordenar un vector de 
 * enteros de forma ascendente.
 * 
 * Posteriormente, dentro de la funcion main, el programa recibe 
 * como input el numero de casos de prueba. Luego, se crea un bucle 
 * que va iterar la cantidad de veces segun sea el numero de casos 
 * de prueba. 
 * 
 * Creo una variable, se recibe como input el valor del tamaño
 * del arreglo y se almacenara en dicha variable. Luego, creo 
 * un vector de enteros que se incializara con el tamaño del 
 * arreglo y otro vector de enteros que usaremos mas adelante 
 * que se llama "ans".
 * 
 * Por medio de un bucle, rellenamos el vector que tiene el 
 * tamaño del arreglo con los numeros que recibiremos de input. 
 * Al salir de este bucle aplicamos la funcion que realiza el 
 * ordenamiento bubble sort al vector que acabamos de rellenar.
 * 
 * Creo una variable llamada "subtraction". Ademas, usaremos un bucle 
 * para recorrer el vector (de izquierda a derecha) que contiene
 * los elementos del arreglo para asi restar cada dos elementos 
 * del vector (vector[i] - vector[i - 1]), el resultado de esa
 * resta se almacena en la variable mencionada y esa variable se
 * añadira como elemento al vector "ans". Al salir del bucle 
 * creamos una variable que se llamara "add" y volvemos a crear 
 * otro bucle para recorrer el vector "ans" y dentro del bucle 
 * se le sumara a la variable "add" cada elemento del vector "ans".
 * 
 * Finalmente, se mostrara por consola el valor de la variable "add".
 * Ademas, se le restara uno a la variable que contiene el numero de 
 * casos de prueba y el bucle mas externo seguira su ejecucion hasta 
 * que el numero de casos de prueba sea igual a cero y culminara el 
 * programa.
*/
#include <iostream>
#include <vector>

using namespace std;

// Algoritmo de ordenamiento bubble sort.
void bubblesort (vector <int> &arr)
{
    /**
     * El algoritmo usa dos variables que son la "i" y la "j". 
     * La variable i va indicar una posicion del vector partiendo
     * de la primera posicion hasta la ultima por medio del 
     * siguiente bucle que, a su vez, contendra un bucle anidado.
    */
    for (int i = 0; i < arr.size(); i++)
    {   
        /**
         * Este bucle anidado usara la variable j para indicar 
         * una posicion del vector desde la ultima posicion del
         * vector hasta la posicion i + 1.
        */
        for (int j = arr.size() - 1; i + 1 <= j; j--)
        {
            /**
             * A medida que j va tomando alguna posicion en el 
             * vector comparara el valor del elemento de la posicion 
             * j con el valor del elemento adyacente a su izquierda, 
             * es decir, con el elemento de posicion j - 1. En caso 
             * de que el elemento en la posicion j sea menor al 
             * elemento de la posicion j - 1, entonces se intercambian
             * los valores entre si.
            */
            if (arr[j] < arr[j - 1])
            {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
        
    }
}


int main ()
{
    int t;
    cin >> t;

    while ( t > 0 )
    {
        int n;
        cin >> n;
        
        vector <int> arr (n);
        vector <int> ans;

        for ( int i = 0; i < n; i++ )
        {
            cin >> arr[i];
        }

        // Aplico el algoritmo de ordenamiento bubblesort.
        bubblesort(arr);    

        int subtraction = 0;

        for ( int i = 1; i < arr.size(); i++ )
        {
            subtraction = arr[i] - arr[i - 1];
            ans.push_back(subtraction);
        }
        
        int add = 0;

        for ( int i = 0; i < ans.size(); i++ )
        {
            add += ans[i];
        }

        // Output
        cout << add << endl;

        t--;
    }
        
}
