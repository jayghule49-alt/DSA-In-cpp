#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int id;
    string name;
    float salary;
    Node *next;
};

Node *head = NULL;

// Insert at beginning
void insertBeginning()
{
    Node *newNode = new Node;

    cout << "Enter Employee ID: ";
    cin >> newNode->id;

    cout << "Enter Employee Name: ";
    cin >> newNode->name;

    cout << "Enter Salary: ";
    cin >> newNode->salary;

    newNode->next = head;
    head = newNode;

    cout << "Employee inserted at beginning.\n";
}

// Insert at end
void insertEnd()
{
    Node *newNode = new Node;

    cout << "Enter Employee ID: ";
    cin >> newNode->id;

    cout << "Enter Employee Name: ";
    cin >> newNode->name;

    cout << "Enter Salary: ";
    cin >> newNode->salary;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Employee inserted at end.\n";
}

// Delete employee
void deleteEmployee()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    Node *temp = head;
    Node *prev = NULL;

    // Delete first node
    if (temp->id == id)
    {
        head = temp->next;
        delete temp;

        cout << "Employee deleted successfully.\n";
        return;
    }

    // Search for employee
    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    // Employee not found
    if (temp == NULL)
    {
        cout << "Employee not found.\n";
        return;
    }

    // Delete the node
    prev->next = temp->next;
    delete temp;

    cout << "Employee deleted successfully.\n";
}

// Search employee
void searchEmployee()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    int id;
    cout << "Enter Employee ID to search: ";
    cin >> id;

    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nEmployee Found!\n";
            cout << "Employee ID : " << temp->id << endl;
            cout << "Name        : " << temp->name << endl;
            cout << "Salary      : " << temp->salary << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "Employee not found.\n";
}

// Display employees
void display()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Node *temp = head;

    cout << "\n----- Employee Records -----\n";

    while (temp != NULL)
    {
        cout << "Employee ID : " << temp->id << endl;
        cout << "Name        : " << temp->name << endl;
        cout << "Salary      : " << temp->salary << endl;
        cout << "----------------------------\n";

        temp = temp->next;
    }
}

// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n===== Employee Linked List =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Delete Employee\n";
        cout << "4. Search Employee\n";
        cout << "5. Display Employees\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertBeginning();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                deleteEmployee();
                break;

            case 4:
                searchEmployee();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}