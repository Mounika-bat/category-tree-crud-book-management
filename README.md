# category-tree-crud-book-management

📘 Category Tree CRUD for Book Management:


👥 Team Members


Mounika

Nitya

🎯 Problem Statement


In an online bookstore, books are organized into different categories like Fiction, Education, Science, etc.
Managing these categories efficiently is important.
This project implements a Category Tree using Data Structures in C to perform CRUD operations on book categories.



🌍 Real-Time Application


This system simulates how an online bookstore organizes books using hierarchical categories.


Example:


Books
├── Fiction
│   ├── Novel
│   └── Stories
├── Education
│   ├── Science
│   └── Math


🏗 Data Structure Used


Tree (General Tree)


Implemented using:



struct

Pointer-based representation (child & sibling)


🔁 Features (CRUD Operations)


Operation	Description

Create	Add new category

Read	Display category tree

Update	Modify category name

Delete	Remove category

Search	Find category

⚙️ Algorithm Explanation


➤ Add Category


Search parent node
Insert new node as child or sibling

➤ Search

Use recursive traversal (DFS)

➤ Update

Search node and modify name

➤ Delete

Remove node and free memory

➤ Display

Print tree structure with indentation

💻 Technologies Used


C Programming Language

GCC Compiler

Dynamic Memory Allocation (malloc, free)

▶️ Compilation & Execution


gcc main.c -o project

./project

📊 Sample Output


1.Add Category

2.Delete Category

3.Update Category

4.Search

5.Display

6.Exit


Enter choice: 1

Enter parent category: Books

Enter new category: Fiction

Added successfully!


Enter choice: 5


Category Tree:

- Books

  - Fiction
  - 
📂 Project Structure


category-tree-crud-book-management/

│
├── src/

│   └── main.c

│
├── docs/

│   └── project_report.pdf

│
├── ppt/

│   └── presentation.pptx

│
├── sample_output.txt

└── README.md

🎥 Demo Video


📌 Google Drive Link: (Add your video link here)


🔒 Note: Keep the video private/restricted.


📈 Results

Successfully implemented tree-based category system

Performed all CRUD operations

Demonstrated dynamic memory usage

✅ Conclusion


This project demonstrates how tree data structures can be used in real-world applications

like online bookstores to manage hierarchical data efficiently.


🔮 Future Enhancements

Add book details under categories

Convert into GUI application

Store data using files

Improve delete operation

📚 References


Data Structures in C – Books & Notes

Online tutorials and documentation


<img width="1920" height="1020" alt="Screenshot 2026-04-24 235751" src="https://github.com/user-attachments/assets/96cd0aa9-b886-4fd4-8baa-5708051f31d0" />






<img width="1920" height="1020" alt="Screenshot 2026-04-24 235812" src="https://github.com/user-attachments/assets/d41d78f7-1a90-41e9-96bf-50405b52fefb" />




<img width="1920" height="1020" alt="Screenshot 2026-04-24 235850" src="https://github.com/user-attachments/assets/9989f172-cbe5-44df-aca0-b8ba680db3c1" />





<img width="1920" height="1020" alt="Screenshot 2026-04-24 235859" src="https://github.com/user-attachments/assets/e57b65e8-2891-4515-b755-41b598401588" />





