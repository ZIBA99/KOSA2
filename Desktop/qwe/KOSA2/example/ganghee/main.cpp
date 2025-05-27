#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "member.h"
#include "guest.h"
#include "product.h"
#include "order.h"

void printMember(const Member* m) {
    printf("=== 회원 정보 ===\n");
    printf("고객 번호: %d\n이름: %s\n회원 코드: %s\n전화번호: %s\n주소: %s\n",
        m->info.customerId, m->name, m->Code,
        m->info.phoneNumber, m->info.address);
    printf("포인트: %d점\n쿠폰: %d장\n\n", m->point, m->couponCount);
}

void printGuest(const Guest* g) {
    printf("=== 비회원 정보 ===\n");
    printf("고객 번호: %d\n전화번호: %s\n주소: %s\n임시번호: %s\n\n",
        g->info.customerId, g->info.phoneNumber,
        g->info.address, g->tempCode);
}

void printProduct(const Product* p) {
    printf("=== 제품 정보 ===\n");
    printf("제품 번호: %d\n제품명: %s\n장르: %s\n등록일: %s\n재고: %d\n가격: %.2f원\n\n",
        p->productId, p->name, p->genre, p->registerDate,
        p->quantity, p->price);
}

int main() {
    Member member1 = {
        {1, "서울시 강남구", "010-1234-5678"},
        "홍길동",
        "MEM001",
        1200,
        3
    };

    Guest guest1 = {
        {2, "부산시 해운대구", "010-8765-4321"},
        "GUEST001"
    };

    Product product1 = {
        100, "무선 마우스", "전자기기", "2025-05-01", 50, 29900.0
    };

    int choice;

    while (1) {
        printf("=== 메인 메뉴 ===\n");
        printf("1. 회원 확인\n");
        printf("2. 신규 가입 (임시 - 회원 정보 추가)\n");
        printf("3. 비회원 확인\n");
        printf("4. 제품 확인\n");
        printf("5. 종료\n");
        printf("번호를 입력하세요: ");
        scanf("%d", &choice);

        getchar();  // 입력 버퍼 개행문자 제거

        switch (choice) {
        case 1:
            printMember(&member1);
            break;
        case 2:
            printf("신규 회원 가입 기능은 아직 구현되지 않았습니다.\n\n");
            break;
        case 3:
            printGuest(&guest1);
            break;
        case 4:
            printProduct(&product1);
            break;
        case 5:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 시도해주세요.\n\n");
        }
    }

    return 0;
}
