#include <vector>
#include <list>
#include <stack>
using namespace std;
#define FALSE 0
#define TRUE 1
#define MAX_INT 0xFFFFFFFF

typedef struct node Node;
struct node{
    int start_time = 0;
    int end_time = MAX_INT;
    bool isvisited = FALSE;
    int finished_child = 0;
    int parent;
};
namespace myTest{
    bool course_schdule(int n, vector<vector<int>> prerequisites){
        //create adjacency list
		vector<list<int>> adj_list_vector(n);
		for(int i = 0; i < prerequisites.size() ; i++){
			adj_list_vector[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
        // DFS and find out backedge

        vector<Node> Nodes_vector(n);
        stack<int> stack;
        int time = 0;
        //insert root to stack
        stack.push(0);

        while(stack.size()!=0){
            int u = stack.top();
            if(Nodes_vector[u].isvisited == FALSE){
                    Nodes_vector[u].isvisited = TRUE;
                    Nodes_vector[u].start_time = time ++;
                for(auto it = adj_list_vector[u].begin(); it != adj_list_vector[u].end(); it++){
                    if(Nodes_vector[*it].isvisited == FALSE){
                        Nodes_vector[*it].parent = u;
                        stack.push(*it);
                    }else{
                        if(Nodes_vector[u].start_time > Nodes_vector[*it].start_time && Nodes_vector[*it].end_time >= Nodes_vector[u].end_time){
                            return FALSE;
                        }else{
                            Nodes_vector[u].finished_child++;
                        }
                    }
                }
            }
            while(adj_list_vector[u].size() == Nodes_vector[u].finished_child){
                stack.pop();
                Nodes_vector[u].end_time = time++;
                u = Nodes_vector[u].parent;
                Nodes_vector[u].finished_child++;
            }
            
            // for(auto it = adj_list_vector[u].begin(); it != adj_list_vector[u].end(); it++){
            //     if(Nodes_vector[*it].isvisited == FALSE){
            //         Nodes_vector[*it].isvisited = TRUE;
            //         Nodes_vector[*it].start_time = time ++;
            //         Nodes_vector[*it].parent = u;
            //         stack.push(*it);
            //     }else{
            //         if(Nodes_vector[u].start_time > Nodes_vector[*it].start_time && Nodes_vector[*it].end_time >= Nodes_vector[u].end_time){
            //             return FALSE;
            //         }else{
            //             Nodes_vector[u].finished_child++;
            //         }
            //     }

            // }
            // while(adj_list_vector[u].size() == Nodes_vector[u].finished_child){
            //     stack.pop();
            //     Nodes_vector[u].end_time = time++;
            //     u = Nodes_vector[u].parent;
            //     Nodes_vector[u].finished_child++;
            // }
        }
        return TRUE;
	}

};