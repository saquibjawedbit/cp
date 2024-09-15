#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
    public:
    int data = -1;
    Node* left = NULL;
    Node* right = NULL;

    Node(int val) {
        data = val;
    }

};

Node* insertBST(Node* root, int val) {
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(root -> data > val) {
        root -> left = insertBST(root -> left, val);
    }
    else {
        root -> right = insertBST(root -> right, val);
    }

    return root;
}

void takeInput(Node* &root)
{
    
    int data; 
    cin >> data;
    while(data != -1) {
        root = insertBST(root, data);
        cin >> data;
    }
}

Node* deleteFromBST(Node *root, int x) {
    if(root == NULL) return NULL;

    if(root -> data == x) {
        //Case 1- No Nodes
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }
        else if(root -> left != NULL && root -> right == NULL) {
            Node *ans = root -> left;
            delete root;
            return ans;
        }
        else if(root -> left == NULL && root -> right != NULL) {
            Node *ans = root -> right;
            delete root;
            return ans;
        }
        else {
            root -> data = root -> right -> data;
            root -> right = deleteFromBST(root -> right, root -> data);
            return root;
        }
    }
    else if(root -> data > x) {
        root -> left = deleteFromBST(root -> left, x);
        return root;
    }
    else {
        root -> right = deleteFromBST(root -> right, x);
        return root;
    }
}

void printTree(Node * root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        for(int i = 0; i < size; i++) {
            Node* n = q.front();
            q.pop();

            if(n -> left) q.push(n -> left);
            if(n -> right) q.push(n -> right);

            cout << n -> data << " ";
        }
        cout << endl;
    }
}

int main() {
    Node* root = NULL;
    takeInput(root);
    printTree(root);
    root = deleteFromBST(root, 10);
    printTree(root);
    return 0;
}