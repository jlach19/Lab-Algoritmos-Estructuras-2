/**
 * Primeramente se crean nos clases con la palabra reservada "struc":
 * 
 * La clase node representa a cada no del arbol rojo negro y tendra como atributos
 * su valor, la posicion segun fue introducido al arbol, indicara quien es us padre
 * el color y los hijos tanto izquierdo como derecho
 * 
 * Y la clase BTR el cual contiene un metodo constructor para inicializar como nulo
 * la raiz y luego se crean diferentes metodo tales como: insertar un elemento a un arbol,
 * rotaciones tanto para la izquierda como derecha, buscar un elemento en un arbol para
 * indicar el la posicion de dicho elemento cuando fue insertado al arbol e incluso se hace un
 * metodo que ayuda a mantener las propiedades de un arbol rojo blanco.
 * 
 * Luego, tenemos la funcion main. Aqui Declaramos las variables "n", "q" y "value" para indicar
 * la cantidad de elementos a insertar al arbol, la cantidad de queries y el valor de cada elemento
 * a insertar al arbol, respectivamente.
 * 
 * Ademas, creo una variable de tipo RBT que representara el arbol, lo llamo tree. Luego, solicito
 * como input el valor de "n" y de "q" para que inmediatamente crear un ciclo "for" e ir llenando el arbol con
 * los elementos que se iran recibiendo como input.
 * 
 * Seguido de esto, se procede a leer cada query. Para esto se hace un ciclo while y se solicitara como input el elemento
 * que se desea buscar en el arbol para asi mostrar como output su posicion segun fue insertado al arbol. En caso de que 
 * el elemento no exista en el arbol mostara como output -1.
 * 
 * El programa finalizara cuando haya culminado todos los queries
 */
#include<iostream>
using namespace std;

// Representa cada nodo
struct node
{
	int key; // Valor del elemento
	int index; // Representa la posicion en la que fue introducido el elemento al arbol
	node *parent; // nodo padre
	char color; // color del nodo. Donde se identificara con una 'b' si es color es negro o 'r' si es rojo
	node *left; // nodo hijo izquierdo
	node *right; // nodo hijo derecho
};

// Representa al arbol rojo blanco
struct RBT
{
	node *root; // Indica la raiz
    int index= 0; // me permitira ir llenando a cada nodo su respectivo de entrada a medida que voy insertando cada elemento

    // Constructor
	RBT()
	{
		root = nullptr;
	}
	
    // Metodo que permite insertar un elemento en el arbol.
    void insert(int z)
    {
        node *p, *q;
        node *t = new node;
        t -> key = z;
        t -> left = nullptr;
        t -> right = nullptr;
        t -> color = 'r';
        t -> index = index;
        index++;
        p = root;
        q = nullptr;

        if (root == nullptr)
        {
            root = t;
            t->parent = nullptr;
        }
        else
        {
            while (p != nullptr)
            {
                q = p;
                if (p->key < t->key)
                {
                    p = p->right;
                } else
                {
                    p = p->left;
                }
            }

            t->parent = q;

            if (q -> key < t -> key)
            {
                q -> right = t;
            } else 
            {
                q->left = t;
            }
        }
        insert_fix(t);
    }

    // Metodo que es responsable de mantener las propiedades de un arbol rojo negro
    void insert_fix(node *t)
    {
        node *u;

        if (root == t)
        {
            t -> color = 'b';
            return;
        }

        while (t -> parent != nullptr && t -> parent -> color == 'r')
        {
            node *g = t -> parent -> parent;
            if (g -> left == t -> parent)
            {
                if (g -> right != nullptr)
                {
                    u = g -> right;
                    if (u -> color == 'r')
                    {
                        t -> parent->color = 'b';
                        u -> color = 'b';
                        g -> color = 'r';
                        t = g;
                    }
                } else
                {
                    if (t -> parent -> right == t)
                    {
                        t = t -> parent;
                        left_rotate(t);
                    }
                    t -> parent -> color = 'b';
                    g -> color = 'r';
                    right_rotate(g);
                }
            } else
            {
                if (g -> left != nullptr)
                {
                    u = g -> left;
                    if (u -> color == 'r')
                    {
                        t -> parent->color = 'b';
                        u -> color = 'b';
                        g -> color = 'r';
                        t = g;
                    }
                } else
                {
                    if (t -> parent -> left == t)
                    {
                        t = t -> parent;
                        right_rotate(t);
                    }

                    t -> parent -> color = 'b';
                    g -> color = 'r';

                    left_rotate(g);
                }
            }

            root -> color = 'b';
        }
    }

    // Metodo para hacer la rotacion a la izquierda
    void left_rotate(node *p)
    {
        if (p -> right == nullptr)
        {
            return;
        } else
        {
            node *y = p -> right;
            if (y -> left != nullptr)
            {
                p -> right = y -> left;
                y -> left -> parent = p;
            }
            else
                p -> right = nullptr;
            if (p -> parent != nullptr)
                y -> parent = p -> parent;
            if (p -> parent == nullptr)
                root = y;
            else
            {
                if (p == p -> parent -> left)
                {
                    p -> parent -> left = y;
                } else
                {
                    p -> parent -> right = y;
                }
            }

            y -> left = p;
            p -> parent = y;
        }
    }

    // Metodo para hacer la rotacion hacia la derecha
    void right_rotate(node *p)
    {
        if (p -> left == nullptr)
        {
            return;
        }
        else
        {
            node *y = p -> left;
            if (y -> right != nullptr)
            {
                p -> left = y->right;
                y -> right->parent = p;
            }
            else
                p -> left = nullptr;
            if (p -> parent != nullptr)
                y -> parent = p->parent;
            if (p -> parent == nullptr)
                root = y;
            else
            {
                if (p == p->parent->left)
                {
                    p -> parent->left = y;
                } else
                {
                    p -> parent->right = y;
                }
            }

            y -> right = p;
            p -> parent = y;
        }
    }

    // Este metodo nos retornara la posicion del elemento segun fue insertado en el arbol.
    // De no encontrarse el elemento nos retorna -1
    int search(int x)
    {
        if (root == nullptr)
        {
            return -1; // El arbol esta vacio
        }

        node *p = root;
        bool found = false;

        while (p != nullptr && found == false)
        {
            if (p->key == x)
            {
                found = true;
            }
            if (found == false)
            {
                if (p->key < x)
                {
                    p = p -> right;
                } else
                {
                    p = p -> left;
                }
            }
        }

        if (found == false)
        {
            return -1;
        } else
        {
            return p -> index;
        }
    }
};

int main()
{
    /**
     * La variable "n" representa la cantidad de elementos que se insertara al arbol.
     * La variable "q" representa los queries.
     * La variable "value" representa el valor de cada uno de los elementos que vayamos a insertar en el arbol.
    */
    int n, q, value;
    RBT tree; // Se declara la variable tree de tipo "RBT"
    scanf("%d", &n); // Recibe la cantidad de elementos que va recibir el arbol.
    scanf("%d", &q);  // Recibe la cantidad de queries.

    // Relleno el arbol
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value); // Recibo el valor del elemento a insertar en el arbol
        tree.insert(value); // Inserto el elemento al arbol
    }

    value = 0;

    // Este ciclo me permitira ir solicitando cada query
    while(q--)
    {
        scanf("%d", &value); // Recibo el valor del elemento que quiero buscar en el arbol
        printf("%d\n", tree.search(value)); // Imprimo la posicion del elemento segun su entrada al arbol y si esta repetido sera su primera ocurrencia
    }

    return 0;
}