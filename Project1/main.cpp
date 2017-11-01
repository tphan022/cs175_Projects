#include <iostream>
#include <queue>
#include <list>
#include <iterator>
#include <cstdlib>
//#include <algorithm>



struct eight_node {
    int board[3][3];
    int MS; // Variable for Misplaced tile
    int moves;
    int solution[3][3];
    bool valid;
    
    eight_node(){
        int k = 1;
        moves = 0;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                solution[i][j] = k;
                k++;
            }
        }
        solution[2][2] = 0;
        
        // Misplaced Tile
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] != solution[i][j]) {
                    if(board[i][j] != 0) {
                        MS++;
                    }
                }
            }
        }
    }
    
    // Swap function for left side.
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
        gen->moves = (this->moves) + 1;
        gen->MS = gen->MS + gen->moves;
        return gen;
        
    }
    
    // Swap function for right side.
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
        gen->moves = (this->moves) + 1;
        gen->MS = gen->MS + gen->moves;
        return gen;
        
    }
    
    // Swap function for bottom side.
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
        gen->moves = (this->moves) + 1;
        gen->MS = gen->MS + gen->moves;
        return gen;
        
    }
    
    // Swap function for top side.
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
        gen->moves = (this->moves) + 1;
        gen->MS = gen->MS + gen->moves;
        return gen;
        
    }
    
    
    // Compares and returns boolean if the current pattern is the solution.
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
    
    bool operator<(const eight_node& right) const {
        return MS > right.MS;
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

// Uniform Cost Search
void UCS(eight_node root) { 
    std::queue<eight_node> QF; // QF is the queue
    std::list<eight_node> LS; // LS is the list to keep track of visited nodes.
    unsigned int counter = 0;
    eight_node *temp = new eight_node;
    bool done = false;
    eight_node curr;
    QF.push(root);
    LS.push_back(curr);
    
    while(!QF.empty()) {
        counter++;
        curr = QF.front();
        QF.pop();
        
        std::cout << "\n";
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                std::cout << curr.board[i][j] << " ";
            }
            std::cout << "\n";
        }
        
        
        if(curr.check_solution()) {
            std::cout << "\n" << "Solution has been reached.\n";
            std::cout << "this took " << counter << " steps.\n";
            done = true;
            break;
        }
        
        temp = curr.generate_left();
        if(temp->valid) {
            if(!checklist(LS, *temp)) {
                LS.push_back(*temp);
                QF.push(*temp);
            }
        }
        temp = curr.generate_down();
        if(temp->valid) {
            if(!checklist(LS, *temp)) {
                LS.push_back(*temp);
                QF.push(*temp);
            }
        }
        temp = curr.generate_right();
        if(temp->valid) {
            if(!checklist(LS, *temp)) {
                LS.push_back(*temp);
                QF.push(*temp);
            }
        }
        temp = curr.generate_up();
        if(temp->valid) {
            if(!checklist(LS, *temp)) {
                LS.push_back(*temp);
                QF.push(*temp);
            }
        }
        
    }
    if(!done) {
        std::cout << "\n" << "Error, no solution.\n";
    }
    
    
}

void Mispaced(eight_node root) { 
    std::priority_queue<eight_node> QF; // QF is the queue
    std::list<eight_node> LS; // LS is the list to keep track of visited nodes.
    unsigned int counter = 0;
    eight_node *temp = new eight_node;
    bool done = false;
    eight_node curr;
    QF.push(root);
    LS.push_back(curr);
    
    while(!QF.empty()) {
        counter++;
        curr = QF.top();
        QF.pop();
        
        //std::cout << "\n";
        // for(int i = 0; i < 3; i++) {
        //     for(int j = 0; j < 3; j++) {
        //         std::cout << curr.board[i][j] << " ";
        //     }
        //     std::cout << "\n";
        // }
        
        
        if(curr.check_solution()) {
            std::cout << "\n" << "Solution has been reached.\n";
            std::cout << "this took " << counter << " steps.\n";
            done = true;
            break;
        }
        
        temp = curr.generate_left();
        if(temp->valid) {
            if(!checklist(LS, *temp)) {
                LS.push_back(*temp);
                QF.push(*temp);
            }
        }
        temp = curr.generate_down();
        if(temp->valid) {
            if(!checklist(LS, *temp)) {
                LS.push_back(*temp);
                QF.push(*temp);
            }
        }
        temp = curr.generate_right();
        if(temp->valid) {
            if(!checklist(LS, *temp)) {
                LS.push_back(*temp);
                QF.push(*temp);
            }
        }
        temp = curr.generate_up();
        if(temp->valid) {
            if(!checklist(LS, *temp)) {
                LS.push_back(*temp);
                QF.push(*temp);
            }
        }
        
    }
    if(!done) {
        std::cout << "\n" << "Error, no solution.\n";
    }
    
    
}

int main() {
    eight_node B;
    int select = 0;
    int arr[9] = {1,8,2,0,4,3,7,6,5};
    int k = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            B.board[i][j] = arr[k];
            k++;
        }
    }
    // for(int i = 0; i < 3; i++) {
    //     for(int j = 0; j < 3; j++) {
    //         std::cout << B.board[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }
    
    std::cout << "Select an algorithm.\n1: Uniform Cost\n2: Mispaced Tile\n";
    std::cin >> select;
    
    if(select == 1) {
        UCS(B);
    }
    else if(select == 2) {
        Mispaced(B);
    }
    
    return 0;
}