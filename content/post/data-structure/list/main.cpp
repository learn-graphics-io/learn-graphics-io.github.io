#include <iostream>
#include "LinkedList.h"

using namespace DataStructure;

int main() {

    // 새로운 링크드 리스트 생성
    LinkedList* list = new LinkedList();
    std::cout << "Create LinkedList" << std::endl;
    std::cout << "Size: " << list->size() << std::endl;

    std::cout << std::endl;

    // 링크드 리스트에 데이터 추가
    std::cout << "Add data to LinkedList" << std::endl;
    for (int i = 0; i < 5; ++i) {
        list->add(i);
    }
    std::cout << "Size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); ++i) {
        std::cout << "Index: " << i << ", Value: " << list->get(i)->data << std::endl;
    }

    std::cout << std::endl;

    // 링크드 리스트에 새로운 데이터 추가
    std::cout << "Add data to LinkedList" << std::endl;
    list->add(1000);
    list->add(2000);
    std::cout << "Size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); ++i) {
        std::cout << "Index: " << i << ", Value: " << list->get(i)->data << std::endl;
    }

    std::cout << std::endl;

    // 링크드 리스트에서 데이터 제거
    std::cout << "Remove data from LinkedList" << std::endl;
    for (int i = 0; i < 4; ++i) {
        list->remove(list->size() - (i + 1));
    }
    std::cout << "Size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); ++i) {
        std::cout << "Index: " << i << ", Value: " << list->get(i)->data << std::endl;
    }

    std::cout << std::endl;

    // 링크드 리스트에 데이터 삽입
    std::cout << "Insert data to LinkedList" << std::endl;
    for (int i = 0; i < list->size(); ++i) {
        if (i % 2 == 0) {
            list->add(i, 7777);
        }
    }
    std::cout << "Size: " << list->size() << std::endl;
    for (int i = 0; i < list->size(); ++i) {
        std::cout << "Index: " << i << ", Value: " << list->get(i)->data << std::endl;
    }

    std::cout << std::endl;

    // 링크드 리스트 제거
    std::cout << "Delete LinkedList" << std::endl;
    delete list;

    return 0;
}
