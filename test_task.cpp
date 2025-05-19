
#include "task.cpp"
#include <limits>

using namespace std;

/**
 * Create a new task by collecting input from the user
 *
 * @@param id (The unique ID to assign to the new task)
 * @@return newTask (Returns a Task object filled with user input)
 */
Task createTaskFromUserInput(int id) {
    Task newTask;
    newTask.id = id;

    cout << "Enter description: ";
    getline(cin, newTask.description);

    cout << "Is it completed? (0 = No, 1 = Yes): ";
    cin >> newTask.completed;

    cout << "Enter priority (1 - low to 5 - high): ";
    cin >> newTask.priority;

    cout << "Enter deadline (DD/MM/YYYY): ";
    cin.ignore(); // Ignore leftover newline
    getline(cin, newTask.deadline);

    return newTask;
}

int main() {
    vector<Task> tasks;
    int nextId = 1;
    int option;

    Task t1 = {1, "Write essay", false, 3, "03/08/2025"};
    Task t2 = {2, "Submit assignment", false, 5, "07/12/2025"};
    Task t3 = {3, "Review code", true, 4, "16/04/2024"};
    Task t4 = {4, "Prepare presentation", false, 2, "04/03/2025"};
    Task t5 = {5, "Crochet a plushie", true, 1, "07/12/2025"};
    Task t6 = {6, "Dance competition", true, 4, "16/04/2024"};
    Task t7 = {7, "Team rehersal", false, 3, "04/03/2025"};


    // Add tasks for test
    tasks = addTask(tasks, t1);
    tasks = addTask(tasks, t2);
    tasks = addTask(tasks, t3);
    tasks = addTask(tasks, t4);
    tasks = addTask(tasks, t5);
    tasks = addTask(tasks, t6);
    tasks = addTask(tasks, t7);

    do {
        cout << "\n=== Task Manager Menu ===\n";
        cout << "1. Add a Task\n";
        cout << "2. Change Task Status\n";
        cout << "3. Show Completed Tasks\n";
        cout << "4. Show Pending Tasks\n";
        cout << "5. Show Tasks Sorted by Priority\n";
        cout << "6. Show Tasks Sorted by Deadline\n";
        cout << "7. Show All Tasks\n";
        cout << "0. Exit\n";
        cout << "Choose an option: ";
        cin >> option;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input

        switch (option) {
            case 1: {
                Task newTask = createTaskFromUserInput(nextId++);
                tasks = addTask(tasks, newTask);
                break;
            }
            case 2: {
                int id;
                cout << "Enter Task ID to toggle: ";
                cin >> id;
                tasks = toggleTaskStatus(tasks, id);
                break;
            }
            case 3: {
                vector<Task> completed = filterByStatus(tasks, true);
                printTasks(completed, "Completed Tasks");
                break;
            }
            case 4: {
                vector<Task> pending = filterByStatus(tasks, false);
                printTasks(pending, "Pending Tasks");
                break;
            }
            case 5: {
                vector<Task> sorted = sortByPriority(tasks);
                printTasks(sorted, "Tasks by Priority");
                break;
            }
            case 6: {
                vector<Task> sorted = sortByDeadline(tasks);
                printTasks(sorted, "Tasks by Deadline");
                break;
            }
            case 7: {
                printTasks(tasks, "All Tasks");
                break;
            }
            case 0: {
                cout << "Goodbye! Have a nice day :)\n";
                break;
            }
            default:
                cout << "Invalid option.\n";
        }

    } while (option != 0);

    return 0;
}
