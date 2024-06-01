/**
 * Este programa recibe inicialmente como input el numero de casos 
 * de prueba. Posteriormente, se crea un bucle que va iterar la 
 * cantidad de veces segun sea el numero de casos de prueba. Dentro 
 * del bucle recibo como input dos numeros enteros: el primero indicara
 * el numero total de cartas que tendremos y el segundo la cantidad de 
 * cartas que deben tener los numeros iguales para poder intercambiar.
 * 
 * Luego, creo un vector que almacenara el valor numerico de cada carta 
 * y lo relleno por medio de un bucle el cual recibira como input los 
 * valores numericos de cada carta.
 * 
 * Posteriormente, creo un vector que tendra 500 posiciones cuyo 
 * valor incial de cada posicion sera cero y se procede a rellenar el 
 * vector con la cantidad de repeticiones del numero cada carta, es 
 * decir, si la carta con valor 3 se repite 5 veces entonces el vector de
 * repeticiones en el indice 2 (3 - 1) tendra como valor el 5.
 * 
 * Luego, creo una variable que se incializara en cero y seguidamente creo
 * un bucle para recorrer cada elemento del vector de repeticiones y dentro 
 * del bucle usaremos un if para ver si ese elemento del vector es mayor 
 * o igual a la cantidad de cartas que deben tener los numeros iguales para 
 * poder intercambiar. En caso de que se cumpla la condicion se le suma 1 
 * a la variable mencionada y sale de este bucle; mientras que, si nunca 
 * se cumple la condicion, esa variable permanecera con el valor de cero.
 * 
 * Finalmente, por medio del operador ternario, verificamos si esta ultima 
 * variable que se creo es igual a cero. En caso de que sea igual a cero 
 * entonces se mostrara por consola el valor de la cantidad total de cartas; 
 * mientras que, en caso de que esa variable sea distinta de cero, entonces 
 * mostrara por consola el valor de la cantidad de cartas que deben tener 
 * los numeros iguales para poder intercambiar restandole uno. Ademas, se 
 * le restara uno a la variable que contiene el numero de casos de prueba 
 * y el bucle mas externo seguira su ejecucion hasta que el numero de casos 
 * de prueba sea igual a cero y culminara el programa.
*/
#include <iostream>
#include <vector>
using namespace std;

int main () {
    int t, n, k;

    // Solicito el numero de casos de prueba.
    cin >> t;

    while (t > 0)
    {
        /**
         * Solicito la cantidad total de cartas y la cantidad 
         * de cartas que deben tener los numeros iguales para 
         * poder intercambiar.
        */
        cin >> n >> k;

        vector <int> cartas (n);

        // Relleno el vector cartas
        for ( int i = 0; i < n; i++ ) {
            cin >> cartas[i];
        }

        /**
         * Creo un vector de 500 posiciones inicializado en cero y 
         * luego relleno las posiciones de dicho vector de acuerdo 
         * a las veces que se repita algun numero en el vector cartas.
        */
        vector <int> repeticiones(500,0);
        for ( int i : cartas )
        {
            repeticiones[ i - 1 ]++;
        }
        
        int c = 0;

        for ( int i : repeticiones )
        {
            if ( i >= k )
            {
                c++;
                break;
            }
        }

        // Output
        cout << ( (c == 0 ) ? n : k - 1 ) << endl;

        t--;
    }
    
    return 0;
}