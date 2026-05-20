<h1 align="center">🎓 Student Information Management System</h1>

<p align="center">
A simple and efficient C-based console application for managing student records using both text and binary file handling.
</p>

<hr>

<h2>📌 Project Overview</h2>
<p>
This project is a <b>Student Information Management System</b> developed using the C programming language.
It allows users to store, search, and display student data such as name, academic number, and grades for multiple subjects.
The system demonstrates practical usage of <b>file handling (text & binary)</b>, <b>structures</b>, and <b>data validation</b>.
</p>

<hr>

<h2>⚙️ Features</h2>
<ul>
  <li>➕ Add new student records</li>
  <li>📄 Store data in both text file and binary file</li>
  <li>🔍 Search for students by Academic Number</li>
  <li>🔍 Search for students by Name</li>
  <li>📊 Display all stored student records in a structured format</li>
  <li>✔️ Input validation for grades (0 - 100)</li>
</ul>

<hr>

<h2>🧠 Technologies Used</h2>
<ul>
  <li>C Programming Language</li>
  <li>File Handling (fopen, fwrite, fread, fprintf)</li>
  <li>Structures (struct)</li>
  <li>String Handling (string.h)</li>
</ul>

<hr>

<h2>📂 Project Structure</h2>
<pre>
Student Information System
│
├── main.c              # Source code
├── degree.txt          # Text file storage
├── Bdegree.bin         # Binary file storage
</pre>

<hr>

<h2>🚀 How to Run</h2>
<ol>
  <li>Compile the program using a C compiler (e.g., GCC)</li>
  <li>Run the executable file</li>
  <li>Choose an option from the menu</li>
</ol>

<pre>
gcc main.c -o student
./student
</pre>

<hr>

<h2>📸 Program Menu</h2>
<pre>
1 - Add Student Information
2 - Show All Students
3 - Search Student Information
4 - Exit
</pre>

<hr>

<h2>📌 Notes</h2>
<ul>
  <li>Data is stored permanently using file handling</li>
  <li>Binary file improves performance and structured storage</li>
  <li>Input validation ensures correct grade entry</li>
</ul>

<hr>

<h2 align="center">💡 Developed in C for learning purposes</h2>
<p align="center">Built to practice structures, file handling, and real-world data management logic.</p>
