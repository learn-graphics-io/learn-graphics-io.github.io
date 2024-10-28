//
// Created by lede7 on 2024-10-28.
//

#ifndef DATASTRUCTURE_LINKEDLIST_H
#define DATASTRUCTURE_LINKEDLIST_H


namespace DataStructure {
    struct Node
    {
        int data;
        Node* next;

        explicit Node(int value) : data(value), next(nullptr) {}
    };

    class LinkedList {
    private:
        Node* head; // 헤드 노드

    public:
        // 생성자: 링크드 리스트 생성
        LinkedList() : head(nullptr) {}

        // 소멸자: 링크드 리스트의 모든 노드를 삭제
        virtual ~LinkedList();

        // 노드 길이: 모든 노드를 순회하여 측정한 길이를 반환
        int size();

        // 노드 추가: 리스트의 끝에 노드를 생성하여 추가
        void add(int data);

        // 노드 삽입: 입력한 인덱스에 새로운 노드를 생성하여 삽입
        void add(int index, int data);

        // 노드 제거: 입력한 인덱스에 해당하는 노드 제거
        void remove(int index);

        // 노드 탐색: 입력한 인덱스에 해당하는 노드 반환
        Node* get(int index);
    };
}


#endif //DATASTRUCTURE_LINKEDLIST_H
