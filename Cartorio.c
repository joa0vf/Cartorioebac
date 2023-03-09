#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função utilizada para cadastrar os usuários no sistema
{
	 setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	//Início da criação de variáveis/string
	char arquivo[40]; 
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
     //Final da criação de variáveis/string
     
    printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
    scanf("%s", cpf);  //%s refere-se a string
     
    strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
     
    FILE *file; //Cria o arquivo no banco de dados
    file = fopen(arquivo, "w"); // cria o arquivo e o W significa escrever
    fprintf(file,cpf); //salvo o valor da variável
    fclose(file); // fecha o arquivo
     
    file = fopen(arquivo, "a"); //"a" é de atualização   //Abrindo o arquivo
    fprintf(file,","); //para colocar espaçamento dentre as linhas
    fclose(file); //Fechando o arquivo
    
    printf("Digite o nome a ser cadastrado: "); //Coletando o nome do usuário
    scanf("%s",nome); //scanf é um comando usado para armazanar um valor em uma variável.   //%s refere-se a string
    
    file = fopen(arquivo, "a"); //Abre o arquivo  // "a" atualiza o arquivo
    fprintf(file,nome); //salvar dentro do arquivo o valor da variável "nome"
    fclose(file); //Fecha o arquivo
    
    file = fopen(arquivo, "a"); //Abre o arquivo
    fprintf(file,","); // Coloca o espaçamento dentre as linhas
    fclose(file); //Fecha o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: "); // Coletando informações do sobrenome do usuário
    scanf("%s",sobrenome); //scanf usado para salvar um valor em uma variável // %s refere-se a string
    
    file = fopen(arquivo, "a"); //Abre o arquivo // "a" atualiza o arquivo
    fprintf(file,sobrenome);  //Salvar dentro do arquivo o valor da variável "sobrenome"
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a"); //abre o arquivo //"a" atualiza o arquivo
    fprintf(file,","); // Coloca o espaçamento dentre as linhas
    fclose(file); //fecha o arquivo
    
    printf("Digite o cargo a ser cadastrado: "); //Coleta informações do cargo do usuário
    scanf("%s",cargo); //scanf para salvar a variável coletada //%s refere-se a string
    
    file = fopen(arquivo, "a"); //abre o arquivo e atualiza
    fprintf(file,cargo); // Salva dentro do arquivo a variável "cargo" 
    fclose(file); //fecha o arquivo
    
    system("pause"); // serve para congelar na tela de decisão
    
}

int consulta() //Função utilizada para consultar os usuários já cadastrados
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //char é uma variável que representa um caractere do tipo texto. 
	char conteudo[200]; //char é uma variável que representa um caractere do tipo texto. 
	
	printf("Digite o CPF a ser consultado: "); // Coleta o CPF do cliente
	scanf("%s",cpf); //scanf é para salvar a variável coletada "cpf"
	
	FILE *file; //Cria o arquivo no banco de dados
	file = fopen(cpf, "r"); //abre o arquivo //"r" para ler o arquivo
	
	if(file == NULL) //if
	{
		printf("Não foi possível abrir o arquivo, não localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	  }  
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
    }
	
}


int main()
    {  
	int opcao=0; //Definindo as variáveis
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		system("cls"); //resposável por limpar a tela
		
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); //Início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opção: "); //FIm do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls");
	    
	    switch(opcao) //inicio da seleção de menu
	    {
	    	case 1:
	    	registro(); //chamada de função registro
		    break;
		    
		    case 2:
	    	consulta(); //chamada de função consulta
   		    break;
   		    
   		    case 3:
   		    deletar(); //chamada de função deletar
		    break; // 
		
		    default:
		    printf("Esta opção não está disponível.\n\n");
		    system("pause"); // 
		    break; //fim da seleção
		}
		
    }
}
