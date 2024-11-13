---
title: 단방향 링크드 리스트
description: 자료구조의 기초 이론을 학습합니다
slug: data-structure-singly-linked-list
date: 2024-10-28
categories:
  - data_structure
tags: 
  - theory
  - computer science
---

# 링크드 리스트와 단방향 링크드 리스트

링크드 리스트(Linked List)는 데이터가 노드(Node) 단위로 연결된 자료구조로, 각 노드가 다음 노드의 주소를 저장하여 연속적인 데이터를 관리하는 방식이다. 배열과는 달리, 링크드 리스트는 동적 메모리 할당을 통해 크기가 고정되지 않고 필요에 따라 조정할 수 있어 유연한 데이터 구조로 평가된다. 특히, 데이터의 삽입과 삭제가 빈번한 경우 유리하게 사용할 수 있다.

이번 섹션에서는 링크드 리스트와 그 중에서도 단방향 링크드 리스트(Singly Linked List)의 개념, 구조, 그리고 주요 특징을 상세히 설명한다.

---

### 링크드 리스트(Linked List)의 개념

링크드 리스트는 **각 노드가 서로 연결**된 형태의 자료구조로, 각 노드는 데이터를 저장하는 **데이터 필드**와 다음 노드를 가리키는 **포인터 필드**로 구성된다. 이때, 각 노드는 다음 노드를 가리키는 방식으로 서로 연결되며, 링크드 리스트의 시작점은 **헤드\(Head\)**라는 첫 번째 노드로 관리된다.

링크드 리스트는 메모리 상에서 **비연속적으로** 배치될 수 있다. 즉, 각 노드는 메모리의 어디에 위치해도 상관없으며, 노드 간 연결이 주소를 통해 이루어지기 때문에 자유로운 메모리 할당과 해제가 가능하다.

#### 링크드 리스트의 주요 특징

1. **동적 크기 조정**: 링크드 리스트는 필요에 따라 노드를 추가하거나 제거할 수 있어 크기가 고정되지 않는다.
2. **비연속적 메모리 할당**: 각 노드가 독립적으로 메모리 공간을 차지하며, 메모리 상에서 인접해 있을 필요가 없다.
3. **삽입과 삭제의 용이성**: 배열과 달리 중간에 요소를 삽입하거나 삭제할 때 데이터의 이동이 필요하지 않다.
4. **탐색 속도**: 링크드 리스트는 원하는 위치의 데이터를 찾기 위해 처음부터 순차적으로 접근해야 하므로, 배열에 비해 탐색 속도가 느릴 수 있다.

---

### 단방향 링크드 리스트(Singly Linked List)란?

단방향 링크드 리스트는 링크드 리스트의 한 유형으로, **한 방향**으로만 탐색이 가능한 자료구조이다. 각 노드에는 다음 노드의 주소를 저장하는 포인터가 포함되어 있으며, 이전 노드의 주소는 저장되지 않는다. 즉, 단방향 링크드 리스트는 첫 번째 노드에서 시작하여 마지막 노드까지 **단방향으로만 이동**할 수 있는 구조를 가진다.

#### 단방향 링크드 리스트의 구성 요소

1. **노드\(Node\)**: 단방향 링크드 리스트의 기본 단위로, 각 노드는 데이터를 저장하는 `데이터 필드(data)`와 다음 노드를 가리키는 `포인터 필드(next)`를 포함한다.
   - **데이터 필드**: 노드에 저장할 실제 데이터 값이다.
   - **포인터 필드\(next\)**: 다음 노드의 주소를 저장하는 포인터로, 이 포인터를 통해 다음 노드로 이동할 수 있다.

2. **헤드\(Head\)**: 리스트의 첫 번째 노드를 가리키는 포인터이다. 단방향 링크드 리스트에서 리스트의 시작점을 나타내며, 리스트 탐색 및 노드 추가/삭제의 기준이 된다.

#### 단방향 링크드 리스트의 주요 특징

- **단방향 연결**: 단방향 링크드 리스트는 한 방향으로만 탐색할 수 있다. 이전 노드로 이동하는 것은 불가능하며, 항상 다음 노드로만 이동 가능하다.
- **끝 노드\(Tail Node\)**: 단방향 링크드 리스트의 끝 노드는 `next` 포인터가 `nullptr`을 가리키며, 리스트의 끝을 나타낸다.
- **탐색의 제한**: 노드가 한 방향으로만 연결되므로, 리스트의 특정 위치에 접근하려면 처음 노드부터 순차적으로 이동해야 한다.

---

### 3. 단방향 링크드 리스트의 주요 연산

단방향 링크드 리스트는 다음과 같은 연산을 통해 노드의 삽입, 삭제, 탐색을 수행할 수 있다.

1. **노드 삽입**:
   - **리스트 시작에 삽입**: 새로운 노드를 리스트의 첫 번째 위치(헤드)로 삽입한다.
   - **리스트 끝에 삽입**: 새로운 노드를 리스트의 마지막에 추가한다.
   - **특정 위치에 삽입**: 특정 위치에 새로운 노드를 삽입하기 위해 해당 위치까지 순차적으로 탐색한 후 삽입한다.

2. **노드 삭제**:
   - **리스트 시작에서 삭제**: 첫 번째 노드(헤드)를 삭제하고, 두 번째 노드를 새로운 헤드로 만든다.
   - **리스트 끝에서 삭제**: 마지막 노드를 제거하기 위해 리스트 끝까지 탐색한 후 삭제한다.
   - **특정 위치의 노드 삭제**: 특정 위치의 노드를 삭제하기 위해 해당 위치까지 이동하여 노드를 제거한다.

3. **노드 탐색**: 단방향 링크드 리스트는 특정 값을 가진 노드를 찾기 위해 **헤드부터 순차적으로** 탐색해야 한다. 이 과정은 리스트 길이에 따라 비례하므로, 최악의 경우 **O\(n\)**의 시간 복잡도를 가진다.

---

### 단방향 링크드 리스트의 장점과 단점

#### 장점
1. **동적 메모리 할당**: 메모리를 미리 예약하지 않고 필요한 시점에 동적으로 할당하므로 메모리 사용이 유연하다.
2. **삽입 및 삭제의 용이성**: 배열과 달리 노드의 삽입/삭제 시 메모리 재배치가 필요하지 않아 빠르게 수행할 수 있다.
3. **메모리 절약**: 필요한 시점에만 메모리를 할당하고, 사용하지 않는 노드는 제거하여 메모리 낭비를 줄일 수 있다.

#### 단점
1. **느린 탐색 속도**: 단방향 연결 구조로 인해 특정 요소에 접근하려면 처음부터 순차적으로 탐색해야 한다.
2. **추가 메모리 사용**: 각 노드가 데이터 외에 포인터 필드를 포함하므로 배열에 비해 추가적인 메모리 공간이 필요하다.
3. **역방향 탐색 불가**: 단방향 링크드 리스트는 한 방향으로만 탐색할 수 있어, 역방향 탐색이 불가능하다.

---

### 단방향 링크드 리스트의 예제 구현 (C++)

다음은 C++로 단방향 링크드 리스트를 구현한 코드로, 리스트의 노드 삽입, 삭제, 탐색 기능을 포함한다.

```cpp
#include <iostream>
using namespace std;

// 노드 클래스 정의
class Node {
public:
    int data;         // 데이터 저장
    Node* next;       // 다음 노드를 가리키는 포인터

    // 생성자
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// 링크드 리스트 클래스 정의
class LinkedList {
private:
    Node* head;       // 헤드 노드를 가리키는 포인터

public:
    // 생성자 - 빈 리스트로 초기화
    LinkedList() {
        head = nullptr;
    }

    // 리스트 끝에 노드 추가
    void append(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 리스트 시작에 노드 추가
    void prepend(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // 특정 인덱스의 노드 삭제
    void deleteAtIndex(int index) {
        if (head == nullptr || index < 0) {
            cout << "인덱스가 유효하지 않습니다." << endl;
            return;
        }

        // 첫 번째 노드를 삭제하는 경우
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            if (temp == nullptr || temp->next == nullptr) {
                cout << "인덱스가 범위를 초과했습니다." << endl;
                return;
            }
            temp = temp->next;
        }

        // 삭제할 노드가 존재하는지 확인
        if (temp->next == nullptr) {
            cout << "인덱스가 범위를 초과했습니다." << endl;
            return;
        }

        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        delete deleteNode;
    }

    // 특정 값의 노드 삭제
    void deleteValue(int value) {
        if (head == nullptr) return;

        // 헤드 노드를 삭제해야 하는 경우
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // 중간 노드를 삭제하는 경우
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) return; // 해당 값이 없는 경우

        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        delete deleteNode;
    }

    // 리스트의 크기 계산
    int size() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // 리스트 출력
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);
    list.prepend(5);

    cout << "초기 리스트: ";
    list.display();

    cout << "리스트 크기: " << list.size() << endl;

    list.deleteAtIndex(2);
    cout << "인덱스 2의 노드 삭제 후 리스트: ";
    list.display();

    cout << "리스트 크기: " << list.size() << endl;

    return 0;
}
```

### 코드 설명
- **Node 클래스**: Node 클래스는 링크드 리스트의 각 노드를 나타내며, 데이터와 다음 노드를 가리키는 포인터(next)를 포함한다.

- **LinkedList 클래스**: LinkedList 클래스는 단방향 링크드 리스트를 나타내며, 노드 추가(append, prepend), 노드 삭제(deleteAtIndex, deleteValue), 리스트 출력(display) 등의 기능을 제공한다.

- **메인 함수**: 리스트에 노드를 추가하고, 삭제한 후 리스트를 출력하여 결과를 확인한다.

---

단방향 링크드 리스트는 동적 메모리 할당이 필요한 프로그램이나 삽입/삭제가 빈번한 데이터 구조에서 유용하게 활용된다. 공학도로서 링크드 리스트의 핵심 개념을 이해하고, 이러한 자료구조를 구현하는 방법을 익히는 것은 효율적인 메모리 관리와 데이터 구조 설계의 기초가 된다.