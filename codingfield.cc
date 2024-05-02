#include <vector>
#include <list>
#include <queue>
#include <string>
using namespace std;

namespace myTest{
    typedef struct piece PIECE, *PIECE_PTR;
    struct piece{
        PIECE_PTR parent;
        int rank = 0;
        piece(){
            parent = this;
        }
    };

    typedef struct block BLOCK, *BLOCK_PTR;
    struct block{
        PIECE_PTR upper;
        PIECE_PTR down;
        PIECE_PTR left;
        PIECE_PTR right;
        // block(){
        //     upper = new PIECE;
        //     down = new PIECE;
        //     left = new PIECE;
        //     right = new PIECE;
        // }
        void init(){
            upper = new PIECE;
            down = new PIECE;
            left = new PIECE;
            right = new PIECE;
        }
    };

    class DSU{
        private:
            vector<vector<BLOCK>> matrix;
        public:
            int unions;
            DSU(int n):matrix(n, vector<BLOCK>(n)), unions(4*n*n){
                for(int i=0; i < n; i++){
                    for(int j=0; j < n; j++){
                        matrix[i][j].init();
                    }
                }
                for(int i=0; i < n; i++){
                    for(int j=0; j < n; j++){
                        if(i+1<n){
                            unin_piece(matrix[i][j].down, matrix[i+1][j].upper);
                        }
                        if(j+1<n){
                            unin_piece(matrix[i][j].right, matrix[i][j+1].left);
                        }
                    }
                }
            }
            PIECE_PTR find_parent(PIECE_PTR current_piece_ptr){
                while(current_piece_ptr != current_piece_ptr->parent){
                    current_piece_ptr = current_piece_ptr->parent;
                }
                return current_piece_ptr;
            }

            bool unin_piece(PIECE_PTR x, PIECE_PTR y){
                PIECE_PTR px = find_parent(x), py = find_parent(y);
                if(px == py){
                    return false;
                }else{
                    if(px->rank > py->rank){
                        py->parent = px;
                    }else{
                        px->parent = py;
                        if(px->rank == py->rank) py->rank++;
                    }
                    unions--;
                    return true;
                }
            }
            void space(int i , int j){
                unin_piece(matrix[i][j].down, matrix[i][j].upper);
                unin_piece(matrix[i][j].down, matrix[i][j].left);
                unin_piece(matrix[i][j].down, matrix[i][j].right);
            }
            // "/"
            void back_slash(int i , int j){
                unin_piece(matrix[i][j].down, matrix[i][j].right);
                unin_piece(matrix[i][j].upper, matrix[i][j].left);
            }
            // "\"
            void forward_slash(int i , int j){
                unin_piece(matrix[i][j].down, matrix[i][j].left);
                unin_piece(matrix[i][j].upper, matrix[i][j].right);
            }
    };


    int regionsBySlashes(vector<string>& grid) {
        DSU mymatrix(grid.size());
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size();j++){
                char w = grid[i][j];
                switch(w){
                    case '/':
                        mymatrix.back_slash(i,j);
                        break;
                    case ' ':
                        mymatrix.space(i,j);
                        break;
                    default:
                        mymatrix.forward_slash(i,j);
                        break;
                }
            }
        }
        return mymatrix.unions;
    }
}

