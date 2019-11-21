// sorted by name address book (adapted from CS106X)

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

entry *find_entry(entry *book, string name)
{
    for (entry *curr = book; curr != NULL; curr = curr->next)
    {
        if (curr->name == name)
            return curr;
    }
    return NULL;
}

// εκμεταλεύεται το γεγονός ότι η λίστα είναι ταξινομημένη έτσι ώστε να σταματήσει νωρίτερα
entry *find_entry_in_sorted(entry *book, string name)
{
    for (entry *curr = book; curr != NULL; curr = curr->next)
    {
        if (name < curr->name)
            return NULL;
        if (curr->name == name)
            return curr;
    }
    return NULL;
}

// προσοχή στο reference σε pointer
void insert(entry *&book, entry *ent)
{
    entry *curr;
    entry *prev = NULL;
    for (curr = book; curr != NULL; curr = curr->next)
    {
        if (ent->name < curr->name)
            break;
        prev = curr;
    }
    ent->next = curr;
    if (prev != NULL)
        prev->next = ent;
    else
        book = ent;
}

entry *build_sorted_address_book()
{
    entry *book = NULL;
    while (true)
    {
        entry *ent = create_entry();
        if (ent == NULL)
            return book;
        insert(book, ent);
    }
}

void delete_entry(entry *&book, const string &name)
{
    entry *curr;
    entry *prev = NULL;
    for (curr = book; curr != NULL; curr = curr->next)
    {
        if (name == curr->name)
            break;
        if (name > curr->name)
            return;
    }
    if (curr == NULL)
        return;
    if (prev != NULL)
        prev->next = curr->next;
    else
        book = curr->next;
    delete curr;
}

int main()
{
    cout << "1. Build address book using input by user:" << endl;
    entry *my_book = build_sorted_address_book();
    print_address_book(my_book);
    cout << "2. Add new contact:" << endl;
    entry *ent = new entry;
    ent->name = "yiannis";
    ent->address = "eleftherias";
    ent->phone = "000000000";
    insert(my_book, ent);
    print_address_book(my_book);
    cout << "3. Remove contact:" << endl;
    delete_entry(my_book, "yiannis");
    print_address_book(my_book);
    free_address_book(my_book);
    cout << "bye" << endl;
}