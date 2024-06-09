#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minimum (int a, int b)
{
    if ( a > b)
    {
        return b;
    } else
    {
        return a;
    }
}

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

int main()
{
    int n; // Numero de piezas de sushi
    int temp = 0;
    int large;
    int ans;
    vector<int> max;

    // Solicito el numero de piezas de sushi
    cin >> n;

    vector<int> rolls (n);
    for (int i = 0; i < n; i++)
    {
        cin >> rolls[i];
    }
    
    int count = 1;
    
    for ( int i = 1; i < n; i++ )
    {
        if ( rolls[i - 1] == rolls[i] && i != n - 1)
        {
            count++;
        } else if ( rolls[i - 1] == rolls[i] && i == n - 1 )
        {
            count++;
            large = minimum(temp, count);
            max.push_back(large);
        } else if ( rolls[i - 1] != rolls[i] && i == n - 1 )
        {
            max.push_back(1);
        } else if (temp == 0)
        {
            temp = count;
            count = 1;
        } else
        {
            large = minimum(temp, count);
            max.push_back(large);
            temp = count;
            count = 1;
        }
    }

    bubblesort(max);
    
    cout << max.back() * 2 << endl;

    return 0;
}
