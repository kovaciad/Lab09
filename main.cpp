#include <iostream>
#include <string>
#include <tuple>
#include <sstream>
#include "Graph.h"

using namespace std;

static char INPUT_REQUEST[] = 
"Press 1 to add an edge to graph.\n\
Press 2 remove an edge from graph.\n\
Press 3 Find an edge in the graph.\n\
Press 4 Find the out edges of a vertices.\n\
Press 5 Find the in edges of a vertices.\n\
Press 6 To Print out Adjacency Matrix.\n\
Press 7 to quit.\n";

tuple<int,int> getInputs()
{
    string input;
    int from, to;
    cout << "From:\n";
    getline(cin, input);
    from = stoi(input);
    cout << "To:\n";
    getline(cin, input);
    to = stoi(input);

    return make_tuple(from, to);
}

void callGraph(Graph graph)
{
    cout << INPUT_REQUEST;
    string inputString;
    int option = 9;
    while (option > 7)
    {
        getline(cin, inputString);
        option = stoi(inputString);
    }
    /*
        Note about file input:
        The first line of the input needs to be the number of vertices.
        The second line needs to be "0" to call the file input function
        Then put the matrix with the size that you put. This is not checked and will result in undefined behavior if not done correctly.
    */
    if (option == 0) // File input
    { 
        for (int i = 0; i < graph.size(); i++)
        {
            vector<int> cols;
            string row;
            getline(cin, row);
            stringstream ss(row);
            std::string edge;
            int col = 0;
            while (getline(ss, edge, ' '))
            {
                if (edge == "1")
                {
                    cout << "Got to the meat and potatoes" << endl;
                    graph.addEdge(i, col);
                }
                col++;
            }
        }
    }
    else if (option == 1)
    {
        int from, to;
        tie(from, to) = getInputs();
        graph.addEdge(from, to);
    }
    else if (option == 2)
    {
        int from, to;
        tie(from, to) = getInputs();
        graph.removeEdge(from, to);
    }
    else if (option == 3)
    {
        int from, to;
        tie(from, to) = getInputs();
        string hasEdge = graph.hasEdge(from, to) ? "Edge Exists" : "Edge does not exist";
        cout << hasEdge << endl;
    }
    else if (option == 4)
    {
        string input;
        cout << "Vertex for in edges:\n";
        getline(cin, input);
        int vertex = stoi(input);
        vector<int> outEdges = graph.outEdges(vertex);
        cout << "Out Edges for " << input << ": ";
        for (int edge : outEdges)
        {
            cout << edge << " ";
        }
        cout << endl;
    }
    else if (option == 5)
    {
        string input;
        cout << "Vertex for out edges:\n";
        getline(cin, input);
        int vertex = stoi(input);
        vector<int> inEdges = graph.inEdges(vertex);
        cout << "In Edges for " << input << ": ";
        for (int edge : inEdges)
        {
            cout << edge << " ";
        }
        cout << endl;
    }
    else if (option == 6)
    {
        graph.printOutAdjacencyMatrix();
    }
    else if (option == 7)
    {
        return;
    }
    callGraph(graph);
}

int main(int, char**) {
    string sizeInput;
    cout << "How many vertices do you want your graph to be?" << endl;
    getline(cin, sizeInput);
    int size = stoi(sizeInput);
    Graph graph = Graph(size);
    callGraph(graph);
}