#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // ������ �ִ� ũ��

int stack[MAX];
int top = -1;  // ������ ��� ������ �ǹ�

// ������ ���� á���� Ȯ��
int isFull() {
    return top == MAX - 1;
}

// ������ ��� �ִ��� Ȯ��
int isEmpty() {
    return top == -1;
}

// Push �Լ�: ���ÿ� ������ ����
void push(int value) {
    if (isFull()) {
        printf("������ ���� á���ϴ�.\n");
        return;
    }
    stack[++top] = value;
    printf("%d�� ���ÿ� �߰��߽��ϴ�.\n", value);
}

// Pop �Լ�: ���ÿ��� ������ ����
int pop() {
    if (isEmpty()) {
        printf("������ ��� �ֽ��ϴ�.\n");
        return -1;
    }
    return stack[top--];
}

// Peek �Լ�: ������ �ֻ�� ���� ��ȯ
int peek() {
    if (isEmpty()) {
        printf("������ ��� �ֽ��ϴ�.\n");
        return -1;
    }
    return stack[top];
}

// ���� �Լ�: ���� �׽�Ʈ
int main() {
    push(10);
    push(20);
    push(30);

    printf("���� ������ top ��: %d\n", peek());

    printf("���ÿ��� pop: %d\n", pop());
    printf("���ÿ��� pop: %d\n", pop());

    push(40);
    printf("���� ������ top ��: %d\n", peek());

    return 0;
}
