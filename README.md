# 💰 Monthly Money Coach (Expense & Budget Tracker)

## 📌 Overview

This project is a **C++ Expense & Budget Tracker** converted into a **web application using Emscripten** and deployed via **GitHub Pages**.

It helps users:

* Track daily expenses
* Monitor monthly spending
* Analyze category-wise expenses
* Get alerts when budget is exceeded

---

## 🚀 Features

### 🧾 Expense Management

* Add expense (Date, Category, Amount, Note)
* View all expenses

### 🔍 Search

* Search by **category**
* Search by **date**

### 📊 Reports

* Monthly total expense
* Category-wise total
* Budget limit warning

### ✅ Validation

* Amount must be positive
* Category must not be empty

---

## 🛠 Technologies Used

* **C++ (OOP concepts)**
* **Emscripten** (C++ → WebAssembly)
* **HTML + JavaScript**
* **GitHub Pages** (deployment)

---

## 🧱 OOP Concepts Used

* Classes (`Expense`, `BudgetManager`)
* Encapsulation (private data members)
* Constructors
* Member functions
* Vector (STL)

---

## 📂 Project Structure

```
cpp-mini-project/
│── index.html
│── index.js
│── index.wasm
│── main.cpp
```

---

## 🌐 Live Demo

👉 https://ak-vj.github.io/cpp-mini-project-25BCE5116/

---

## ▶️ How to Run Locally

### 1. Install Emscripten

```
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
emsdk install latest
emsdk activate latest
emsdk_env.bat
```

### 2. Compile

```
em++ main.cpp -o index.html
```

### 3. Run

Open `index.html` in a browser (or use Live Server)

---

## 🧪 Sample Input (Test Sequence)

```
1
10-04
Food
200
Breakfast
1
11-04
Travel
500
Bus fare
1
12-04
Bills
1200
Electricity
2
3
Food
4
11-04
5
6
Travel
7
```

---

## ⚠️ Notes

* Input is taken via browser prompt (one value at a time)
* All files must remain in the same directory for proper execution
* WebAssembly requires running via a server (GitHub Pages works)

---

## 🎯 Learning Outcomes

* Applied OOP concepts in C++
* Learned file handling and data persistence
* Understood WebAssembly and Emscripten workflow
* Deployed a C++ project as a web application

---

## 👨‍💻 Author

**Akshay Vijayan**
Roll No: 100001

---

## ⭐ Acknowledgement

This project was developed as part of academic coursework to demonstrate C++ programming and web deployment concepts.
