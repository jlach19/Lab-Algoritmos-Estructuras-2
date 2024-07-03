/**
 * Primeramente, para representar la cola usamos listas enlazadas. 
 * Es por eso que creamos una clase llamada "Elem" que representa a cada elemento de la cola,
 * dichos elementos estaran enlazados ya que tienen un apuntador dentro de la clase que apunta 
 * al siguiente elemento de la cola ("next"). Ademas, tambien tiene un valor entero que representa
 * el valor del elemento.
 * 
 * Luego, creamos una clase que representa la cola llamada "Queue" y que contendra dos apuntadores: uno que apunta
 * al primer elemento de la cola ("front") y el otro apunta al ultimo elemento de la cola ("rear"). Ademas, usamos el metodo
 * constructor para que en cada instancia de la la clase se inicialicen estos apuntadores como nulos.
 * 
 * Luego, creamos el metodo para insertar un elemento a la cola, dicho metodo se llama "enqueue" y recibe como parametro un valor entero. Dentro de este metodo 
 * se crea un nuevo elemento de la cola con el valor que fue pasado como argumento al metodo y el puntero "next" sera nulo. Luego tanto el apuntador "front" como el apuntador 
 * "rear" apuntaran a este nuevo elemento, en caso de que se este insertando el primer elemento a la cola; o, en caso de que no sea el primer elemento que se esta insertando
 * en la cola, entonces el puntero "next" del puntero "rear" apuntara al nuevo elemento y luego asignamos al puntero "rear" que apunte a este nuevo elemento (ya que es el
 * es el elemento insertado y sera el ultimo en la cola).
 * 
 * Posteriormente, dentro de la misma clase hay otro metodo que es para eliminar el primer elemento de la cola, este metodo es llamado "dequeue".
 * Donde primero verifica que la cola esta vacia o no, si esta vacia no hace nada el metodo y si no lo esta entonces crea un apuntador que lo
 * utilizaremos como auxiliar y que representara al primer elemento de la cola, luego el "front" apuntara al elemento inmediato que le sigue
 * y en caso de que el elemento a eliminar sea el unico que hay en la cola entonces entonces, ademas de que "front" seria un puntero nulo,
 * "rear" pasara a ser un puntero nulo y por ultimo en este metodo se procede a eliminar el apuntador auxiliar (el primer elemento de la cola).
 * 
 * Ademas, tendremos otros dos metodos en esta clase: Uno es un metodo llamado "front_queue" que nos retorna el valor del primer elemento de la cola
 * y el otro metodo llamado "is_empty" que verifica si la cola esta vacia retornando un valor booleano.
 * 
 * Posteriormente, en la funcion main, se declara una variable "t" que representa la cantidad de consultas y estas son recibidas como input
 * y se declara una variable del tipo "Queue" que representa la cola. Luego, creamos un ciclo while y dentro de el se declara una variable "x"
 * que representa la opcion de la consulta que sera recibido como input. Seguidamente creamos un condicional else if donde se verifica si "x" es igual 
 * a uno (1) entonces se declara una variable "n" que representa un entero el cual va ser el que añadiremos a la cola y sera recibido como
 * input y luego llamamos el metodo "enqueue" de la clase "Queue" pasandole como argumento a "n" para añadir el elemento a la cola; en caso de que
 *  "x" no sea uno (1) verifica si "x" es igual a dos (2) entonces  eliminamos el primer elemento de la cola por medio del metodo "dequeue" de la clase "Queue" y si "x" 
 * no es ni uno (1) ni dos (2) entonces creamos a otro condicional if para imprimir el string "Empty!" en caso de que la cola sea vacio (para esto se usa
 * el metodo "is_empty" de la clase "Queue" en la condicion del if) y en caso de que no sea vacio entonces imprime por consola el valor del primer elemento de la cola a 
 * traves del metodo "front_queue" de la clase "Queue" y luego salimos de todos los condicionales para restarle a uno (1) al valor de "t" y volvera a comenzar el ciclo. 
 * 
 * El programa finaliza cuando se hayan realizado todas las consultas, es decir, cuando "t" valga cero.
 */
#include <iostream>
using namespace std;

// Clase que representa los elementos de la cola.
struct Elem
{
    int data; // Valor del elemento.
    Elem *next; // Apuntador al siguiente elemento.
};

// Clase que representa la cola.
struct Queue
{
    Elem *front; // Apuntador al primer elemento de la cola.
    Elem *rear; // Apuntador al ultimo elemento de la cola.

    // Constructor
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Metodo para insertar un elemento en la cola.
    void enqueue(int x) 
    {
        // Se crea un nuevo elemento para insertar a la cola.
        Elem* new_element = new Elem;
        new_element -> data = x;
        new_element -> next = nullptr;

        if (front == nullptr) 
        {
            /**
             * Inserta el primer elemento a la cola.
             * Por lo tanto, hacemos que los apuntadores
             * de "front" y "rear" apunten a este
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
             * insertando en la cola y el puntero "rear" apuntara a
             * ese nuevo elemento insertado. Lo que indica que este
             * elemento es ahora el ultimo de la cola.
             */
            rear -> next = new_element;
            rear = new_element;
        }
    }

    // Metodo que elimina el primer elemento de la cola
    void dequeue() 
    {
        // Verificacion de que la cola esta vacia.
        if (front == nullptr)
        {
          return; // No hace nada si la cola está vacia.
        }

        /**
         * Se crea un apuntador auxiliar que se inicializa
         * apuntando a "front". Luego hacemos que el elemento al que esta 
         * apuntando "next" del apuntador de "front" sea el 
         * al que ahora apuntara "front". Puede ser que dicho elemento
         * que esta apuntado "next" sea nulo y en ese caso "front" seria un puntero nulo.
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

    // Metodo que retorna el valor del primer elemento de la cola.
    int front_queue() 
    {
        return front -> data;
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
            my_queue.dequeue(); // Se elimina el primer elemento de la cola.
        } else
        {
            if (my_queue.is_empty())
            {
                printf("Empty!\n"); // Imprime por consola el string "Empty!" si la cola es vacia.
            } else 
            {
                printf("%d\n", my_queue.front_queue()); // Imprime el valor del primer elemento de la cola si no esta vacia.
            }
        }
        
        t--; // Se resta uno (1) al valor de "t".
    }

    return 0;
}