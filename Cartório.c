#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca respons�vel por cuidar das string


int registro() //Fun��o local respons�vel por cadastrar os usu�rios no sistema 
{	

	//inicio da cria��o de vari�veis /string
	char arquivo [40]; // a vari�vel char � usada pois � melhor no gerenciamento de strang
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis 
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); // %s � usado para salvar uma string
	
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo e o * � usado para referenciar o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo o valor da vari�vel 
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //abriu o arquivo e o "a" � usado para atualizar o arquivo 
	fprintf(file,","); //salvo o valor da vari�vel
	fclose(file); //fecho o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o do usu�rio 
	scanf("%s",nome); //salvo a vari�vel 
	
	file = fopen(arquivo, "a"); //abriu o arquivo 
	fprintf(file,nome); //salvo o valor da vari�vel 
	fclose(file); //fecho o arquivo 
	
	file = fopen(arquivo, "a"); //abriu o arquivo 
	fprintf(file,","); //salvo o valor da vari�vel 
	fclose(file); //fecho o arquivo 
	
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o do usu�rio 
    scanf("%s",sobrenome); // salvo a vari�vel 
    
    file = fopen(arquivo, "a"); //abriu o arquivo 
    fprintf(file,sobrenome); // salvo o valor da vari�vel 
    fclose(file); //fecho o arquivo 
	
	file = fopen(arquivo, "a"); // abriu o arquivo 
	fprintf(file,","); //salvo o valor da variavel 
	fclose(file); //fecho o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��es do usu�rio 
	scanf("%s", cargo); //salvo a vari�rel
	
	file = fopen(arquivo, "a"); //abriu o arquivo
	fprintf(file,cargo); //salvo o valor da vari�vel 
	fclose(file); //fecho o arquivo
	
}

int consulta() //Fun��o local respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informa��es do usu�rio 
	scanf("%s",cpf); //salvo o arquivo
	
	FILE *file; // busco o arquivo na biblicioteca 
	file = fopen(cpf,"r"); //abriu o arquivo  e o "r" � usado para ler o arquivo
	
	if(file == NULL) // arquivo nulo 
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); // retorno de mensagem para o usu�rio 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //la�o de repeti��o e o "!=" significa diferente 
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); // retorno de mensagem para o usu�rio  
		printf("%s", conteudo); //salvo o valor da vari�vel 
		printf("\n\n");
		fclose(file); //fecho o arquivo 
	}
			
	system("pause"); // respons�vel por mostra a mensagem por usu�rio at� o usu�rio n�o querer mais
}

int deletar() //Fun��o local respons�vel por deletar os usu�rios do sistema 
{	
 	char cpf[40];
 	
 	printf("Digite  o CPF  do usu�rio a ser deletado: "); //coletando informa��es do usu�rio 
 	scanf("%s", cpf); //salvo o arquivo 
 	
 	remove(cpf); //fun��o da biblioteca respons�vel por deletar o arquivo 
 	
 	FILE *file; //busca os arquivo na biblioteca
 	file = fopen(cpf,"r"); //abrir o arquivo 
 	fclose(file); //fecho o arquivo
 	
 	if (file == NULL) // arquivo nulo 
    {
 		printf("O usu�rio n�o se encontra no sistema!.\n"); //retorno de mensagem para o usu�rio 
 		system("pause"); // respons�vel por mostra a mensagem por usu�rio at� o usu�rio n�o querer mais
 		
    }
    
}


int main() //Func�o principal / global 
    { 	
	int opcao=0;  // Definindo variaveis
    int laco=1; 
	
	for (laco=1;laco=1;) // estrutura de repeti��o // usado para sempre voltar para o menu 
    {
	
	    system("cls"); // respons�vel por limpar a tela 
	    
    	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
    	printf("Cart�rio da EBAC\n"); // O "\" � entendido pelo sistema como um comando 
    	printf("========================\n");
    	printf("ESCOLHA A OP��O DESEJADA DO MENU: \n");
    	printf("========================\n");
    	printf("\t1 - Registar nomes\n");
    	printf("\t2 - Consutar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
   	    printf("Op��o: "); //Fim do menu
    
   	    scanf("%d" , &opcao); //Armazenando a escolha do usu�rio
    
        system("cls"); //respons�vel por limpar a tela 
        
        
        switch(opcao) //inicio da sele��o do menu 
        {
        	case 1: // ":" � usuado para falar tudo que vai acontecer 
        	registro(); //chamada de fun��es 
			break; //encerro a op��o 
        	
        	case 2:
        	consulta();	
        	break;
        	
        	case 3:
        	deletar();	
        	break;	
        	
        	case 4:
        	printf("Obrigado por utilizar o nosso sistema!\n");
        	return 0;
        	break;
        	
        	default: //op��o inv�lida 
            printf("Essa op��o n�o est� disponivel!/n"); //retorno de mensagem para o usu�rio 	
        	system("pause"); // respons�vel por mostra a mensagem por usu�rio at� o usu�rio n�o querer mais
        	break;	    
            
		} 
		   
    } 
 } 


