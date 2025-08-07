# C++ User Database with Custom MD5 Implementation

This is an advanced C++ console application that demonstrates a complete, object-oriented system for managing a collection of user data. A key and highly educational feature of this project is its own custom, from-scratch implementation of the **MD5 hashing algorithm** for handling passwords.

## About The Project

This project serves as an excellent portfolio piece for an intermediate-to-advanced C++ developer. It showcases a deep understanding of several complex topics:

*   **Object-Oriented Programming (OOP)**: The system is designed with well-defined classes (`Database` for a single user, `Users` for managing the collection) that encapsulate data and logic.
*   **Custom Data Structures**: The `Users` class uses a `std::map` to create an ID-based database of user objects, demonstrating effective use of the C++ Standard Library.
*   **Cryptographic Algorithm Implementation**: The `md5.h` file contains a from-scratch implementation of the MD5 hashing algorithm, showing a low-level understanding of bitwise operations, memory management, and cryptographic principles.
*   **C++ Best Practices**: The project uses modern C++ features like `initializer_list` for easy object construction.

## Project Structure

The application is modularized into several key files:

*   **`main.cpp`**: The entry point of the application. It demonstrates how to create user objects and manage them with the `Users` collection.
*   **`Database.h`**: Defines the `Database` class, which represents a single user. It holds the user's name, email, and hashed password and includes methods for input and display.
*   **`Users.h`**: Defines the `Users` class, which acts as a container for all user objects. It uses a `std::map` to associate a unique ID with each user.
*   **`md5.h`**: A header-only library containing a custom implementation of the MD5 hashing algorithm. This is used to hash user passwords upon input.

## How to Build and Run

You will need a C++ compiler (like G++, Clang, or MSVC).

1.  Place all the header and source files (`.h` and `.cpp`) in the same directory.
2.  Open a terminal or command prompt in that directory.
3.  Compile the project:
    ```sh
    g++ main.cpp -o user_db_app -std=c++11
    ```
    *Note: The `-std=c++11` flag ensures modern features are enabled.*
4.  Run the executable:
    ```sh
    ./user_db_app
    ```

---

## ‼️ Important Notes on the MD5 Implementation ‼️

Implementing a cryptographic algorithm from scratch is a fantastic learning exercise. However, it's crucial to understand the security implications and design choices of the provided `md5.h` file.

### 1. Security of MD5

*   **MD5 is Obsolete and Insecure**: The MD5 algorithm is considered **cryptographically broken** and is no longer safe for security-sensitive applications like password hashing. It is highly vulnerable to collision attacks.
*   **Educational Use Only**: This implementation should be viewed as an academic exercise in understanding how hashing algorithms work. **It should never be used in a real-world, production environment.** For secure password storage, modern standards recommend using algorithms like **Argon2**, **bcrypt**, or **scrypt**.

### 2. Design and Implementation Issues

*   **Use of Global Variables**: The `md5.h` file relies heavily on global variables (`A`, `B`, `C`, `D`, `T`, `block`, etc.). This is a poor design practice that makes the code difficult to maintain, understand, and use safely, especially in a multi-threaded context. A better approach would be to encapsulate the entire MD5 state within a class or struct.
*   **Flawed Hashing Logic in `Users::GetUsers`**:
    *   The `GetUsers` method re-hashes passwords that are already supposed to be hashed. The logic `if (it.second.getHashPassword() != hashedPassword)` will almost always be true because it compares a raw password string (mistakenly stored as a hash) with a newly computed hash of that same string.
    *   This indicates a misunderstanding in the main application logic of how password hashing should be handled (i.e., you hash on input/creation, then compare hashes, you don't re-hash existing hashes).

### Conclusion

This project is a very impressive C++ programming demo, especially the custom MD5 implementation. It's a testament to the developer's skill and ambition. The security and design notes above are intended to provide context and highlight areas for improvement, turning the project into an even more valuable learning tool.
```
