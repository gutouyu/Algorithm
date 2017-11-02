#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    vector<vector<pair<int, int>> > graph;
    int V;

public:
    Graph(int V);
    void addEdge(int s, int t, int w);
    void dijkstra(int s);
};

Graph::Graph(int V) { this->V = V; graph.resize(V);}

void Graph::addEdge(int s, int t, int w)
{
    graph[s].push_back(make_pair(t, w));
}

int minDistance(const vector<int>&distance,const vector<bool>& spt)
{
    int min_idx = -1, min_dist = INT_MAX;
    for (int i = 0; i < distance.size(); ++i)
    {
        if (distance[i] < min_dist && spt[i]==false)//不在spt中，并且距离是最小的
        {
            min_dist = distance[i];
            min_idx = i;
        }
    }
    return min_idx;
}

void printSolution(const vector<int>& dist)
{
    std::cout << "Vertex    Distance from source" << endl;
    for (int i = 0; i < dist.size(); ++i)
    {
        std::cout << i << "\t" << dist[i] << std::endl;
    }

}

void Graph::dijkstra(int s)
{
    //spt: shorest path tree,表示是否在spt中;初始化为false,spt为空
    vector<bool> spt(V,false);

    vector<int> distance(V, INT_MAX);//初始化所有的距离为最大，原点距离为0; 同时也是我们最后的结果
    distance[s] = 0;

    //dijkstra只需要把所有节点遍历一遍，就可得出结果
    for (int count = 0; count < V; ++count)
    {

        // 1. 找到不在spt中，距离最小的vertex
        int vertex = minDistance(distance, spt);

        // 2. 加入到spt中
        spt[vertex] = true;

        // 3. 更新其相邻节点的distance
        vector<pair<int,int> > adjs = graph[vertex];

        for (vector<pair<int,int> >::iterator ite = adjs.begin(); ite != adjs.end(); ++ite)
        {
            int adj = ite->first, weight = ite->second;
            int old_dist = distance[adj];

            //如果从新节点到此节点的距离更近，那么就更新到该节点的距离
            if (old_dist > distance[vertex] + weight)
            {
                distance[adj] = distance[vertex] + weight;
            }
        }
    }
    printSolution(distance);
}


void test_dijkstra()
{
    Graph g(9);
    g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,0,4);
    g.addEdge(1,2,8);
    g.addEdge(1,7,11);
    g.addEdge(2,1,8);
    g.addEdge(2,3,7);
    g.addEdge(2,5,4);
    g.addEdge(2,8,2);
    g.addEdge(4,8,2);
    g.addEdge(3,2,7);
    g.addEdge(3,4,9);
    g.addEdge(3,5,14);
    g.addEdge(4,3,9);
    g.addEdge(4,5,10);
    g.addEdge(5,2,4);
    g.addEdge(5,3,14);
    g.addEdge(5,4,10);
    g.addEdge(5,6,2);
    g.addEdge(6,5,2);
    g.addEdge(6,7,1);
    g.addEdge(6,8,6);
    g.addEdge(7,0,8);
    g.addEdge(7,1,11);
    g.addEdge(7,6,1);
    g.addEdge(7,8,7);
    g.addEdge(8,2,2);
    g.addEdge(8,6,6);
    g.addEdge(8,7,7);

    g.dijkstra(0);

}