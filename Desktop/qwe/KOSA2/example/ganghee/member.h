#ifndef MEMBER_H
#define MEMBER_H

#define MAX_STR 100

typedef struct {
    int customerId;
    char address[MAX_STR];
    char phoneNumber[MAX_STR];
} CustomerInfo;

typedef struct {
    CustomerInfo info;
    char name[MAX_STR];
    char Code[MAX_STR];
    int point;
    int couponCount;
} Member;

#endif // MEMBER_H
