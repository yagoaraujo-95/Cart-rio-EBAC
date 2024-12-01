#include <stdio.h> // Blibioteca de comunicação com usuario
#include <stdlib.h> // Blibioteca de loção de espaço em memória
#include <locale.h> // Blibioteca de locação de texto por região
#include <string.h> // Blibioteca responsavel por cuidar das string;



int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite seu cpf a ser cadastrado");
	scanf("%s",cpf);
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo 
	file = fopen(arquivo,"w");// cria o arquivo no banco de dados 
	
	fprintf(file,cpf);// salvo o valor da variavel
	fclose(file); // aqui e eu fecho o arquivo
	

	fprintf(file,",");
	file = fopen(arquivo,"a");// abrindo arquivo salvo no banco de dados 
	fclose(file);
	
	
	printf("Digite o nome a ser cadastrado");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a"); // atualizando nomes no banco de dados 
	fprintf(file,nome); // armazenado nomes no banco de dados 
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	
	
	printf("Digite o sobrenome a ser cadastrado");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	
	printf("Digiti o cargo a ser cadastrodo");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	
	system("pause");
	
		
}

int consultar()
{
	setlocale(LC_ALL,"Portuguese");//definindo a linguagem
	
	char cpf [40];
	char conteudo [200];
	
	printf("Digite o cpf a ser consultado");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foipossivel  localizar o arquivo!.\n");
	}
	
	while(fgets(conteudo,200, file) !=NULL)
	{
		printf("\nEssa são as informações do usuario.\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");


}

int deletar()
{
	char cpf [40];
	
	printf("Digite o cpfdo usuário a ser deletado");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL);
	{
	    printf(" O usuário foi deletado com sucesso \n O usuário não se encontra no sistema. \n");
		system("pause");
	}
 
}


int main()
 {
  
	int opcao=0; // definir variáveis
	int laco=1;
	
	for(laco=1; laco==1;)
	{
	
	  system("cls");
	  
    	
	  setlocale(LC_ALL,"Portuguese");//definindo a linguagem
	
	  printf("### Cartório da EBAC ### \n\n");// inicio do menu
	  printf("escolha apção desejada do menu:\n\n");
 	  printf("\t1 Registra nomes\n\n");
	  printf("\t2 Consultar nomes\n\n");
	  printf("\t3 Deletar nomes\n\n");
	  printf("Opção:");// fim do menu

      scanf("%d", &opcao);// armazenando as informação do usuario
   
      system("cls");
      
      switch(opcao)
	  {
	  	case 1:
 		registro();
   	    break;
   	    
   	    case 2:
   	   	consultar();
   	    break;
   	    
   	    case 3:
   	    deletar();
   	    break;
   	    	
   	    default:
   	   	 printf("Essa opção não esta disponivel!\n");
   	    system("pause");
   	    break;
	  }
   
      
   
     }
}
