#include <vector>
#include <numeric>
using namespace std;

namespace myTest{
    
    class DSU{
        private:
            vector<int> parent;
            vector<int> rank;
        public:
            int sets;
            DSU(int n):parent(n), rank(n,0), sets(n){
                iota(parent.begin(), parent.end(), 0);
            }
            int find_parent(int cur){
                while(cur != parent[cur]){
                    cur = parent[cur];
                }
                return cur;
            }
            bool set_union(int x, int y){
                int px = find_parent(x), py = find_parent(y);
                if(px == py){
                    return false;
                }else{
                    if(rank[px] > rank[py]){
                        parent[py] = px;
                    }else{
                        parent[px] = py;
                        if(rank[px] == rank[py])rank[py]++;
                    }
                    sets--;
                }
            }

    };

    int removeStones(vector<vector<int>>& stones) {
        DSU myset(stones.size());
        // x to node idx in stones
        unordered_map<int, int> x_map;
        unordered_map<int, int> y_map;

        for(int i = 0; i < stones.size(); i++){
            if(x_map.find(stones[i][0]) != x_map.end()){
                myset.set_union(x_map.find(stones[i][0])->second, i);
            }else{
                x_map[stones[i][0]] = i;
            }

            if(y_map.find(stones[i][1]) != y_map.end()){
                myset.set_union(y_map.find(stones[i][0])->second, i);
            }else{
                y_map[stones[i][1]] = i;
            }
        }
        return stones.size()-myset.sets;
    }
}

