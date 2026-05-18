
#include <iostream>
#include <cstring>

using namespace std;

// ======================================================
// TASK 1.7
// Template functions for min and max
// ======================================================

template <typename T>
T findMin(T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T>
T findMax(T a, T b)
{
    return (a > b) ? a : b;
}

// Specialization for char*

template <>
char* findMin<char*>(char* a, char* b)
{
    return (strcmp(a, b) < 0) ? a : b;
}

template <>
char* findMax<char*>(char* a, char* b)
{
    return (strcmp(a, b) > 0) ? a : b;
}

// ======================================================
// TASK 2.2
// Shell Sort Template Function
// ======================================================

template <typename T>
void shellSort(T arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            T temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

// Specialization for char*

template <>
void shellSort<char*>(char* arr[], int size)
{
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < size; i++)
        {
            char* temp = arr[i];
            int j;

            for (j = i; j >= gap &&
                strcmp(arr[j - gap], temp) > 0; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

template <typename T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// ======================================================
// TASK 3.7
// Template Singly Linked List
// ======================================================

template <typename T>
class List
{
private:

    template <typename U>
    class Node
    {
    public:
        U data;
        Node* next;

        Node(U value)
        {
            data = value;
            next = NULL;
        }
    };

    Node<T>* head;

public:

    List()
    {
        head = NULL;
    }

    ~List()
    {
        while (head != NULL)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(T value)
    {
        Node<T>* newNode = new Node<T>(value);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node<T>* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    void show()
    {
        Node<T>* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

// ======================================================
// TASK 1
// ======================================================

void task1()
{
    cout << "\n===== TASK 1.7 =====\n";

    int a = 10;
    int b = 25;

    cout << "Min int = " << findMin(a, b) << endl;
    cout << "Max int = " << findMax(a, b) << endl;

    double x = 5.6;
    double y = 2.1;

    cout << "Min double = " << findMin(x, y) << endl;
    cout << "Max double = " << findMax(x, y) << endl;

    char* s1 = (char*)"apple";
    char* s2 = (char*)"orange";

    cout << "Min string = " << findMin(s1, s2) << endl;
    cout << "Max string = " << findMax(s1, s2) << endl;
}

// ======================================================
// TASK 2
// ======================================================

void task2()
{
    cout << "\n===== TASK 2.2 =====\n";

    int arr[] = { 34, 12, 5, 66, 1, 90 };
    int size = 6;

    cout << "Array before sorting:\n";
    printArray(arr, size);

    shellSort(arr, size);

    cout << "Array after sorting:\n";
    printArray(arr, size);

    char* words[] =
    {
        (char*)"banana",
        (char*)"apple",
        (char*)"pear",
        (char*)"orange"
    };

    int size2 = 4;

    cout << "\nStrings before sorting:\n";
    printArray(words, size2);

    shellSort(words, size2);

    cout << "Strings after sorting:\n";
    printArray(words, size2);
}

// ======================================================
// TASK 3
// ======================================================

void task3()
{
    cout << "\n===== TASK 3.7 =====\n";

    List<int> intList;

    intList.add(10);
    intList.add(20);
    intList.add(30);

    cout << "Integer list:\n";
    intList.show();

    List<double> doubleList;

    doubleList.add(1.5);
    doubleList.add(2.7);
    doubleList.add(3.9);

    cout << "Double list:\n";
    doubleList.show();
}

// ======================================================
// MAIN MENU
// ======================================================

int main()
{
    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1 - Task 1.7\n";
        cout << "2 - Task 2.2\n";
        cout << "3 - Task 3.7\n";
        cout << "0 - Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            task1();
            break;

        case 2:
            task2();
            break;

        case 3:
            task3();
            break;

        case 0:
            cout << "Program finished.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}