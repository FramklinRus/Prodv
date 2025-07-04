#include <catch2/catch_test_macros.hpp>
#include<catch2/catch_session.hpp>
#include <cstdint>

//����������� �������
//uint32_t factorial(uint32_t number) {
//    return number <= 1 ? number : factorial(number - 1) * number;
//}
#include <iostream>

struct ListNode
{
public:
    ListNode(int value, ListNode* prev = nullptr, ListNode* next = nullptr)
        : value(value), prev(prev), next(next)
    {
        if (prev != nullptr) prev->next = this;
        if (next != nullptr) next->prev = this;
    }

public:
    int value;
    ListNode* prev;
    ListNode* next;
};


class List
{
public:
    List()
        : m_head(new ListNode(static_cast<int>(0))), m_size(0),
        m_tail(new ListNode(0, m_head))
    {
    }

    virtual ~List()
    {
        Clear();
        delete m_head;
        delete m_tail;
    }

    bool Empty() { return m_size == 0; }

    unsigned long Size() { return m_size; }

    void PushFront(int value)
    {
        new ListNode(value, m_head, m_head->next);
        ++m_size;
    }

    void PushBack(int value)
    {
        new ListNode(value, m_tail->prev, m_tail);
        ++m_size;
    }

    int PopFront()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_head->next->next);
        int ret = node->value;
        delete node;
        return ret;
    }

    int PopBack()
    {
        if (Empty()) throw std::runtime_error("list is empty");
        auto node = extractPrev(m_tail);
        int ret = node->value;
        delete node;
        return ret;
    }

    void Clear()
    {
        auto current = m_head->next;
        while (current != m_tail)
        {
            current = current->next;
            delete extractPrev(current);
        }
    }

private:
    ListNode* extractPrev(ListNode* node)
    {
        auto target = node->prev;
        target->prev->next = target->next;
        target->next->prev = target->prev;
        --m_size;
        return target;
    }

private:
    ListNode* m_head;
    ListNode* m_tail;
    unsigned long m_size;
};
//����-����
//TEST_CASE("Factorials are computed", "[factorial]") {
//    REQUIRE(factorial(1) == 1);
//    REQUIRE(factorial(2) == 2);
//    REQUIRE(factorial(3) == 6);
//    REQUIRE(factorial(10) == 3'628'800);
//}

TEST_CASE("Empty are computed", "[Empty]")
{
    List list1;
    
    REQUIRE(list1.Empty() == 1);

    list1.PushFront(5);
  
    REQUIRE(list1.Empty() == 0);
    list1.Clear();
    REQUIRE(list1.Empty() == 1);
}

TEST_CASE("Size are computed", "[Size]")
{
    List list1;

    REQUIRE(list1.Size() == 0);

    list1.PushFront(5);
    list1.PushFront(6);
    list1.PushFront(7);
    REQUIRE(list1.Size() == 3);
    list1.Clear();
    REQUIRE(list1.Size() == 0);
}
TEST_CASE("Clear are computed", "[Clear]")
{
    List list1;

    REQUIRE(list1.Empty() == 1);
    list1.PushFront(5);
    list1.PushFront(6);
    list1.PushFront(7);
    REQUIRE(list1.Size() == 3);
    list1.Clear();
    REQUIRE(list1.Size() == 0);
    REQUIRE(list1.Empty() == 1);
}


int main(int argc, char* argv[])
{
    
    return Catch::Session().run(argc, argv);
   

}