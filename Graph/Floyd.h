//
// Created by 李宁 on 2017/11/7.
//

#ifndef ALGORITHM_FLOYD_H
#define ALGORITHM_FLOYD_H

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Floyd(const vector<vector<int> >& graph)
{
    vector<vector<int> > dist = graph;
    int V = graph.size();

    for (int i = 0; i < V; ++i)
    {
        dist[i][i] = 0;
    }

    for (int k = 0; k < V; ++k)
    {
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
                        && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return dist;
}


void test_Floyd()
{
    int V = 4;
    int INF = INT_MAX;

    vector<vector<int> > graph;
    graph.push_back({0, 5, INF, 10});
    graph.push_back({INF, 0,   3, INF});
    graph.push_back({INF, INF, 0,   1});
    graph.push_back({INF, INF, INF, 0});

    vector<vector<int>> dist = Floyd(graph);

    cout <<  "Following matrix shows the shortest distances between every pair of vertices" << endl;

    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            if(dist[i][j] == INT_MAX)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }

}

#endif //ALGORITHM_FLOYD_H
