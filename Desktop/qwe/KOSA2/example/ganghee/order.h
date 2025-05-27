#ifndef ORDER_H
#define ORDER_H

typedef struct {
    int customerId;
    int productId;
    char purchaseDate[20];
    char deliveryDate[20];
} Order;

#endif // ORDER_H
