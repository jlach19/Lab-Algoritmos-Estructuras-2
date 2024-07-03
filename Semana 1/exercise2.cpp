/**
 * Este codigo lo que haces es recibir por 
 * medio de un bucle un numero y lo mostrara 
 * por la consola mientras que sea distinto 
 * de 42. Cuando el numero es 42 no mostrara 
 * el numero por consola y saldra del bucle 
 * para finalizar el programa.
*/
#include <iostream>
using namespace std;

int main()
{
    int x;

    while (true)
    {
        cin >> x;

        if ( x != 42 )
        {
            cout << x << endl;
        } else
        {
            break;
        }
    }

    return 0;
}
