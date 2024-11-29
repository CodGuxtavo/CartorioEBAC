#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço na memória
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsável por cuidar das string


int registro() //Função local responsável por cadastrar os usuários no sistema 
{	

	//inicio da criação de variáveis /string
	char arquivo [40]; // a variável char é usada pois é melhor no gerenciamento de strang
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis 
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); // %s é usado para salvar uma string
	
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo e o * é usado para referenciar o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever 
	fprintf(file,cpf); //salvo o valor da variável 
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //abriu o arquivo e o "a" é usado para atualizar o arquivo 
	fprintf(file,","); //salvo o valor da variável
	fclose(file); //fecho o arquivo 
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação do usuário 
	scanf("%s",nome); //salvo a variável 
	
	file = fopen(arquivo, "a"); //abriu o arquivo 
	fprintf(file,nome); //salvo o valor da variável 
	fclose(file); //fecho o arquivo 
	
	file = fopen(arquivo, "a"); //abriu o arquivo 
	fprintf(file,","); //salvo o valor da variável 
	fclose(file); //fecho o arquivo 
	
    printf("Digite o sobrenome a ser cadastrado: "); //coletando informação do usuário 
    scanf("%s",sobrenome); // salvo a variável 
    
    file = fopen(arquivo, "a"); //abriu o arquivo 
    fprintf(file,sobrenome); // salvo o valor da variável 
    fclose(file); //fecho o arquivo 
	
	file = fopen(arquivo, "a"); // abriu o arquivo 
	fprintf(file,","); //salvo o valor da variavel 
	fclose(file); //fecho o arquivo 
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informações do usuário 
	scanf("%s", cargo); //salvo a variárel
	
	file = fopen(arquivo, "a"); //abriu o arquivo
	fprintf(file,cargo); //salvo o valor da variável 
	fclose(file); //fecho o arquivo
	
}

int consulta() //Função local responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); //coletando informações do usuário 
	scanf("%s",cpf); //salvo o arquivo
	
	FILE *file; // busco o arquivo na biblicioteca 
	file = fopen(cpf,"r"); //abriu o arquivo  e o "r" é usado para ler o arquivo
	
	if(file == NULL) // arquivo nulo 
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n"); // retorno de mensagem para o usuário 
	}
	
	while(fgets(conteudo, 200, file) != NULL) //laço de repetição e o "!=" significa diferente 
	{
		printf("\nEssas são as informações do usuário: "); // retorno de mensagem para o usuário  
		printf("%s", conteudo); //salvo o valor da variável 
		printf("\n\n");
		fclose(file); //fecho o arquivo 
	}
			
	system("pause"); // responsável por mostra a mensagem por usuário até o usuário não querer mais
}

int deletar() //Função local responsável por deletar os usuários do sistema 
{	
 	char cpf[40];
 	
 	printf("Digite  o CPF  do usuário a ser deletado: "); //coletando informações do usuário 
 	scanf("%s", cpf); //salvo o arquivo 
 	
 	remove(cpf); //função da biblioteca responsável por deletar o arquivo 
 	
 	FILE *file; //busca os arquivo na biblioteca
 	file = fopen(cpf,"r"); //abrir o arquivo 
 	fclose(file); //fecho o arquivo
 	
 	if (file == NULL) // arquivo nulo 
    {
 		printf("O usuário não se encontra no sistema!.\n"); //retorno de mensagem para o usuário 
 		system("pause"); // responsável por mostra a mensagem por usuário até o usuário não querer mais
 		
    }
    
}


int main() //Funcão principal / global 
    { 	
	int opcao=0;  // Definindo variaveis
    int laco=1; 
	
	for (laco=1;laco=1;) // estrutura de repetição // usado para sempre voltar para o menu 
    {
	
	    system("cls"); // responsável por limpar a tela 
	    
    	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
    	printf("Cartório da EBAC\n"); // O "\" é entendido pelo sistema como um comando 
    	printf("========================\n");
    	printf("ESCOLHA A OPÇÃO DESEJADA DO MENU: \n");
    	printf("========================\n");
    	printf("\t1 - Registar nomes\n");
    	printf("\t2 - Consutar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
   	    printf("Opção: "); //Fim do menu
    
   	    scanf("%d" , &opcao); //Armazenando a escolha do usuário
    
        system("cls"); //responsável por limpar a tela 
        
        
        switch(opcao) //inicio da seleção do menu 
        {
        	case 1: // ":" é usuado para falar tudo que vai acontecer 
        	registro(); //chamada de funções 
			break; //encerro a opção 
        	
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
        	
        	default: //opção inválida 
            printf("Essa opção não está disponivel!/n"); //retorno de mensagem para o usuário 	
        	system("pause"); // responsável por mostra a mensagem por usuário até o usuário não querer mais
        	break;	    
            
		} 
		   
    } 
 } 


