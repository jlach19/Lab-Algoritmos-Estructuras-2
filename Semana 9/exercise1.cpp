#include <iostream>
using namespace std;

// Clase que representa los elementos de la cola.
struct Elem
{
    int date; // Valor del elemento.
    Elem *next; // apuntador al siguiente elemento.
};

// Clase que representa la cola.
struct Queue
{
    Elem *front; // Apuntador al primer elemento de la cola
    Elem *rear; // Apuntador al ultimo elemento de la cola

    // Constructor
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Metodo para insertar un elemento en la cola
    void enqueue(int x) 
    {
        // Creo un nuevo elemento para la cola
        Elem* new_element = new Elem;
        new_element -> date = x;
        new_element -> next = nullptr;

        if (front == nullptr) 
        {
            /**
             * Inserta el primer elemento a la cola.
             * Por lo tanto, inicializamos los apuntadores
             * de front y rear pra que ambos apunten a este
             * primer elemento que se esta insertando.
             */
            front = new_element;
            rear = new_element;
        } else 
        {   
            /**
             * Inserta el nuevo elemento a la cola pero no es
             * el primer elemento que se inserta.
             * Por lo tanto, el apuntador "next" del apuntador
             * "rear" apuntara al nuevo elemento que se esta
             * insertando en la cola yla variable rear apuntara a
             * ese nuevo elemento insertado. Lo que indica que este
             * elemento es el ultimo de la cola.
             */
            rear -> next = new_element;
            rear = new_element;
        }
    }

    // Metodo que elimina un elemento de la cola
    void dequeue() 
    {
        // Verificacion de que la cola esta vacia.
        if (front == nullptr)
        {
          return; // No hace nada si la cola está vacia.
        }

        /**
         * Creamos un apuntador auxiliar que se inicializa
         * apuntando a front. Luego hacemos que el elemento al que esta 
         * apuntando "next" del apuntador de "front" sea el 
         * nuevo elemento al que apuntara "front".
         */
        Elem *aux = front;
        front = front -> next;

        /**
         * Este condicional lo que hace es verificar si el elemento
         * que se va eliminar es el ultimo elemento que queda en la cola.
         * 
         * Pues, como front ahora apunta al elemento que esta despues del elemento
         * que va eliminar; entonces, en caso de que front sea nulo es porque el
         * elemento que se va a eliminar es el unico que queda en la cola.
         */ 
        if (front == nullptr)
        {
            /**
             * Se hace una asignacion al apuntador de "rear" para que sea nulo tambien.
            */
            rear = nullptr;
        }

        delete aux; // Eliminamos "aux" que es primer elemento de la cola.
    }

    // Metodo que retorna el primer elemento de la cola.
    int front_queue() 
    {
        return front -> date;
    }

    // Metodo que verifica si la cola está vacia.
    bool is_empty() 
    {
        return front == nullptr;
    }
};

int main() 
{
    int t; // Cantidad de consultas.
    scanf("%d", &t); // Recibe por consola el valor de la cantidad de consultas.
    Queue my_queue; // Representa a la cola.

    while (t > 0)
    {
        int x; // Representa a la opcion de la consulta.
        scanf("%d", &x); // Recibe por consola la opcion de la consulta.

        if (x == 1)
        {
            int n; // Representa el valor del elemento que se va añadir a la cola.
            scanf("%d", &n); // Recibe por consola el valor del elemento que se va añadir a la cola.
            my_queue.enqueue(n); // Se añade el elemento a la cola.
        } else if ( x == 2 )
        {
            my_queue.dequeue(); // Eliminamos el primer elemento de la cola
        } else
        {
            if (my_queue.is_empty())
            {
                printf("Empty!\n"); // Imprime por consola el string "Empty!" si la cola es vacia
            } else 
            {
                printf("%d\n", my_queue.front_queue()); // Imprime el valor del primer elemento de la cola
            }
        }
        
        t -= 1; // Se resta uno (1) al valor de "t"
    }

    return 0;
}