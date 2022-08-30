#include <iostream>
#include <string>

using namespace std;

int main(){
    int len;
    cout << "Input: ";
    cin >> len;
    char letras[len];
    for(int i = 0; i < len; i++){
        cin >> letras[i];
    }

    string frase;
    cout << "Frase:" << endl;
    getline (cin,frase,'\n');  // A linha esta sendo pulada

    for(int i = 0; i < len; i++){
        for(int j = 0; i < frase.length(); j++){
            if(letras[i] == frase[j]){
                frase.replace(j, 1, "#");
            }
        }
    }

    cout << frase << endl;

    return 0;
}
