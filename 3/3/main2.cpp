#include <catch2/catch_test_macros.hpp>
#include<catch2/catch_session.hpp>
#include <cstdint>

//проверяемая функция
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
//юнит-тест
//TEST_CASE("Factorials are computed", "[factorial]") {
//    REQUIRE(factorial(1) == 1);
//    REQUIRE(factorial(2) == 2);
//    REQUIRE(factorial(3) == 6);
//    REQUIRE(factorial(10) == 3'628'800);
//}

TEST_CASE("Front are computed", "[Front]")
{
    List list1;

    list1.PushFront(1);
    REQUIRE(list1.Size() == 1);
    REQUIRE(list1.PopFront() == 1);
    REQUIRE_THROWS(list1.PopFront());
    list1.PushFront(5);
    list1.PushFront(1);
    list1.PushFront(7);
    list1.PushFront(10);
    REQUIRE(list1.PopFront() == 10);
    REQUIRE(list1.PopFront() == 7);
    REQUIRE(list1.PopFront() == 1);
    REQUIRE(list1.PopFront() == 5);
    REQUIRE_THROWS(list1.PopFront());
    
    list1.PushFront(1);
    list1.PushFront(7);
    list1.PushFront(10);
    list1.PushBack(5);
    list1.PushBack(76);
    REQUIRE(list1.PopFront() == 10);
    REQUIRE(list1.PopFront() == 7);
    REQUIRE(list1.PopFront() == 1);
    REQUIRE(list1.PopFront() == 5);
    REQUIRE(list1.PopFront() == 76);
    list1.PushBack(1);
    REQUIRE(list1.PopFront() == 1);

    list1.PushFront(1);
    list1.PushBack(2);
    list1.PushFront(3);
    list1.Clear();
    REQUIRE(list1.Empty());
    REQUIRE_THROWS(list1.PopFront());
}

TEST_CASE("Back are computed", "[Back]")
{
    List list1;

    list1.PushBack(1);
    REQUIRE(list1.PopBack() == 1);
   
    list1.PushFront(5);
    list1.PushFront(1);
    list1.PushFront(7);
    list1.PushFront(10);
    REQUIRE(list1.PopBack() == 5);
    REQUIRE(list1.PopBack() == 1);
    REQUIRE(list1.PopBack() == 7);
    REQUIRE(list1.PopBack() == 10);
   
    list1.PushBack(5);
    list1.PushBack(1);
    list1.PushBack(7);
    list1.PushBack(10);
    REQUIRE(list1.PopBack() == 10);
    REQUIRE(list1.PopBack() == 7);
    REQUIRE(list1.PopBack() == 1);
    REQUIRE(list1.PopBack() == 5);
    REQUIRE_THROWS(list1.PopBack());
   
    list1.PushFront(1);
    list1.PushFront(7);
    list1.PushFront(10);
    list1.PushBack(5);
    list1.PushBack(76);
    REQUIRE(list1.PopBack() == 76);
    REQUIRE(list1.PopBack() == 5);
    REQUIRE(list1.PopBack() == 1);
    REQUIRE(list1.PopBack() == 7);
    REQUIRE(list1.PopBack() == 10);

    list1.PushFront(1);
    list1.PushBack(2);
    list1.PushFront(3);
    REQUIRE(list1.PopFront() == 3);
    REQUIRE(list1.PopBack() == 2);
    REQUIRE(list1.PopFront() == 1);
    REQUIRE_THROWS(list1.PopBack());
    REQUIRE_THROWS(list1.PopFront());

    list1.PushFront(1);
    list1.PushBack(2);
    list1.PushFront(3);
    list1.Clear();
    REQUIRE(list1.Empty());
    REQUIRE_THROWS(list1.PopBack());

}

int main(int argc, char* argv[])
{

    return Catch::Session().run(argc, argv);


}