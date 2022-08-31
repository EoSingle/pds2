#include <iostream>
#include <string>

using namespace std;

int main(){
    int len;
    string frase;

    cin >> len;
    char letras[len];
    int pontos[len]={};
    for(int i = 0; i < len; i++){
        cin >> letras[i];
    }


    cin.ignore();
    getline(cin, frase);

    for(int i = 0; i < len; i++){
        for(int j = 0; j < frase.length(); j++){
            if(letras[i] == frase[j]){
                frase[j] = '#';
                pontos[i]++;
            }
        }
    }

    cout << frase << endl;
    for(int i = 0; i < len; i++){
        cout << letras[i] << " " << pontos[i] << endl;
    }

    return 0;
}
