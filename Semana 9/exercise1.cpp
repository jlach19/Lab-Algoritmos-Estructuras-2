#include <iostream>
using namespace std;

struct Node {
    int date;
    Node* next;
};

struct Queue {
    Node* front;
    Node* rear;

    // Constructor
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }
    // Insertar un elemento en la cola
    void enqueue(int date) 
    {
        Node* new_node = new Node;
        new_node -> date = date;
        new_node -> next = nullptr;

        if (front == nullptr) 
        {
            front = new_node;
            rear = new_node;
        } else {
            rear -> next = new_node;
            rear = new_node;
        }
    }

    // Eliminar un elemento de la cola
    void dequeue() 
    {
        if (front == nullptr) {
          return; // No hace nada si la cola está vacía
        }

        // Elimina el primer nodo
        Node* aux = front;
        front = front -> next;

        if (front == nullptr) {
          rear = nullptr;
        }

        delete aux;
    }

    // Ver el primer elemento de la cola
    int front_queue() {
        return front -> date;
    }

    // Verificar si la cola está vacía
    bool is_empty() {
    return front == nullptr;
    }
};

int main() 
{
    int t;
    scanf("%d", &t);
    Queue my_queue;

    while (t > 0)
    {
        int x;
        scanf("%d", &x);

        if (x == 1)
        {
            int n;
            scanf("%d", &n);
            my_queue.enqueue(n);
        } else if ( x == 2 )
        {
            my_queue.dequeue();
        } else
        {
            if (my_queue.is_empty())
            {
                printf("Empty!\n");
            } else 
            {
                printf("%d\n", my_queue.front_queue());
            }
        }
        
        t -= 1;
    }

    return 0;
}