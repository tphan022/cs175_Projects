#include <iostream>
#include <queue>
//#include <algorithm>

template <class T> void swap ( T& a, T& b )
{
  T c(a); a=b; b=c;
}

struct eight_node {
    int board[3][3];
    //int cost;
    //int depth;
    eight_node *left;
    eight_node *up;
    eight_node *right;
    eight_node *down;
    //eight_node *parent;
    
    eight_node(){
        left = NULL;
        up = NULL;
        right = NULL;
        down = NULL;
    }
    // eight_node operator=(eight_node rgt) {
    //     for(int i = 0; i < 3; i++) {
    //         for(int j = 0; j < 3; j++) {
    //             this->board[i][j] = rgt.board[i][j];
    //         }
    //     }
    //     this->left = rgt.left;
    //     this->right = rgt.right;
    //     this->up = rgt.up;
    //     this->down = rgt.down;
    //     return *this;
    // }
    void generate() {
        
    }
    
};

void UCS(eight_node root) { // Uniform Cost Search
    std::queue<eight_node> QF;
    eight_node curr;
    QF.push(root);
    curr = QF.front();
    std::cout << curr.board[0][0] << std::endl;
    
}

int main() {
    eight_node B;
    int arr[9] = {1,2,3,4,0,6,7,5,8};
    int k = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            B.board[i][j] = arr[k];
            k++;
        }
    }
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            std::cout << B.board[i][j] << " ";
        }
        std::cout << "\n";
    }
    UCS(B);
    
    return 0;
}