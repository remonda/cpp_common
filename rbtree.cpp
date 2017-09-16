/*
 * rbtree.cpp
 * Copyright (C) 2017 zhangyuehua <zhangyuehua@zhangyuehuadeMacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 *
 * compile: g++ -std=c++11 rbtree.cpp -o rbtree
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define RED  0
#define BLACK  1

using namespace std;


struct rbtree_node {
    int data;
    rbtree_node* left;
    rbtree_node* right;
    rbtree_node* parent;
    int color;
};


class RBTree {
    private:
        rbtree_node* root;


    public:
        RBTree() {
            root = NULL;
        }

        RBTree(rbtree_node* node) {
            root = node;
            root->color = BLACK;
        }

        ~RBTree() {
        
        }

        rbtree_node* create_node(int i) {
            rbtree_node* node = (rbtree_node*)malloc(sizeof(rbtree_node));
            node->data = i;
            return node;
        }


};

int main(int argc, char* argv[]) {
    for (int i = 0 ; i< argc; ++i) {
        // arg 0 is the app itself
        std::cout<<"arg[" << i << "]" << argv[i] << std::endl;
    }
    /* 
     * add your code here
     */
    return 0;
}


