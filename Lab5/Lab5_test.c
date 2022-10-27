#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Lab5.h"

void test_caesar();

int main() {
	setbuf(stdout, NULL);
	test_caesar();
	return 0;
}

void test_caesar() {
	printf("------------------------------\n");
	printf("Start: Testing Caesar Cipher:\n\n");

	char *plaintext = NULL, *ciphertext = NULL;
	int key;

	plaintext = (char*) malloc(27);
	key = 5;
	printf("key = %d\n", key);
	strcpy(plaintext, "abcdefghijklmnopqrstuvwxyz");
	ciphertext = encrypt(plaintext, key);
	printf("plaintext = %s\nciphertext= %s\n\n", plaintext, ciphertext);

	strcpy(plaintext, "");
	plaintext = decrypt(ciphertext, key);
	printf("ciphertext = %s\nplaintext = %s\n\n", ciphertext, plaintext);

	printf("key = %d\n", key);
	strcpy(ciphertext, "");
	strcpy(plaintext, "Welcome Back");
	ciphertext = encrypt(plaintext, key);
	printf("plaintext = %s\nciphertext= %s\n\n", plaintext, ciphertext);
	strcpy(plaintext, "");
	plaintext = decrypt(ciphertext, key);
	printf("ciphertext = %s\nplaintext = %s\n\n", ciphertext, plaintext);

	key = 4;
	printf("key = %d\n", key);
	strcpy(ciphertext, "");
	strcpy(plaintext, "Welcome Back");
	ciphertext = encrypt(plaintext, key);
	printf("plaintext = %s\nciphertext= %s\n\n", plaintext, ciphertext);
	strcpy(plaintext, "");
	plaintext = decrypt(ciphertext, key);
	printf("ciphertext = %s\nplaintext = %s\n\n", ciphertext, plaintext);

	free(plaintext);
	plaintext = NULL;
	free(ciphertext);
	ciphertext = NULL;

	printf("End: Testing Caesar Cipher\n");
	printf("------------------------------\n\n");
	return;
	return;
}

