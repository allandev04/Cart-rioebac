#include <stdio.h>//bibloteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das strings
 
int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o de vari�veis/string
	char arquivo[40]; //definindo o limite de caracteres do arquivo
	char cpf[40]; //definindo o limite de algarismos do cpf
	char nome [40]; //definindo o limite de letras para os nomes
	char sobrenome[40]; //definindo o limite de letras dos sobrenomes
	char cargo[40]; //definindo o limite de letras dos cargos
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infos. do usu�rio
	scanf("%s", cpf); //%s refere-se �s strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizando o arquivo
	fprintf(file,","); //inserindo a v�rgula, depois de atualizar o arquivo
	fclose(file); //fechando a p�gina do arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando infos. do usu�rio
	scanf("%s",nome); //fazendo a leitura de dados de "nome"
	
	file = fopen(arquivo, "a"); //atualizando o arquivo
	fprintf(file,nome); //referenciando ao usu�rio o local onde digitar o nome
	fclose(file); //fechando a p�gina
	
	file = fopen(arquivo,"a"); //atualizando
	fprintf(file,","); //inserindo a v�rgula, depois de atualizar o arquivo
	fclose(file); //fechando a p�gina
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando infos. do usu�rio
	scanf("%s",sobrenome); //fazendo a a leitura de dados de "sobrenome"
	
	file = fopen(arquivo, "a"); //atualizando o arquivo
	fprintf(file,sobrenome); //referenciando ao usu�rio o local onde digitar o sobrenome
	fclose(file); //fechando a p�gina
	
	file = fopen(arquivo,"a"); //atualizando
	fprintf(file,","); //inserindo a v�rgula
	fclose(file); //fechando a p�gina
	
	
	printf("Digite o cargo a ser cadastrado: "); //coletando infos. do usu�rio
	scanf("%s",cargo); //fazendo a a leitura de dados de "cargo"
	
	file = fopen(arquivo, "a"); //atualizando
	fprintf(file,cargo); //referenciando ao usu�rio o local onde digitar o cargo
	fclose(file); //fechando a p�gina
	
	system("pause:"); //pausa na tela	
}

int consulta() //Fun��o respons�vel por consultar nomes 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //definindo o limite de caracteres do arquivo
	char conteudo[200]; //Quantidade limite de caracteres definidos no conte�do
	
	printf("Digite o CPF a ser consultado: "); //coletando infos. do usu�rio
	scanf("%s",cpf); //fazendo a leitura de dados do "cpf"
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //Abrindo e lendo o arquivo "cpf"
	
	if(file == NULL) //Estrutura condicional. "Se o arquivo for nulo.."
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado\n"); //Aviso ao usu�rio, caso o arquivo seja nulo
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //"Enquanto o conte�do for diferente de nulo.."
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n"); //Aviso ao usu�rio, quando as infos. forem encontrados
		printf("%s", conteudo); 
		printf("\n\n");
	}
	
	system("pause"); //pausando a tela
	
	}

int deletar() //Fun��o respons�vel por deletar nomes de usu�rios
{
	char cpf[40]; //definindo/lembrando o limite de caracteres do arquivo
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //coletando infos. do usu�rio
   scanf("%s",cpf); //Fazendo a leitura dos dados de "cpf"

    remove(cpf); //Instru��o para remover o cpf mencionado
    
    
    FILE *file; //Criando arquivo
    file = fopen(cpf,"r"); //Abrindo e lendo o cpf
    
    if(file == NULL) //Estrutura concional: "Se o arquivo for nulo..."
    {
    	printf("Usu�rio n�o encontrado no sistema! \n"); //Aviso ao usu�rio, caso n�o seja encontrado
    	system("pause"); //Pausando a tela
	}
	
	if(file != NULL) //Estrutura condicional: "Se o arquivo n�o for nulo..."
	{
		printf("Usu�rio deletado com sucesso! \n"); //Aviso ao usu�rio, caso seja deletado
		system("pause"); //pausando a tela
	}
    
}
int main() //Fun��o principal/Menu
   {
    int opcao=0; //Definindo vari�veis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
		
	  system("cls"); //respons�vel por limpar a tela
	  
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	  printf("### Cart�rio da EBAC ###\n\n"); //In�cio do Menu
	  printf("Escolha a op��o desejada do menu:\n\n"); //Apresentando op��es
	  printf("\t1 - Registrar nomes\n"); //Apresentando op��o de registrar
	  printf("\t2 - Consultar nomes\n"); //Apresentando op��o de consultar
	  printf("\t3 - Deletar nomes\n"); //Apresentando op��o de deletar
	  printf("\t4 - Voltar ao Menu\n\n"); //Apresentando a op��o de voltar ao menu
	  printf("Op��o:"); //fim do menu
	
   	  scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	  system("cls"); //respons�vel por limpar a tela
	  
	  
	  switch(opcao) //in�cio da sele��o do menu
	  {
	  	case 1:
	  	registro(); //chamada de fun��o
	  	break;
	  	
	  	case 2:
	  	consulta(); //chamada de fun��o
		break;
		
		case 3:
		deletar(); //chamada de fun��o
		break;
		
		case 4:
		printf("Obrigado por utilizar o sistema!\n");
		return 0;
		break;	
			
		default:
		printf("Esta op��o n�o est� dispon�vel\n"); //Aviso ao usu�rio, caso procure uma op��o inexistente
		system("pause"); //Pausa na tela
		break;
		}//fim da sele��o
	  
	  }
}
