#include <locale.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <windows.h>

//cores
void apresentar(char poltronas[], int qtdePoltronas);
void reservar(char poltronas[], char letra, int numero);
void confirmar(char poltronas[], char letra, int numero);
void cancelar(char poltronas[], char letra, int numero);
void leValidaFilme (char *nomeFilme);
int leValidaCadeira ();
float leValidaValor();
int leValidaIdade();
char leValidaCategoria();
float calculaIngresso (float valorIngresso);

main() {
	setlocale (LC_ALL, "Portuguese");
	char poltronas[500];
	int i, k=1;
	char j='A';

	char nomeFilme[100], opc, opc2, opc3, categoria[500], fileira, fileiraReserva[500], opc4, opc5;
	int qtdePoltronas, idade[500], cadeira, idReserva[500], indiceReserva, contReserva, quantReserva, indPesquisa, codReserva, cadeiraReserva[500], contCadeirasD, contCadeirasR, contCadeirasC;
	float valorIngresso, novoIngresso, totalIngresso;
	int indFinal;

	//Entrada dos dados do filme

	printf ("Bem-vindo!\nInsira os dados respectivos a sala: \n");
	leValidaFilme (nomeFilme);
	qtdePoltronas = leValidaCadeira();
	valorIngresso = leValidaValor();
	do {
		printf ("Pressione 's' para efetuar uma reserva ou 'm' para ver o mapa da sala: ");
		opc = getche();
		opc=toupper(opc);
		printf ("\n");
		system ("cls");
		for(i=0; i<qtdePoltronas; i++) {
			poltronas[i]='D';
		}
		if(opc=='M') {
			printf ("\n\n\t\t\t\t\t\t\t\t\t\t\t\tMapa da sala: \n\n");
			apresentar(poltronas, qtdePoltronas);
			printf ("\n\n");
			printf ("Pressione 'b' para voltar: ");
			opc2=getche();
			opc2=toupper(opc2);
			printf ("\n");
		}
	} while (opc2=='B'&& opc!='S');

	totalIngresso = 0;
	indiceReserva = 0;
	contReserva=0;
	do {
		if (opc=='S') {
			contReserva=contReserva+1;
			idReserva[indiceReserva]=contReserva;
			printf ("Insira os dados do comprador: \n");
			idade[indiceReserva] = leValidaIdade();
			if (idade[indiceReserva]>12) {
				categoria[indiceReserva] = leValidaCategoria();
			} else {
				categoria[indiceReserva] = 'C';
			}
			printf ("\n\n\t\t\t\t\t\t\t\t\t\t\t\tSeleção de lugar: \n\n");
			apresentar(poltronas, qtdePoltronas);
			printf ("\n\n");
			printf ("Digite a letra da fileira: ");
			fileira = getche();
			fileira = toupper (fileira);
			printf ("\nDigite o número da cadeira: ");
			scanf ("%i", &cadeira);
			fileiraReserva[indiceReserva]=fileira;
			cadeiraReserva[indiceReserva]=cadeira;
			//system("pause");
			system("cls");
			printf ("\n\n\t\t\t\t\t\t\t\t\t\t\t\tSeleção de lugar: \n\n");
			reservar(poltronas, fileira, cadeira);
			apresentar(poltronas, qtdePoltronas);
			printf ("\n\n\t\t\t\t\t\t\t\t\t\t\tReserva efetuada com sucesso!\n\n");
			if (categoria[indiceReserva] == 'E' || categoria[indiceReserva] == 'P' || categoria[indiceReserva] == 'I' || categoria[indiceReserva] == 'D' || categoria[indiceReserva] == 'C') {
				novoIngresso =  calculaIngresso (valorIngresso);
				totalIngresso = totalIngresso + novoIngresso;
				printf ("VALOR DO INGRESSO: R$ %.2f.", novoIngresso);
				printf ("\nO CÓDIGO DA SUA RESERVA É: %i", idReserva[indiceReserva]);
			} else {
				totalIngresso = totalIngresso + valorIngresso;
				printf ("VALOR DO INGRESSO: R$ %.2f.", novoIngresso);
				printf ("\nO CÓDIGO DA SUA RESERVA É: %i", idReserva[indiceReserva]);
			}
			printf ("\nPressione 's' para nova reserva ou qualquer outra tecla para sair: ");
			opc3=getche();
			opc3=toupper(opc3);
			system("cls");
		}
		indiceReserva=indiceReserva+1;
	} while (opc3=='S' && indiceReserva<qtdePoltronas);
	quantReserva=indiceReserva;
	do {
		printf ("Digite o código da sua reserva: ");
		scanf ("%i", &codReserva);
		for (indPesquisa=0; indPesquisa<quantReserva; indPesquisa++) {
			if (codReserva==idReserva[indPesquisa]) {
				printf ("\n\n\t\t\t\t\t\t\t\t\t\t\t\tDados da reserva: \n\n");
				printf ("IDADE: %i\n", idade[indPesquisa]);
				printf ("CATEGORIA: %c", categoria[indPesquisa]);
				if (categoria[indPesquisa=='E']) {
					printf (" - ESTUDANTE");
				} else if (categoria[indPesquisa=='P']) {
					printf (" - PESSOAS COM DEFICIÊNCIA");
				} else if (categoria[indPesquisa=='I']) {
					printf (" - IDOSO");
				} else if (categoria[indPesquisa=='D']) {
					printf (" - DOADOR DE SANGUE");
				} else if (categoria[indPesquisa=='C']) {
					printf (" - CRIANÇA");
				} else if (categoria[indPesquisa=='N']) {
					printf (" - NENHUMA");
				}
				printf ("\nFILEIRA: %c\n", fileiraReserva[indPesquisa]);
				printf("POLTRONA: %i\n", cadeiraReserva[indPesquisa]);
				if (categoria[indPesquisa] == 'E' || categoria[indPesquisa] == 'P' || categoria[indPesquisa] == 'I' || categoria[indPesquisa] == 'D' || categoria[indPesquisa] == 'C') {
					novoIngresso =  calculaIngresso (valorIngresso);
					printf ("VALOR DO INGRESSO: R$ %.2f.", novoIngresso);
				} else {
					printf ("VALOR DO INGRESSO: R$ %.2f.", valorIngresso);
				}
				printf ("\nPressione 'c' para confirmar a compra ou 'x' para cancelar a reserva: ");
				opc4=getche();
				opc4=toupper(opc4);
				printf ("\n\n");
				if (opc4=='C') {
					fileira=fileiraReserva[indPesquisa];
					cadeira=cadeiraReserva[indPesquisa];
					confirmar(poltronas, fileira, cadeira);
					printf ("\n\n\t\t\t\t\t\t\t\t\t\t\tCOMPRA CONFIRMADA COM SUCESSO!\n\n");
					apresentar(poltronas, qtdePoltronas);
					printf ("\n");
				} else if (opc4=='X') {
					fileira=fileiraReserva[indPesquisa];
					cadeira=cadeiraReserva[indPesquisa];
					cancelar(poltronas, fileira, cadeira);
					printf ("\n\n\t\t\t\t\t\t\t\t\t\t\tRESERVA CONFIRMADA COM SUCESSO!\n\n");
					apresentar(poltronas, qtdePoltronas);
					printf ("\n");
				}
			} else {
				printf ("Código de reserva inexistente!\n");
			}
		}
		printf ("Pressione 's' para pesquisar novo código de reserva ou 'x' para encerrar: ");
		opc5=getche();
		opc5=toupper(opc5);
		printf ("\n");
		system("cls");
	} while (opc5=='S');

	contCadeirasD = 0;
	contCadeirasR = 0;
	contCadeirasC = 0;
	for(indFinal=0; indFinal<qtdePoltronas; indFinal++) {
		if (poltronas[indFinal]=='D') {
			contCadeirasD = contCadeirasD+1;
		} else if (poltronas[indFinal]=='R') {
			contCadeirasR = contCadeirasR+1;
		} else if (poltronas[indFinal]=='C') {
			contCadeirasC = contCadeirasC+1;
		}
	}
	printf ("DADOS DE VENDA FINAIS: \n");
	printf ("QUANTIDADE DE CADEIRAS DISPONÍVEIS: %i\n", contCadeirasD);
	printf ("QUANTIDADE DE CADEIRAS RESERVADAS: %i\n", contCadeirasR);
	printf ("QUANTIDADE DE CADEIRAS CONFIRMADAS: %i\n", contCadeirasC);
	printf ("VALOR TOTAL DE INGRESSOS VENDIDOS: R$ %.2f", totalIngresso);
}
/*system("pause");
	system("cls");
	*/

void apresentar(char poltronas[], int qtdePoltronas) {
	int i, k=1;
	char j='A';
	for(i=0; i<qtdePoltronas; i++) {
		if (poltronas[i]=='D') {
			SetColor(10,0);
			if(i%10==0)
				printf("\t\t\t\t\t\t\t%c  ", j);
			if(i==10) {
				printf(" %i-[ %c ] ", k++, poltronas[i]);
			} else {
				printf(" %i-[ %c ] ", k++, poltronas[i]);
			}
			if(k==6)
				printf("    ");
			if(k==11) {
				printf("  %c", j);
				printf("\n");
				j++;
				k=1;
			}
		} else if (poltronas[i]=='R') {
			SetColor(12,0);
			if(i%10==0)
				printf("\t\t\t\t\t\t\t%c  ", j);
			if(i==10) {
				printf(" %i-[ %c ] ", k++, poltronas[i]);
			} else {
				printf(" %i-[ %c ] ", k++, poltronas[i]);
			}
			if(k==6)
				printf("    ");
			if(k==11) {
				printf("  %c", j);
				printf("\n");
				j++;
				k=1;
			}
		} else 	if (poltronas[i]=='C') {
			SetColor(9,0);
			if(i%10==0)
				printf("\t\t\t\t\t\t\t%c  ", j);
			if(i==10) {
				printf(" %i-[ %c ] ", k++, poltronas[i]);
			} else {
				printf(" %i-[ %c ] ", k++, poltronas[i]);
			}
			if(k==6)
				printf("    ");
			if(k==11) {
				printf("  %c", j);
				printf("\n");
				j++;
				k=1;
			}
		}
	}
	SetColor(7,0);
}

void cancelar(char poltronas[], char letra, int numero) {
	int i, k=1;
	char j='A';
	for(i=0; i<200; i++) {
		if(letra==j && numero==k)
			poltronas[i]='D';
		k++;
		if(k==11) {
			j++;
			k=1;
		}
	}
}

void reservar(char poltronas[], char letra, int numero) {
	int i, k=1;
	char j='A';
	for(i=0; i<200; i++) {
		if(letra==j && numero==k)
			poltronas[i]='R';
		k++;
		if(k==11) {
			j++;
			k=1;
		}
	}
}

void confirmar(char poltronas[], char letra, int numero) {
	int i, k=1;
	char j='A';
	for(i=0; i<200; i++) {
		if(letra==j && numero==k)
			poltronas[i]='C';
		k++;
		if(k==11) {
			j++;
			k=1;
		}
	}
}

void leValidaFilme (char *nomeFilme) {
	do {
		printf ("Digite o nome do filme: ");
		gets (nomeFilme);
		if (strcmp(nomeFilme, "")==0) {
			printf ("Nome do filme não pode ser vázio!");
		}
	} while (strcmp(nomeFilme, "")==0);
}

int leValidaCadeira () {
	int qtdePoltronas;
	do {
		printf ("Digite a quantidade de poltronas: ");
		scanf ("%i", &qtdePoltronas);
		if (qtdePoltronas<100 || qtdePoltronas>499) {
			printf ("Quantidade de poltronas inválida!\n");
		}
	} while (qtdePoltronas<100 || qtdePoltronas>499);
	return qtdePoltronas;
}

int leValidaIdade() {
	int idade;
	do {
		printf ("Digite a sua idade: ");
		scanf ("%i", &idade);
		if (idade<0) {
			printf ("Idade inválida!");
		}
	} while (idade<0);
}

float leValidaValor() {
	float valorIngresso;
	do {
		printf ("Digite o valor do ingresso: ");
		scanf ("%f", &valorIngresso);
		if (valorIngresso<0) {
			printf ("Valor do ingresso inválido!");
		}
	} while (valorIngresso<0);
	return valorIngresso;
}

char leValidaCategoria() {
	char categoria;
	do {
		printf ("E - Estudantes\nP - Pessoas com deficiência\nI - Idosos\nD - Doadores de sangue\nN - Nenhuma\n");
		printf ("Digite a sua categoria: ");
		categoria = getche();
		if (categoria == 'E' || categoria == 'e')
			categoria = 'E';
		else if (categoria == 'P' || categoria == 'p')
			categoria = 'P';
		else if (categoria == 'I' || categoria == 'i')
			categoria = 'I';
		else if (categoria == 'D' || categoria == 'd')
			categoria = 'D';
		else if (categoria == 'N' || categoria == 'n')
			categoria = 'N';
		else if (categoria != 'E' && categoria != 'P' && categoria != 'I' && categoria != 'D' && categoria != 'N')
			printf ("\nCategoria Inexistente!\n");
	} while (categoria != 'E' && categoria != 'P' && categoria != 'I' && categoria != 'D' && categoria != 'N');
	return categoria;
}

float calculaIngresso (float valorIngresso) {
	float novoIngresso;
	novoIngresso = valorIngresso/2;
	return novoIngresso;
}

void SetColor(int ForgC, int BackC) {
	// cores default SetColor(7,0)
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD count;

	SetConsoleTextAttribute(hStdOut, wColor);
	/*Name         | Value
	         |
	Black        |   0
	Blue         |   1
	Green        |   2
	Cyan         |   3
	Red          |   4
	Magenta      |   5
	Brown        |   6
	Light Gray   |   7
	Dark Gray    |   8
	Light Blue   |   9
	Light Green  |   10
	Light Cyan   |   11
	Light Red    |   12
	Light Magenta|   13
	Yellow       |   14
	White        |   15
	*/
}



