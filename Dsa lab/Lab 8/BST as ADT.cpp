#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value) {
        if (node == NULL) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return node;
    }

    Node* search(Node* node, int value) {
        if (node == NULL || node->data == value) {
            return node;
        }

        if (value < node->data) {
            return search(node->left, value);
        }

        return search(node->right, value);
    }

    void inorder(Node* node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    Node* deleteNode(Node* node, int value) {
        if (node == NULL) {
            return node;
        }

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);

            node->data = temp->data;

            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != NULL) {
            node = node->left;
        }
        return node;
    }

public:
    BST() : root(NULL) {}

    void insert(int value) {
        root = insert(root, value);
    }

    bool search(int value) {
        Node* result = search(root, value);
        return result != NULL;
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void deleteNode(int value) {
        root = deleteNode(root, value);
    }
};

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal: ";
    tree.inorder();

    cout << "Searching for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Searching for 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;

    tree.deleteNode(20);
    cout << "In-order traversal after deleting 20: ";
    tree.inorder();

    tree.deleteNode(30);
    cout << "In-order traversal after deleting 30: ";
    tree.inorder();

    tree.deleteNode(50);
    cout << "In-order traversal after deleting 50: ";
    tree.inorder();

    return 0;
}

