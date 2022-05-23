#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* Generate_Key(char *key, int length){
	char *key_string = (char *)malloc(sizeof(char) * (length + 1));
	int i = 0;
	int j = 0;
	while(i < length){
		char temp = key[i];
		if(temp == '{' || temp == '}' || temp == '_' || isdigit(temp)){
			i++;
			continue;
		}
		key_string[i] = key[j % strlen(key)];
		i++;
		j++;
	}
	key_string[i] = '\0';
	printf(key_string);
	return key_string;
}

char* Generate_Plaintext(char *key_string, char *cipher_text){
	char return_me[strlen(cipher_text) * 2];
	int i = 0;
	int j = 0;
	while(i <= strlen(cipher_text)){
		char temp = cipher_text[i];
		if(temp == '{' || temp == '}' || temp == '_'){
			return_me[i] = temp;
			i++;
			continue;
		}
		if(isdigit(temp)){
			return_me[i] = temp;
			i++;
			continue;
		}
		return_me[i] = (((toupper(temp) - key_string[j]) + 26) % 26) + 'A';
		i++;
		j++;
	}
	printf("out of for loop\n");
	return_me[i] = '\0';
	printf(return_me);
	return return_me;
}

char* Generate_Plaintext_Improved(char *key_string, char *cipher_text){
	//char return_me[strlen(key_string) + 1];
	char *return_me = (char *)malloc(sizeof(char) * (strlen(cipher_text) + 2));
	int i = 0;
	int j = 0;
	while(cipher_text[i] != '}'){
		char temp = cipher_text[i];
		if(temp == '{' || temp == '}' || temp == '_'){
			return_me[i] = temp;
			i++;
			continue;
		}
		if(isdigit(temp)){
			return_me[i] = temp;
			i++;
			continue;
		}
		return_me[i] = (((toupper(temp) - key_string[j % strlen(key_string)]) + 26) % 26) + 'A';
		printf("%c\n", return_me[i]);
		i++;
		j++;
	}
	printf("out of for loop\n");
	return_me[i] = '}';
	return_me[i+1] = '\0';
	printf("%c\n", cipher_text[i]);
	printf("%s\n", return_me);
	return return_me;
}

int main(){
	char str[] = "rgnoDVD{O0NU_WQ3_G1G3O3T3_A1AH3S_f85729e7}end";
	char key[] = "CYLAB";
	printf("%s\n", str);
	printf("%s\n", key);

	char *key_string = Generate_Key(key, strlen(str));
	printf("%s\n", key_string);
	//Generate_Plaintext(key_string, str);
	Generate_Plaintext_Improved(key, str);

}
