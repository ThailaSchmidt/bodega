#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "drink.h"
#include "cliente.h"
#include "company.h"

int main(void) {
    Sent *list;
    Sent2 *list2;
    list = (Sent *)malloc(sizeof(Sent));
    list2 = (Sent2 *)malloc(sizeof(Sent2));
    printCompany(); 
    int menu;
    while(1==1) {
        printf("\n\nMENU:\n\n");
        printf("1. Cadastrar Bebida: \n");
        printf("2. Mostrar Bebidas: \n");
        printf("3. Comprar Bebida: \n");
        printf("4. Vender Bebida: \n");
        printf("5. Cadastrar Cliente: \n");
        printf("6. Mostrar Cliente: \n");
        printf("7. Sair do Sistema: \n");
        scanf("%d", &menu);
        
        if(menu == 1) list = insertDrink(list);
        else if (menu == 2) printDrink(list);
        else if (menu == 3) buyDrink(list);
        else if (menu == 4) sellDrink(list, list2);
        else if (menu == 5) list2 = insertClient(list2);
        else if (menu == 6) printClient(list2);
        else if (menu == 7) break;
        else printf("Opção Inválida!");
    }
    if (!emptyDrink(list) || !emptyClient(list2)) {
        int cont = freeDrink(list) + freeClient(list2);
        printf("\n%d elementos liberados.\n", cont);
    }
    printf("\nEnd.\n");
    return 0;
}