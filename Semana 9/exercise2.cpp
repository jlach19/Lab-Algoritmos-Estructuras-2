#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node *previous;
};

struct Stack
{
    Node *top;

    // Constructor
    Stack()
    {
        top = nullptr;
    }

    // Insertar elemento a la pila
    void push(int x)
    {
        Node* new_node = new Node;
        new_node -> data = x;
        new_node -> next = top;
        new_node -> previous = nullptr;

        if (top != nullptr)
        {
            top -> previous = new_node;
        }

        top = new_node;
    }

    // Eliminar un elemento de la pila
    void pop()
    {
        if (top == nullptr)
        {
            return; // No hace nada si la pila esta vacia
        }
        
        // eliminamos el ultimo nodo
        Node* temp = top;
        top = top -> next;

        if (top != nullptr)
        {
            top -> previous = nullptr;
        }

        delete temp;
    }

    // ver el ultimo elemento de la pila
    int top_stack() {
        return top -> data;
    }

    bool is_empty()
    {
        return top == nullptr;
    }
    
};

int main()
{
    int t;
    scanf("%d", &t);
    Stack my_stack;

    while (t > 0)
    {
        int x;
        scanf("%d", &x);

        if (x == 1)
        {
            int n;
            scanf("%d", &n);
            my_stack.push(n);
        } else if (x == 2)
        {
            my_stack.pop();
        } else
        {
            if (my_stack.is_empty())
            {
                printf("Empty!\n");
            } else 
            {
                printf("%d\n", my_stack.top_stack());
            }
        }
        
        t--;
    }
    
    return 0;
}
