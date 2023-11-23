//
// Created by Павел on 22.11.2023.
//

#ifndef LAB4_GRAPH_H
#define LAB4_GRAPH_H

#include <string>

#include "GraphNode.h"

template <typename K, typename V>
class Graph {
private:
    std::vector<GraphNode<K, V>> nodes;
public:
    Graph() {
        nodes = std::vector<GraphNode<K, V>>();
    }

    Graph(const Graph<K, V> &graph) {
        std::copy(graph.nodes.begin(), graph.nodes.end(), nodes.begin());
    }

    ~Graph() {

    }

    void clear() const {
        for (V item: nodes) {
            delete item;
        }
    }

    int length() const{
        return nodes.size();
    }

    void saveFile(std::string path){

    }

    void readFile(std::string path){

    }

    void add(GraphNode<K, V> node) {
        nodes.push_back(node);
    }

    bool isIn(const K &key){
        for (int i = 0; i < nodes.size(); ++i) {
            if(nodes[i].getKey()==key){
                nodes.erase(nodes.begin(), nodes.end(), i);
            }
        }
    }

    void remove(const V &value){
        for (int i = 0; i < nodes.size(); ++i) {
            if(nodes[i].getValue()==value){
                nodes.erase(nodes.begin(), nodes.end(), i);
            }
        }
    }

    bool operator == (const Graph<K, V> &graph){
        if(length()!=graph.length()){
            return false;
        }
        std::sort(nodes.begin(), nodes.end());
        for (int i = 0; i < graph; ++i) {
            if(nodes[i]!=graph.nodes[i]){
                return false;
            }
        }
        return true;
    }

    V operator[](K key) {
        for (int i = 0; i < nodes.size(); ++i) {
            if (nodes[i].getKey() == key) {
                return nodes[i].getValue();
            }
        }

        nodes.emplace_back(GraphNode<K, V>(key, V()));
        return nodes.back().getValue();
    }

    Graph<K, V> operator&&(const Graph<K, V> &graph){
        Graph<K, V> result = Graph<K, V>();
        for (int i = 0; i < length(); ++i) {
            for (int j = 0; j < graph.length(); ++j) {
                if(nodes[i] == graph.nodes[i]){
                    result.add(nodes[i]);
                }
            }
        }
        return result;
    }

    K* path(const Graph<K, V> &a, const Graph<K, V> &b){
        return nullptr;
    }
};


#endif //LAB4_GRAPH_H
