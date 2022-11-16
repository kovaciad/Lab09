#include <iostream>
#include "Graph.h"


Graph::Graph(int numVertices) // 2D Dynamically allocated matrix inspired by https://www.learncpp.com/cpp-tutorial/pointers-to-pointers/
{
    matrix = new int*[numVertices];
    for (int i = 0; i < numVertices; i++)
    {
        matrix[i] = new int[numVertices];
    }
    this->numVertices = numVertices;
}

Graph::~Graph()
{
    // for (int i = 0; i < numVertices; i++)
    // {
    //     delete [] matrix[i];
    // }
    // delete[] matrix;
}

bool Graph::addEdge(int i, int j)
{
    if((i < numVertices || j < numVertices) && i != j)
    {
        if (matrix[i][j] == 1)
        {
            return false;
        }
        matrix[i][j] = 1;
        return true;
    }
    return false;
}

bool Graph::removeEdge(int i, int j)
{
    if(i < numVertices || j < numVertices)
    {
        if(matrix[i][j] == 0)
        {
            return false;
        }
        matrix[i][j] = 0;
        return true;
    }
    return false;
}

bool Graph::hasEdge(int i, int j)
{
    if (i >= numVertices || j >= numVertices) 
    {
        return false;
    }
    return matrix[i][j] == 1;
}

std::string Graph::printOutAdjacencyMatrix()
{
    std::string result = "";
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            result.append(std::to_string(matrix[i][j]) + " ");
        }
        result.append("\n");
    }
    std::cout << result;
    return result;
}

std::vector<int> Graph::inEdges(int j)
{
    if (j >= numVertices)
    {
        throw std::exception();
    }
    std::vector<int> edges;
    for (int i = 0; i < numVertices; i++)
    {
        if (matrix[i][j] == 1)
        {
            edges.push_back(i);
        } 
    }
    return edges;
}

std::vector<int> Graph::outEdges(int i)
{
    if (i >= numVertices)
    {
        throw std::exception();
    }
    std::vector<int> edges;
    for (int j = 0; j < numVertices; j++)
    {
        if (matrix[i][j] == 1)
        {
            edges.push_back(j);
        } 
    }
    return edges;
}