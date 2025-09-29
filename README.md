# Project Name: Payment System Solution Version 1

## Description
- This project started as me accidentally discovering QT researching for frameworks. I was always fascinated by Software and both the visible and invisible aspects of both software and how data moves around.  
- I was inspired to build a simple payment system full stack by exploring how GUI's are made, how data gets handled by apps we use everyday. I wanted to learn full stack concepts in more practice with C++. 

## Tech Stack
- **Frontend:** QT6 tools, Classes: PaymentSystemWindow
- **Backend:** Classes: Payment(CardMethod, ChequeMethod), Invoice

## Features
- GUI built with Qt6 tools  
- CMake automation tool with `CMakeLists.txt` instructions  
- Local project configuration using JSON files (**do not commit these**)  
- Temporary class data storage in CSV files until GUI closes  


## Installation (bash or zsh)

### 1. Open in Browser
Go to QT website and download QT5 or QT6 tools

### 2. Open in CLI (Terminal)
- brew install cmake

### 3. Clone the repository
- git clone https://github.com/your-username/your-repo.git
- cd your-repo
- mkdir .vscode

### 4. Open in VSCode directory .vscode Prepare local JSON configs (user-specific)
 - c_cpp_properties.json
 - settings.json
 - tasks.json

### 5. Setup project
- prepare .json configs in .vscode (c_cpp_properties.json, settings.json, tasks.json)
- cmake -B build -DCMAKE_PREFIX_PATH=$HOME/directory-to-qt5-or-qt6-tools
- cmake -B build
- cmake --build build
- ./build/build-executable-name



### Folder Structure
- root/
- ├─.vscode/               # User-specific VSCode configs (do not push!)
- ├─backend/               # C++ backend classes
- ├─GUI/                   # QT framework tools called up
- ├─CMakeLists.txt         # Instructions for Cmake build generator
- ├─main.cpp               # Automates project build/run
- ├─simulated_server.csv   # Temporary storage of data
- ├─ README.md



