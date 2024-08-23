// Autores: Jonathan Batista Bispo, Dennis Ramos, Matheus Arthur e Caue Ferreira Lacerda

#include <stdio.h>

int main()
{
    int l, t, b=0, n = 0, nota, total = 0;

    printf("Digite a quantidade de teste(s): ");
    scanf("%i" ,&t);
    
    int c[t], menor[t], maior[t];
    
    for(l = 0; l < t; l++){
        printf("Digite a quantidade de notas do teste numero %i (sendo Nota > 2): ",(l+1));
        scanf("%i" ,&c[l]);
        while (c[l] <= 2)
        {
            printf("Valor de notas insuficiente, entre com uma quantia correta: ");
            scanf("%i",&c[l]);
        }
    }
    
    for(l = 0; l < t; l++){
        if(b < c[l]){
            b = c[l];
        }
    }
    
    int teste[t][b], totaltes[t];
    
    for(l = 0; l < t; l++)
    {
        printf("Notas do teste %i:\n",l+1);
        for(n = 0; n < c[l]; n++)
        {
            printf("Digite a nota numero %i: ",(n+1));
            scanf("%i",&nota);
            while(nota < 0 || nota > 10)
            {
                printf("Digite uma nota correta que esteja entre 0 a 10: ");
                scanf("%i",&nota);
            }
            teste[l][n] = nota;

            printf("%i",teste[l][n]);
            printf("\n");

            
        }
        
    }
    
    for(l = 0; l < t; l++){
        maior[l] = 0;
        menor[l] = 10;
        for(n = 0; n < c[l]; n++){
            if(teste[l][n] < menor[l])
            {
                menor[l] = teste[l][n];
            }
            if (teste[l][n] > maior[l])
            {
                maior[l] = teste[l][n];
            }    
        }
    }
    
    for(l = 0; l < t; l++){
        total = 0;
        for(n = 0; n < c[l]; n++){
        total = total + teste[l][n];
        }
        total = total - (maior[l] + menor[l]);
        totaltes[l] = total; 
    }
    
    totaltes[t+1] = 0;
    
    for(l = 0; l < t; l++){
        totaltes[t+1] = totaltes[t+1] + totaltes[l];
    }
    
    
    for(l = 0; l < t; l++)
    {
        printf("A nota do teste %i foi: " ,(l+1));
        for(n = 0; n < c[l]; n++)
        {
            printf("%i ",teste[l][n]);
        }
        printf("\nO total da nota do teste %i foi ", (l+1));
        printf("%i \n", totaltes[l]);
    }
    printf("A nota final do candidato foi: %i" ,totaltes[t+1]);

    return(70);
}