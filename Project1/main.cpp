#include <iostream>
#include <queue>
#include <list>
#include <iterator>
//#include <algorithm>



struct eight_node {
    int board[3][3];
    //int cost;
    //int depth;
    int solution[3][3];
    bool valid;
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
        int k = 1;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                solution[i][j] = k;
                k++;
            }
        }
        solution[2][2] = 0;
    }
    eight_node* generate_left() {
        eight_node *gen = new eight_node; // generates a new node
        int row = -1;
        int column = -1;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(board[i][j] == 0) {
                    row = i;
                    column = j;
                    //std::cout << "\n" << i << "\n" << j << "\n";
                }
            }
        }
        if(column > 0) {
            gen->board[row][column] = this->board[row][column - 1];
            gen->board[row][column - 1] = this->board[row][column];
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if( (row == i && column == j) || (row == i && (column-1) == j ) ) {
                        
                    }
                    else {
                        gen->board[i][j] = this->board[i][j];
                    }
                }
            }
            gen->valid = true;
        }
        else {
            gen->valid = false;
        }
        return gen;
        
    }
    
    eight_node* generate_right() {
        eight_node *gen = new eight_node; // generates a new node
        int row = -1;
        int column = -1;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(board[i][j] == 0) {
                    row = i;
                    column = j;
                    //std::cout << "\n" << i << "\n" << j << "\n";
                }
            }
        }
        if(column < 2) {
            gen->board[row][column] = this->board[row][column + 1];
            gen->board[row][column + 1] = this->board[row][column];
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if( (row == i && column == j) || (row == i && (column+1) == j ) ) {
                        
                    }
                    else {
                        gen->board[i][j] = this->board[i][j];
                    }
                }
            }
            gen->valid = true;
        }
        else {
            gen->valid = false;
        }
        return gen;
        
    }
    
    eight_node* generate_down() {
        eight_node *gen = new eight_node; // generates a new node
        int row = -1;
        int column = -1;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(board[i][j] == 0) {
                    row = i;
                    column = j;
                    //std::cout << "\n" << i << "\n" << j << "\n";
                }
            }
        }
        if(row < 2) {
            gen->board[row][column] = this->board[row + 1][column];
            gen->board[row + 1][column] = this->board[row][column];
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if( (row == i && column == j) || ( (row+1) == i && column == j ) ) {
                        
                    }
                    else {
                        gen->board[i][j] = this->board[i][j];
                    }
                }
            }
            gen->valid = true;
        }
        else {
            gen->valid = false;
        }
        return gen;
        
    }
    
    eight_node* generate_up() {
        eight_node *gen = new eight_node; // generates a new node
        int row = -1;
        int column = -1;
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(board[i][j] == 0) {
                    row = i;
                    column = j;
                    //std::cout << "\n" << i << "\n" << j << "\n";
                }
            }
        }
        if(row > 0) {
            gen->board[row][column] = this->board[row - 1][column];
            gen->board[row - 1][column] = this->board[row][column];
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    if( (row == i && column == j) || ( (row-1) == i && column == j ) ) {
                        
                    }
                    else {
                        gen->board[i][j] = this->board[i][j];
                    }
                }
            }
            gen->valid = true;
        }
        else {
            gen->valid = false;
        }
        return gen;
        
    }
    
    bool check_solution() {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] != solution[i][j]) {
                    return false;
                }
            }
        }
        return true;
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
    eight_node curr;
    QF.push(root);
    // int g = 0;
    // int arr2[9] = {1,2,3,4,0,6,7,5,8};
    // eight_node test;
    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         test.board[i][j] = arr2[g];
    //         g++;
    //     }
    // }
    while(!QF.empty()) {
        curr = QF.front();
        QF.pop();
    }
    curr = QF.front();
    // LS.push_back(test);
    // checklist(LS, curr);
    
    //std::cout << checklist(LS, curr) << std::endl;
    
}

int main() {
    eight_node B;
    eight_node *C;
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
    std::cout << "\n" << B.check_solution() << "\n";
    // C = B.generate_up();
    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         std::cout << C->board[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
    //UCS(B);
    
    return 0;
}