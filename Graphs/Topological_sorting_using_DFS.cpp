# include<bits/stdc++.h>
using namespace std;
void DFS(std::vector<int> adj[],int u, std::stack<int> &s, bool visited[]);
void add_edge(std::vector<int> adj[], int u, int v);
void topological_DFS(std::vector<int> adj[], int v);

void add_edge(std::vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void print_edge(std::vector<int> adj[], int v)
{
    for(int i = 0; i < v; i++)
    {
        for( auto x : adj[i])
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

void topological_DFS(std::vector<int> adj[], int v)
{
    bool visited[v] = {false};
    std::stack<int> s;

    for(int i = 0; i < v; i++)
    {
        if(visited[i] == false)
        {
            DFS(adj,i, s, visited);
        }
    }

    while(s.empty() == false)
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}

void DFS(std::vector<int> adj[],int u, std::stack<int> &s, bool visited[])
{
    visited[u] = true;
    for(auto x : adj[u])
    {
        if(visited[x] == false)
        {
            DFS(adj,x,s,visited);
        }
    }
    s.push(u);
}





int main()
{
    int v = 5;
    std::vector<int> adj[v];
    add_edge(adj,0,2);
    add_edge(adj,0,3);
    add_edge(adj,2,3);
    add_edge(adj,1,3);
    add_edge(adj,1,4);
    //add_edge(adj,3,4,indegree);
    topological_DFS(adj,v);
}
