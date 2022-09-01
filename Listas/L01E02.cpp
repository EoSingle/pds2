/*
Você deve escrever um programa capaz de ocultar letras em uma frase.
Será informada uma lista de letras que devem ser substituídas por '#' (hash) 
em toda a frase. A frase será composta por um número não conhecido
anteriormente de palavras. Ao final, o programa deve imprimir a frase com as 
devidas alterações e o número de vezes que cada letra foi substituída na frase.
*/

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
