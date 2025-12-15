# 🚂 Railway Reservation System (C-Language)

A simple, console-based Railway Reservation System implemented entirely in C, designed to handle basic operations like ticket booking, cancellation, availability checks, and data persistence.

## ✨ Features & ⚙️ System Workflow

The system provides the following core functionalities to the user:

* **Ticket Booking:** Allows users to book new tickets by providing necessary journey details (e.g., train number, destination, passenger info).
* **Ticket Cancellation:** Facilitates the cancellation of existing bookings using a unique identifier (like a Booking ID).
* **Check Availability:** Enables users to check the current seat availability for a specific train or route.
* **View All Bookings:** Displays a comprehensive list of all currently booked tickets stored in the system.
* **Data Persistence:** Ensures that booking data is saved and retained even after the program is closed, thanks to file handling.

## 💻 Tech Stack

This project is built using the following technologies:

* **Language:** C (Standard C language features and libraries)
* **Data Storage:** File Handling
    * **File Name:** `bookings.dat`
    * **File Type:** Binary File is used for efficient reading and writing of structured booking data.

## 🛠️ Prerequisites

To compile and run this project, you will need a standard C compiler, such as:

* GCC (GNU Compiler Collection)
* Any other ANSI C compatible compiler

## ▶️ How to Run

1.  **Clone the Repository:**
    ```bash
    https://github.com/asmitston/Railway-Reservation-System
    ```
    (Replace with your actual GitHub URL)

2.  **Compile the Code:**
    Use a C compiler (e.g., GCC) to compile the source file(s):
    ```bash
    gcc main.c -o railway_reservations
    ```
    (Assuming your main source file is `main.c`)

3.  **Run the Executable:**
    Execute the compiled program from your terminal:
    ```bash
    ./railway_reservations
    ```

4.  **Usage:** Follow the menu prompts displayed on the console to perform various operations like booking, cancellation, and viewing records.

---

## 🙋 Author

* **Asmit Kumar** - (https://github.com/asmitston)

## 💡 Future Enhancements

* Integration of a basic GUI (Graphical User Interface).
* Implementation of user login/authentication.
* Advanced search and filtering options for bookings.
