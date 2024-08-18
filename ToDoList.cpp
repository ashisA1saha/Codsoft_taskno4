#include <iostream>
#include <vector>
#include <string>
using namespace std ;
vector<string> tasks;
vector<bool> completed;

void showMenu() {
    cout << "---------To-Do List Manager----------------"<<endl;
    cout << "1. Add Task" <<endl;
    cout << "2. View Tasks" <<endl;
    cout << "3. Mark Task as Completed"<<endl;
    cout << "4. Remove Task"<<endl;
    cout << "5. Exit"<<endl ;
    cout << "Choose an option (1-5): " ;
  
}

void addTask() {
    string task;
    cout << "Enter a new task : ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back(task);
    completed.push_back(false);
    cout << "Task added successfully !"<<endl ;
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks in the list."<<endl ;
        return;
    }
    // using ternary operator
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i] 
                  << " - " << (completed[i] ? "Completed" : "Pending") << endl;
    }
}

void markTaskCompleted() {
    viewTasks();
    if (tasks.empty()) return;
    
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
   // tasknumber-1 : In most programming languages, including C++, arrays (and vectors) are zero-based. 
   //This means the first element is at index 0, the second element is at index 1, and so on.   
   //to access the corresponding element in the tasks or completed vector, we need to convert
   // this one-based number to zero-based indexing by subtracting 1.


    if (taskNumber > 0 && taskNumber <= tasks.size()) {
         completed[taskNumber - 1] = true;
        cout << "Task marked as completed!"<<endl ;
    } else {
        cout << "Invalid task number!"<<endl;
    }
}

void removeTask() {
    viewTasks();
    if (tasks.empty()) return;
    
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;
    
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        completed.erase(completed.begin() + taskNumber - 1);
        cout << "Task removed!"<<endl ;
    } else {
        cout << "Invalid task number!"<<endl ;
    }
}

int main() {
    while (true) {
        showMenu();
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            addTask();
        } else if (choice == 2) {
            viewTasks();
        } else if (choice == 3) {
            markTaskCompleted();
        } else if (choice == 4) {
            removeTask();
        } else if (choice == 5) {
            cout << "Exit !"<<endl;
            break;
        } else {
            cout << "Invalid choice! Please choose a number between 1 and 5.\n";
        }
    }
    return 0;
}
