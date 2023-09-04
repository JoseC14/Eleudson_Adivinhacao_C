//ALUNO : JOSÉ CARLOS PERERIRA VIEIRA
//SEGUNDO SEMESTRE DE CIÊNCIA DA COMPUTAÇÃO
// REFERENCIA QUE USEI PARA ABRIR O ARQUIVO DE ASCII ART: https://www.geeksforgeeks.org/c-program-print-contents-file/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>
int main(){
	setlocale(LC_ALL,"Portuguese");
	int chute, numeroGrande, seed, numero,num,pontuacao;
	int pontosErrados;

	char ch,c;
	int sair = 0;
    
	FILE *arquivo;

	arquivo = fopen("title.txt","r");
	//Se o arquivo de titulo nao for baixado ele irá printar uma tela padrao sem ascii art
	if(arquivo == NULL){
		printf("***********************\n");
		printf("* JOGO DA ADIVINHACAO *\n");
		printf("***********************\n");
	}else{
		c = fgetc(arquivo);
		while (c != EOF)
		{
			printf ("%c", c);
			c = fgetc(arquivo);
		}

		fclose(arquivo);		
	}

	while(!sair){
		pontuacao = 1000;
		//Gera um número aleatório
		int tentativas = 5;
		seed = time(0);
		srand(seed);
		numeroGrande = rand();
		numero       = numeroGrande % 100; // Números de 1 a 100;
		while(tentativas != 0){
			printf("\nChances restantes %d ", tentativas);
			printf("\nSeu chute: ");
			if(scanf("%d", &chute) == 0){
				printf("Tipo de dado inválido\n");
				while(c = getchar() != '\n');
				continue;
			}else{
				setbuf(stdin,NULL);
			}
			if(chute == 1234){//Senha que revela o numero secreto
				printf("Número secreto %d",numero);
				continue;
			}
            if(chute > 0  && chute < 100){

				if(chute == numero){
					printf("PARABÉNS. VOCÊ ACERTOU!!!\n");
					printf("Pontuacao: %d \n",pontuacao);
					break;
				}else{
					pontosErrados = round((numero-chute)/2.0);

					if(pontosErrados < 0 ){
						pontosErrados = abs(pontosErrados);
					}
					printf("ERROU!! \n");
                    if (tentativas == 1){
						break;
					}
					if(chute > numero){
						printf("Alto\n");
					}else{
						printf("Baixo\n");
					}
					tentativas -= 1;

					
				}
       
				pontuacao -= pontosErrados;
			
			
			}else{
				printf("Digite um número de 1 a 99");
				continue;
			}
		}
		
		chooseoption:
		printf("Deseja jogar novamente?(S/N): ");
		setbuf(stdin,NULL);
		ch  = getchar();
		getchar();
		
		
		if(ch == 'S' || ch == 's'){
			continue;
		}else if(ch == 'N' || ch == 'n'){
			break;
		}else{
			printf("Opção Inválida\n");
			goto chooseoption;
		}

	}

	arquivo = fopen("gameover.txt","r");
		//Se o arquivo de game over nao for baixado ele irá printar uma tela padrao sem ascii art
	if (arquivo == NULL){
		printf("***********************\n");
		printf("*      GAME OVER      *\n");
		printf("***********************\n");
	}else{
		c = fgetc(arquivo);
		while (c != EOF)
		{
			printf ("%c", c);
			c = fgetc(arquivo);
		}

		fclose(arquivo);		
	}

	
	
	return 0;
	
}
