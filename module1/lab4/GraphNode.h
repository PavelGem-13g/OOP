//
// Created by Павел on 23.11.2023.
//

#ifndef LAB4_GRAPHNODE_H
#define LAB4_GRAPHNODE_H

#include <iostream>

template <typename K, typename V>
class GraphNode {
private:
    K key;
    V value;

    std::vector<GraphNode<K, V>> nodes;
    std::vector<int> costs;
public:
    const K getKey() const{
        return key;
    }
    void setKey(K &value){
        this->key = value;
    }
    const V getValue() const{
        return value;
    }
    void setValue(V &value){
        this->value = value;
    }

    GraphNode(){
        key = nullptr;
        value = nullptr;

        nodes = std::vector<K>();
        costs = std::vector<int>();
    }
    GraphNode(const K &key, const V &value){
        this->key = key;
        this->value = value;

        nodes = std::vector<GraphNode<K, V>>();
        costs = std::vector<int>();
    }

    void addConnection(const GraphNode<K, V> &graphNode, int cost){
        nodes.push_back(graphNode);
        costs.push_back(cost);
    }

    bool operator == (const GraphNode<K, V> &graphNode){
        return key==graphNode.key && value==graphNode.value;
    }
};


#endif //LAB4_GRAPHNODE_H
