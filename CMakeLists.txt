cmake_minimum_required(VERSION 3.16)
project(PaymentSystemSolution)

# Find Qt6 components
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

# Enable automatic MOC for Qt signals/slots
set(CMAKE_AUTOMOC ON)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Include directories for your headers
include_directories(
    ${PROJECT_SOURCE_DIR}/Backend
    ${PROJECT_SOURCE_DIR}/GUI
)

# Add all source files including template instantiations
add_executable(PaymentSystem
    main.cpp
    GUI/PaymentSystemWindow.cpp
    Backend/Invoice.hpp
    Backend/CardMethod.hpp
    Backend/ChequeMethod.hpp
)

# Link Qt libraries
target_link_libraries(PaymentSystem Qt6::Core Qt6::Widgets)
