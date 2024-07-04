#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

struct Book {
    std::string name;
    std::string author;
    int id;
};

struct Student {
    std::string name;
    std::string email;
    std::string book;
    int id;
};

std::vector<Book> start_lib;
std::vector<Student> start;

void initialize_lib(std::vector<Book>&);
void book_issue(std::vector<Student>&);
void book_return(std::vector<Student>&);
void display_lib(const std::vector<Book>&);
void delete_book(int);
void add_book(const std::string&, const std::string&, int);
void display(const std::vector<Student>&);
void greetings();
void main_menu();

int main() {
    initialize_lib(start_lib);
    greetings();
    main_menu();
    return 0;
}

void greetings() {
    std::cout << "\n\n";
    std::cout << "\t\t\t     ****************************************\n";
    std::cout << "\t\t\t     *                                      *\n";
    std::cout << "\t\t\t     *       ------------------------       *\n";
    std::cout << "\t\t\t     *              WELCOME TO              *\n";
    std::cout << "\t\t\t     *           STUDENT LIBRARY            *\n";
    std::cout << "\t\t\t     *       ------------------------       *\n";
    std::cout << "\t\t\t     *                                      *\n";
    std::cout << "\t\t\t     *                                      *\n";
    std::cout << "\t\t\t     *    Lovely professional University    *\n";
    std::cout << "\t\t\t     *  Email: salonijaiswal7412@gmail.com  *\n";
    std::cout << "\t\t\t     *            Contact:7903875964        *\n";
    std::cout << "\t\t\t     *                                      *\n";
    std::cout << "\t\t\t     ****************************************\n";
    std::cout << "\n\n\t\t\t             Press any key to continue: ";
    std::cin.ignore();
    std::cin.get();
}

void main_menu() {
    int choice;
    do {
        std::cout << "\n\n";
        std::cout << "\n\t\t\t*\n";
        std::cout << "\n\t\t\t\t      MAIN MENU: ";
        std::cout << "\n\t\t\t\t     1.ISSUE BOOKS ";
        std::cout << "\n\t\t\t\t     2.RETURN BOOKS ";
        std::cout << "\n\t\t\t\t     3.DISPLAY STUDENT DETAILS ";
        std::cout << "\n\t\t\t\t     4.DELETE BOOK ";
        std::cout << "\n\t\t\t\t     5.ADD BOOK";
        std::cout << "\n\t\t\t\t     6.DISPLAY AVAILABLE BOOKS";
        std::cout << "\n\t\t\t\t     7.EXIT\n ";
        std::cout << "\n\t\t\t*\n";
        std::cout << "\n\t\t\t\t      Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
        case 1: {
            book_issue(start);
            break;
        }
        case 2: {
            book_return(start);
            break;
        }
        case 3: {
            display(start);
            break;
        }
        case 6:{
            display_lib(start_lib);
            break;
        }

        case 4:{
            int id;
           std::cout << "\n\tEnter book ID to delete: ";
            std::cin >> id;
            delete_book(id);
            system("cls");
            break;
        }
        case 5:{
            std::string bookname, authorname;
            int id;
            std::cout << "\n\tEnter book name: ";
            std::cin.ignore();
            std::getline(std::cin, bookname);
            std::cout << "\n\tEnter author name: ";
            std::getline(std::cin, authorname);
            std::cout << "\n\tEnter book ID: ";
            std::cin >> id;
            add_book(bookname, authorname, id);
            break;
        }
        case 7: {
            exit(1);
        }
        default: {
            std::cout << "\n\t\t\t\t      ...Invalid Option!...\n";
            std::cout << "\n\t\t\t\t      Press any key to try again: ";
            std::cin.ignore();
            std::cin.get();
        }
        }
    } while (choice != 7);
}

void initialize_lib(std::vector<Book>& start) {
    start.push_back({ "The Kite Runner", "Khaled Hosseini", 101 });
    start.push_back({ "To Kill A Mockingbird", "Harper Lee", 102 });
    start.push_back({ "The Alchemist", "Paulo Coelho", 103 });
    start.push_back({ "Pride And Prejudice", "Jane Austen", 104 });
    start.push_back({ "A Tale Of Two Cities", "Charles Dickens", 105 });
     start.push_back({ "Harry Potter", "JK Rowling", 106 });
    start.push_back({ "Eleven Minutes", "Paulo Coelho", 107 });
    start.push_back({ "Emma", "Jane Austen", 108 });
    start.push_back({ "Picture Of Dorian Gray", "Charles Dickens", 109 });
    start.push_back({ "God of small things", "Arundhati Roy", 110 });
}

void book_issue(std::vector<Student>& start) {
    std::vector<Book> books = start_lib;
    std::string name, email;
    int id, flag = 0;
    if (books.empty()) {
        std::cout << "\n\t\t\t\t No books left in the library to issue!\n\t\t\t\t Sorry for the inconvenience!\n";
    } else {
        system("cls");
        std::cout << "\n\t*************** Books Available: ****************\n";
        for (size_t i = 0; i < books.size(); i++) {
            std::cout << "\n\t_\n";
            std::cout << "\n\t Book " << i + 1;
            std::cout << "\n\t Book Title: " << books[i].name;
            std::cout << "\n\t Name of Author: " << books[i].author;
            std::cout << "\n\t Book ID: " << books[i].id;
            std::cout << "\n\t_\n";
        }
        std::cout << "\n\n\t Enter the Book ID: ";
        std::cin >> id;
        for (size_t i = 0; i < books.size(); i++) {
            if (books[i].id == id) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            std::cout << "\n\t Enter Student Details:\n ";
            std::cout << "\n\t Enter your Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "\n\t Enter your Email: ";
            std::cin.ignore();
            std::getline(std::cin, email);
            Student new_student = { name, email, books[id - 101].name, id };
            start.push_back(new_student);
            std::cout << "\n\t Issue of Book ID " << id << " done successfully!\n";
            std::cout << "\n\n\t*\n";

            start_lib.erase(std::remove_if(start_lib.begin(), start_lib.end(),
                [id](const Book& b) { return b.id == id; }), start_lib.end());
            std::cout << "\n\n\t Press any key to go to the main menu: ";
            std::cin.ignore();
            std::cin.get();
            system("cls");
        } else {
            std::cout << "\n\t\t     ...Invalid Option!...\n";
            std::cout << "\n\t\t      Press any key to try again: ";
            std::cin.ignore();
            std::cin.get();
            system("cls");
        }
    }
}

void book_return(std::vector<Student>& start) {
    int identity, flag = 0;
    std::cout << "\n\n\t*************** Books Submission: ****************\n";
    std::cout << "\n\n\t Enter your Book ID: ";
    std::cin >> identity;
    for (size_t i = 0; i < start.size(); i++) {
        if (start[i].id == identity) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        std::cout << "\n\t_\n";
        std::cout << "\n\t Student Name: " << start[identity - 101].name;
        std::cout << "\n\t Student Email: " << start[identity - 101].email;
        std::cout << "\n\t Name of Book Issued: " << start[identity - 101].book;
        std::cout << "\n\t_\n";
        std::cout << "\n\n\t Return of Book ID " << identity << " done successfully!\n";
        std::cout << "\n\n\t*\n";
        start.erase(start.begin() + identity - 101);
        std::cout << "\n\t Thank you! \n\t Do visit again! ";
        std::cout << "\n\n\t Press any key to go to the main menu: ";
        std::cin.ignore();
        std::cin.get();
        system("cls");
    } else {
        std::cout << "\n\tSorry the book doesn't exist! Please recheck the entered ID";
        std::cout << "\n\t\t\t\t      Press any key to try again: ";
        std::cin.ignore();
        std::cin.get();
        system("cls");
    }
}

void display_lib(const std::vector<Book>& start) {
    std::cout << "\n\t************* Books Available: **************\n";
    for (const auto& book : start) {
        std::cout << "\n\t_\n";
        std::cout << "\n\t Book Title: " << book.name;
        std::cout << "\n\t Name of Author: " << book.author;
        std::cout << "\n\t Book ID: " << book.id;
        std::cout << "\n\t_\n";
        std::cout << "\n\n\t*\n";
    }
    std::cout << "\n\n\t Press any key to go to the main menu: ";
    std::cin.ignore();
    std::cin.get();
    system("cls");
}

void delete_book(int id) {

    
    auto it = std::find_if(start_lib.begin(), start_lib.end(),
        [id](const Book& b) { return b.id == id; });
   if (it!= start_lib.end()) {

        start_lib.erase(it);
}
}

void add_book(const std::string& bookname, const std::string& authorname, int id) {
    start_lib.push_back({ bookname, authorname, id });
}

void display(const std::vector<Student>& start) {
    std::cout << "\n\t************* Details of Students: **************\n";
    for (const auto& student : start) {
        std::cout << "\n\t_\n";
        std::cout << "\n\t\t Student Name: " << student.name;
        std::cout << "\n\t\t Student Email: " << student.email;
        std::cout << "\n\t\t Name of Book Issued: " << student.book;
        std::cout << "\n\t\t Book ID: " << student.id;
        std::cout << "\n\t_\n";
        std::cout << "\n\n\t*\n";
    }
    std::cout << "\n\n\t Press any key to go to the main menu: ";
    std::cin.ignore();
    std::cin.get();
    system("cls");
}

