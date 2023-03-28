#include <stdio.h>//bibloteca de comunicação com o usuário
#include <stdlib.h>//biblioteca de alocação de espaço em memória
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings
 
int registro() //Função responsável por cadastrar os usuários no sistema
{
	//início da criação de variáveis/string
	char arquivo[40]; //definindo o limite de caracteres do arquivo
	char cpf[40]; //definindo o limite de algarismos do cpf
	char nome [40]; //definindo o limite de letras para os nomes
	char sobrenome[40]; //definindo o limite de letras dos sobrenomes
	char cargo[40]; //definindo o limite de letras dos cargos
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infos. do usuário
	scanf("%s", cpf); //%s refere-se ás strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo 
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualizando o arquivo
	fprintf(file,","); //inserindo a vírgula, depois de atualizar o arquivo
	fclose(file); //fechando a página do arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando infos. do usuário
	scanf("%s",nome); //fazendo a leitura de dados de "nome"
	
	file = fopen(arquivo, "a"); //atualizando o arquivo
	fprintf(file,nome); //referenciando ao usuário o local onde digitar o nome
	fclose(file); //fechando a página
	
	file = fopen(arquivo,"a"); //atualizando
	fprintf(file,","); //inserindo a vírgula, depois de atualizar o arquivo
	fclose(file); //fechando a página
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando infos. do usuário
	scanf("%s",sobrenome); //fazendo a a leitura de dados de "sobrenome"
	
	file = fopen(arquivo, "a"); //atualizando o arquivo
	fprintf(file,sobrenome); //referenciando ao usuário o local onde digitar o sobrenome
	fclose(file); //fechando a página
	
	file = fopen(arquivo,"a"); //atualizando
	fprintf(file,","); //inserindo a vírgula
	fclose(file); //fechando a página
	
	
	printf("Digite o cargo a ser cadastrado: "); //coletando infos. do usuário
	scanf("%s",cargo); //fazendo a a leitura de dados de "cargo"
	
	file = fopen(arquivo, "a"); //atualizando
	fprintf(file,cargo); //referenciando ao usuário o local onde digitar o cargo
	fclose(file); //fechando a página
	
	system("pause:"); //pausa na tela	
}

int consulta() //Função responsável por consultar nomes 
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40]; //definindo o limite de caracteres do arquivo
	char conteudo[200]; //Quantidade limite de caracteres definidos no conteúdo
	
	printf("Digite o CPF a ser consultado: "); //coletando infos. do usuário
	scanf("%s",cpf); //fazendo a leitura de dados do "cpf"
	
	FILE *file; //cria o arquivo
	file = fopen(cpf, "r"); //Abrindo e lendo o arquivo "cpf"
	
	if(file == NULL) //Estrutura condicional. "Se o arquivo for nulo.."
	{
		printf("Não foi possível abrir o arquivo, não localizado\n"); //Aviso ao usuário, caso o arquivo seja nulo
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //"Enquanto o conteúdo for diferente de nulo.."
	{
		printf("\nEssas são as informações do usuário:\n"); //Aviso ao usuário, quando as infos. forem encontrados
		printf("%s", conteudo); 
		printf("\n\n");
	}
	
	system("pause"); //pausando a tela
	
	}

int deletar() //Função responsável por deletar nomes de usuários
{
	char cpf[40]; //definindo/lembrando o limite de caracteres do arquivo
	
	printf("Digite o CPF do usuário a ser deletado: "); //coletando infos. do usuário
   scanf("%s",cpf); //Fazendo a leitura dos dados de "cpf"

    remove(cpf); //Instrução para remover o cpf mencionado
    
    
    FILE *file; //Criando arquivo
    file = fopen(cpf,"r"); //Abrindo e lendo o cpf
    
    if(file == NULL) //Estrutura concional: "Se o arquivo for nulo..."
    {
    	printf("Usuário não encontrado no sistema! \n"); //Aviso ao usuário, caso não seja encontrado
    	system("pause"); //Pausando a tela
	}
	
	if(file != NULL) //Estrutura condicional: "Se o arquivo não for nulo..."
	{
		printf("Usuário deletado com sucesso! \n"); //Aviso ao usuário, caso seja deletado
		system("pause"); //pausando a tela
	}
    
}
int main() //Função principal/Menu
   {
    int opcao=0; //Definindo variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
		
	  system("cls"); //responsável por limpar a tela
	  
	  setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	  printf("### Cartório da EBAC ###\n\n"); //Início do Menu
	  printf("Escolha a opção desejada do menu:\n\n"); //Apresentando opções
	  printf("\t1 - Registrar nomes\n"); //Apresentando opção de registrar
	  printf("\t2 - Consultar nomes\n"); //Apresentando opção de consultar
	  printf("\t3 - Deletar nomes\n\n"); //Apresentando opção de deletar
	  printf("Opção:"); //fim do menu
	
   	  scanf("%d", &opcao); //armazenando a escolha do usuário
	
	  system("cls"); //responsável por limpar a tela
	  
	  
	  switch(opcao) //início da seleção do menu
	  {
	  	case 1:
	  	registro(); //chamada de função
	  	break;
	  	
	  	case 2:
	  	consulta(); //chamada de função
		break;
		
		case 3:
		deletar(); //chamada de função
		break;
		
		default:
		printf("Esta opção não está disponível\n"); //Aviso ao usuário, caso procure uma opção inexistente
		system("pause"); //Pausa na tela
		break;
		}//fim da seleção
	  
	  }
}
