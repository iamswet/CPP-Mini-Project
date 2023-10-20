#include <iostream>
#include <string>
using namespace std;
class Task {          
public:
    string description;
    bool completed;
    Task() : completed(false) {}
};
class Node {
public:
    Task task;
    Node* next;
    Node(const Task& t) : task(t), next(nullptr) {}
};
class TodoListManager {
private:
    Node* head;
    int numTasks;
public:
    TodoListManager() : head(nullptr), numTasks(0) {}
    void addTask(string desc) {
        Task newTask;
        newTask.description = desc;
        if (head == nullptr) {
            head = new Node(newTask);
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(newTask);
        }
        numTasks++;
    }
    void printTasks() {
        Node* current = head;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". " << current->task.description;
            if (current->task.completed) {
                cout << " - Completed";
            }
            cout << endl;
            current = current->next;
            i++;
        }
    }
    void toggleTaskCompletion(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= numTasks) {
            Node* current = head;
            for (int i = 1; i < taskIndex; i++) {
                current = current->next;
            }
            current->task.completed = !current->task.completed;
        } else {
            cout << "Invalid task index" << endl;
        }
    }
    void removeTask(int taskIndex) {
        if (taskIndex >= 1 && taskIndex <= numTasks) {
            Node* current = head;
            if (taskIndex == 1) {
                head = current->next;
                delete current;
            } else {
                for (int i = 1; i < taskIndex - 1; i++) {
                    current = current->next;
                }
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            }
            numTasks--;
        } else {
            cout << "Invalid task index" << endl;
        }
    }
};
int main() {              //Main Function
    TodoListManager manager;
    while (true) {
        cout << "-------------------------------OPERATIONS----------------------------------" << '\n';
        cout << "1. Add task" << endl;
        cout << "2. Print tasks" << endl;
        cout << "3. Toggle task completion" << endl;
        cout << "4. Remove task" << endl;
        cout << "5. Quit" << endl;
        cout << "---------------------------------------------------------------------------" << '\n';
        int choice;
        cout << "ENTER CHOICE:- ";
        cin >> choice;
        switch (choice) {      //Switch Case used for selection of operations
        case 1: {
            string desc;
            cout << "Enter task description: ";
            cin.ignore();
            getline(cin, desc);
            manager.addTask(desc);
            break;
        }
        case 2:
            cout << "ALL THE TASKS ARE:- " << '\n';
            manager.printTasks();
            break;
        case 3: {
            int taskIndex;
            cout << "Enter task index: ";
            cin >> taskIndex;
            manager.toggleTaskCompletion(taskIndex);
            break;
        }
        case 4: {
            int taskIndex;
            cout << "Enter task index: ";
            cin >> taskIndex;
            manager.removeTask(taskIndex);
            break;
        }
        case 5:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
return 0;
}