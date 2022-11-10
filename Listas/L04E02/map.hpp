#ifndef MAP_H
#define MAP_H

#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>

class Map {
    private:
        struct Node {
            int key;
            int value;
            Node(int k, int v) : key(k), value(v) {}
        };
        std::list<Node> _nodes;

    public:
        void read_from_file(std::string filename);
        bool find(int key, int &found_val);
        void insert(int key, int val);
        void remove(int key);
        void print();

};

#endif
