
// GTRACE HEADER FILE
// Radokhleb Valery
// Version 1.0
// ██████╗ ██████╗ ██╗  ██╗        ████████╗██████╗  █████╗  █████╗ ███████╗        ████████╗ █████╗  █████╗ ██╗
// ██╔══██╗██╔══██╗██║  ██║        ╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔════╝        ╚══██╔══╝██╔══██╗██╔══██╗██║
// ██████╔╝██║  ██║███████║           ██║   ██████╔╝███████║██║  ╚═╝█████╗             ██║   ██║  ██║██║  ██║██║
// ██╔══██╗██║  ██║██╔══██║           ██║   ██╔══██╗██╔══██║██║  ██╗██╔══╝             ██║   ██║  ██║██║  ██║██║
// ██║  ██║██████╔╝██║  ██║           ██║   ██║  ██║██║  ██║╚█████╔╝███████╗           ██║   ╚█████╔╝╚█████╔╝███████╗
// ╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝           ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝ ╚════╝ ╚══════╝           ╚═╝    ╚════╝  ╚════╝ ╚══════╝
// GTRACE HEADER FILE

#pragma once
#include <windows.h>

#define _LOCAL setlocale(LC_ALL, "")

typedef char* _PATH; // Path of the files
typedef char* _COM; // Command
typedef char* RESULT; // Result launch full command


// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Error codes: 1 - malloc error; 2 - Usage; 3 - arg NULL error;+
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Launch with args from command prompt
VOID Launch(_COM command);
// Heap malloc safety function
PVOID Malloc_handler(size_t size);
// Usage (Help alert) if args above 2
VOID Usage(int argc, _COM command);
// Add one argument in result command
VOID Add_arg(char* buffer, size_t size_of_buffer, _COM arg);
