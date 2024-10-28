//
// Created by lede7 on 2024-10-28.
//

#include "LinkedList.h"

namespace DataStructure
{
    LinkedList::~LinkedList() {
        Node* current = head;
        while(current != nullptr) // 헤드 노드부터 모든 노드를 순회하여, 노드를 힙 메모리에서 해제합니다.
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    int LinkedList::size() {
        int size = 0;
        Node* current = head;
        while(current != nullptr) // 현재 노드가 nullptr 값이 될 때까지 반복
        {
            current = current->next; // 현재 노드를 다음 노드로 설정
            size++; // 길이를 1 증가
        }
        return size;
    }

    void LinkedList::add(int data) {
        Node* node = new Node(data); // 새로운 노드를 힙 메모리에 생성
        if (head == nullptr) // 헤드 노드가 없다면 생성한 노드를 헤드로 설정
        {
            head = node;
            return;
        }

        // 헤드 노드가 존재한다면, 모든 노드를 순회하여 마지막에 새로운 테일 노드를 추가
        Node* current = head;
        while(current->next != nullptr)
        {
            current = current->next;
        }
        current->next = node;
    }

    void LinkedList::remove(int index) {
        if (head == nullptr) // 헤드 노드가 없다면 중단
        {
            return;
        }

        int size = LinkedList::size(); // 링크드 리스트의 사이즈를 체크하여 입력받은 인덱스가 유효한 값인지 확인
        if (index < 0 || index >= size) // 사이즈는 유효 인덱스 + 1의 값을 갖음
        {
            return;
        }

        if (index == 0) // 첫번째 노드를 제거하는 경우
        {
            Node* temp = head; // 헤드 노드를 임시 저장
            head = head->next; // 헤드 노드를 다음 노드로 설정
            delete temp; // 헤드 노드 제거
            return;
        }

        // 나머지 노드를 제거하는 경우
        Node* prev = nullptr;
        Node* current = head;
        while(index > 0) // 인덱스가 목표 인덱스에 도달할 때까지 탐색
        {
            prev = current;
            current = current->next;
            index--;
        } // 목표 인덱스의 노드에 도달했다면 탐색 종료

        prev->next = current->next; // 이전 노드의 다음 노드를, 제거하려는 노드의 다음 노드로 설정
        delete current; // 탐색한 노드 제거
    }

    Node* LinkedList::get(int index) {
        if (head == nullptr) // 헤드 노드가 없다면 중단
        {
            return nullptr;
        }

        int size = LinkedList::size(); // 링크드 리스트의 사이즈를 체크하여 입력받은 인덱스가 유효한 값인지 확인
        if (index < 0 || index >= size) // 사이즈는 유효 인덱스 + 1의 값을 갖음
        {
            return nullptr;
        }

        Node* current = head; // 헤드 노드부터 시작
        while(index > 0) // 인덱스가 목표 인덱스에 도달할 때까지 탐색
        {
            current = current->next; // 현재 노드를 다음 노드로 설정
            index--;
        }

        return current; // 탐색한 노드를 반환
    }

    void LinkedList::add(int index, int data) {
        if (head == nullptr) // 헤드 노드가 없다면 중단
        {
            return;
        }

        int size = LinkedList::size(); // 링크드 리스트의 사이즈를 체크하여 입력받은 인덱스가 유효한 값인지 확인
        if (index < 0 || index >= size) // 사이즈는 유효 인덱스 + 1의 값을 갖음
        {
            return;
        }

        Node* node = new Node(data); // 새로운 노드 생성
        if (index == 0) { // 헤드 노드에 데이터를 추가하는 경우
            node->next = head; // 새로운 노드의 다음 노드를 헤드 노드로 설정
            head = node; // 헤드 노드를 새로운 노드로 설정
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        while(index > 0) // 인덱스가 목표 인덱스에 도달할 때까지 탐색
        {
            prev = current; // 이전 노드를 현재 노드로 설정
            current = current->next; // 현재 노드를 다음 노드로 설정
            index--;
        }

        prev->next = node; // 이전 노드의 다음 노드를 새로운 노드로 설정
        node->next = current; // 새로운 노드의 다음 노드를 현재 노드로 설정
    }

}