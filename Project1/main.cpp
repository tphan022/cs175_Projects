#include <iostream>
#include <queue>
#include <list>
#include <iterator>
//#include <algorithm>



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

// Function to test if a node has already been searched
bool checklist(std::list<eight_node> ls, eight_node chk) {
    std::list<eight_node>::iterator it;
    int num = 0;
    for(it = ls.begin(); it != ls.end(); ++it) {
        num = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(it->board[i][j] == chk.board[i][j]) {
                    num++;
                }
            }
        }
        if(num == 9) {
            return true;
        }
    }
    return false;
}


void UCS(eight_node root) { // Uniform Cost Search
    std::queue<eight_node> QF;
    std::list<eight_node> LS;
    // int g = 0;
    // int arr2[9] = {1,2,3,4,0,6,7,5,8};
    // eight_node test;
    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         test.board[i][j] = arr2[g];
    //         g++;
    //     }
    // }
    eight_node curr;
    QF.push(root);
    curr = QF.front();
    // LS.push_back(test);
    // checklist(LS, curr);
    
    //std::cout << checklist(LS, curr) << std::endl;
    
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