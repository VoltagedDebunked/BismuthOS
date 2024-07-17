# BismuthOS

This is a simple operating system project. It includes a basic bootloader and kernel setup in C++.

## Building and Running

### Prerequisites

- `nasm`
- `i386-elf-gcc`
- `i386-elf-ld`
- `qemu` (for emulation)

### Build

```sh
make
```

## Features

## Core Functionalities
### Memory Management

Basic memory initialization and setup.
Functions to manage memory allocation.
## Shell Interface

Basic command-line interface.
Commands like echo, help, and exit.
User authentication integrated with the shell.
## User Authentication

Basic user authentication system with predefined usernames and passwords.
## GPU Support

Initialization of VESA-compatible graphics mode.
Basic graphics functions like clearing the screen and drawing pixels.
##  Packages System
### Package System
Ability to import and manage packages.
#### Example packages:
linuxdistroimport: Imports a Linux distro as a Docker container.
devmode: Enables developer mode for additional functionalities.
## Directory Structure

BismuthOS/
├── config/
│   └── structure.md
├── public/
│   └── readme.md
├── build/
├── include/
│   ├── kernel/
│   │   ├── shell.h
│   │   ├── security.h
│   │   ├── gpu.h
│   └── other/
├── src/
│   ├── arch/
│   │   └── x86/
│   │       ├── boot.asm
│   │       ├── gdt.cpp
│   │       ├── gdt.h
│   │       └── kernel_entry.cpp
│   ├── kernel/
│   │   ├── main.cpp
│   │   ├── memory.cpp
│   │   ├── memory.h
│   │   ├── shell.cpp
│   │   ├── security.cpp
│   │   ├── gpu.cpp
│   │   └── ...
│   ├── system/
│   │   └── config.sys
│   ├── memory/
│   │   └── memory.asm
│   ├── packages/
│   │   ├── linuxdistroimport/
│   │   │   ├── linuxdistroimport.h
│   │   │   └── linuxdistroimport.cpp
│   │   └── devmode/
│   │       ├── devmode.h
│   │       └── devmode.cpp
│   └── ...
├── linker.ld
├── Makefile
└── data/
    └── icons/
        ├── icon.ico
        └── icon2.ico

## Configuration Files
JSON and XML configuration files for system settings.
## Security Features
Basic user authentication with predefined users and passwords.
## Graphics Features
Basic VESA graphics mode initialization.
Screen clearing and pixel drawing functions.
## Summary
BismuthOS is a simple operating system project that includes core functionalities like memory management, a command-line interface with user authentication, and basic GPU support. It also has a package system to extend its capabilities with additional features. The project structure is organized and includes necessary build scripts and configuration files.
