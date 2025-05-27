#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "member.h"
#include "guest.h"
#include "product.h"
#include "order.h"

void printMember(const Member* m) {
    printf("=== ȸ�� ���� ===\n");
    printf("�� ��ȣ: %d\n�̸�: %s\nȸ�� �ڵ�: %s\n��ȭ��ȣ: %s\n�ּ�: %s\n",
        m->info.customerId, m->name, m->Code,
        m->info.phoneNumber, m->info.address);
    printf("����Ʈ: %d��\n����: %d��\n\n", m->point, m->couponCount);
}

void printGuest(const Guest* g) {
    printf("=== ��ȸ�� ���� ===\n");
    printf("�� ��ȣ: %d\n��ȭ��ȣ: %s\n�ּ�: %s\n�ӽù�ȣ: %s\n\n",
        g->info.customerId, g->info.phoneNumber,
        g->info.address, g->tempCode);
}

void printProduct(const Product* p) {
    printf("=== ��ǰ ���� ===\n");
    printf("��ǰ ��ȣ: %d\n��ǰ��: %s\n�帣: %s\n�����: %s\n���: %d\n����: %.2f��\n\n",
        p->productId, p->name, p->genre, p->registerDate,
        p->quantity, p->price);
}

int main() {
    Member member1 = {
        {1, "����� ������", "010-1234-5678"},
        "ȫ�浿",
        "MEM001",
        1200,
        3
    };

    Guest guest1 = {
        {2, "�λ�� �ؿ�뱸", "010-8765-4321"},
        "GUEST001"
    };

    Product product1 = {
        100, "���� ���콺", "���ڱ��", "2025-05-01", 50, 29900.0
    };

    int choice;

    while (1) {
        printf("=== ���� �޴� ===\n");
        printf("1. ȸ�� Ȯ��\n");
        printf("2. �ű� ���� (�ӽ� - ȸ�� ���� �߰�)\n");
        printf("3. ��ȸ�� Ȯ��\n");
        printf("4. ��ǰ Ȯ��\n");
        printf("5. ����\n");
        printf("��ȣ�� �Է��ϼ���: ");
        scanf("%d", &choice);

        getchar();  // �Է� ���� ���๮�� ����

        switch (choice) {
        case 1:
            printMember(&member1);
            break;
        case 2:
            printf("�ű� ȸ�� ���� ����� ���� �������� �ʾҽ��ϴ�.\n\n");
            break;
        case 3:
            printGuest(&guest1);
            break;
        case 4:
            printProduct(&product1);
            break;
        case 5:
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ����ּ���.\n\n");
        }
    }

    return 0;
}
