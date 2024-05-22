#include <vector>
#include <numeric>
#include <list>
using namespace std;

namespace myTest{
    
    void DFS(list<int>& ans, const vector<list<int>> &adj_map, const int current_vertice, vector<bool> &is_visited){
        if(is_visited[current_vertice] == false){
            is_visited[current_vertice] = true;
            for(auto vertice:adj_map[current_vertice]){
                DFS(ans, adj_map, vertice, is_visited);
            }
            ans.push_front(current_vertice);
        }
    }

    list<int> topological_sort(vector<vector<int>>map){
        vector<list<int>>adj_map(map.size());
        vector<bool>is_visited(map.size(),false);
        list<int> ans;
        for(int i = 0; i < map.size();i++){
            for(auto vertex: map[i]){
                adj_map[i].push_back(vertex);
            }
        }

        //DFS
        for(int vertice_idx = 0; vertice_idx<map.size(); vertice_idx++){
            DFS(ans, adj_map, vertice_idx, is_visited);
        }
        return ans;
    }
}

