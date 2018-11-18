#include <iostream>
#include <vector>
#include <list>
#include <queue>


using namespace std;

class Graph{
  int V; //number of vertices
  
  vector<int> *adjList;
  
public:
  Graph(int numVertices);
  void addEdge(int n, int m);
  void DFS(int vertix);
  void DFSUtil(bool* visited, int vertix);
  void path(int vertix, int vertix2);
  void BFS(int vertix);
};

int main()
{
  Graph *graph = new Graph(5);
  
  graph->addEdge(0, 1);
  graph->addEdge(0, 2);
  graph->addEdge(1, 2);
  graph->addEdge(2, 0);
  graph->addEdge(2, 3);
  graph->addEdge(3, 3);
  graph->addEdge(3, 4);
  
  cout << "DFS: ";
  graph->DFS(2);
  cout << "BFS: ";
  graph->BFS(2);
  
  //graph->path(0, 4);
  
  return 0;
}

Graph::Graph(int numVertices)
{
  V = numVertices;
  adjList = new vector<int>[numVertices];
}

void Graph::addEdge(int n, int m)
{
  adjList[n].push_back(m);
}

void Graph::DFS(int vertix)
{
  //do a DFS starting from the vertix we passed in
  bool visited[V] = {false};
  
  DFSUtil(visited, vertix);
  
  cout << endl;
}

void Graph::DFSUtil(bool *visited, int vertix)
{
  visited[vertix] = true;
  cout << vertix << " ";
  
  vector<int>::iterator it;
  
  for(it = adjList[vertix].begin(); it != adjList[vertix].end(); ++it){
    
    if(!visited[*it])
      DFSUtil(visited, *it);
  }
}

void Graph::BFS(int vertix)
{
  bool visited[V] = {false};
  
  queue<int> queue1;
  
  queue1.push(vertix);
  
  cout << vertix << " ";
  
  while(!queue1.empty()){
    vertix = queue1.front();
    visited[vertix] = true;
    queue1.pop();
    vector<int>::iterator i;
    
    for(i = adjList[vertix].begin(); i != adjList[vertix].end(); ++i){
      if(!visited[*i]){
        queue1.push(*i);
        visited[*i] = true;
        cout << *i << " ";
      }
    }
  }
  cout << endl;
}


void Graph::path(int vertix, int vertix2){
  bool visited[V] = {false};
  
  list<int> queue;
  
  visited[vertix] = true;
  queue.push_back(vertix);
  
  while(!queue.empty()){
    vertix = queue.front();
    //cout << vertix << " ";
    queue.pop_front();
    
    vector<int>::iterator it;
    
    for(it = adjList[vertix].begin(); it != adjList[vertix].end(); ++it){
      if(!visited[*it])
      {
        queue.push_back(*it);
        visited[*it] = true;
      }
      
      if(*it == vertix2){
        cout << "there is a path" << endl;
        break;
      }
    }
    if(*it == vertix2)
      break;
  }
  cout << endl;
}
