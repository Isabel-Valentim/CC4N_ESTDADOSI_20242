#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da BST
typedef struct BSTNode {
    int key;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Função para criar um novo nó
BSTNode* createNode(int key) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    if (!node) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para inserir um nó na BST
BSTNode* insert(BSTNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Função para buscar um nó na BST
BSTNode* search(BSTNode* root, int key) {
    if (root == NULL || root->key == key) {
        return root;
    }
    if (key < root->key) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// Função para encontrar o menor valor na BST
BSTNode* findMin(BSTNode* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Função para remover um nó na BST
BSTNode* deleteNode(BSTNode* root, int key) {
    if (root == NULL) {
        return root;
    }
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        BSTNode* temp = findMin(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Função para imprimir os elementos em ordem
void inorderTraversal(BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// Função principal para testar a BST
int main() {
    BSTNode* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal: ");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 20);
    printf("After deleting 20: ");
    inorderTraversal(root);
    printf("\n");

    BSTNode* found = search(root, 60);
    if (found) {
        printf("Found 60\n");
    } else {
        printf("60 not found\n");
    }

    return 0;
}
