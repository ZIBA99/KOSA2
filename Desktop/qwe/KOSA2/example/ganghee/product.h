#ifndef PRODUCT_H
#define PRODUCT_H

#define MAX_STR 100

typedef struct {
    int productId;
    char name[MAX_STR];
    char genre[MAX_STR];
    char registerDate[20];
    int quantity;
    double price;
} Product;

#endif // PRODUCT_H