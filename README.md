# DS-Project
# 🍕 Pizza House Management System

This project is a console-based pizza shop management system implemented in C++ using object-oriented design principles and efficient data structures. It provides a way to add, manage, search, and analyze pizza branches across a virtual city, using **KD-Tree** and **Hash Tables** for performance.

---

## 🚀 Features

- **Add-N [Name]**: Add a neighborhood defined by 4 coordinates.
- **Add-P [Name]**: Add a main pizza branch at a given location.
- **Add-Br [Name]**: Add a sub-branch to a main pizza branch.
- **Del-Br**: Delete a sub-branch at a given location (main branches cannot be deleted).
- **List-P [Neighborhood]**: List all pizzerias located inside a neighborhood.
- **List-Brs [MainBranch]**: List all branches under a given main pizza branch.
- **Near-P**: Find and display the closest pizzeria to a given point.
- **Near-Br [MainBranch]**: Find the closest sub-branch to a main branch.
- **Avail-P**: List all pizzerias within a given radius from a point.
- **Most-Brs**: Identify the main branch with the highest number of sub-branches.
- **Undo**: Roll back the system to a previous command state.

---

## 🧱 Data Structures Used

- **KD-Tree**: Used to store and query spatial data (coordinates of pizza branches) efficiently.
- **Hash Tables**:
  - `HashMain`: For managing main branches by name.
  - `HashValley`: For managing neighborhoods by name.
- **Command History**: Commands are stored for undo functionality using a stack-like structure (`ProgramState`).

---

## 💡 How It Works

The program runs through a command-based menu system on the console. Users input commands in the following format:

```
COMMAND [ARGUMENT] && COMMAND [ARGUMENT]
```

Multiple commands can be chained using `&&`.

Example:
```
Add-N [Downtown] && Add-P [PizzaHut] && Add-Br [PizzaHut]
```

Each command modifies the internal data structure accordingly. Input validation and error handling are included for cases like duplicate locations, missing main branches, or invalid coordinates.

---

## 🔧 Build & Run

**Language**: C++  
**Platform**: Windows (Console-based)

To build and run:
1. Use a C++17 (or later) compiler (e.g., g++, MSVC).
2. Open the `Project1.sln` file in Visual Studio or compile using your preferred C++ build system.
3. Run the program in a Windows console environment (due to use of `Sleep()` and console color codes).

---

## 🗂 Project Structure

- `Menu.h`: Core file handling the main loop, user input, and menu display.
- `KDtree`: Handles spatial organization and nearest-neighbor queries.
- `Branch`, `MainBranchClass`: Represent pizza shops and their structure.
- `HashMain`, `HashValley`: Hash tables for fast name-based access.
- `Command`, `ProgramState`: Enable Undo functionality by saving state.
- `point`, `valley`: Represent geometric points and neighborhoods.

---

## 📌 Notes

- All user interactions occur via the console with colored output for clarity.
- No third-party libraries are used.
- Input format requires commands to be valid; otherwise, the program prompts the user to retry.
