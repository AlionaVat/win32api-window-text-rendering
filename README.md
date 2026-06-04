# Win32 API Window Text Rendering

## Overview

This project demonstrates the creation of a native Windows desktop application using the Win32 API in C++.

The application creates a custom window with a colored background and renders multiple text elements using different colors and alignments. The project focuses on understanding the Windows message loop, window procedures, painting operations, and graphical output using the Win32 API.

---

## Features

* Native Win32 desktop application
* Custom window creation and registration
* Green window background
* Centered green text
* Top-right violet text
* Top-left yellow text
* Bottom centered red text
* Windows message handling (WM_PAINT, WM_DESTROY)
* Text rendering using DrawText()
* Custom color management using RGB values

---

## Technologies

* C++
* Win32 API
* Microsoft Visual Studio 2022
* Windows SDK

---

## Project Structure

```text
win32api-window-text-rendering/
│
├── README.md
│
├── src/
│   └── main.cpp
│
└── docs/
    └── Proiect_Win32API.pdf
```

---

## Learning Objectives

This project demonstrates:

* Creating and registering custom window classes
* Creating native Windows applications
* Working with the Windows message loop
* Handling WM_PAINT events
* Drawing text inside a window
* Using RGB color definitions
* Managing window resources
* Understanding event-driven programming

---

## Application Behavior

The application displays:

### Center Message

* Color: Green
* Alignment: Centered

### Top Right Message

* Color: Violet
* Alignment: Top Right

### Top Left Message

* Color: Yellow
* Alignment: Top Left

### Bottom Message

* Color: Red
* Alignment: Bottom Center

### Window Background

* Color: Green

---

## Build Instructions

### Requirements

* Visual Studio 2022
* Windows SDK
* C++ Desktop Development workload

### Build

1. Open Visual Studio 2022
2. Create a new Win32 Project
3. Replace the generated source code with `main.cpp`
4. Build the solution

```text
Build → Build Solution
```

or

```text
Ctrl + Shift + B
```

### Run

```text
Debug → Start Without Debugging
```

or

```text
Ctrl + F5
```

---

## Win32 Concepts Used

### Window Class Registration

```cpp
RegisterClassEx()
```

Registers the custom window class with the operating system.

### Window Creation

```cpp
CreateWindowEx()
```

Creates the application window.

### Message Loop

```cpp
GetMessage()
TranslateMessage()
DispatchMessage()
```

Processes user and system events.

### Text Rendering

```cpp
DrawText()
```

Draws text inside the window client area.

### Color Management

```cpp
SetTextColor()
RGB()
```

Defines custom text colors.

---

## Educational Purpose

This project was developed as part of a university assignment focused on Windows programming and graphical user interface development using the Win32 API.

---

## Author

Aliona Vataman

Software Engineering Student

Academy of Economic Studies of Moldova (ASEM)

