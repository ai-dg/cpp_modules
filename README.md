# C++ Modules - Advanced Object-Oriented Programming

📌 **42 School - C++ Specialization Track**  

## ▌ Description
The **C++ Modules** series is a comprehensive deep dive into **Object-Oriented Programming (OOP)**, memory management, and advanced C++ features.  
The goal of these modules is to progressively introduce **polymorphism, operator overloading, exceptions, STL, and advanced templates** while strictly following **C++98** standards.
<img src="assets/overview.png" alt="C++ Modules — overview" width="760">

```mermaid
flowchart TB
    A[Module 00<br/>C++ Basics] --> B[Module 01<br/>Memory and References]
    B --> C[Module 02<br/>Operator Overloading<br/>Canonical Form]
    C --> D[Module 03<br/>Inheritance]
    D --> E[Module 04<br/>Subtype Polymorphism<br/>Abstract Classes]
    E --> F[Module 05<br/>Exceptions]
    F --> G[Module 06<br/>Type Conversion<br/>Casts]
    G --> H[Module 07<br/>Templates]
    H --> I[Module 08<br/>STL Containers<br/>Iterators Algorithms]
    I --> J[Module 09<br/>Advanced STL<br/>Applied Problems]

    %% Cross-cutting skills
    B --> K[Core Skill<br/>RAII and Memory Safety]
    C --> L[Core Skill<br/>Rule of Three]
    E --> M[Core Skill<br/>Virtual Dispatch]
    I --> N[Core Skill<br/>Complexity and Iterators]

    %% Styling
    classDef basic fill:#4c72b0,color:#ffffff,stroke:#2c4a7a,stroke-width:2px;
    classDef memory fill:#55a868,color:#ffffff,stroke:#2f6f46,stroke-width:2px;
    classDef oop fill:#8172b2,color:#ffffff,stroke:#4b3f7a,stroke-width:2px;
    classDef runtime fill:#dd8452,color:#ffffff,stroke:#8a4a24,stroke-width:2px;
    classDef generic fill:#c44e52,color:#ffffff,stroke:#7a1f24,stroke-width:2px;
    classDef stl fill:#7f7f7f,color:#ffffff,stroke:#4a4a4a,stroke-width:2px;

    class A basic
    class B,C memory
    class D,E oop
    class F,G runtime
    class H generic
    class I,J stl

    class K,L,M,N stl

```

## ▌ Key Concepts Covered
▸ **Memory Management & Pointers**  
▸ **Ad-hoc & Subtype Polymorphism**  
▸ **Operator Overloading**  
▸ **Exception Handling**  
▸ **Abstract Classes & Interfaces**  
▸ **Templates & STL (Standard Template Library)**  

## ▌ Result: **All 10 modules validated**
All **10 modules** were successfully completed, covering core and advanced C++ topics. 🎉

## ▌ **Modules Overview**
| 📌 Module | Description |
|----------|-------------|
| **Module 00** ![Score](https://img.shields.io/badge/Completed-100%25-brightgreen) | Introduction to C++ - Namespaces, classes, member functions, and initialization lists |
| **Module 01** ![Score](https://img.shields.io/badge/Completed-100%25-brightgreen)   | Memory allocation, pointers to members, references, and switch statements |
| **Module 02** ![Score](https://img.shields.io/badge/Completed-100%25-brightgreen)   | Ad-hoc polymorphism, operator overloading, and Orthodox Canonical Form |
| **Module 03** ![Score](https://img.shields.io/badge/Completed-100%25-brightgreen)   | Inheritance and class hierarchy |
| **Module 04** ![Score](https://img.shields.io/badge/Completed-80%25-brightgreen)   | Abstract classes, interfaces, and subtype polymorphism |
| **Module 05** ![Score](https://img.shields.io/badge/Completed-100%25-brightgreen)   | Exception handling and bureaucratic form processing |
| **Module 06** ![Score](https://img.shields.io/badge/Completed-100%25-brightgreen)   | Type conversion and C++ casting (`static_cast`, `dynamic_cast`, `reinterpret_cast`) |
| **Module 07** ![Score](https://img.shields.io/badge/Completed-100%25-brightgreen)   | Function and class templates |
| **Module 08** ![Score](https://img.shields.io/badge/Completed-100%25-brightgreen)   | STL Containers, Iterators, and Algorithms |
| **Module 09** ![Score](https://img.shields.io/badge/Completed-100%25-brightgreen)   | Advanced STL - Bitcoin Exchange, Reverse Polish Notation, Merge Sorting |

## ▌ Example Implementations
### ■ **Module 02 - Operator Overloading**
- Implemented a **fixed-point arithmetic class** with overloaded operators.
- Ensured proper **copy constructor, assignment operator, and destructor**.

### ■ **Module 04 - Polymorphism**
- Designed an **Animal hierarchy** using **abstract classes**.
- Implemented **virtual destructors** and **dynamic binding**.

### ■ **Module 08 - STL Algorithms**
- Created a **custom container manipulator**.
- Implemented **iterators**, a templated `easyfind`, and used **`std::sort`**.

## ▌ Compilation & Usage
### ■ **Compile a Module** (each `CXX/exYY` folder has its own Makefile)
```sh
make
``` 

### ■ **Run an Example (e.g., Polymorphism)**
```sh
cd C04/ex02 && make && ./abstract  
```

## 📜 License

This project was completed as part of the **42 School** curriculum.  
It is intended for **academic purposes only** and follows the evaluation requirements set by 42.  

Unauthorized public sharing or direct copying for **grading purposes** is discouraged.  
If you wish to use or study this code, please ensure it complies with **your school's policies**.
