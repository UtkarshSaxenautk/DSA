#include <iostream>
#include <queue>
#include <vector>
using namespace std ;

void addedge(vector<int> adj[] , int u , int v){
    adj[u].push_back(v);
    adj[v].push_back(u);

}

void BFS(vector<int> adj[] , int s , bool visited[]){
    queue<int> q ;
    q.push(s);
    visited[s] = true ;

    while(q.empty() == false){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v : adj[u]){
            if(visited[v] == false){
                visited[v] = true ;
                q.push(v);
            }
        }
    }
}


int BFS_Undirected(vector<int> adj[] , int v){
    bool visited[v];
    int count = 0 ;
    for(int i = 0 ; i < v ; i++){
        visited[i]  = false ;
    }
    for(int i =0 ; i < v ; i++){
        if(visited[i] == false){
            BFS(adj , i , visited);
            count++ ;
        }
    }
    return count ;
}

int main() {
    int v = 6 ;
    vector<int> adj[v];
    addedge(adj , 0 , 1);
    addedge(adj, 0 , 2);
    addedge(adj , 1 , 2);
    //addedge(adj  , 1 , 3);
    addedge(adj , 2 , 3);
    addedge(adj , 1 , 4);
    // for this bfs doesnt work out normally but it will
    addedge(adj , 5 , 5);
  cout <<  BFS_Undirected(adj , 6);
}