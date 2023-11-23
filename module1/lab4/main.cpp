#include <iostream>
#include <cassert>

#include "Graph.h"
#include "PostOffice.h"



int main() {
    Graph<int, PostOffice> graph = Graph<int, PostOffice>();

    PostOffice postOffice1 = PostOffice(1, 0);
    PostOffice postOffice2 = PostOffice(2, 1);
    PostOffice postOffice3 = PostOffice(3, 3);

    GraphNode<int, PostOffice> node1 = GraphNode<int, PostOffice>(postOffice1.getIndex(), postOffice1);
    assert(node1.getKey()==1);
    assert(node1.getValue().getMails()==0);

    GraphNode<int, PostOffice> node2 = GraphNode<int, PostOffice>(postOffice2.getIndex(), postOffice2);

    graph.add(node1);
    graph.add(node2);
    assert(graph.length()==2);

    assert(graph[node1.getKey()].getMails()==0);
    assert(graph[node2.getKey()].getMails()==1);

    Graph<int, PostOffice> graph2 = Graph<int, PostOffice>();
    GraphNode<int, PostOffice> node3 = GraphNode<int, PostOffice>(postOffice3.getIndex(), postOffice3);
    graph2.add(node2);
    graph2.add(node3);

    Graph<int, PostOffice> graph3 = graph&&graph2;

    assert(graph3.length()==1);

    Graph<int, PostOffice> graphCopy = Graph<int, PostOffice>(graph);
    assert((graph==graphCopy)== true);

    node1.addConnection(node2, 1);
    node2.addConnection(node1, 1);



    std::cout<<"All tests has completed successfully";

    return 0;
}
