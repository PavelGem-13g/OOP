#include <iostream>
#include <cassert>

#include "Graph.h"
#include "PostOffice.h"



int main() {
    Graph<int, PostOffice> graph = Graph<int, PostOffice>();

    PostOffice postOffice1 = PostOffice(1, 0);
    PostOffice postOffice2 = PostOffice(2, 1);

    GraphNode<int, PostOffice> node1 = GraphNode<int, PostOffice>(postOffice1.getIndex(), postOffice1);
    assert(node1.getKey()==1);
    assert(node1.getValue().getMails()==0);

    GraphNode<int, PostOffice> node2 = GraphNode<int, PostOffice>(postOffice2.getIndex(), postOffice2);

    graph.add(node1);
    graph.add(node2);

    assert(graph[node1.getKey()].getMails()==0);
    assert(graph[node2.getKey()].getMails()==1);



    node1.addConnection(node2, 1);
    node2.addConnection(node1, 1);




    //std::cout<<graph.length()<<std::endl;

    return 0;
}
