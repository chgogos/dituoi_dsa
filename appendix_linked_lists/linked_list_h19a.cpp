// simple example of an address book using a singly linked list (adapted from CS106X)
// 8/11/2019
#include <iostream>

using namespace std;

struct entry
{
    string name;
    string address;
    string phone;
    entry *next;
};

entry *create_entry()
{
    cout << "Enter  name (q=quit):";
    string input;
    cin >> input;
    if (input == "q")
        return NULL;
    entry *ent = new entry;
    ent->name = input;
    cout << "Enter  address:";
    cin >> ent->address;
    cout << "Enter  phone:";
    cin >> ent->phone;
    ent->next = NULL;
    return ent;
}

void print_entry(entry *ent)
{
    cout << ent->name << " " << ent->address << " " << ent->phone << endl;
}

entry *build_address_book()
{

    entry *book = NULL;
    while (true)
    {
        entry *ent = create_entry();
        if (ent == NULL)
            return book;
        ent->next = book;
        book = ent;
    }
}

void free_address_book(entry *book)
{
    entry *curr = book;
    while (curr != NULL)
    {
        entry *next = curr->next;
        delete curr;
        curr = next;
    }
}

void print_address_book(entry *book)
{
    cout << endl;
    for (entry *curr = book; curr != NULL; curr = curr->next)
    {
        print_entry(curr);
    }
}

void print_address_book_r(entry *book)
{
    if (book == NULL)
    {
        return;
    }
    else
    {
        print_entry(book);
        print_address_book_r(book->next);
    }
}

int main()
{
    entry *my_book = build_address_book();
    print_address_book(my_book);
    print_address_book_r(my_book); // κλήση της αναδρομικής συνάρτησης
    free_address_book(my_book);
}