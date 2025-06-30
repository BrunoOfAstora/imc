#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>

#define F fflush(stdout)


int main()
{

	char input[10];

	unsigned int height = 0;
 	unsigned int weight = 0;

	printf("*********************\n"); F;
	printf("*Calculadora de IMC** (Por Bruno Silva Ferreira)\n"); F;
	printf("*********************\n"); F;
	printf("(Digitar 0 fecha o programa)\n"); F;
	

	while(1)
	{
		printf("\nDigite seu Peso : "); F;
			
			if((scanf("%d", &weight)) == 0)
			{
				int c;

				while((c = getchar()) != '\n' && c != EOF);
				weight = 0;

				printf("	>Digite um Número válido!");				
				continue;
			}
			
			if(weight == 0)
			{
				printf("\nSaindo...\n");
				return 1;
			}
		

		
		memset(input, 0, sizeof(input));


		printf("\nDigite sua Altura :"); F;
		
			if((scanf("%d", &height)) == 0)
			{
				int c;
	
				while((c = getchar()) != '\n' && c != EOF);
				height = 0;

				printf("	>Digite um Número válido!");
				continue;
			}

			if(height == 0)
			{
				printf("\nSaindo...\n");
				return 1;
			}						
			
			
		printf("\n"); F;

		float height_f = (float)height / 100.0f;

		float result = weight / (height_f * height_f);

        printf("\n----------------------------------------\n");
		
		if(result < 18.5)
		{
			printf("Seu IMC é de %.2f \n Você está Abaixo do Peso.\n\n", result);
		}

		else if(result > 18.5 && result < 24.9)
		{
			printf("Seu IMC é de %.2f \n Você está no Peso Adequado.\n\n", result);
		}
		
		else if(result >= 25 && result < 29.9)
		{
			
			printf("Seu IMC é de %.2f \n Você está Acima do Peso.\n\n", result);
		}
		
		else if(result >= 30 && result < 34.9)
		{

			printf("Seu IMC é de %.2f \n Você está com Obesidade Grau I.\n\n", result);
		}

		else if(result >= 35 && result < 39.9)
		{
		
			printf("Seu IMC é de %.2f \n Você está com Obesidade Grau II.\n\n", result);
		}
		
		else if(result >= 40)
		{
		
			printf("Seu IMC é de %.2f \n Você está com Obesidade Grau III (Obesidade Mórbida).\n\n", result);
		}
		
		else 
		{
			printf("IMC inválido, saindo...");
			return 1;
		}

		printf("\n----------------------------------------\n");
	
	}
	
	return 0;
}
