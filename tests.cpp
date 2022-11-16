#include "Graph.h"
#include <gtest/gtest.h>

        TEST(addEdge, canAdd)
        {
            Graph graph = Graph(5);
            auto i = 2;
            auto j = 3;
            graph.addEdge(i, j);
            EXPECT_TRUE(graph.hasEdge(i,j) == 1);
        }

        TEST(addEdge, alreadyExists)
        {
            int numVertices = 5;
            int i = 3;
            int j = 4;
            Graph graph = Graph(numVertices);
            EXPECT_TRUE(graph.addEdge(i,j));
            EXPECT_FALSE(graph.addEdge(i,j));
        }

        TEST(removeEdge, canRemove)
        {
            Graph graph = Graph(5);
            auto i = 2;
            auto j = 3;
            graph.addEdge(i,j);
            EXPECT_TRUE(graph.removeEdge(i,j));
        }

        TEST(removeEdge, noEdges)
        {
            Graph graph = Graph(5);
            auto i = 2;
            auto j = 3;
            EXPECT_FALSE(graph.removeEdge(i, j));
        }

        TEST(hasEdge, exists)
        {
            Graph graph = Graph(5);
            auto i = 2;
            auto j = 3;
            graph.addEdge(i,j);
            EXPECT_TRUE(graph.hasEdge(i,j));
        }

        TEST(hasEdge, doesNotExist)
        {
            Graph graph = Graph(5);
            auto i = 2;
            auto j = 3;
            graph.addEdge(i,j);
            EXPECT_FALSE(graph.hasEdge(4, 5));
        }

        TEST(inEdges, hasCorrectEdges)
        {
            std::vector<int> edges;
            Graph graph = Graph(5);
            auto i = 1;
            auto j = 2;
            graph.addEdge(i, j);
            i = 3;
            j = 2;
            graph.addEdge(i, j);
            edges = graph.inEdges(j);
            std::vector<int> expectedEdges = { 1, 3 };
            for(int i = 0; i < 2; i++) 
            {
                EXPECT_TRUE(edges.at(i) == expectedEdges.at(i));
            }
        }

        TEST(inEdges, outOfRange)
        {
            Graph graph = Graph(1);
            EXPECT_THROW(graph.inEdges(2), std::exception);
        }

        TEST(inEdges, noEdges)
        {
            std::vector<int> edges;
            Graph graph = Graph(5);
            edges = graph.inEdges(1);
            EXPECT_TRUE(edges.empty());
        }

        TEST(outEdges, hasCorrectEdges)
        {
            std::vector<int> edges;
            std::vector<int> expectedEdges = { 1, 3 };
            Graph graph = Graph(5);
            auto i = 2;
            auto j = 1;
            graph.addEdge(i, j);
            i = 2;
            j = 3;
            graph.addEdge(i, j);
            edges = graph.outEdges(i);
            for (int j = 0; j < 2; j++)
            {
                EXPECT_TRUE(edges.at(j) == expectedEdges.at(j));
            }
        }
 
        TEST(outEdges, outOfRange)
        {
            Graph graph = Graph(1);
            EXPECT_THROW(graph.outEdges(2), std::exception);
        }

        TEST(outEdges, noEdges)
        {
            std::vector<int> edges;
            Graph graph = Graph(5);
            edges = graph.outEdges(1);
            EXPECT_TRUE(edges.empty());
        }

        TEST(printAdjacencyMatrix, noMatrix)
        {
            Graph graph = Graph(0);
            EXPECT_TRUE(graph.printOutAdjacencyMatrix() == "");
        }
        
        TEST(printAdjacencyMatrix, isMatrix)
        {
            Graph graph = Graph(5);
            std::string expected = 
                "0 0 1 0 0 \n"
                "1 0 0 0 0 \n"
                "0 0 0 0 0 \n"
                "0 0 0 0 0 \n"
                "0 0 0 0 0 \n";
            auto i = 0;
            auto j = 2;
            graph.addEdge(i, j);
            i = 1;
            j = 0;
            graph.addEdge(i, j);
            EXPECT_TRUE(graph.printOutAdjacencyMatrix() == expected);
        }


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}