#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* next,
        * prev;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, int first_, int end_)
{
    Info a;
    if (first_ <= end_)
    {
        cout << "a" << first_ << "="; cin >> a;
        Elem* tmp = new Elem;
        tmp->info = a;
        tmp->next = NULL;
        if (last != NULL)
            last->next = tmp;
        tmp->prev = last;
        last = tmp;
        if (first == NULL)
            first = tmp;
        enqueue(first, last, first_ + 1, end_);
    }
}

void dequeue(Elem*& first, Elem*& last)
{
    if (first != NULL)
    {
        Elem* tmp = first->next;
        delete first;
        first = tmp;
        if (first == NULL)
            last = NULL;
        else
            first->prev = NULL;
        dequeue(first, last);
    }
}

void print(Elem* first)
{
    if (first != NULL)
    {
        cout << first->info << " ";
        print(first->next);
    }
}

void Change(Elem* L)
{
    Elem* tmp = new Elem;

    if (L->next != NULL)
    {
        tmp->info = L->info;
        L->info = L->next->info;
        L->next->info = tmp->info;
        if (L->next->next == NULL)
        {
            Change(L = L->next);
        }
        else
        {
            Change(L = L->next->next);
        }
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Elem* first = NULL,
        * last = NULL;


    int N;

    cout << "¬вед≥ть к≥льк≥сть елемент≥в: "; cin >> N;

    enqueue(first, last, 1, N);
    
    cout << endl;

    cout << "—писок: "; print(first); cout << endl << endl;

    Change(first);

    cout << "«м≥нений список: "; print(first); cout << endl << endl;

    dequeue(first, last);

    system("pause");
    return 0;
}