// Λύση με διπλά συνδεδεμένη λίστα της STL

#include <iostream>
#include <list> // doubly linked list
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

int main()
{
    std::string line;
    // 1. STL
    std::cout << "1. STL read data" << std::endl;
    std::list<student> students_stl_list;
    while (std::getline(std::cin, line))
    {
        student a_student;
        std::stringstream ss(line);
        ss >> a_student.id;
        ss >> a_student.name;
        ss >> a_student.year;
        ss >> a_student.direction;
        ss >> a_student.grade;
        students_stl_list.push_back(a_student);
    }
    for (auto s : students_stl_list)
    {
        std::cout << s.id << " " << s.name << " " << s.year << " "
                  << s.direction << " " << s.grade << std::endl;
    }

    // 2. STL
    std::cout << "2. STL add student front, add student back" << std::endl;
    student s2 = {"011", "iasonas", 3, "CS", 7.0};
    students_stl_list.push_front(s2);
    student s3 = {"012", "electra", 5, "CE", 6.0};
    students_stl_list.push_back(s3);
    for (auto s : students_stl_list)
    {
        std::cout << s.id << " " << s.name << " " << s.year << " "
                  << s.direction << " " << s.grade << std::endl;
    }

    // 3. STL
    std::cout << "3. STL remove student 005" << std::endl;
    student s4 = {"005"};
    students_stl_list.remove(s4);
    for (auto s : students_stl_list)
    {
        std::cout << s.id << " " << s.name << " " << s.year << " "
                  << s.direction << " " << s.grade << std::endl;
    }

    // 4. STL
    std::cout << "4. STL remove specific students" << std::endl;
    std::list<student>::iterator iter = students_stl_list.begin();
    while (iter != students_stl_list.end())
    {
        if (iter->direction == "CS" && iter->grade >= 5.0)
            iter++;
        else
            iter = students_stl_list.erase(iter);
    }
    std::list<student>::reverse_iterator riter;
    for (riter = students_stl_list.rbegin(); riter != students_stl_list.rend(); riter++)
    {
        std::cout << riter->id << " " << riter->name << " " << riter->year << " "
                  << riter->direction << " " << riter->grade << std::endl;
    }
}