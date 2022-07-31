#include <stdio.h>
#include <stdlib.h>
#include "charFila.h"

int isNumber(char c){
	return c>='0' && c<='9';
}

int main(int argc, char *argv[]){
	if(argc<2){
		printf("Digite o nome do txt apos o executavel\n");
		exit(1);
	}
	FILE *arq = fopen(argv[1], "r");
	FILE *out = fopen("out.txt", "w");
	if(arq==NULL){
		printf("Impossivel ler o arquivo(cheque a grafia)\n");
		exit(1);
	}
	char c;
	Fila *f = criaFila();
	Pilha *num = criaPilha();
	while(fscanf(arq, "%c", &c)!=EOF){
		if(c=='\n'){
			while(!vazia(f)){
				c = retira(f);
				if(isNumber(c))push(c, num);
				else{
					if(!vazia(num)){
						int n = pilha2Int(num);
						libera(num->top);
						num->top=NULL;
						for(int i=0; i<n;i++) fprintf(out, "1");
					}
					fprintf(out, "%c", c);
				}
			}
			if(!vazia(num)){
				int n = pilha2Int(num);
				libera(num->top);
				num->top=NULL;
				for(int i=0; i<n;i++) fprintf(out, "1");
			}
			fprintf(out, "\n");
		}
		else insere(c, f);
	}
	while(!vazia(f)){
		c = retira(f);
		if(isNumber(c))push(c, num);
		else{
			fprintf(out, "%c", c);
			if(!vazia(num)){
				int n = pilha2Int(num);
				libera(num->top);
				num->top=NULL;
				for(int i=0; i<n;i++) fprintf(out, "1");
			}
		}
	}
	if(!vazia(num)){
		int n = pilha2Int(num);
		libera(num->top);
		num->top=NULL;
		for(int i=0; i<n;i++) fprintf(out, "1");
	}
	fprintf(out, "\n");
	libera(f);
	libera(num);
	fclose(out);
	fclose(arq);
	return 0;
}
