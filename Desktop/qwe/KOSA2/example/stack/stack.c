#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // 스택의 최대 크기

int stack[MAX];
int top = -1;  // 스택이 비어 있음을 의미

// 스택이 가득 찼는지 확인
int isFull() {
    return top == MAX - 1;
}

// 스택이 비어 있는지 확인
int isEmpty() {
    return top == -1;
}

// Push 함수: 스택에 데이터 삽입
void push(int value) {
    if (isFull()) {
        printf("스택이 가득 찼습니다.\n");
        return;
    }
    stack[++top] = value;
    printf("%d를 스택에 추가했습니다.\n", value);
}

// Pop 함수: 스택에서 데이터 제거
int pop() {
    if (isEmpty()) {
        printf("스택이 비어 있습니다.\n");
        return -1;
    }
    return stack[top--];
}

// Peek 함수: 스택의 최상단 값을 반환
int peek() {
    if (isEmpty()) {
        printf("스택이 비어 있습니다.\n");
        return -1;
    }
    return stack[top];
}

// 메인 함수: 스택 테스트
int main() {
    push(10);
    push(20);
    push(30);

    printf("현재 스택의 top 값: %d\n", peek());

    printf("스택에서 pop: %d\n", pop());
    printf("스택에서 pop: %d\n", pop());

    push(40);
    printf("현재 스택의 top 값: %d\n", peek());

    return 0;
}
