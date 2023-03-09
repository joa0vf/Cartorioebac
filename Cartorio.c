#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o utilizada para cadastrar os usu�rios no sistema
{
	 setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//In�cio da cria��o de vari�veis/string
	char arquivo[40]; 
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
     //Final da cria��o de vari�veis/string
     
    printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
    scanf("%s", cpf);  //%s refere-se a string
     
    strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
     
    FILE *file; //Cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); // cria o arquivo e o W significa escrever
    fprintf(file,cpf); //salvo o valor da vari�vel
    fclose(file); // fecha o arquivo
     
    file = fopen(arquivo, "a"); //"a" � de atualiza��o   //Abrindo o arquivo
    fprintf(file,","); //para colocar espa�amento dentre as linhas
    fclose(file); //Fechando o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //Coletando o nome do usu�rio
    scanf("%s",nome); //scanf � um comando usado para armazanar um valor em uma vari�vel.   //%s refere-se a string
    
    file = fopen(arquivo, "a"); //Abre o arquivo  // "a" atualiza o arquivo
    fprintf(file,nome); //salvar dentro do arquivo o valor da vari�vel "nome"
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a"); //Abre o arquivo
    fprintf(file,","); // Coloca o espa�amento dentre as linhas
    fclose(file); //Fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); // Coletando informa��es do sobrenome do usu�rio
    scanf("%s",sobrenome); //scanf usado para salvar um valor em uma vari�vel // %s refere-se a string
    
    file = fopen(arquivo, "a"); //Abre o arquivo // "a" atualiza o arquivo
    fprintf(file,sobrenome);  //Salvar dentro do arquivo o valor da vari�vel "sobrenome"
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //abre o arquivo //"a" atualiza o arquivo
    fprintf(file,","); // Coloca o espa�amento dentre as linhas
    fclose(file); //fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: "); //Coleta informa��es do cargo do usu�rio
    scanf("%s",cargo); //scanf para salvar a vari�vel coletada //%s refere-se a string
    
    file = fopen(arquivo, "a"); //abre o arquivo e atualiza
    fprintf(file,cargo); // Salva dentro do arquivo a vari�vel "cargo" 
    fclose(file); //fecha o arquivo
    
    system("pause"); // serve para congelar na tela de decis�o
    
}

int consulta() //Fun��o utilizada para consultar os usu�rios j� cadastrados
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //char � uma vari�vel que representa um caractere do tipo texto. 
	char conteudo[200]; //char � uma vari�vel que representa um caractere do tipo texto. 
	
	printf("Digite o CPF a ser consultado: "); // Coleta o CPF do cliente
	scanf("%s",cpf); //scanf � para salvar a vari�vel coletada "cpf"
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(cpf, "r"); //abre o arquivo //"r" para ler o arquivo
	
	if(file == NULL) //if
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	  }  
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
    }
	
}


int main()
    {  
	int opcao=0; //Definindo as vari�veis
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		system("cls"); //respos�vel por limpar a tela
		
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Op��o: "); //FIm do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls");
	    
	    switch(opcao) //inicio da sele��o de menu
	    {
	    	case 1:
	    	registro(); //chamada de fun��o registro
		    break;
		    
		    case 2:
	    	consulta(); //chamada de fun��o consulta
   		    break;
   		    
   		    case 3:
   		    deletar(); //chamada de fun��o deletar
		    break; // 
		
		    default:
		    printf("Esta op��o n�o est� dispon�vel.\n\n");
		    system("pause"); // 
		    break; //fim da sele��o
		}
		
    }
}
