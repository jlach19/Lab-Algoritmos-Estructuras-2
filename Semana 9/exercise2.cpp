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
        
        t--;
    }
    
    return 0;
}