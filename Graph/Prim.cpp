#include <queue>
#include <vector>
#include <set>
#include <iostream>
using namespace std ;

typedef pair<int, int> pi;

class Node {
  public:
  int nextv ;
  int weight ;
  Node(){
      nextv = -1 ;
      weight = -1 ;
  }
  Node(int nv , int w){
      nextv = nv ;
      weight = w ;
  }
};


void add_edge(vector<Node*>adj[] , int v , int u , int w){
    adj[v].push_back(new Node(u , w));
    adj[u].push_back(new Node(v , w));
}

int main(){
    int v = 9 ;
    vector<Node*> adj[v];
    priority_queue<pi, vector<pi>, greater<pi>> pq ;
    add_edge(adj , 0 , 1 , 4);
    add_edge(adj , 0 , 7 , 8);
    add_edge(adj , 1 , 2 , 8);
    add_edge(adj , 1 , 7 , 11);
    add_edge(adj , 2 , 3 , 7);
    add_edge(adj , 2 , 8 , 2);
    add_edge(adj , 2 , 5 , 4 );
    add_edge(adj , 3 , 4 , 9);
    add_edge(adj , 3 , 5 , 14);
    add_edge(adj , 4 , 5 , 10);
    add_edge(adj , 5 , 6 , 2);
    add_edge(adj , 6 , 7 , 1);
    add_edge(adj , 6 , 8 , 6);
    add_edge(adj , 8 , 7 , 8);
    bool visited[v];
    for(int i = 0 ; i < v ; i++ ){
        visited[i] = false ;
    }
    int count = 0 ;
    for(int i = 0 ; i < v ; i++){
        for(Node* x : adj[i]){
            pq.push(make_pair(x->weight , x->nextv));
        }

        while (pq.empty() == false)
        {
            if(visited[pq.top().second] == false){
                cout << i << " to " << pq.top().second << " = " << pq.top().first << "\n";
                count += pq.top().first ;
                //visited[pq.top().second] = true ;
                break ;
            }
            pq.pop();
        }
        while(pq.empty() == false){
            pq.pop();
        }
        
        visited[i] = true ;
    }
    cout << count << " \n";
}
