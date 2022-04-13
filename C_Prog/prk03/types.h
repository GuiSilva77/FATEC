struct table {
    char *header;
    struct node *debt;
    struct node *credit;
};

struct node {
    float value;
    struct node *ant;
    struct node *prox;
};

struct date {
    int year;
    int month;
    int day;
};

struct launch
{
    float value;
    char account;
};

struct diary_node {
    struct date date;
    struct launch debt;
    struct launch credit;
};

struct diary_book {
    char* header;
    struct diary_node *accounts;
};

struct tbanco_dados {
    struct table *Cx;
    struct table *bank;

    struct diary_book diary;
};

typedef struct tbanco_dados banco_dados;
