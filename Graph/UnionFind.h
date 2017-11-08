//
// Created by 李宁 on 2017/11/8.
//

#ifndef ALGORITHM_UNIONFIND_H
#define ALGORITHM_UNIONFIND_H

#include <iostream>
#include <vector>
using namespace std;

/**
 * find: 找到element所在的subset
 * union: 将两个element放到一个subset钟
 * int parent[]: index表示元素，对应的值表示parent 也就对应了所在的subset。如果为-1，表示他自己的subset
 *
 * 可以用来检测： 无向图中是否有边。 默认无向图中没有自连接的节点。
 * 方法：遍历每一条边，分别把src dst对应的subset找到，如果相同就说明有环，否则就加入到同一个subset中。然后继续遍历
 *
 */
namespace UnionFind {
    struct Edge {
        int src;
        int dst;

        Edge(int s, int d) : src(s), dst(d) {}
    };

    struct Graph {
        int V;
        int E;
        vector<Edge> edges;

    };

    struct Graph *createGraph(int v, int e) {
        Graph *graph = new Graph;
        graph->V = v;
        graph->E = e;
        return graph;
    }

    int find(vector<int> &parent, int i) {
        /* Method 1*/
        /*
        while(parent[i] != -1)
            i = parent[i];
        return i;
        */

        /* Method 2*/
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void Union(vector<int> &parent, int x, int y) {
        /* Method 1 */
        /*
        while( parent[x] != -1)
            x = parent[x];
        parent[x] = y;
        */

        /* Method 2 */
        int xset = find(parent, x);
        int yset = find(parent, y);
        parent[xset] = yset;
    }

    bool hasCycle(struct Graph *graph) {
        vector<int> parent(graph->V, -1);
        for (int i = 0; i < graph->edges.size(); ++i) {
            int x = find(parent, graph->edges[i].src);
            int y = find(parent, graph->edges[i].dst);

            if (x == y)
                return true;

            Union(parent, graph->edges[i].src, graph->edges[i].dst);
        }
        return false;
    }

    void test_UnionFind() {
        int V = 3, E = 3;

        Graph *graph = createGraph(V, E);
        graph->edges.push_back(Edge(0, 1));
        graph->edges.push_back(Edge(0, 2));
        graph->edges.push_back(Edge(1, 2));

        if (hasCycle(graph))
            cout << "graph contains cycle" << endl;
        else
            cout << "graph doesn't contains cycle" << endl;
    }


}
#endif //ALGORITHM_UNIONFIND_H
