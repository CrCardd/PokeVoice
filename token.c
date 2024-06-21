#include <stdio.h>
#include <string.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 50

int main() {
    char input[] = "apple,orange,banana,grape";
    char *token;
    char tokens[MAX_TOKENS][MAX_TOKEN_LENGTH];  // Array to store tokens
    int token_count = 0;

    // Use strtok to split the string by comma
    token = strtok(input, ",");
    
    // Iterate through tokens
    while (token_count < MAX_TOKENS) {
        strcpy(tokens[token_count], token);  // Copy token to tokens array
        token_count++;
        token = strtok(NULL, ",");  // Get next token
    }

    // Print tokens
    for (int i = 0; i < token_count; i++) {
        printf("Token %d: %s\n", i+1, tokens[i]);
    }

    return 0;
}
