/**
 * Primeramente, para representar la pila usamos listas doblemente enlazadas.
 * Por lo tanto, creamos una clase llama "Elem" que representa a los elementos de la pila, dichos
 * elementos estaran enlazados ya que tienen dos apuntadores dentro de esta clase: uno apunta al 
 * elemento anterior que esta hacia arriba en la pila que lo llamamos "previous" y otro que apunta
 * al elemento siguiente que esta hacia abajo en la pila que lo llamamos "next". Ademas, esta clase 
 * tambien tiene un valor entero que representa el valor del elemento.
 * 
 * Luego, se crea una clase llamada "Stack" que representa a la pila y contendra al apuntador "top" que 
 * apunta al elemento que esta en la parte superior de la pila. Luego, creamos el metodo contructor de la clase
 * para que en cada instancia inicialice al puntero "top" como nulo.
 * 
 * Luego, creamos el metodo "push" que recibe como parametro un entero. Este metodo lo que hace es insertar un elemento
 * a la pila. El metodo crea el elemento para insertar en la pila con el valor del parametro que le pasamos como argumento
 * al metodo, el apuntador "next" del nuevo elemento apuntara a "top" y el apuntador "previous" del nuevo elemento 
 * sera nulo. Seguidamente, verificamos si "top" es distinto de nulo por medio de un condicional if para que su 
 * puntero "previous" apunte al nuevo elemento y luego (fuera del if) hacemos que "top" apunte a ese nuevo elemento.
 * 
 * Posteriormente, se crea un metodo para eliminar el elemento de la pila que esta en la parte superior.
 * Este metodo se llama "pop" y dentro de este metodo se verifica por medio de un condicional if si la pila esta 
 * vacia (en caso de que lo este no se hace nada en este metodo) si la pila tiene algun elemento entonces se crea
 * un puntero temporal que apuntara a "top" y luego "top" hacemos que apunte al puntero "next" del puntero "top".
 * Luego, creamos un condicional pare verificar si "top" es nulo, de ser cierto entonces su puntero "previous" lo asignamos como nulo
 * y salimos del if para que eliminemos ese puntero temporal que esta representando el elemento de la pila
 * que esta en la parte superior de la pila.
 * 
 * Posteriormente, se crean dos metodos mas: uno es "top_stack" que es para retornar el valor del elemento que esta
 * en la parte superior de la pila y el otro es "is_empty" que verifica si la pila esta vacia y retorna un valor booleano.
 * 
 * Luego, en la funcion main declaramos una variable "t" que representa la cantidad de consultas que seran recibidas
 * como input, se crea una variable de tipo "Stack" que representa la pila y luego creamos a un ciclo while.
 * Dentro de este ciclo se declara una variable "x" que representa la opcion de la consulta y sera recibido
 * como input. Ademas, se crea un else if que primero verifica si "x" es igual a uno (1), de ser cierto entonces
 * se declara una variable "n" que representa el numero que se va añadir a la pila y se recibe como input para
 * luego llamar al metodo "push" de la clase "Stack" y pasarle como argumento la variable "n" para que añada el elemento a la pila; 
 * en caso de que "x" no sea (uno) 1, entonces se verifica que "x" sea igual a (dos) 2 y en caso de ser cierto se
 * elimina el elemento de la parte superior de la pila a traves del metodo "pop" de la clase "Stack"; en caso de 
 * que "x" no sea ni uno (1) ni dos (2) entonces se crea un condicional if else que verifica si la pila esta 
 * vacia por medio del metodo "is_empty" de la clase "Stack", si es cierto entonces imprime por consola el string
 * "Empty!"; en caso contrario, imprime por consola el valor del elemento de la parte superior de la pila por medio 
 * del metodo "top_stack" de la clase "Stack". Luego se le resta uno (1) al valor de "t" y comienza nuevamente el ciclo.
 * 
 * El programa finaliza cuando ya se hayan realizado todas las consultas, es decir, cuando "t" sea igual a cero.
 */
#include <iostream>
using namespace std;

// Clase que representa los elementos de la pila.
struct Elem {
    int data; // Representa el valor del elemento.
    Elem *previous; // Apuntador al elemento anterior (que esta hacia arriba en la pila)
    Elem *next; // Apuntador al elemento siguiente (que esta hacia abajo en la pila)
};

// Clase que representa la pila
struct Stack
{
    // Apuntador al ultimo elemento insertado en la pila (que esta en la parte superior de la pila)
    Elem *top; 

    // Constructor
    Stack()
    {
        top = nullptr;
    }

    // Metodo para insertar un elemento a la pila.
    void push(int x)
    {
        // Creo un elemento para insertar a la pila.
        Elem *new_element = new Elem;
        new_element -> data = x;
        new_element -> next = top;
        new_element -> previous = nullptr;

        // Verificamos si "top" es distinto de nulo.
        if (top != nullptr)
        {
            /**
             * Hacemos que el elemento previo a top apunte
             * al elemento que se acaba de crear.
             */
            top -> previous = new_element;
        }

        top = new_element; // El elemento "top" ahora apuntara al nuevo elemento insertado.
    }

    // Metodo para eliminar el elemento de la pila que esta en la parte supeior.
    void pop()
    {
        // Verificacion de que la pila esta vacia
        if (top == nullptr)
        {
            return; // No hace nada si la pila esta vacia
        }
        
        /**
         * Se crea un apuntador temporal que se inicializa apuntando a "top".
         * Luego hacemos que "top" apunte al elemento que esta apuntador "next"
         * del mismo apuntador "top". Puede ser que dicho elemento que esta 
         * apuntado "next" sea nulo y por lo tanto "front" apuntaria a nulo.
         */
        Elem *temp = top;
        top = top -> next;

        /**
         * Este condicional verifica que el "top" sea distinto de nulo.
         * En caso de ser cierto,  entonces el apuntador al elemento anterior ("previous")
         * del apuntador "top" le asignamos que sea nulo.
         */
        if (top != nullptr)
        {
            top -> previous = nullptr;
        }

        delete temp; // Eliminamos "temp" que es elemento de la pila que esta en la parte superior.
    }

    // Metodo que retorna el valor del elemento que esta en la parte superior de la pila.
    int top_stack()
    {
        return top -> data;
    }

    // Metodo que verifica que la pila esta vacia.
    bool is_empty()
    {
        return top == nullptr;
    }
    
};

int main()
{
    int t; // Cantidad de consultas.
    scanf("%d", &t); // Recibe por consola el valor de la cantidad de consultas.
    Stack my_stack; // Representa a la pila

    while (t > 0)
    {
        int x; // Representa a la opcion de la consulta
        scanf("%d", &x); // Recibe por consola la opcion de la consulta.

        if (x == 1)
        {
            int n; // Representa el valor del elemento que se va añadir a la pila.
            scanf("%d", &n); // Recibe por consola el valor del elemento que se va añadir a la pila.
            my_stack.push(n); // Se añade el elemento a la pila.
        } else if (x == 2)
        {
            my_stack.pop(); // Se elimina el elemento de la parte superior de la pila.
        } else
        {
            if (my_stack.is_empty())
            {
                printf("Empty!\n"); // Imprime por consola el string "Empty!" si la pila esta vacia.
            } else 
            {
                printf("%d\n", my_stack.top_stack()); // Imprime el valor del elemento de la parte superior de la pila.
            }
        }
        
        t--; // Se le resta uno (1) al valor de "t".
    }
    
    return 0;
}