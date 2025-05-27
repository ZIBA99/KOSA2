#ifndef GUEST_H
#define GUEST_H

#include "member.h" // CustomerInfo 정의 포함

#define MAX_STR 100

// CustomerInfo 재정의하지 말고, member.h에서 포함하거나
// 또는 아래처럼 다른 헤더에서 선언하지 않도록 조심!
// 만약 꼭 사용한다면, 하나의 헤더에서만 CustomerInfo 선언하기! 주의!!!!!!!!

typedef struct {
    CustomerInfo info; // 이제 CustomerInfo가 올바르게 인식됩니다.
    char tempCode[MAX_STR];
} Guest;

#endif // GUEST_H
