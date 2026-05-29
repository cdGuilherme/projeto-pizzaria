// Pizzaria 1.4.0

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

// Definição da função clreol para limpeza da linha
void clreol(int col, int lin) {
	int col1;
	if ((lin > 0 && lin < 25) && (col > 0 && col < 81))
		for (col1 = col; col1 <= 80; ++ col1) {
			gotoxy(col1,lin); puts(" ");
		}
}

int main()
{
	setlocale(LC_ALL, "pt-BR");
	
	// Definindo as variáveis //
	////////////////////////////
	
	// Valores de cada produto ou serviço
	const float
		valorChopp         = 15.00, // R$
		valorPizza         = 55.00, // R$
		valorCobertura     = 10.00, // R$
		valorRefri         =  8.00, // R$
		valorAgua          =  6.00, // R$
		porcentagemGorjeta = 10.00, // %%
		porcDescontoAte400 =  5.20, // %%
		porcDescontoAte700 =  8.00, // %%
		porcDescontoMaximo = 10.00; // %%
	
	// Quantidade de consumo e de pessoas
	int numMesa, qtdChopp, qtdPizza, qtdCobertura, qtdRefri, qtdAgua, qtdPessoa;
	
	// Valores finais após os cálculos
	float valorConsumo, valorGorjeta, valorConta, porcentagemDesconto, valorDesconto, valorPagar, valorPessoa;
	
	// Variável para controle de validação
	bool validPizzaCobertura = false;
	
	
	
	// Início e loop do programa //
	///////////////////////////////
	
	do {
		// Exibindo a tela inicial //
		/////////////////////////////
		
		system("cls");
		
		gotoxy(10, 2);
		printf("<<  Pizzaria Five nights at Bianchi  >>");
		
		gotoxy(11, 4);
		printf("<< Consumo da mesa:     [0 = Sair] >>");
		
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
		
		
		
		// Recebendo e validando os dados //
		////////////////////////////////////
		
		do {
			// Receber o número da mesa
			gotoxy(31, 4);
			puts("   ");
			gotoxy(31, 4);
			fflush(stdin);
			scanf("%i", &numMesa);
			
			// Mesas numeradas de 1 a 10
			gotoxy(8, 23);
			if (numMesa < 0 || numMesa > 10)
				printf("Número da Mesa deve estar entre 1 e 10, inclusive.");
			else
				clreol(8, 23);
		} while (numMesa < 0 || numMesa > 10);
		
		// Validação da mesa
		// Sair do programa se informado mesa 0
		if (numMesa == 0) {
			break;
		}
		
		// Receber a quantidade de chopps
		gotoxy(36, 6);
		fflush(stdin);
		scanf("%i", &qtdChopp);
		
		do {
			// Reinicialização da variável
			validPizzaCobertura = false;
			
			// Limpa a entrada do usuário de iteração passada
			clreol(36, 7);
			clreol(36, 8);
			
			// Receber a quantidade de pizzas
			gotoxy(36, 7);
			fflush(stdin);
			scanf("%i", &qtdPizza);
			
			// Receber a quantidade de cobertura
			gotoxy(36, 8);
			fflush(stdin);
			scanf("%i", &qtdCobertura);
			
			// Validação de pizzas e coberturas
			// Não pediu pizzas, porém pediu coberturas
			if (qtdPizza == 0 && qtdCobertura >= 1) {
				clreol(8, 23);
				gotoxy(8, 23);
				printf("Erro: Informe a quantidade de Pizzas");
			// Não pediu coberturas, porém pediu pizzas
			} else if (qtdCobertura == 0 && qtdPizza >= 1) {
				clreol(8, 23);
				gotoxy(8, 23);
				printf("Erro: Informe a quantidade de Cobertura");
			// Validação sucesso
			} else {
				clreol(8, 23);
				validPizzaCobertura = true;
			}
		} while (!validPizzaCobertura);
		
		// Receber a quantidade de refri
		gotoxy(36, 9);
		fflush(stdin);
		scanf("%i", &qtdRefri);
		
		// Receber a quantidade de água
		gotoxy(36, 10);
		fflush(stdin);
		scanf("%i", &qtdAgua);
		
		do {
			// Receber a quantidade de pessoas
			clreol(36, 12);
			gotoxy(36, 12);
			fflush(stdin);
			scanf("%i", &qtdPessoa);
			
			// Validar a quantidade de pessoas
			gotoxy(8, 23);
			if (qtdPessoa == 0)
				printf("Erro: Obrigatório informar o número de Pessoas na mesa");
			else
				clreol(8, 23);
		} while (qtdPessoa == 0);
		
		
		
	 	// Cálculos //
	 	//////////////
	 	
	 	valorConsumo =
			(qtdChopp * valorChopp) +
			(qtdPizza * valorPizza) +
			(qtdRefri * valorRefri) +
			(qtdAgua * valorAgua) +
			(qtdCobertura * valorCobertura);
	 	
	 	valorGorjeta = valorConsumo * porcentagemGorjeta / 100;
	 	valorConta = valorConsumo + valorGorjeta;
	 	
	 	if (valorConta <= 400) {
	 		porcentagemDesconto = porcDescontoAte400;
		} else if (valorConta <= 700) {
			porcentagemDesconto = porcDescontoAte700;
		} else {
			porcentagemDesconto = porcDescontoMaximo;
		}
		
		valorDesconto = valorConta * porcentagemDesconto / 100;
		valorPagar = valorConta - valorDesconto;
		valorPessoa = valorPagar / qtdPessoa;
	 	
	 	
	 	
	 	// Exibindo a tela de saida 1 //
	 	////////////////////////////////
	 	
	 	system("cls");
	 	
		gotoxy(17, 2);
		printf(" <<  Pizzaria Five nights at Bianchi  >>");
		
		gotoxy(17, 4);
		printf("<<   Fechamento da Conta da Mesa:      >>");
		
		gotoxy(19, 6);
		printf("Valor Total do Consumo....:");
		gotoxy(19, 7);
		printf("%% da Gorjeta do Garcom....:");
		gotoxy(19, 8);
		printf("Valor da Gorjeta..........:");
		gotoxy(19, 9);
		printf("Valor Total da conta......:");
		gotoxy(19, 10);
		printf("%% do desconto.............:");
		gotoxy(19, 11);
		printf("Valor do Desconto.........:");
		
		gotoxy(19, 13);
		printf("Valor Total a Pagar.......:");
		
		gotoxy(19, 15);
		printf("Quantidade Pessoas na mesa:");
		gotoxy(19, 16);
		printf("Valor a Pagar por pessoa..:");
		
		
		
		// Saída de dados 1 //
		//////////////////////
		
		gotoxy(51, 4);
		printf("%i", numMesa);
	
		gotoxy(47,6);
		printf("R$ %.2f", valorConsumo);
		gotoxy(47,7);
		printf("%.2f %%", porcentagemGorjeta);
		gotoxy(47,8);
		printf("R$ %.2f", valorGorjeta);
		gotoxy(47,9);
		printf("R$ %.2f", valorConta);
		gotoxy(47,10);
		printf("%.2f %%", porcentagemDesconto);
		gotoxy(47,11);
		printf("R$ %.2f", valorDesconto);
		
		gotoxy(47,13);
		printf("R$ %.2f", valorPagar);
		
		gotoxy(47,15);
		printf("%i", qtdPessoa);
		gotoxy(47,16);
		printf("R$ %.2f", valorPessoa);
		
		printf("\n\n");
		
		system("pause");
	
	} while (numMesa != 0); // Se informar 0 na mesa, exibe a tela de saida 2
	
	// Exibindo a tela de saída 2 //
	////////////////////////////////
	
	system("cls");
	 	
	gotoxy(17, 2);
	printf(" <<  Pizzaria Five nights at Bianchi  >>");
	
	// ...
	
	// Saída de dados 2 //
	//////////////////////
	
	// ...
	
	return 0;
}
