# 🆔 **NADRA Management System (DSA Project - C++ | Hashing)**

---

## Overview

This project simulates a **NADRA (National Database & Registration Authority) Management System** built as a **Data Structures & Algorithms (DSA)** project using **C++**.
It uses **Hashing** to efficiently manage and retrieve citizen data based on **CNIC (Computerized National Identity Card)** numbers.

---

## Key Features

* **Register New Citizen (Add Record)**
* **Search Citizen by CNIC (Hashing Search)**
* **Update Citizen Information**
* **Delete Citizen Record**
* **Display All Citizens (Hash Table Traversal)**
* **Efficient Data Retrieval using Hash Functions**

---

## Technologies & Concepts

| Technology                  | Purpose              |
| --------------------------- | -------------------- |
| **C++**                     | Programming Language |
| **Hash Tables**             | Core Data Structure  |
| **Chaining (Linked Lists)** | Collision Handling   |
| **Console Application**     | User Interface       |

---

## How It Works

1. **Data Structure Used:**

   * **Hash Table with Chaining**
   * Each bucket uses a **Linked List** to handle collisions.

2. **Hash Function:**

   * CNIC is hashed to an index in the table using a **modular hashing algorithm**.

3. **Citizen Information Fields:**

   * CNIC Number
   * Name
   * Father’s Name
   * Date of Birth
   * Address

4. **Operations Menu:**

| Option | Description          |
| ------ | -------------------- |
| 1      | Register New Citizen |
| 2      | Search by CNIC       |
| 3      | Update Citizen       |
| 4      | Delete Citizen       |
| 5      | Display All Citizens |
| 6      | Exit                 |

---

## Project Structure

```
NADRA-Management-System-Hashing-Cpp/
│
├── main.cpp           # Main source code (Hash Table implementation)
├── README.md          # Project documentation (this file)
```

---

## Usage Guide

### 1️⃣ Clone the Repository

```bash
git clone https://github.com/m-wasiq-37/DSA-PROJECT.git
cd DSA-PROJECT
```

### 2️⃣ Compile and Run

For Windows:

```bash
g++ main.cpp -o nadra_system
nadra_system.exe
```

For Linux/macOS:

```bash
g++ main.cpp -o nadra_system
./nadra_system
```

---

## Example Menu Output

```
========== NADRA MANAGEMENT SYSTEM ==========

1. Register New Citizen
2. Search Citizen by CNIC
3. Update Citizen Record
4. Delete Citizen Record
5. Display All Citizens
6. Exit

Enter your choice:
```

---

## Learning Objectives

* Implement **Hash Tables and Chaining**
* Learn about **collision resolution techniques**
* Apply **DSA concepts** to real-world systems
* Practice **dynamic data management** using C++

---

## Limitations

* No file storage (data lost on program exit)
* Only console-based interface
* Simple hash function (can be improved for real-world scenarios)

---

## Future Improvements

* Implement **persistent storage (file/database)**
* Use **more advanced hash functions** (e.g., SHA family for better key distribution)
* Develop a **GUI interface**
* Add **biometric data handling** for advanced NADRA simulation

---

## Contribution

Contributions are welcome!

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Open a Pull Request

---

## License

This project is **open-source** under the **MIT License**.

---

## Acknowledgements

Developed by **[M Wasiq](https://github.com/m-wasiq-37)**
For academic practice in **Data Structures (Hashing) using C++**
