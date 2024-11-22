#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef struct NODE {
    int key;
    struct NODE* next;
} NODE;

// pop push empty full print 함수
// int void int int  void

int count = 0;
NODE* top = NULL;

int empty(){ // 스택 메모리에 값이 비어있는 경우
    if(top == NULL)
        return 1;
    return 0;
}

int full(){ // 스택 메모리가 다 찬 경우
    if(count >= MAX_STACK_SIZE)
        return 1;
    return 0;
}

void push(int val){
    //스택 공간 부족한 경우
    if(full()){
        printf("stack is full. value %d can't push in stack\n", val);
        return;
    }

    NODE* new_node = (NODE*)malloc(sizeof(struct NODE)); // 동적 메모리 생성
    if(new_node == NULL){
        printf("memory allocation failed\n");
        return;
    }
    // 스택에 입력된 값 저장, 링크드 리스트 형성
    new_node -> key = val;
    new_node -> next = top;
    top = new_node;
    count++;
}

void pop(){
    // 스택에 저장된 값이 없는 경우
    if(empty()){
        printf("there are no nodes to delete\n");
        return;
    }
    
    // 임시 구조체 포인터 변수 생성, top이 가리키는 삭재할 노드값을 free()시킨 후, 
    // 삭재된 노드의 다음 구조체를 top이 가리키도록 한다
    NODE* temp = top;
    int value = temp->key; // 삭제될 값 저장
    top = temp->next;      // top을 다음 노드로 이동
    free(temp);            // 메모리 해제
    count--;
    printf("value %d is poped in stack\n", value);
}

void print_stack(){ //스택값 모두 출력
    NODE* temp = top;
    while(temp){
        printf("%d ", temp -> key);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    int val, menu_n;
    
    while(1){
        printf("\n ---menu---\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. print stack\n");
        printf("0. exit program\n");
        printf("choice menu: ");
        scanf("%d", &menu_n);

        switch (menu_n)
        {
        case 1:
            printf("Enter the value to push in stack: ");
            scanf("%d", &val);
            push(val);
            break;
        case 2:
            pop();
            break;
        case 3:
            print_stack();
            break;
        case 0:
            return 0;
        default:
            printf("Incorrect input value\n");
            break;
        }

    }
    return 0;
}