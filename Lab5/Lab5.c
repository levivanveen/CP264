/*
 * ---------------------------------
 * Student Name: Levi Van Veen
 * Student ID: 200852490
 * Student Email: vanv2490@mylaurier.ca
 * ---------------------------------
 */
#include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

char* encrypt(char *plaintext, int key) {
	int index = 0, i = 0, size = strlen(plaintext);
	char *cipher = (char*) malloc(size + 1);

	for (i = 0; i < size; i++) {
		if (isalpha(plaintext[i])) {
			char letter = plaintext[i];
			if (islower(plaintext[i])) {
				index = ((letter - 97) + (key % 26)) % 26;
				cipher[i] = index + 97;
			} else {
				index = ((letter - 65) + (key % 26)) % 26;
				cipher[i] = index + 65;
			}
		} else {
			cipher[i] = plaintext[i];
		}
	}
	cipher[size] = '\0';
	return cipher;
}

char* decrypt(char *ciphertext, int key) {
	int size = strlen(ciphertext), index = 0, i = 0;
	char *plain = (char*) malloc(size + 1);

	for (i = 0; i < size; i++) {
		if (isalpha(ciphertext[i])) {
			char letter = ciphertext[i];
			if (islower(ciphertext[i])) {
				index = ((letter - 97) - (key % 26)) % 26;
				if (index < 0)
					plain[i] = index + 123;
				else
					plain[i] = index + 97;
			} else {
				index = ((letter - 65) - (key % 26)) % 26;
				if (index < 0)
					plain[i] = 91 + index;
				else
					plain[i] = index + 65;
			}
		} else {
			plain[i] = ciphertext[i];
		}
	}
	plain[size] = '\0';
	return plain;
}
