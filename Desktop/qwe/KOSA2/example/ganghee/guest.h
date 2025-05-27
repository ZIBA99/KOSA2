#ifndef GUEST_H
#define GUEST_H

#include "member.h" // CustomerInfo ���� ����

#define MAX_STR 100

// CustomerInfo ���������� ����, member.h���� �����ϰų�
// �Ǵ� �Ʒ�ó�� �ٸ� ������� �������� �ʵ��� ����!
// ���� �� ����Ѵٸ�, �ϳ��� ��������� CustomerInfo �����ϱ�! ����!!!!!!!!

typedef struct {
    CustomerInfo info; // ���� CustomerInfo�� �ùٸ��� �νĵ˴ϴ�.
    char tempCode[MAX_STR];
} Guest;

#endif // GUEST_H
