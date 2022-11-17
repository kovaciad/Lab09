#pragma once

#include <vector>
#include <string>

class Graph
{
public:
    Graph();
    Graph(int numVertices);
    ~Graph();
    int size() {
        return numVertices;
    };
    bool addEdge(int,int);
    bool removeEdge(int,int);
    bool hasEdge(int, int);
    std::vector<int> outEdges(int);
    std::vector<int> inEdges(int);
    std::string printOutAdjacencyMatrix();

private:
    int numVertices;
    std::vector<std::vector < int > > matrix;
};