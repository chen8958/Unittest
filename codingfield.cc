#include <vector>
#include <numeric>
#include <list>
using namespace std;

namespace myTest{
    
    void relax(vector<int> &parent, vector<int> &distance, int u, int v, int w){
        if(distance[v] > distance[u] + w){
            parent[v] = u;
            distance[v] = distance[u] + w;
        }
    }
    //----------------------------------------------------------------
    vector<int> Bellman(vector<vector<int>> edges, int node_number, int src){
        // vector<list<pair<int,int>>> adj_map(node_number);//u->v and weight
        vector<int> parent(node_number);
        vector<int> distance(node_number, INT_MAX);
        // for(auto edge:edges){
        //     adj_map[edge[0]].push_back(make_pair(edge[1],edge[2]));
        // }
        distance[src] = 0;
        for(int i = 0; i < node_number; i++){
            for(auto edge:edges){
                relax(parent, distance, edge[0], edge[1], edge[2]);
            }
        }
        return distance;
        // traversal all edge

        
    }
    
}


