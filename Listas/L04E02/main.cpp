#include "map.hpp"
#include "map_exceptions.hpp"

int main(){
    std::string data;
    Map map;

    while(std::cin>>data){
        if(data=="i"){
            int key, val;
            std::cin>>key>>val;
            try{
                map.insert(key, val);
            }catch(map_exc::key_in_use &e){
                std::cout<<"Key in use key = "<< e.get_key() <<std::endl;
            }
        }
        else if(data=="f"){
            int key, val;
            std::cin>>key;
            if(map.find(key, val)){
                std::cout<<"found "<<val<< " in key " << key <<std::endl;
            }
            else{
                std::cout<< "key " << key <<" not found"<<std::endl;
            }
        }
        else if(data=="r"){
            int key;
            std::cin>>key;
            try{
                map.remove(key);
            }catch(map_exc::key_not_found &e){
            std::cout<<"Key not found key = "<< e.get_key() << std::endl;
            }
        }
        else if(data=="p"){
            map.print();
        }
        else if(data=="r_f"){
            std::string filename;
            std::cin>>filename;
            try{
                map.read_from_file(filename);
            }catch(map_exc::invalid_map_in_file &e){
                    std::cout<<"Invalid Map in File "<< e.get_filename() << " Key "<< e.get_key() << " in line " << e.get_line() << std::endl;
            }
            catch(map_exc::file_not_found &e){
                    std::cout<<"File not found "<< e.get_filename() <<std::endl;
            }
            
        }  
    }
    return 0;
}
