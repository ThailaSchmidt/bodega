
struct drink{
	int cod;
    char name[20];
    int ml;
    double price;
    int inventory;
    int alcoholic;
	struct drink *prev, *next;
};
typedef struct drink Drink;

struct sent{
    Drink *first;
    Drink *last;
};
typedef struct sent Sent;

Drink *newDrink();
Sent *insertDrink(Sent *list);
Sent *buyDrink(Sent *list);
int emptyDrink (Sent *list);
void printDrink (Sent *list);
int freeDrink(Sent *list);