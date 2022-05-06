#include <iostream>

using namespace std;

struct treenode
{
    int info;
    treenode *left;
    treenode *right;
};

typedef treenode *treenodeptr;

void tInsert(treenodeptr &root, int x)
{
    if (root == NULL)
    {
        root = new treenode;
        root->info = x;
        root->left = NULL;
        root->right = NULL;
    }
    else if (x < root->info)
        tInsert(root->left, x);
    else if (x >= root->info)
        tInsert(root->right, x);
}

treenodeptr tSearch(treenodeptr root, int x)
{
    if (root == NULL)
        return NULL;
    else if (x == root->info)
        return root;
    else if (x < root->info)
        return tSearch(root->left, x);
    else if (x > root->info)
        return tSearch(root->right, x);
}

void tPrint(treenodeptr root)
{
    if (root != NULL)
    {
        tPrint(root->left);
        cout << root->info << " ";
        tPrint(root->right);
    }
}

int main()
{
    treenodeptr arvore = NULL; // Ponteiro para a raiz da árvore
    int x = 0;                 // Valor a ser inserido
    treenodeptr p;             // Ponteiro para o nó a ser buscado

    while (x != -1)
    {
        cout << "Inserir um valor: ";
        cin >> x;

        if (x != -1)
            tInsert(arvore, x);
    }

    // Imprime a árvore

    cout << "Arvore: ";
    tPrint(arvore);
    cout << endl;

    // Busca um valor na árvore

    cout << "Buscar um valor: ";
    cin >> x;

    p = tSearch(arvore, x);

    if (p == NULL)
        cout << "Valor nao encontrado" << endl;
    else
        cout << p->info << endl;



    return 0;
}