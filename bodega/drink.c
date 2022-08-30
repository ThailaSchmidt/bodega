#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "drink.h"
#include "cliente.h"

Drink *newDrink() {
    Drink *newD;
    newD = (Drink*)malloc(sizeof(Drink));
    printf("Digite o código da bebida:\n");
    scanf("%d", &newD->cod);
    printf("Digite o nome da bebida:\n");
    scanf("%s", newD->name);
    printf("Digite o conteúdo líquido da bebida em ml:\n");
    scanf("%d", &newD->ml);
    printf("Digite o preço da bebida:\n");
    scanf("%lf", &newD->price);
    printf("A bebida é alcóolica? (1 - sim, 2 - não)\n");
    scanf("%d", &newD->alcoholic);
    newD->prev = NULL;
    newD->next = NULL;
    return newD;
}

Sent *insertDrink(Sent *list) {
    Drink *aux = list->first;
    Drink *newD = newDrink();
    if (aux == NULL) {
        list->first = newD;
        list->last = newD;
        return list;
    } else {
        for (; aux != NULL; aux = aux->next){
            if(aux->cod == newD->cod){
                printf("\nCódigo já existente, tente novamente!");
                return list;
            }
        }
        newD->prev = list->last;
        list->last->next = newD;
        list->last = newD;
        newD -> next = NULL;
        printf("\nBebida cadastrada com sucesso!");
        return list;
    }  
}

int emptyDrink (Sent *list) {
    if (list->first == NULL) return 1;
    return 0;
}

void printDrink (Sent *list) {
    Drink *aux = list->first;
    if (emptyDrink(list)) {
        printf("Nenhuma bebida cadastrada!\n");
        return;
    }
    for (; aux != NULL; aux = aux->next)
        printf("\n Código da bebida: %d;\n Nome da Bebida: %s;\n Conteúdo líquido: %dml;\n Preço da bebida: R$%.2f;\n Álcool: %d;\n Quantidade em estoque: %d unidade(s);\n", aux->cod, aux->name, aux->ml, aux->price, aux->alcoholic, aux->inventory);   
}

int freeDrink(Sent *list) { 
    Drink *aux = list->first;
    int contD = 0;
    while (aux != NULL) {
        list->first = aux->next;
        free(aux);
        contD ++;
        aux = list->first;
    }
    return contD;
    printf("\n");
}

Sent *buyDrink(Sent *list) {
    Drink *aux;
    int cod, qtd;
    printf("Digite o código da bebida a ser comprada:\n");
    scanf("%d", &cod);
    printf("Digite a quantidade a ser comprada:\n");
    scanf("%d", &qtd);
    if (qtd < 1){
        printf("\nA quantidade não pode ser negativa ou igual a zero.");
        return list;
    }else{
        for (aux = list->first; aux != NULL; aux = aux->next){
            if(aux->cod == cod){
                aux->inventory = aux->inventory + qtd;
                printf("\nBebida comprada com sucesso!");
                return list; 
            }
        }
    }
    printf("\nCódigo inexistente.");
    return list;
}  

Sent *sellDrink(Sent *list) {
    Drink *aux;
    int cod, qtd, cpf;
    printf("Digite o código da bebida a ser vendida:\n");
    scanf("%d", &cod);
    printf("Digite a quantidade a ser vendida:\n");
    scanf("%d", &qtd);
    printf("Digite o cpf do cliente:\n");
    scanf("%d", &cpf);
    if (qtd < 1){
        printf("\nA quantidade não pode ser negativa ou igual a zero.");
        return list;
    }else{
        for(aux = list->first; aux != NULL; aux = aux->next){
            if(aux->cod == cod){
                if(aux->inventory < qtd){
                    printf("\nNão há estoque suficiente.");
                    return list;
                }else if (aux->alcoholic == 1){
                    
                }else{
                    aux->inventory = aux->inventory - qtd;
                    printf("\nBebida vendida com sucesso!");
                    return list; 
                }
            }
        }
        printf("\nCódigo inexistente.");
        return list;
    }
    printf("!");
    return list;
}  