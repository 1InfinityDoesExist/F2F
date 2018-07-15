#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdges(int x, int y);
    void DFS(int src);
    void BFS(int src);
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdges(int u, int v)
{
    adj[v].push_back(u);
    adj[u].push_back(v);
}
void Graph::DFS(int src)
{
    int *visited = (int *)malloc(sizeof(int ) * V);
    for(int iter = 0; iter < V; iter++)
    {
        visited[iter] = false;
    }
    stack<int> s;
    s.push(src);
    visited[src] = true;
    while(!s.empty())
    {
        int temp = s.top();
        s.pop();
        cout << temp << " ";
        for(list<int>::iterator iter = adj[temp].begin(); iter != adj[temp].end(); iter++)
        {
            if(!visited[*iter])
            {
                s.push(*iter);
                visited[*iter] = true;
            }
        }
    }
    cout << endl;
    return;
}
void Graph::BFS(int src)
{
    int *visited = (int *)malloc(sizeof(int) * V);
    for(int iter = 0; iter < V; iter++)
    {
        visited[iter] = false;
    }
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        for(list<int>::iterator iter = adj[temp].begin(); iter != adj[temp].end(); iter++)
        {
            if(!visited[*iter])
            {
                visited[*iter] = true;
                q.push(*iter);
            }
        }
    }
    cout << endl;
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Graph g(4);
    g.addEdges(0, 1);
    g.addEdges(0, 2);
    g.addEdges(1, 2);
    g.addEdges(2, 0);
    g.addEdges(2, 3);
    g.addEdges(3, 3);

    g.DFS(0);
    g.BFS(0);

    return 0;
}
