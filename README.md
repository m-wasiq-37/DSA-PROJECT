# 🆔 NADRA Management System (DSA Project - C++ | Hashing & Collision Resolution)

## 📝 Project Overview

This project is a **NADRA (National Database & Registration Authority) Management System** developed using **C++** and advanced **Data Structures & Algorithms (DSA)** concepts.
It simulates the storage and management of **CNIC-based citizen data** using **hashing techniques** for efficient searching, insertion, and deletion.

---

## ⚙️ Features

* **Register Citizen:**

  * CNIC, Name, Father’s Name, Gender, Address
* **Search Citizen by CNIC**
* **Delete Citizen Record**
* **Display All Records**
* **Collision Handling using:**

  * **Linear Probing**
  * **Linked List Chaining**
  * **Binary Search Tree (BST) Chaining**
* **Performance Metrics:**

  * Count of **Insertion Collisions**
  * Count of **Search Collisions**

---

## 📊 Data Structures Used

| Data Structure             | Purpose                                |
| -------------------------- | -------------------------------------- |
| **Hash Table**             | Main storage (based on CNIC)           |
| **Linear Probing**         | For open addressing collision handling |
| **Linked List Chaining**   | For separate chaining                  |
| **BST Chaining**           | For tree-based chaining                |
| **Random Data Generation** | Random names, addresses, CNICs         |

---

## 🛠️ How It Works

1. **CNIC Hashing:**
   A **rolling hash function** hashes CNIC strings into integer keys.

2. **Collision Handling Techniques:**

   * **Linear Probing**: Sequential search for the next empty slot.
   * **Linked List Chaining**: Each hash slot points to a linked list of colliding entries.
   * **BST Chaining**: Each hash slot points to a **binary search tree** for faster collision management.

3. **Operations Supported:**

   * Insertion of citizen records
   * Searching by CNIC
   * Deletion of records
   * Display all data

---

## 🧰 File Structure

```
NADRA-Management-System-DSA-Hashing-Cpp/
│
├── 082_Wasiq_Part1.cpp   # Main NADRA system (Citizen records using CNIC & Hashing)
├── 081_Wasiq_part2.cpp   # Additional hashing methods with numerical data (Prime/Even/Odd IDs)
├── Namesboys.txt         # Random names for male citizens
├── Namesgirls.txt        # Random names for female citizens
├── Address.txt           # Random addresses for citizens
├── README.md              # Project documentation (this file)
```

---

## 🚀 How to Run

### 1️⃣ Clone the Repository:

```bash
git clone https://github.com/m-wasiq-37/DSA-PROJECT.git
cd DSA-PROJECT
```

### 2️⃣ Compile the Code:

For Windows:

```bash
g++ 082_Wasiq_Part1.cpp -o nadra_system
nadra_system.exe
```

For Linux/macOS:

```bash
g++ 082_Wasiq_Part1.cpp -o nadra_system
./nadra_system
```

---

## 🖥️ Menu Example

```
1. For Linear Probing
2. For Linked List Chaining
3. For BST Chaining
4. Exit

Enter your choice:
```

Each method has submenus for:

* Insertion
* Deletion
* Searching
* Display All Records

---

## 📈 Performance Output Example

At the end, the system reports:

```
Linear Probing:
Collisions in Insertion: [count]
Collisions in Search: [count]

Linked List Chaining:
Collisions in Insertion: [count]
Collisions in Search: [count]

BST Chaining:
Collisions in Insertion: [count]
Collisions in Search: [count]
```

---

## 🎯 Learning Objectives

* Implement **Hashing with Collision Resolution**
* Compare **Linear Probing, Linked List Chaining, and BST Chaining**
* Use **Random Data Generation** for testing
* Apply **DSA concepts** in a real-world problem scenario

---

## 🗂️ Limitations

* No persistent storage (data is lost on exit)
* Files like `Namesboys.txt`, `Namesgirls.txt`, and `Address.txt` must exist in the same directory
* Only console-based UI

---

## 🔮 Future Improvements

* Add **file-based storage** (save and load data)
* Implement **better hash functions** for real CNIC patterns
* Develop a **GUI frontend**
* Compare time complexities using actual timing functions

---

## 🤝 Contribution

Contributions are welcome!
Feel free to fork, enhance features, or add new data structures.

---

## 📄 License

This project is **open-source** under the **MIT License**.

---

## 🙌 Acknowledgements

Developed by **[M Wasiq](https://github.com/m-wasiq-37)**
For academic practice in **Hashing, Collision Handling, and Data Structures (DSA)**.
