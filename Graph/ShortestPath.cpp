#include <iostream>
#include <queue>
#include <vector>
using namespace std ;

void addedge(vector<int>adj[] , int u , int v){
   adj[u].push_back(v);
   adj[v].push_back(u);
}


void count(vector<int> adj[] , int v , int s) {

    int distance[v]  ;
    for(int i = 0  ; i < v ; i++){
        distance[i] = -1 ;
    }
    distance[s] = 0 ;
    queue<int> q ;
    bool visited[v];
    for(int i = 0 ; i < v ; i++){
        visited[i] = false ;
    }
    q.push(s);
    visited[s] = true ;
    while(q.empty() == false){
       int u = q.front();
       q.pop();
        for(int v : adj[u]){
            if(visited[v] == false){
                distance[v] = distance[u] +1 ;
                q.push(v);
                visited[v] = true ;
            }
        }
    }
     for(int i =0 ; i < v ; i++){
         cout << distance[i] << "\n" ;
     } 
}


int main() {
    int v = 8 ;
    vector<int> adj[v];
     addedge(adj , 0 , 1);
    addedge(adj, 0 , 2);
    addedge(adj , 1 , 2);
    addedge(adj  , 1 , 3);
    addedge(adj , 2 , 3);
    addedge(adj , 3 , 4);
    // for this bfs doesnt work out normally but it will by disconnected graph
   /* addedge(adj , 5 , 5);
    addedge(adj , 6 , 7);
    addedge(adj , 5 , 7);
    addedge(adj , 4 , 6);*/
     
    count(adj , 5 , 0);
     
    
}