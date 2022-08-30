struct date {
    int day;
    int month;
    int year;
};
typedef struct date Date;

struct client{
    int cod;
	int cpf;
    char name[20];
    int fiado;
    Date date;
	struct client *prev, *next;
};
typedef struct client Client;

struct sent2{
    Client *first;
    Client *last;
};
typedef struct sent2 Sent2;

Client *newClient();
Sent2 *insertClient(Sent2 *list2);
int emptyClient (Sent2 *list2);
void printClient (Sent2 *list2);
int freeClient(Sent2 *list2);