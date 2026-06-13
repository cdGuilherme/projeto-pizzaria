// Pizzaria 5.0.2

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

// Definicao da funcao gotoxy para mapeamento da tela
void gotoxy(int col, int lin) {
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){col-1,lin-1});
}

// Definicao da funcao clreol para limpeza da linha
void clreol(int col, int lin) {
	int col1;
	if ((lin > 0 && lin < 25) && (col > 0 && col < 81))
		for (col1 = col; col1 <= 80; ++ col1) {
			gotoxy(col1,lin); puts(" ");
		}
}

struct ResumoMesa {
	float valorPagar;
	float totalChopp;
	float totalPizza;
	float totalCobertura;
	float totalRefri;
	float totalAgua;
	int qtdPessoa;
};

int main()
{
	setlocale(LC_ALL, "pt-BR");
	
	// Definindo as variaveis //
	////////////////////////////
	
	// Valores de cada produto ou servico
	const float
		precoChopp         = 15.00, // R$
		precoPizza         = 55.00, // R$
		precoCobertura     = 10.00, // R$
		precoRefri         =  8.00, // R$
		precoAgua          =  6.00, // R$
		taxaGorjeta 	   = 10.00, // %%
		taxaDesconto1 	   =  5.20, // %%
		taxaDesconto2 	   =  8.00, // %%
		taxaDescontoMaximo = 10.00; // %%
	
	// Limite de descontos
	const float
		limiteDesconto1 = 400.00, // R$
		limiteDesconto2 = 700.00; // R$
	
	// Quantidade de mesas
	const int qtdMesas = 10;
	
	// Quantidade de consumo e de pessoas
	int numMesa, qtdChopp, qtdPizza, qtdCobertura, qtdRefri, qtdAgua, qtdPessoa;
	
	// Variavel para controle de validacao
	bool validPizzaCobertura = false;
	
	// Valores finais apos os calculos por mesa
	float valorConsumo, valorGorjeta, valorConta, porcentagemDesconto, valorDesconto, valorPagar, valorPessoa, totalChopp, totalPizza, totalCobertura, totalRefri, totalAgua;
	
	// Quantidade de mesas atendidas
	int mesasAtendidas = 0;
	
	// Vetor de mesas utilizando struct do C++
	ResumoMesa resumoMesas[qtdMesas] = {};
	
	// Valores finais para tela de saida 2
	float totalFaturado = 0, mediaMesas = 0;
	
	
	
	// Inicio e loop do programa //
	///////////////////////////////
	
	do {
		// Exibindo a tela inicial //
		/////////////////////////////
		
		system("cls");
		
		gotoxy(10, 2);
		printf("<<  Pizzaria Five nights at Bianchi  >>");
		
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
			// Receber o numero da mesa
			clreol(37, 4);
			gotoxy(16, 4);
			printf("<<  Consumo da mesa:     >>");

			gotoxy(37, 4);
			fflush(stdin);
			scanf("%i", &numMesa);
			
			// Mesas numeradas de 1 a 10
			gotoxy(8, 23);
			if (numMesa < 0 || numMesa > qtdMesas)
				printf("Número da Mesa deve estar entre 1 e %i, inclusive.", qtdMesas);
			else
				clreol(8, 23);
		} while (numMesa < 0 || numMesa > qtdMesas);

		// Validacao da mesa
		// Sair do programa se informado mesa 0
		if (numMesa == 0) {
			break;
		}
		
		// Receber a quantidade de chopps
		gotoxy(36, 6);
		fflush(stdin);
		scanf("%i", &qtdChopp);
		
		do {
			// Reinicializacao da variavel
			validPizzaCobertura = false;
			
			// Limpa a entrada do usuario de iteracao passada
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
			
			// Validacao de pizzas e coberturas
			// Nao pediu pizzas, porem pediu coberturas
			if (qtdPizza == 0 && qtdCobertura >= 1) {
				clreol(8, 23);
				gotoxy(8, 23);
				printf("Erro: Informe a quantidade de Pizzas");
			// Nao pediu coberturas, porem pediu pizzas
			} else if (qtdCobertura == 0 && qtdPizza >= 1) {
				clreol(8, 23);
				gotoxy(8, 23);
				printf("Erro: Informe a quantidade de Cobertura");
			// Validacao sucesso
			} else {
				clreol(8, 23);
				validPizzaCobertura = true;
			}
		} while (!validPizzaCobertura);
		
		// Receber a quantidade de refri
		gotoxy(36, 9);
		fflush(stdin);
		scanf("%i", &qtdRefri);
		
		// Receber a quantidade de agua
		gotoxy(36, 10);
		fflush(stdin);
		scanf("%i", &qtdAgua);
		
		do {
			// Receber a quantidade de pessoas
			clreol(37, 12);
			gotoxy(37, 12);
			fflush(stdin);
			scanf("%i", &qtdPessoa);
			
			// Validar a quantidade de pessoas
			gotoxy(8, 23);
			if (qtdPessoa == 0)
				printf("Erro: Obrigatório informar o número de Pessoas na mesa");
			else
				clreol(8, 23);
		} while (qtdPessoa == 0);
		
		
		
	 	// Calculos //
	 	//////////////
	 	
		totalChopp = (qtdChopp * precoChopp);
		totalPizza = (qtdPizza * precoPizza);
		totalRefri = (qtdRefri * precoRefri);
		totalAgua = (qtdAgua * precoAgua);
		totalCobertura = (qtdCobertura * precoCobertura);
		
		valorConsumo = totalChopp + totalPizza + totalRefri + totalAgua + totalCobertura;
	 	
	 	valorGorjeta = valorConsumo * taxaGorjeta / 100;
	 	valorConta = valorConsumo + valorGorjeta;
	 	
	 	if (valorConta <= limiteDesconto1) {
	 		porcentagemDesconto = taxaDesconto1;
		} else if (valorConta <= limiteDesconto2) {
			porcentagemDesconto = taxaDesconto2;
		} else {
			porcentagemDesconto = taxaDescontoMaximo;
		}
		
		valorDesconto = valorConta * porcentagemDesconto / 100;
		valorPagar = valorConta - valorDesconto;
		valorPessoa = valorPagar / qtdPessoa;
		
		// Acumulando o valor total e tudo que foi consumido
		resumoMesas[numMesa - 1].valorPagar = valorPagar;
		resumoMesas[numMesa - 1].totalChopp = totalChopp;
		resumoMesas[numMesa - 1].totalPizza = totalPizza;
		resumoMesas[numMesa - 1].totalRefri = totalRefri;
		resumoMesas[numMesa - 1].totalAgua = totalAgua;
		resumoMesas[numMesa - 1].totalCobertura = totalCobertura;
		resumoMesas[numMesa - 1].qtdPessoa = qtdPessoa;
	 	
	 	
	 	
	 	// Exibindo a tela de saida 1 //
	 	////////////////////////////////
	 	
	 	system("cls");
	 	
		gotoxy(17, 2);
		printf(" <<  Pizzaria Five nights at Bianchi   >>");
		
		gotoxy(19, 4);
		printf("<<  Fechamento da Conta da Mesa:    >>");
		
		gotoxy(19, 6);
		printf("Valor Total do Consumo....:");
		gotoxy(19, 7);
		printf("%% da Gorjeta do Garcom....:");
		gotoxy(19, 8);
		printf("Valor da Gorjeta..........:");
		gotoxy(19, 10);
		printf("Valor Total a Pagar.......:");
		gotoxy(19, 11);
		printf("%% do desconto.............:");
		gotoxy(19, 12);
		printf("Valor do desconto.........:");
		
		gotoxy(19, 14);
		printf("Valor Total com Desconto..:");
		
		gotoxy(19, 16);
		printf("Quantidade Pessoas na mesa:");
		gotoxy(19, 17);
		printf("Valor a Pagar por pessoa..:");
		
		
		
		// Saida de dados 1 //
		//////////////////////
		
		gotoxy(52, 4);
		printf("%i", numMesa);
	
		gotoxy(47,6);
		printf("R$ %7.2f", valorConsumo);
		gotoxy(47,7);
		printf("%.2f %%", taxaGorjeta);
		gotoxy(47,8);
		printf("R$ %7.2f", valorGorjeta);
		gotoxy(47,10);
		printf("R$ %7.2f", valorConta);
		gotoxy(47,11);
		printf("%.2f %%", porcentagemDesconto);
		gotoxy(47,12);
		printf("R$ %7.2f", valorDesconto);
		
		gotoxy(47,14);
		printf("R$ %7.2f", valorPagar);
		
		gotoxy(47,16);
		printf("%i", qtdPessoa);
		gotoxy(47,17);
		printf("R$ %7.2f", valorPessoa);
		
		printf("\n\n");
		
		system("pause");
		
		mesasAtendidas++;
	
	} while (numMesa != 0); // Se informar 0 na mesa, exibe a tela de saida 2
	
	// Exibindo a tela de saida 2 //
	////////////////////////////////
	
	system("cls");
	 	
	gotoxy(12, 2);
	printf("<<  Pizzaria Five nights at Bianchi  >>");
	
	gotoxy(15, 3);
	printf("<<  Fechamento do Faturamento  >>");
	
	// Fauramento no dia

	if (mesasAtendidas != 0) {
		// Saida de dados 2 //
		//////////////////////
		
		gotoxy(12, 5);
		puts("<<<           Valor Total Consumido               >>>");
		
		gotoxy(5, 5);
		puts("Numero");
		gotoxy(6, 6);
		puts("Mesa");
		
		gotoxy(13, 6);
		puts("Pizzas");
		
		gotoxy(23, 6);
		puts("Coberturas");
		
		gotoxy(35, 6);
		puts("Chopps");
		
		gotoxy(47, 6);
		puts("Refri");
		
		gotoxy(58, 6);
		puts("�gua");
		
		gotoxy(68, 5);
		puts("Total");
		gotoxy(67, 6);
		puts("Pessoas");
		
		// Exibe o valor individual de cada mesa
		int linha = 0; // Variavel auxiliar para nao pular linhas ao exibir mesas
		for (int i = 0; i < qtdMesas; i++) {
			if (resumoMesas[i].valorPagar != 0) {
				int y = 8 + linha;
				// Numero mesa
				gotoxy(7, y);
				printf("%2.i", i + 1);
				
				// Pizzas
				gotoxy(12, y);
				printf("%9.2f", resumoMesas[i].totalPizza);
				
				// Coberturas
				gotoxy(23, y);
				printf("%9.2f", resumoMesas[i].totalCobertura);
				
				// Chopps
				gotoxy(34, y);
				printf("%9.2f", resumoMesas[i].totalChopp);
				
				// Refri
				gotoxy(45, y);
				printf("%9.2f", resumoMesas[i].totalRefri);
				
				// Agua
				gotoxy(56, y);
				printf("%9.2f", resumoMesas[i].totalAgua);
				
				// Total Pessoas
				gotoxy(69, y);
				printf("%3.i", resumoMesas[i].qtdPessoa);
				
				// Soma do valor total de todas as mesas
				totalFaturado += resumoMesas[i].valorPagar;
				
				linha++;
			}
		}
		
		gotoxy(5, 19);
		printf("Total do Faturamento do dia.. R$");
		gotoxy(5, 21);
		printf("Média do Faturamento por Mesa R$");
		
		// Calculo da media faturada por mesas
		mediaMesas = totalFaturado / mesasAtendidas;
		
		// Print do total e das medias das mesas
		gotoxy(38,19);
		printf("%.2f", totalFaturado);
		
		gotoxy(39,21);
		printf("%.2f", mediaMesas);
		
	} else {
		gotoxy(2, 23);
		printf("Atenção! NÃO houve Faturamento neste dia!");
	}
	
	return 0;
}
