#include <iostream>

class Item{
    private:
        int _key;
        int _val;
    public:
        Item(int key, int val);
        Item();

        friend bool operator > (const Item &i1, const Item &i2);
        friend std::ostream& operator << (std::ostream &out, const Item &i);
};

Item::Item(int key, int val){
    _key = key;
    _val = val;
}

Item::Item(){
    _key = 0;
    _val = 0;
}

bool operator > (const Item &i1, const Item &i2){
    return i1._val > i2._val;
}

std::ostream& operator << (std::ostream &out, const Item &i){
    out << "(" <<i._key << "," << i._val << ")" ;
    return out;
}

