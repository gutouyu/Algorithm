//
//  Graph_D.cpp
//  Algorithm
//
//  Created by 李宁 on 2017/11/1.
//  Copyright © 2017年 李宁. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//表示有向图，用链表(list)来组织
class Graph_D
{
    
private:
    int V;
    vector<vector<int> > adj;

protected:
    void DFSUtils(int s, vector<bool>& visited);
    
public:
    Graph_D(int V);
    
    void addEdge(int v, int w);
    
    void BFS(int s);

    void DFS(int s);
};

Graph_D::Graph_D(int V)
{
    this->V = V;
    adj.clear();
    adj.resize(V);
}

void Graph_D::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph_D::BFS(int s)//广度优先搜索
{
    vector<bool> visited(V,false);
    queue<int> queue;
    
    visited[s] = true;
    queue.push(s);
    while ( !queue.empty() )
    {
        int v = queue.front();
        cout << v << " ";
        queue.pop();
        
        for (auto ite : adj[v] ){
            if (!visited[ite])
            {
                visited[ite] = true;
                queue.push(ite);
            }
        }
    }
}

void Graph_D::DFSUtils(int s, vector<bool> &visited)
{
    visited[s] = true;

    //do something with node s
    cout << s << " ";

    for (auto ite : adj[s])
    {
        if (!visited[ite])
        {
            DFSUtils(ite, visited);
        }
    }
}

void Graph_D::DFS(int s)
{
    vector<bool> visited(V, false);
    DFSUtils(s, visited);
}

void test_BFS()
{
    Graph_D g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "Following is BFS, Staring from vertex 2" << endl;
    g.BFS(2);
}

void test_DFS()
{
    Graph_D g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n";
    g.DFS(2);
}


