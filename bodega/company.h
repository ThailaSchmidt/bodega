struct company{
	char cnpj[20];
    char name[20];
	struct company *prev, *next;
};
typedef struct company Company;

void *printCompany ();