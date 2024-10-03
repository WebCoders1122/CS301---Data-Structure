
#include <iostream>
#include "List.cpp" // Assuming List.cpp contains the List class implementation

int main() {
    List myList;

    // Add elements to the list
    myList.add(10);
    myList.add(20);
    myList.add(30);

    // Check the list's length
    std::cout << "List length: " << myList.length() << std::endl;

    // Get the current value
    std::cout << "Current value: " << myList.get() << std::endl;

    // Move to the next element and check the value
    myList.next();
    std::cout << "Next value: " << myList.get() << std::endl;

    // Move to the previous element and check the value
    myList.back();
    std::cout << "Previous value: " << myList.get() << std::endl;

    // Remove the current element
    myList.remove();
    std::cout << "List length after removal: " << myList.length() << std::endl;

    // Check if the list is empty
    if (myList.length() == 0) {
        std::cout << "List is empty." << std::endl;
    } else {
        std::cout << "List is not empty." << std::endl;
    }

    return 0;
}

