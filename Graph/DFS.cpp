#include <iostream>
#include <vector>

using namespace std ;


void DFSR(vector<int> adj[], int s , bool visited[]){
  visited[s] = true ;
  cout << s << " ";
  for(int u : adj[s]){
      if(visited[u] == false){
          DFSR(adj , u , visited);
      }
  }
}

void DFs(vector<int> adj[] , int v ){
    bool visited[v];
    for(int i = 0 ; i < v ; i++){
        visited[i] = false ;
    }
    for(int i =0 ; i < v ; i++){
        if(visited[i] == false){
            DFSR(adj , i , visited);
        } 
    }
}

void addedge(vector<int> adj[] , int u , int v){
    adj[u].push_back(v);
    adj[v].push_back(u);

}


int main() {
    int v = 8 ;
    vector<int> adj[v];
    addedge(adj , 0 , 1);
    addedge(adj, 0 , 2);
    addedge(adj , 1 , 2);
    addedge(adj  , 1 , 3);
    addedge(adj , 2 , 3);
    addedge(adj , 1 , 4);
    // for this bfs doesnt work out normally but it will by disconnected graph
    addedge(adj , 5 , 5);
    addedge(adj , 6 , 7);
    addedge(adj , 5 , 7);
    addedge(adj , 4 , 6);
    DFs(adj ,8 );
}