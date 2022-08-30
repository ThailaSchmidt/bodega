#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

Client *newClient() {
    Client *newC;
    newC = (Client*)malloc(sizeof(Client));
    printf("Digite o código do cliente:\n");
    scanf("%d", &newC->cod);
    printf("Digite o cpf do cliente:\n");
    scanf("%d", &newC->cpf);
    printf("Digite o nome do cliente:\n");
    scanf("%s", newC->name);
    printf("Digite a data de nascimento do cliente:\n");
    scanf("%d/%d/%d", &newC->date.day, &newC->date.month, &newC->date.year);
    printf("Pode vender fiado: (1 - sim, 2 - não)\n");
    scanf("%d", &newC->fiado);
    newC->prev = NULL;
    newC->next = NULL;
    return newC;
}

Sent2 *insertClient(Sent2 *list2) {
    Client *aux = list2->first;
    Client *newC = newClient();
    if(newC->date.day == 0 || newC->date.month == 0 || newC->date.year == 0){
            printf("\nDatas não podem ser zero!");
            return list2;
    }else if (aux == NULL) {
        list2->first = newC;
        list2->last = newC;
        return list2;
    } else {
        for (; aux != NULL; aux = aux->next){
            if(newC->cpf == aux->cpf){
                printf("\nCPF já existente, tente novamente!");
                return list2;
            }
        } if (newC->date.year < list2->first->date.year){ //if < primeiro
            list2->first->prev = newC;
            newC->prev = NULL;
            newC->next = list2->first;
            list2->first = newC;
            return list2;
        }else if (newC->date.year > list2->last->date.year){ //if > ultimo
            list2->last->next = newC;
            newC->prev = list2->last;
            newC->next = NULL;
            list2->last = newC;
            return list2;
        }
        for (aux = list2->first; aux != NULL; aux = aux->next){
            if ((aux->date.year > newC->date.year) || (aux->date.year == newC->date.year)){// if > or = do meio
                newC->prev = aux->prev;
                aux->prev->next = newC;
                newC->next = aux;
                aux->prev = newC;
                aux = newC;
                return list2;
            }
        }
        return list2;
    }  
}

int emptyClient (Sent2 *list2) {
    if (list2->first == NULL) return 1;
    return 0;
}

void printClient (Sent2 *list2) {
    Client *aux;
    if (emptyClient(list2)) {
        printf("Nenhum cliente cadastrado!\n");
        return;
    }
    for (aux = list2->first; aux != NULL; aux = aux->next)
        printf("\n Código: %d;\n CPF: %d;\n Nome: %s;\n Data de nascimento: %d/%d/%d;\n Fiado (1-sim, 2-não): %d\n", aux->cod, aux->cpf, aux->name, aux->date.day, aux->date.month, aux->date.year, aux->fiado);   
}

int freeClient(Sent2 *list2) { 
    Client *aux = list2->first;
    int contC = 0;
    while (aux != NULL) {
        list2->first = aux->next;
        free(aux);
        contC ++;
        aux = list2->first;
    }
    return contC;
}