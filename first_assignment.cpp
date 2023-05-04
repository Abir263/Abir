#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> key = {123, 45, 67, 89, 10, 11, 12, 13, 14, 15};

string encrypt(string message) {
    string ciphertext;
    int length = message.length();
    for (int i = 0; i < length; i++) {
        int letter = message[i];
        int encryptedLetter = letter ^ key[i % 10];
        ciphertext += encryptedLetter;
    }
    return ciphertext;
}

string decrypt(string ciphertext) {
    string message;
    int length = ciphertext.length();
    for (int i = 0; i < length; i++) {
        int encryptedLetter = ciphertext[i];
        int letter = encryptedLetter ^ key[i % 10];
        message += letter;
    }
    return message;
}

int main() {
    string msg = "thisisamessage";
    string ciphertext = encrypt(msg);
    string decryptedMessage = decrypt(ciphertext);
    cout << "Main Msg: " << msg << endl;
    cout << "Enc msg: " << ciphertext << endl;
    cout << "Dec msg: " << decryptedMessage << endl;
    return 0;
}
