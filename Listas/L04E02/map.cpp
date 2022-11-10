#include "map.hpp"
#include "map_exceptions.hpp"

void Map::read_from_file(std::string filename) {
    std::list<int> keys;
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw map_exc::file_not_found(filename.c_str());
    }
    std::string line;
    int line_number = 0;
    while (std::getline(file, line)) {
        line_number++;
        std::istringstream iss(line);
        int key, value;
        iss >> key >> value;
        for(auto it = keys.begin(); it != keys.end(); it++){
            if(*it==key){
                throw map_exc::invalid_map_in_file(filename.c_str(), line_number, key);
            }
        }
        keys.push_back(key);
        for (auto it = _nodes.begin(); it != _nodes.end(); it++) {
            if (it->key == key) {
                throw map_exc::invalid_map_in_file(filename.c_str(), line_number, key);
            }
        }
    }
    file.clear();
    file.seekg(0);
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        int key, value;
        iss >> key >> value;
        insert(key, value);
    }
    file.close();
}

bool Map::find(int key, int &found_val) {
    for (auto it = _nodes.begin(); it != _nodes.end(); it++) {
        if (it->key == key) {
            found_val = it->value;
            return true;
        }
    }
    return false;
}

void Map::insert(int key, int val) {
    for (auto it = _nodes.begin(); it != _nodes.end(); it++) {
        if (it->key == key) {
            throw map_exc::key_in_use(key);
        }
    }
    _nodes.push_back(Node(key, val));
}

void Map::remove(int key) {
    for (auto it = _nodes.begin(); it != _nodes.end(); it++) {
        if (it->key == key) {
            _nodes.erase(it);
            return;
        }
    }
    throw map_exc::key_not_found(key);
}

void Map::print() {
    std::cout<<"========================"<<std::endl;
    for (auto it = _nodes.begin(); it != _nodes.end(); it++) {
        std::cout << "<" <<it->key << "," << it->value << ">" << std::endl;
    }
    std::cout<<"========================"<<std::endl;
}