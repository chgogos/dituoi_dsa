// Λύση με διπλά συνδεδεμένη λίστα

#include <iostream>
#include <sstream>

struct student
{
    std::string id;
    std::string name;
    int year;
    std::string direction;
    double grade;
    bool operator==(const student &other) const
    {
        return id == other.id;
    }
};

struct node
{
    student *data;
    node *next;
    node *previous;
};

void insert_front(node *&head, student *new_student)
{
    node *new_node = new node;
    new_node->data = new_student;
    new_node->next = head;
    if (head != nullptr)
    {
        head->previous = new_node;
    }
    head = new_node;
}

void insert_back(node *&head, student *new_student)
{
    node *new_node = new node;
    new_node->data = new_student;
    new_node->next = nullptr;

    if (head == nullptr)
    {
        new_node->previous = nullptr;
        head = new_node;
        return;
    }
    node *curr = head;
    while (curr->next != nullptr)
    {
        curr = curr->next;
    }
    curr->next = new_node;
    new_node->previous = curr;
}

void erase(node *&head, std::string id)
{
    // άδεια λίστα
    if (head == nullptr)
        return;
    // το στοιχείο προς διαγραφή βρίσκεται στην 1η θέση
    node *curr = head;
    if (head->data->id == id)
    {
        head = head->next;
        delete curr;
        return;
    }
    // το στοιχείο προς διαγραφή βρίσκεται μετά την 1η θέση ή δεν υπάρχει
    while (curr != nullptr)
    {
        if (curr->data->id == id)
        {
            node *curr_previous = curr->previous;
            node *curr_next = curr->next;
            curr_previous->next = curr_next;
            delete curr;
            return;
        }
        curr = curr->next;
    }
}

void print_forward(node *&head)
{
    node *curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->data->id << " " << curr->data->name << " " << curr->data->year
                  << " " << curr->data->direction << " " << curr->data->grade << std::endl;
        curr = curr->next;
    }
}

void print_reverse(node *&head)
{
    node *tail = head;
    node *curr = head;
    while (curr != nullptr)
    {
        tail = curr;
        curr = curr->next;
    }

    curr = tail;
    while (curr != nullptr)
    {
        std::cout << curr->data->id << " " << curr->data->name << " " << curr->data->year
                  << " " << curr->data->direction << " " << curr->data->grade << std::endl;
        curr = curr->previous;
    }
}

void delete_list(node *head)
{
    node *curr = head;
    while (curr != nullptr)
    {
        std::cerr << "delete student " << curr->data->id << std::endl;
        delete curr->data;
        node *tmp = curr;
        curr = curr->next;
        delete tmp;
    }
}

int main()
{
    node *head = nullptr;

    std::string line, str;
    // 1. Doubly Linked List
    std::cout << "1. DLL read data" << std::endl;
    while (std::getline(std::cin, line))
    {
        student *a_student = new student;
        std::stringstream ss(line);
        ss >> a_student->id;
        ss >> a_student->name;
        ss >> a_student->year;
        ss >> a_student->direction;
        ss >> a_student->grade;
        insert_back(head, a_student);
    }
    print_forward(head);

    // 2. Doubly Linked List
    std::cout << "2. DLL add student front, add student back" << std::endl;
    student *s2 = new student{"011", "iasonas", 3, "CS", 7.0};
    insert_front(head, s2);

    student *s3 = new student{"012", "electra", 5, "CE", 6.0};
    insert_back(head, s3);
    print_forward(head);

    // 3. Doubly Linked List
    std::cout << "3. DLL remove student 005" << std::endl;
    erase(head, "005");
    print_forward(head);

    // 4. Doubly Linked List
    std::cout << "4. DLL remove specific students" << std::endl;
    node *curr = head;
    while (curr != nullptr)
    {
        if (curr->data->grade >= 5.0 && curr->data->direction=="CS")
        {
            curr = curr->next;
        }
        else if (curr->previous == nullptr)
        {
            curr = curr->next;
            delete head;
            head = curr;
        }
        else
        {
            node *curr_previous = curr->previous;
            node *curr_next = curr->next;
            curr_previous->next = curr_next;
            if (curr_next!=nullptr)
                curr_next->previous = curr_previous;
            delete curr;
            curr = curr_next;
        }
    }
    print_reverse(head);

    delete_list(head);
}