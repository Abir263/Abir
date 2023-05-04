#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j, ciphertext_len, key_len, key_pos;
    char c;
    ciphertext_len = strlen(ciphertext);
    key_len = strlen(key);
    j = 0;
    for (i = 0; i < ciphertext_len; i++) {
        c = ciphertext[i];
        if (isalpha(c)) {
            c = toupper(c);
            key_pos = j % key_len;
            c = ((c - 'A') - (key[key_pos] - 'A') + 26) % 26 + 'A';
            j++;
        }
        plaintext[i] = c;
    }
    plaintext[ciphertext_len] = '\0';
}

int main() {
    char plaintext[10000], ciphertext[10000], key[10000];
    printf("Enter the ciphertext: ");
    fgets(ciphertext, 10000, stdin);
    ciphertext[strcspn(ciphertext, "\n")] = '\0';  // remove trailing newline
    printf("Enter the key: ");
    fgets(key, 10000, stdin);
    key[strcspn(key, "\n")] = '\0';  // remove trailing newline
    decrypt(ciphertext, key, plaintext);
    printf("Decrypted plaintext: %s\n", plaintext);
    return 0;
}

