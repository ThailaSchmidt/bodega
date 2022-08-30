#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "company.h"

void *printCompany () {
    Company *comp;
    comp = (Company*)malloc(sizeof(Company));
    printf("Digite o nome da bodega:\n");
    scanf("%s", comp->name);
    printf("Digite o cnpj da bodega:\n");
    scanf("%s", comp->cnpj);
    printf("\n%s\n\n%s\n\n", comp->name, comp->cnpj);
} 