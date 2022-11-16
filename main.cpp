#include <iostream>
#include <string>
#include <tuple>
#include <sstream>
#include <fstream>
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

void callGraph(Graph graph, ifstream* fileInput)
{
    /*
        Note about file input:
        The first line of the input needs to be the number of vertices.
        Then put the matrix with the size from above. This is not checked and will result in undefined behavior if not done correctly.
    */
    if (fileInput != nullptr) // File input
    { 
        for (int i = 0; i < graph.size(); i++)
        {
            vector<int> cols;
            string row;
            getline(*fileInput, row);
            stringstream ss(row);
            std::string edge;
            int col = 0;
            while (getline(ss, edge, ' '))
            {
                if (edge == "1")
                {
                    graph.addEdge(i, col);
                }
                col++;
            }
        }
    }
    cout << INPUT_REQUEST;
    string inputString;
    int option = 9;
    while (option > 7)
    {
        getline(cin, inputString);
        option = stoi(inputString);
    }
    if (option == 1)
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
        cout << "Vertex for out edges:\n";
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
        cout << "Vertex for in edges:\n";
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
    else if (option == 7) // Ctrl+C also works but oh well, not trigger detecting here
    {
        return;
    }
    callGraph(graph, nullptr);
}

int main(int argc, char** argv) {
    string sizeInput;
    if (argc > 1 && (string) argv[1] == "-f")
    {
        ifstream fileInput;
        string arg2 = argv[2];
        fileInput.open(arg2);
        getline(fileInput, sizeInput);
        int size = stoi(sizeInput);
        Graph graph = Graph(size);
        callGraph(graph, &fileInput);
        fileInput.close();
    }
    else
    {
        cout << "How many vertices do you want your graph to be?" << endl;
        getline(cin, sizeInput);
        int size = stoi(sizeInput);
        Graph graph = Graph(size);
        callGraph(graph, nullptr);
    }
    
}