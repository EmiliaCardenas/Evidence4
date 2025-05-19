# Evidence4 - Task APP

## Description
This project tackles the problem of managing organization of tasks through a little Task application. It has been designed using the functional programming paradigm, prioritizing pure functions. The goal of the application is to allow users to create, manage, sort, and filter tasks based on attributes such as status, priority, and deadline, providing a practical tool for personal organization.

The motivation behind the project is that sometimes people forget which tasks have been completed, which ones are soon to be completed. There are already some apps that do this kind of organizatión, but this is the main base of how they work.  This project demonstrates how functional principles can support the base of these managers in maintainable code.

Functional programming is known for promoting code that is easier to test, debug, and deal with state transformations. The project involves frequent changes to task states (complete/incomplete, priority updates, reordering), which benefit from immutability and preserve previous states for undo features.

## Models
The architecture follows a functional approach. Tasks are treated as immutable data structures, and operations like adding or toggling a task generate a new copy of the task list rather than modifying the existing one.

* **Input Layer**: Handles user input, including commands like `add`, `toggle`, `filter`, `sort`, and `print`.
* **Core Logic Layer**: Processes data using functions. All operations on tasks (add, toggle, filter, sort) are stateless and return new vectors of tasks.
* **Output Layer**: Displays the list of tasks in a formatted way, reflecting the requested operation.

Data flow:
```
[User Input] --> [Functional Logic (Add/Toggle/Filter)] --> [New Task List] --> [Display Output]
```

* **Immutability** ensures that all state transitions are predictable and testable.
* **First-class functions** allow operation logic to be passed as arguments.
* **Referential transparency** guarantees that functions always return the same output, simplifying testing and debugging.

