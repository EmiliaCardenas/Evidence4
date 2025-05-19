#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// This struct defines a task with details
struct Task {
    int id;
    string description;
    bool completed;
    int priority;
    string deadline;
};

/**
 * Add a new task to the task list
 *
 * @@param tasks (The vector of tasks that are already in the list)
 * @@param newTask (The new task to add)
 * @@return updated (Returns the list updated with the new task)
 */
vector<Task> addTask(const vector<Task>& tasks, const Task& newTask) {
    vector<Task> updated = tasks;
    updated.push_back(newTask);
    return updated;
}

/**
 * Toggle (change) the completed status of a task based on its ID
 *
 * @@param tasks (The current list of tasks)
 * @@param id (The ID of the task to toggle)
 * @@return updated (Returns the list with the task's status toggled)
 */
vector<Task> toggleTaskStatus(const vector<Task>& tasks, int id) {
    vector<Task> updated;
    for (const Task& task : tasks) {
        if (task.id == id) {
            Task modified = task;
            modified.completed = !task.completed;
            updated.push_back(modified);
        } else {
            updated.push_back(task);
        }
    }
    return updated;
}

/**
 * Filter tasks by their completion status
 *
 * @@param tasks (The list of tasks to filter)
 * @@param completed (The status to filter by: true for completed, false for incomplete)
 * @@return result (Returns a list of tasks matching the specified status)
 */
vector<Task> filterByStatus(const vector<Task>& tasks, bool completed) {
    vector<Task> result;
    for (const Task& task : tasks) {
        if (task.completed == completed) {
            result.push_back(task);
        }
    }
    return result;
}

/**
 * Sort tasks by their priority in descending order
 *
 * @@param tasks (The list of tasks to sort)
 * @@return sorted (Returns a list of tasks sorted by priority)
 */
vector<Task> sortByPriority(const vector<Task>& tasks) {
    vector<Task> sorted = tasks;
    sort(sorted.begin(), sorted.end(), [](const Task& a, const Task& b) {
        return a.priority > b.priority;
    });
    return sorted;
}

/**
 * Sort tasks by their deadline in ascending order
 *
 * @@param tasks (The list of tasks to sort)
 * @@return sorted (Returns a list of tasks sorted by deadline)
 */
vector<Task> sortByDeadline(const vector<Task>& tasks) {
    vector<Task> sorted = tasks;
    sort(sorted.begin(), sorted.end(), [](const Task& a, const Task& b) {
        return a.deadline < b.deadline;
    });
    return sorted;
}

/**
 * Print all tasks with a title
 *
 * @@param tasks (The list of tasks to print)
 * @@param title (Optional title to display above the tasks list)
 */
void printTasks(const vector<Task>& tasks, const string& title = "Tasks") {
    cout << "\n=== " << title << " ===\n";
    for (const Task& task : tasks) {
        cout << "ID: " << task.id
             << " | Description: " << task.description
             << " | Completed: " << (task.completed ? "Yes" : "No")
             << " | Priority: " << task.priority
             << " | Deadline: " << task.deadline
             << "\n";
    }
}
