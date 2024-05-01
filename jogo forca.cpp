#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h> 

char palavraSecretaManual[50], palavraJogo[50];

void forca(int erro) {
  if (erro == 0) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } else if (erro == 1) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } else if (erro == 2) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|          |");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } else if (erro == 3) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|         -|");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } else if (erro == 4) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|         -|-");
    printf("\n|");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } else if (erro == 5) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|         -|-");
    printf("\n|         /");
    printf("\n|");
    printf("\n|");
    printf("\n-");
  } else if (erro == 6) {
    printf("\n------------");
    printf("\n|          |");
    printf("\n|          0");
    printf("\n|         -|-");
    printf("\n|         / \\");
    printf("\n|");
    printf("\n|      You Died!");
    printf("\n-");
  }
}

void escolhaPalavraAleatoria(){
	char  palavra [0][9], palavraAleatoria[30];
	int qtd;
	
	strcpy(palavra[0], "BRASIL");
	strcpy(palavra[1], "CHILE");
	strcpy(palavra[2], "URUGUAI");
	strcpy(palavra[3], "PARAGUAI");
	strcpy(palavra[4], "IRLANDA");
	strcpy(palavra[5], "ALEMANHA");
	strcpy(palavra[6], "CROACIA");
	strcpy(palavra[7], "ARGENTINA");
	strcpy(palavra[8], "ITALIA");
	strcpy(palavra[9], "EUA");
	
	srand(time(0));
	
	qtd = rand() % 9;
	
	palavra[qtd][strlen(palavra[qtd])];
	strcpy(palavraAleatoria, palavra[qtd]);

	
    
  	for (int i = 0; i < strlen(palavraAleatoria); i++) {
    palavraAleatoria[i] = '_';
  	}
}

void escrevaPalavraSecreta(char palavraManual[50]){
	
  	printf("Jogador 1 informe a palavra secreta: ");
  	fgets(palavraSecretaManual, 30, stdin);   

	
  	printf("A palavra secreta é: %s", palavraSecretaManual);
  	printf("\nA palavra tem %lu caracteres", strlen(palavraSecretaManual) - 1);

	
	palavraSecretaManual[strlen(palavraSecretaManual) - 1] = '\0';
	strcpy(palavraJogo, palavraSecretaManual);

	
  	for (int i = 0; i < strlen(palavraJogo); i++) {
    palavraJogo[i] = '_';
  }
 	 
  
}

void jogo(){


  int erros = 0;
  while (1) {
    system("cls");
	
    forca(erros);
    
    printf("\nAdivinhe: ");
   
    for (int i = 0; i < strlen(palavraJogo); i++) {
      printf(" %c", palavraJogo[i]);
    }
   
    printf("\nLetra: ");
    char letra;
    scanf("%c", &letra);
    
    fflush(stdin);
   
    int seraQueErrou = 1; 
    for (int i = 0; i < strlen(palavraJogo); i++) {
      if (letra == palavraSecretaManual[i]) {
        palavraJogo[i] = letra;
        seraQueErrou = 0;
        
      }
    }
    if (seraQueErrou == 1) {
      erros++;
    }
    if(strcmp(palavraJogo, palavraSecretaManual) == 0){
    	system("cls");
    	printf("\nA palavra eh: %s", palavraSecretaManual);
    	printf("\nVoce venceu!!!");
    	break;
	}
    
    if (erros == 6) {
     
      forca(erros);
      break;
    }
  }
}


int main(void) {
 	
 	escrevaPalavraSecreta();
 	system("cls");
	jogo(); 
}
