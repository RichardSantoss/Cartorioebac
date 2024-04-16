#include <stdio.h>   //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��es de texto por regi�o
#include <string.h>  //biblioteca respons�vel por cuidar das strings

int registro() // fun��o respons�vel por cadastrar usu�rios no sistema
{
	//inicio cria��o de vari�reis/strings
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final cria��o de vari�reis/strings
    
    printf("Digite o cpf a ser cadastrado: ");//coletando informa��o do usu�rio
    scanf("%s", cpf);//%s refere-se a string
    
    strcpy(arquivo, cpf); //Respons�vel por copiar o valor das strings
    
    FILE *file; //Cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //salvo o valor da vari�vel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
    
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
	
	if(file == NULL)
	{
	    printf("N�o foi possivel abrir o arquivo, n�o foi localizado\n");		
	} 
	
	while(fgets(conteudo, 200, file) != NULL)
	{	
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
    

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema\n");
		system("pause");
		
	}else{
		fclose(file);
		remove(cpf);
		FILE *file;	
		file = fopen(cpf,"r");
		if(file == NULL){
			printf("Usu�rio deletado com sucesso!.\n");
			system("pause");
		}
		
	}
	fclose(file);
	
}

int main()
{ 
    setlocale(LC_ALL, "Portuguese");
    int opcao=0; // Definindo vari�veis
    int x=1;  
    char senhadigitada[10]="a";
    char logindigitado[10]="a";   
    int comparacao;
    int comparacao2;
    
    
    printf("### Cart�rio da EBAC ###\n\n");
    printf("Login de administrador! \n\nDigite o seu login: ");
    scanf("%s",logindigitado);
    
    comparacao2 = strcmp(logindigitado,"richardsantos");
	  
    printf("\nDigite a sua senha: ");
    scanf("%s",senhadigitada);
    
    comparacao = strcmp(senhadigitada,"admin");
       				   
    if(comparacao == 0)
    {
    	
    	if (comparacao2 == 0)
		{
								  	 		        
   		 for(x=1;x=1;)
   		 {
	
		  system("cls");
	 
    	 setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
    
	 	 printf("### Cart�rio da EBAC ###\n\n"); //�nicio do menu	
	 	 printf("Escolha a op��o desejada do menu: \n\n");
     	 printf("\t1 - Registrar nomes\n");
     	 printf("\t2 - Consultar nomes\n");
     	 printf("\t3 - Deletar nomes\n\n");
     	 printf("\t4 - Sair do sistema\n\n");
	   	 printf("Op��o:" ); //Fim do menu
         
      	scanf("%d", &opcao);//Armazenando a escolha do usu�rio
         
     	 system("cls");//comando usado para "limpar" tela de menu
      
     	 switch(opcao)// inicio da sele��o do menu
     	 	{
      		case 1:
      		registro();//chamada de fun��es
			break;
		
			case 2:
			consulta();
			break;
		
			case 3:	
        	deletar();   
	 		break;
	 	
	 		case 4:
	 		printf("Obrigado por utilizar o sistema!");
	 		return 0;
	 		break;
	 	
	 		default:
	 		printf("Essa op��o n�o est� disponivel! Tente novamente\n");
	 		system("pause");
	 		break;
	     }	
	 			 			 			 			 			 		
	  		}	  		
   	   }else
   	       printf("Login incorreto!");		  		    	      	     	   
   	}else
		printf("Senha incorreta!");		
 }
	    



















