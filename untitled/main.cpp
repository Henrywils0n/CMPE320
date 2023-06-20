#include <iostream>

using namespace std;

struct node {
    node *lchild;
    node *rchild;
    int val;
};

int* initialize(int val) {
    node head;
    head.lchild = nullptr;
    head.rchild = nullptr;
    head.val = val;
}


int main() {
    initialize(5);

    return 0;
}
