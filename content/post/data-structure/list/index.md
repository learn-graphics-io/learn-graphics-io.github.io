---
title: "자료구조: 링크드 리스트"
description: 리스트(List) 형식의 자료구조를 학습합니다
slug: data-structure-linkedlist
date: 2024-10-26
categories:
  - data_structure
tags: 
  - theory
  - computer science
---

# 리스트(List)
리스트는 그 이름에서 유추할 수 있듯이 목록 형태로 이루어진 자료구조입니다. 리스트의 목록을 이루는 개별 요소는 노드(Node)라고 부릅니다.
특히 첫 번째 노드는 헤드(Head), 마지막 노드는 테일(Tail)이라고 부릅니다. 리스트의 길이는 헤드부터 테일까지 이르는 노드 개수와 동일합니다.
```c++
[Node 1 (Head)] -> [Node 2] -> [Node 3] -> ... -> [Node N - 1] -> [Node N (Tail)]
```

# 리스트와 배열
배열은 리스트처럼 데이터 목록을 다루며, C++ 언어에서 기본적으로 제공하기 때문에 프로그래머가 따로 구현하지 않아도 됩니다.
그러나 배열은 생성하는 시점에 반드시 극 크기를 지정하여야 하고 생성한 후에는 그 크기를 변경할 수 없다는 단점이 있습니다.
이러한 한계를 극복하기 위해 필요한 것이 배열처럼 데이터 집합 보관 기능을 가지면서도 배열과 달리 유연하게 크기를 바꿀 수 있는 자료구조입니다.
그것이 바로 리스트입니다.

# 링크드 리스트(Linked List)

## 링크드 리스트 구조
링크드 리스트는 리스트를 구현하는 여러 가지 기법 중에서도 가장 간단한 방법입니다. 링크드 리스트는 `노드를 연결해서 만든 리스트`입니다.
링크드 리스트의 노드는 다음과 같이 데이터를 보관하는 필드, 다음 노드와 연결 고리 역할을 하는 포인터로 이루어집니다.
```c++
[ Data | Next ] -> [ Data | Next ] -> [ Data | Next ] -> NULL
```

이와 같이 다뤄야 하는 데이터 집합의 크기를 미리 알지 못해도, 데이터가 늘어날 때마다 노드를 만들어 테일에 붙이면 자유롭게 데이터를 추가할 수 있습니다.
리스트 사이에 데이터를 끼워넣거나, 제거하기도 아주 간단합니다. 해당 노드를 가리키는 포인터를 제거함으로 데이터의 삽입과 제거를 수행할 수 있습니다.

## 링크드 리스트의 장단점
장점
- 새로운 노드의 추가, 삽입, 삭제가 쉽고 빠릅니다.

단점
- 다음 노드를 가리키려는 포인터 때문에 각 노드마다 추가적인 메모리가 필요합니다.
- 특정 위치에 있는 노드에 접근하기 위한 비용이 크며, 접근하기까지 시간도 많이 소요됩니다. 마지막 노드에 접근하기 위해서는 모든 노드를 순회하여야 합니다.

정리해보면, 링크드 리스트는 `노드의 추가, 삽입, 삭제 연산은 빠르지만 특정 위치에 있는 노드에 접근하는 연산은 느린 것`이라고 할 수 있습니다.
따라서 링크드 리스트는 노드의 추가, 삽입, 삭제가 빈번하지만 조회는 드문 곳에서 사용하기 적합합니다.
예를 들어, 데이터베이스에서 조회해온 레코드를 순차적으로 다루는데 적합할 수 있습니다.

## 링크드 리스트의 노드 표현
링크드 리스트를 구현하도록 하겠습니다. 링크드 리스트의 노드를 C++로 표현하면 다음과 같은 구조체로 나타낼 수 있습니다.
```c++
struct Node 
{
    int data;
    Node* next;
    
    Node(int value) : data(value), next(nullptr) {}
};
```

## 링크드 리스트 클래스
링크드 리스트 자료구조의 생성과 삭제 그리고 시작 노드를 표현할 클래스를 생성합니다.

```c++
class LinkedList
{

private:
    Node* head; // 헤드 노드

public:
    // 생성자: 링크드 리스트 생성
    LinkedList() : head(nullptr) {} 
    
    // 소멸자: 링크드 리스트의 모든 노드를 삭제
    ~LinkedList() 
    { 
        Node* current = head;
        while(current != nullptr) // 헤드 노드부터 모든 노드를 순회하여, 노드를 힙 메모리에서 해제합니다.
        { 
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
}
```

## 링크드 리스트의 주요 연산
다음으로 링크드 리스트가 어떤 연산을 가져야 할지 생각해봅시다. 링크드 리스트에는 두 종류의 연산이 필요합니다. 
첫 번재는 자료구조를 구축하기 위한 연산이고, 두 번째는 자료구조에 저장된 데이터를 활용하기 위한 연산입니다.
그 종류는 다음과 같습니다
- 노드 추가
- 노드 탐색
- 노드 삭제
- 노드 삽입

### 노드 길이 연산
먼저 노드의 길이를 확인하는 연산을 구현합니다. 전체 노드의 수를 세고 그 값을 반환합니다.
```c++
class LinkedList
{
public:
    // 노드 길이: 모든 노드를 순회하여 측정한 길이를 반환
    int size()
    {
        int size = 0;
        Node* current = head;
        while(current != nullptr) // 현재 노드가 nullptr 값이 될 때까지 반복
        {
            current = current->next; // 현재 노드를 다음 노드로 설정
            size++; // 길이를 1 증가
        }
        return size;
    }
}
```

### 노드 추가 연산
링크드 리스트에 노드를 추가하는 연산을 구현합니다. Node 구조체의 데이터 변수의 타입에 해당하는 데이터를 추가하면, Node 구조체를 생성하고 그것을 테일에 부착합니다.
```c++
class LinkedList
{

public:
    // 노드 추가: 리스트의 끝에 노드를 생성하여 추가
    void add(int data) 
    {
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
}
```

### 노드 제거 연산
링크드 리스트의 노드를 제거하는 연산을 구현합니다. 링크드 리스트에서 제거할 인덱스의 번호를 입력받으면, 인덱스 번호에 해당하는 노드를 제거합니다.
```c++
class LinkedList
{
public:
    // 노드 제거: 입력한 인덱스에 해당하는 노드 제거
    void remove(int index) 
    {
        if (head == nullptr) // 헤드 노드가 없다면 중단
        {
            return;
        }
        
        int size = size(); // 링크드 리스트의 사이즈를 체크하여 입력받은 인덱스가 유효한 값인지 확인
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
}
```

### 노드 탐색 연산
링크드 리스트의 노드를 탐색하는 연산을 구현합니다. 링크드 리스트의 인덱스 번호를 입력받으면, 인덱스 번호에 해당하는 노드를 반환합니다.
```c++
class LinkedList
{
public:
    // 노드 탐색: 입력한 인덱스에 해당하는 노드 반환
    Node* get(int index) 
    {
        if (head == nullptr) // 헤드 노드가 없다면 중단
        {
            return nullptr;
        }
    
        int size = size(); // 링크드 리스트의 사이즈를 체크하여 입력받은 인덱스가 유효한 값인지 확인
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
}
```

### 노드 삽입 연산
링크드 리스트에 노드를 삽입하는 연산을 구현합니다. 링크드 리스트의 인덱스 번호와 추가할 데이터를 입력받으면, Node 구조체를 생성하고 그것을 인덱스 위치에 추가합니다.
```c++
class LinkedList
{
public:
    // 노드 삽입: 입력한 인덱스에 새로운 노드를 생성하여 삽입
    void add(int index, int data)
    {
        if (head == nullptr) // 헤드 노드가 없다면 중단
        {
            return;
        }
        
        int size = size(); // 링크드 리스트의 사이즈를 체크하여 입력받은 인덱스가 유효한 값인지 확인
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
```

## 정리
구현한 모든 기능을 합하여 실행해 볼 수 있습니다. 다음 코드를 다운로드 하여 직접 실행해 봅시다.
- [LinkedList.h](./LinkedList.h)
- [LinkedList.cpp](./LinkedList.cpp)
- [main.cpp](./main.cpp)


> [이전글: 자료구조](https://learngraphics.io/p/data-structure-intro/)
  
> [다음글: 자료구조: 더블 링크드 리스트](https://learngraphics.io/p/data-structure-double-linkedlist/)