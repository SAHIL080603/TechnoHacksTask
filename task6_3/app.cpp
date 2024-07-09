#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Task structure to hold task details
struct Task {
    int id;
    string description;
};

// Function declarations
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Ignore newline character left in the input buffer

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                removeTask(tasks);
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    cout << "\nTo-Do List Menu:\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Remove Task\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void addTask(vector<Task>& tasks) {
    Task newTask;
    newTask.id = tasks.size() + 1;
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    tasks.push_back(newTask);
    cout << "Task added successfully." << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        cout << "\nTo-Do List:\n";
        for (const auto& task : tasks) {
            cout << task.id << ". " << task.description << endl;
        }
    }
}

void removeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to remove." << endl;
        return;
    }

    int id;
    cout << "Enter the task ID to remove: ";
    cin >> id;
    cin.ignore(); // Ignore newline character left in the input buffer

    auto it = remove_if(tasks.begin(), tasks.end(), [id](const Task& task) {
        return task.id == id;
    });

    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        cout << "Task removed successfully." << endl;
    } else {
        cout << "Task ID not found." << endl;
    }
}