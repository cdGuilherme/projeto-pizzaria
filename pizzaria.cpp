
// Nota: 9,0

// Pizzaria 1.4.3

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
	
	// Quantidade de mesas
	const int qtdMesas = 10;
	
	// Quantas mesas foram atendidas
	int mesasAtendidas = 0;
	
	// Vetor acumulando o valor total pago de cada mesa
	float acumuladoMesas[qtdMesas] = {}, totalFaturado = 0, mediaMesas = 0;
	
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
		
		gotoxy(16, 4);
		printf("<<  Consumo da mesa:     >>");
		
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
			gotoxy(37, 4);
			
// Aten��o! executar o procedimento: clreol  para limpar uma linha			
			
			puts("    ");
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

// Aten��o! declarar valores constantes no in�cio do programa
	 	
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
		
		// Acumulando o valor total pago
		acumuladoMesas[numMesa - 1] += valorPagar;
	 	
	 	
	 	
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
		
		
		
		// Saída de dados 1 //
		//////////////////////
		
		gotoxy(52, 4);
		printf("%i", numMesa);
	
		gotoxy(47,6);
		printf("R$ %7.2f", valorConsumo);
		gotoxy(47,7);
		printf("%.2f %%", porcentagemGorjeta);
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
	
	} while (numMesa != 0); // Se informar 0 na mesa, exibe a tela de saida 2
	
	// Exibindo a tela de saída 2 //
	////////////////////////////////
	
	system("cls");
	 	
	gotoxy(12, 2);
	printf("<<  Pizzaria Five nights at Bianchi  >>");
	
	gotoxy(15, 4);
	printf("<<  Fechamento do Faturamento  >>");

// Aten��o! Mostrar valores de faturamento por mesa e valores totais somente se houve
//          Fauramento no dia

	
	gotoxy(21, 6);
	printf("Num.Mesa  Tot.Faturado");
	
	gotoxy(5, 19);
	printf("Total do Faturamento do dia.. R$");
	gotoxy(5, 21);
	printf("Média do Faturamento por Mesa R$");
	
	// Saída de dados 2 //
	//////////////////////
	
	// Print das mesas suas respectivas contas
	for(int i = 0; i < qtdMesas; i++) {
		if (acumuladoMesas[i] > 0)
			mesasAtendidas++;
		
		gotoxy(24,i + 8);
		printf("%i", i + 1);
		gotoxy(33,i + 8);
		printf("%9.2f", acumuladoMesas[i]);
		totalFaturado += acumuladoMesas[i];
	}
	
	//Calculo da Média Faturada por Mesas
	if (mesasAtendidas != 0) {
		mediaMesas = totalFaturado / mesasAtendidas;
	}
	
	// Print do total e das médias das mesas
	gotoxy(38,19);
	printf("%.2f", totalFaturado);
	
	gotoxy(39,21);
	printf("%.2f", mediaMesas);
	
	if (mesasAtendidas == 0) {
		gotoxy(2, 23);
		printf("Atenção! NÃO houve Faturamento neste dia!");
	}
	
	return 0;
}
