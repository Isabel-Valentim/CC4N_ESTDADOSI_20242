#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó AVL
typedef struct AVLNode {
    int key;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// Função para criar um novo nó
AVLNode* createNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    if (!node) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

// Função para obter a altura de um nó
int getHeight(AVLNode* node) {
    return node == NULL ? 0 : node->height;
}

// Função para calcular o fator de balanceamento
int getBalance(AVLNode* node) {
    return node == NULL ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Função para realizar uma rotação à direita
AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));
    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));

    return x;
}

// Função para realizar uma rotação à esquerda
AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + (getHeight(x->left) > getHeight(x->right) ? getHeight(x->left) : getHeight(x->right));
    y->height = 1 + (getHeight(y->left) > getHeight(y->right) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

// Função para inserir um nó na AVL
AVLNode* insert(AVLNode* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node; // Chave duplicada
    }

    node->height = 1 + (getHeight(node->left) > getHeight(node->right) ? getHeight(node->left) : getHeight(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key) {
        return rotateRight(node);
    }
    if (balance < -1 && key > node->right->key) {
        return rotateLeft(node);
    }
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

// Função para imprimir os elementos em ordem
void inorderTraversal(AVLNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Função principal para testar a AVL
int main() {
    AVLNode* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("In-order traversal da AVL: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
