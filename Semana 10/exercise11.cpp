#include<iostream>

using namespace std;

struct node
{
	int key;
	int index;
	node *parent;
	char color;
	node *left;
	node *right;
};

struct RBtree
{
	node *root;
	node *q;
    int index= 0; 

    // Constructor
	RBtree()
	{
		q = NULL;
		root = NULL;
	}
	
    void insert(int z)
    {
        node *p, *q;
        node *t = new node;
        t -> key = z;
        t -> left = NULL;
        t -> right = NULL;
        t -> color = 'r';
        t -> index = index;
        index++;
        p = root;
        q = NULL;
        if (root == NULL)
        {
            root = t;
            t->parent = NULL;
        }
        else
        {
            while (p != NULL)
            {
                q = p;
                if (p->key < t->key)
                    p = p->right;
                else
                    p = p->left;
            }
            t->parent = q;
            if (q->key < t->key)
                q->right = t;
            else
                q->left = t;
        }
        insert_fix(t);
    }

    void insert_fix(node *t)
    {
        node *u;

        if (root == t)
        {
            t->color = 'b';
            return;
        }

        while (t->parent != NULL && t->parent->color == 'r')
        {
            node *g = t->parent->parent;
            if (g->left == t->parent)
            {
                if (g->right != NULL)
                {
                    u = g->right;
                    if (u->color == 'r')
                    {
                        t->parent->color = 'b';
                        u->color = 'b';
                        g->color = 'r';
                        t = g;
                    }
                } else
                {
                    if (t->parent->right == t)
                    {
                        t = t->parent;
                        left_rotate(t);
                    }
                    t->parent->color = 'b';
                    g->color = 'r';
                    right_rotate(g);
                }
            } else
            {
                if (g->left != NULL)
                {
                    u = g->left;
                    if (u->color == 'r')
                    {
                        t->parent->color = 'b';
                        u->color = 'b';
                        g->color = 'r';
                        t = g;
                    }
                } else
                {
                    if (t->parent->left == t)
                    {
                        t = t->parent;
                        right_rotate(t);
                    }

                    t->parent->color = 'b';
                    g->color = 'r';

                    left_rotate(g);
                }
            }

            root->color = 'b';
        }
    }


    void left_rotate(node *p)
    {
        if (p->right == NULL)
        {
            return;
        } else
        {
            node *y = p->right;
            if (y->left != NULL)
            {
                p->right = y->left;
                y->left->parent = p;
            }
            else
                p->right = NULL;
            if (p->parent != NULL)
                y->parent = p->parent;
            if (p->parent == NULL)
                root = y;
            else
            {
                if (p == p->parent->left)
                    p->parent->left = y;
                else
                    p->parent->right = y;
            }
            y->left = p;
            p->parent = y;
        }
    }

    void right_rotate(node *p)
    {
        if (p->left == NULL)
            return;
        else
        {
            node *y = p->left;
            if (y->right != NULL)
            {
                p->left = y->right;
                y->right->parent = p;
            }
            else
                p->left = NULL;
            if (p->parent != NULL)
                y->parent = p->parent;
            if (p->parent == NULL)
                root = y;
            else
            {
                if (p == p->parent->left)
                    p->parent->left = y;
                else
                    p->parent->right = y;
            }
            y->right = p;
            p->parent = y;
        }
    }

    void search(int x)
    {
        if (root == NULL)
        {
            cout << "\nEmpty Tree\n";
            return;
        }

        node *p = root;
        int found = 0;

        while (p != NULL && found == 0)
        {
            if (p->key == x)
                found = 1;
            if (found == 0)
            {
                if (p->key < x)
                    p = p->right;
                else
                    p = p->left;
            }
        }

        if (found == 0)
        {
            cout << "\nElement Not Found."; //? PUDIERA AQUI DECIR QUE RETORNE -1 LA FUNCION
            cout << "La posicion es :" << -1;
        }
        else
        {
            cout << "\n\t FOUND NODE: ";
            cout << "\n Key: " << p->key;
            cout << "\n Colour: ";
            if (p->color == 'b')
                cout << "Black";
            else
                cout << "Red";
            if (p->parent != NULL)
                cout << "\n Parent: " << p->parent->key;
            else
                cout << "\n There is no parent of the node.  ";
            if (p->right != NULL)
                cout << "\n Right Child: " << p->right->key;
            else
                cout << "\n There is no right child of the node.  ";
            if (p->left != NULL)
                cout << "\n Left Child: " << p->left->key;
            else
                cout << "\n There is no left child of the node.  ";
            cout << endl;

            cout << "La posicion es: " << p -> index << endl;

        }
    }
};

int main()
{
    int n, q, value;
	RBtree tree;
    scanf("%d", &n); 
    scanf("%d", &q); 

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        tree.insert(value);
    }

    while (q--)
    {
        int value;
        scanf("%d", &value);
        tree.search(value);

    }
        

	return 0;
}