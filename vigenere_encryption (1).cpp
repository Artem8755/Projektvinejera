#include <iostream>
#include <string>

using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// функция получения кода символа
int keycode(char s){
    for(int i = 0; i < alphabet.length(); i++){
        if(s == alphabet[i]) return i;
    }
    return 0;
}

string Encode(string text, string key){
    string code;
    for(int i = 0; i < text.length(); i++){
        code += alphabet[(keycode(text[i]) + keycode(key[i % key.length()])) % alphabet.length()];
    }
    return code;
}

string Decode(string text, string key){
    string code;
    for(int i = 0; i < text.length(); i++){
        code += alphabet[(keycode(text[i]) - keycode(key[i % key.length()]) + alphabet.length()) % alphabet.length()];
    }
    return code;
}

int main(){
    string txt, key;
    char x;
    cout << "enter number encoding(1) or decoding(2)" << endl;
    cin >> x;
    
    if(x != '1' && x != '2'){
        cout << "value entered incorrectly" << endl;
        exit(0);
    }
    
    cout << "enter text: ";
    cin >> txt;
    cout << "enter key: ";
    cin >> key;
    
    for(auto& c : txt) c = toupper(c);
    for(auto& c : key) c = toupper(c);
    
    if(x == '1') cout << Encode(txt, key);
    if(x == '2') cout << Decode(txt, key);
}