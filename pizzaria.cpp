// Pizzaria 1.1.0

// Grupo 04:
// Cesar Henrique;
// Daniel de Freitas;
// Davi Dias Campos;
// Guilherme Antonio;
// Marcos Vinicius;

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// Definição da função gotoxy para mapeamento da tela
void gotoxy(int col, int lin) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1});
}

int main()
{
	setlocale(LC_ALL, "pt-BR");
	
	// Definindo as variáveis //
	////////////////////////////
	
	// Valores de cada produto ou serviço
	float
		valorChopp         = 15.00, // R$
		valorPizza         = 55.00, // R$
		valorCobertura     = 10.00, // R$
		valorRefri         = 10.00, // R$
		valorAgua          =  8.00, // R$
		porcentagemGorjeta = 10.00; // %%
	
	// Quantidade de consumo e de pessoas
	int qtdChopp, qtdPizza, qtdCobertura, qtdRefri, qtdAgua, qtdPessoa;
	
	// Valores finais após os calculos
	float valorTotal, valorGorjeta, valorPagar, valorPessoa;
	
	// Exibindo a tela inicial //
	/////////////////////////////
	
	system("cls");
	gotoxy(11, 2);
	printf("<<  Pizzaria Five nights at Bianch  >> ");
	gotoxy(16, 4);
	printf("<<    Consumo da mesa    >> ");
	gotoxy(20, 6);
	printf("Chopps........: ");
	gotoxy(20, 7);
	printf("Pizzas Mistas.: ");
	gotoxy(20, 8);
	printf("Coberturas....: ");
	gotoxy(20, 9);
	printf("Refrigerante..: ");
	gotoxy(20, 10);
	printf("Agua..........: ");
	gotoxy(20, 12);
	printf("Pessoas na mesa: ");
	
	// Recebendo os dados //
	////////////////////////
	
	gotoxy(36, 6);
	fflush(stdin); scanf("%i", &qtdChopp);
	gotoxy(36, 7);
	fflush(stdin); scanf("%i", &qtdPizza);
	gotoxy(36, 8);
	fflush(stdin); scanf("%i", &qtdCobertura);
	gotoxy(36, 9);
	fflush(stdin); scanf("%i", &qtdRefri);
	gotoxy(36, 10);
	fflush(stdin); scanf("%i", &qtdAgua);
	gotoxy(37, 12);
	fflush(stdin); scanf("%i", &qtdPessoa);
	printf("\n");
	
	system("pause");
	
 	// Cálculos //
 	//////////////
 	
 	valorTotal =
		(qtdChopp * valorChopp) +
	 	(qtdPizza * valorPizza) +
	 	(qtdRefri * valorRefri) +
	 	(qtdAgua * valorAgua)  +
	 	(qtdCobertura * valorCobertura);
 	
 	valorGorjeta = valorTotal * porcentagemGorjeta / 100;
 	valorPagar = valorTotal + valorGorjeta;
 	valorPessoa = valorPagar / qtdPessoa;
 	
 	// Exibindo a tela final //
 	///////////////////////////
 	
 	system("cls");
	gotoxy(18, 2);
	printf(" <<  Pizzaria Five nights at Bianch  >> ");
	gotoxy(19, 4);
	printf("<<   Fechamento da Conta da Mesa    >>");
	gotoxy(19, 6);
	printf("Valor Total do Consumo....: R$ %.2f", valorTotal);
	gotoxy(19, 7);
	printf("%% da Gorjeta do Garcom....: %.2f %%", porcentagemGorjeta);
	gotoxy(19, 8);
	printf("Valor da Gorjeta..........: R$ %.2f", valorGorjeta);
	gotoxy(19, 10);
	printf("Valor Total a Pagar.......: R$ %.2f", valorPagar);
	gotoxy(19, 12);
	printf("Quantidade Pessoas na mesa: %i", qtdPessoa);
	gotoxy(19, 13);
	printf("Valor a Pagar por pessoa..: R$ %.2f", valorPessoa);
	printf("\n\n");
	
	system("pause");
}