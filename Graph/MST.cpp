#include <iostream>
#include <vector>
#include <algorithm>
using namespace std ;


class Node {
  public:
  int nextv ;
  int val ;
  Node(int n , int v) {
     nextv = n;
     val = v ;

  }
};



void edge(vector<Node*> adj[] , int a , int b , int val){
    adj[a].push_back(new Node(b , val));
    adj[b].push_back(new Node(a , val));
}

bool check(vector<pair<int , int>> p , int x , int y){
    bool answer = true ;
    for(int i = 0 ; i < p.size(); i++){
      if(p[i].first == x && p[i].second == y){
          answer = false ;
          break ;
      }
      else if(p[i].second == x && p[i].first == y){
          answer = false ;
          break ;
      }
    }
    return answer ;
}

void minium_span(vector<pair<int , pair<int , int>>> v , int n  ){
    vector<pair<int , int>> ans ;
    //vector<pair<int , int>> temp ;
    int count = 0 ;
     
     bool visited[n];
      for(int i =0; i < n ; i++){
         visited[i] = false ;
      }

     for(int i =0 ; i < v.size(); i++){
         if(visited[v[i].second.second] == false || visited[v[i].second.first] == false){
             ans.push_back(make_pair(v[i].second.first , v[i].second.second));
             visited[v[i].second.first] = true ;
              visited[v[i].second.second] = true ;
             count += v[i].first;
         }
     }

    // ans.push_back(make_pair(v[0].second.first , v[0].second.second));
    // temp.push_back(make_pair(v[0].second.first , v[0].second.second));
    // for(int i = 1; i < v.size(); i++){
    //     if(check(temp , v[i].second.first , v[i].second.second) == true){
    //         ans.push_back(make_pair(v[i].second.first , v[i].second.second));
    //         count += v[i].first;
    //     }
    //     temp.push_back(make_pair(v[i].second.first , v[i].second.second));
    // }

    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i].first << " and " << ans[i].second << "\n";
    }
    cout << count << "\n";

}


int main() {
    vector<Node*> adj[6];
    vector<pair<int , pair<int , int>>> v ;
    edge(adj , 0 , 4 , 19);
    edge(adj , 0 , 1 , 16);
    edge(adj ,0 , 5 , 21);
    edge(adj ,4 , 3 , 18);
    edge(adj ,4 , 5 , 33);
    edge(adj ,5 , 1 , 11);
    edge(adj ,5 , 3 , 14);
    edge(adj ,3 , 2 , 10);
    edge(adj ,3 , 1 , 6);
    edge(adj ,2 , 1 , 5);
    for(int i =0 ; i < 6 ; i++){
        for(Node * temp : adj[i]){
            v.push_back(make_pair(temp->val , make_pair(i , temp->nextv)));
            cout << i << " -> " << temp->nextv << " := " << temp->val << "\n"; 
        }
    }

    sort(v.begin() , v.end());

    for(int i =0 ;i < v.size();  i++){
        cout << v[i].second.first << "  " << v[i].second.second << "  = " << v[i].first << "\n";
    }
    
    minium_span(v , 6);

}