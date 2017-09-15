/*
 * bsl.cpp
 * Copyright (C) 2017 zhangyuehua <zhangyuehua@zhangyuehuadeMacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 * complie: g++ -std=c++11 bst.cpp -g -o bst
 */

#include <vector>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct tree_node {
    int data;
    tree_node* left;
    tree_node* right;
    tree_node* parent;
};


class Bst {
    private:
        tree_node root;
        int size;

    public:
        Bst() {
            root.data = 0;
            root.parent = NULL;
            root.left = NULL;
            root.right = NULL;
            size = 1;
        }

        Bst(int i) {
            root.data = i;
            root.parent = NULL;
            root.left = NULL;
            root.right = NULL;
            size = 1;
        }


        ~Bst() {
            
        }

        tree_node* create_node(int i);
        void mid_traverse(const tree_node* root);
        void pre_traverse(const tree_node* root);
        void add_node(tree_node* node); 
        tree_node* get_root();
        tree_node* search(int i);
        void del_node(int i);
};


tree_node* Bst::create_node(int i) {
    tree_node* t = (tree_node*)malloc(sizeof(tree_node));
    t->data = i;
    t->left = NULL;
    t->right = NULL;
    t->parent = NULL;
    return t;
}

void Bst::mid_traverse(const tree_node* root) {
    if (root == NULL) { 
        cout<< endl; 
        return;
    }
    if (root->left != NULL) {
        mid_traverse(root->left);
    } 
    cout << root->data << "\t";
    if (root->right != NULL) {
        mid_traverse(root->right);
    } 
}

void Bst::pre_traverse(const tree_node* root) {
    if (root == NULL) {
        cout << endl;
        return;
    }
    cout << root->data << "\t";
    if (root->left != NULL) {
        pre_traverse(root->left);
    } 
    if (root->right != NULL) {
        pre_traverse(root->right);
    } 
}

void Bst::add_node(tree_node* node) {
    tree_node* p = &root;
    while(1) {
        if (node->data < p->data) {
            if ( p->left == NULL ) {
                p->left = node;
                node->parent = p;
                return;
            }
            p = p->left;
        } else if (node->data > p->data) {
            if (p->right == NULL) {
                p->right = node;
                node->parent = p;
                return;
            } 
            p = p->right;
        } else if (node->data == p->data) {
            break;
        }

    }
}

tree_node* Bst::get_root() {
    return &root;
}

tree_node* Bst::search(int i) {
    tree_node* p = &root;
    while(1) {
        if (p == NULL) {
            return p;
        } else if (i == p->data) {
            return p;
        } else if (i > p->data) {
            p = p->right;
        } else if (i < p->data) {
            p = p->left;
        }
    }
}

void Bst::del_node(int i) {
    tree_node* p = search(i);
    if (p == NULL) {
        return; // not found do nothing
    } else {
        // p has no child
        if (p->left == NULL && p->right == NULL) {
            tree_node* parent = p->parent;
            if (parent->left == p) {
                parent->left = NULL;
            } else if (parent->right == p) {
                parent->right = NULL;
            }
        delete p;
        } else if (p->left == NULL && p->right != NULL) {
            // p has one right child
            tree_node* parent = p->parent;
            if (parent->left == p) {
                parent->left = p->right;
            } else if (parent->right == p) {
                parent->right = p->right;
            }
        delete p;
        } else if (p->right == NULL && p->left != NULL) {
            // p has one left child
             tree_node* parent = p->parent;
            if (parent->left == p) {
                parent->left = p->left;
            } else if (parent->right == p) {
                parent->right = p->left;
            }
        delete p;
        }
    }
}

int main(int argc, char* argv[]) {
    for (int i = 0 ; i< argc; ++i) {
        // arg 0 is the app itself
        std::cout<<"arg[" << i << "]" << argv[i] << std::endl;
    }
    /* 
     * add your code here
     */
    Bst bst(45);
    tree_node* n;
    vector<int> a  = {24,53,12,37,93,22,27,18,58,74};
    for (size_t i = 0; i< a.size(); ++i) {
        n = bst.create_node(a[i]);
        bst.add_node(n);
    }
    cout << "pre: " << endl;
    bst.pre_traverse(bst.get_root());

    cout << "mid: " << endl;
    bst.mid_traverse(bst.get_root());
    for (int i = 21; i< 28; ++i) {
        if (bst.search(i)) {
            cout << "find " << i << " in bst" << endl;
        } else {
            cout << "not found " << i << " in bst" << endl;
        }
    }    

    return 0;
}


