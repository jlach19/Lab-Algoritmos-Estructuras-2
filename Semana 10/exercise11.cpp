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
#include <iostream>
using namespace std;

// Representa cada nodo
struct node
{
    int key;      // Valor del elemento
    int index;    // Representa la posición en la que fue introducido el elemento al árbol
    node *parent; // Nodo padre
    char color;   // Color del nodo. 'b' si es negro, 'r' si es rojo
    node *left;   // Nodo hijo izquierdo
    node *right;  // Nodo hijo derecho

    node(int k, int idx) : key(k), index(idx), parent(nullptr), color('r'), left(nullptr), right(nullptr) {}
};

// Representa el árbol rojo-negro
struct RBT
{
    node *root; // Indica la raíz

    // Constructor
    RBT() : root(nullptr) {}

    // Método que permite insertar un elemento en el árbol.
    void insert(int key, int index)
    {
        if (search(root, key) != -1)
        {
            return;
        }

        node *new_node = new node(key, index);

        if (root == nullptr)
        {
            root = new_node;
            new_node->color = 'b';
            return;
        }

        node *parent = nullptr;
        node *current = root;

        while (current != nullptr)
        {
            parent = current;
            if (new_node->key < current->key)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        new_node->parent = parent;
        if (new_node->key < parent->key)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }

        insert_fix(new_node);
    }



    // Método que es responsable de mantener las propiedades de un árbol rojo-negro
    void insert_fix(node *n)
    {
        while (n->parent != nullptr && n->parent->color == 'r')
        {
            node *grandparent = n->parent->parent;
            if (n->parent == grandparent->left)
            {
                node *uncle = grandparent->right;
                if (uncle != nullptr && uncle->color == 'r')
                {
                    n->parent->color = 'b';
                    uncle->color = 'b';
                    grandparent->color = 'r';
                    n = grandparent;
                }
                else
                {
                    if (n == n->parent->right)
                    {
                        n = n->parent;
                        left_rotate(n);
                    }
                    n->parent->color = 'b';
                    grandparent->color = 'r';
                    right_rotate(grandparent);
                }
            }
            else
            {
                node *uncle = grandparent->left;
                if (uncle != nullptr && uncle->color == 'r')
                {
                    n->parent->color = 'b';
                    uncle->color = 'b';
                    grandparent->color = 'r';
                    n = grandparent;
                }
                else
                {
                    if (n == n->parent->left)
                    {
                        n = n->parent;
                        right_rotate(n);
                    }
                    n->parent->color = 'b';
                    grandparent->color = 'r';
                    left_rotate(grandparent);
                }
            }
        }
        root->color = 'b';
    }

    // Método para hacer la rotación a la izquierda
    void left_rotate(node *n)
    {
        node *r = n->right;
        n->right = r->left;
        if (r->left != nullptr)
        {
            r->left->parent = n;
        }
        r->parent = n->parent;
        if (n->parent == nullptr)
        {
            root = r;
        }
        else if (n == n->parent->left)
        {
            n->parent->left = r;
        }
        else
        {
            n->parent->right = r;
        }
        r->left = n;
        n->parent = r;
    }

    // Método para hacer la rotación a la derecha
    void right_rotate(node *n)
    {
        node *l = n->left;
        n->left = l->right;
        if (l->right != nullptr)
        {
            l->right->parent = n;
        }
        l->parent = n->parent;
        if (n->parent == nullptr)
        {
            root = l;
        }
        else if (n == n->parent->left)
        {
            n->parent->left = l;
        }
        else
        {
            n->parent->right = l;
        }
        l->right = n;
        n->parent = l;
    }

    // Método para buscar un elemento en el árbol
    int search(node *root, int key)
    {
        if (root == nullptr)
        {
            return -1; // El árbol está vacío
        }
        if (root->key == key)
        {
            return root->index;
        }
        if (root->key > key)
        {
            return search(root->left, key);
        }
        else
        {
            return search(root->right, key);
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

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Recibe la cantidad de elementos que va recibir el arbol.
    // Recibe la cantidad de queries.
    cin >> n >> q;

    // Relleno el arbol
    for (int i = 0; i < n; i++)
    {
        cin >> value;          // Recibo el valor del elemento a insertar en el arbol
        tree.insert(value, i); // Inserto el elemento al arbol
    }

    value = 0;



    // Este ciclo me permitira ir solicitando cada query
    while (q--)
    {
        cin >> value; // Recibo el valor del elemento que quiero buscar en el arbol
        cout << tree.search(tree.root, value) << "\n";
    }

    return 0;
}