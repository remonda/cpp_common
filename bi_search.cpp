/*
 * test.c
 * Copyright (C) 2017 zhangyuehua <zhangyuehua@zhangyuehuadeMacBook-Pro.local>
 *
 * Distributed under terms of the MIT license.
 *
 * complie : g++ -std=c++11 bi_search.cpp -o bi_search
 */

#include "stdio.h"
#include <iostream>
#include <vector>

using namespace std;

int bi_search(vector<int>&, int );

int main(int argc, char* argv[]) {
    for (int i = 0 ; i< argc; ++i) {
        // arg 0 is the app itself
        printf("arg[%d] : %s\n", i, argv[i]);
    }
    /*
     * add your code here
     */
    vector<int> a = {0,1,2,3,4,5,6,7,8,9};
    for (int i=0; i< 12 ; i++) {
       bi_search(a, i);
    }
    return 0;
}


int bi_search(vector<int>& arr, int search) {
    if (arr.size() == 0) {
        cout << "not found"<< endl;
        return 0;
    } else {
        int bot = 0;
        int top = arr.size();
        int flag = top/2;
        while (bot < top) {
            if (search > arr[flag] ) {
                bot = flag + 1;
                flag = bot + (top - bot)/2;
            } 
            if (search < arr[flag]) {
                top = flag - 1; 
                flag = bot + (top - bot)/2;
            }
            if (search == arr[flag]) {
                cout<<"find " << search << " at index " << flag << endl;
                return 1;
            }
        }
        cout << "not found"<< endl;
        return 0;
    }

}
