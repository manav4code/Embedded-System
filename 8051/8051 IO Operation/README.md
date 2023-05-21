# C Programs for 8051 Microcontroller

This directory contains C programs written for the 8051 microcontroller. The programs are aimed at solving specific problems or implementing certain functionalities using the 8051 microcontroller.

## Prerequisites
Before running these programs, make sure you have the following:
- An 8051 microcontroller or a compatible development board.
- Keil uVision by ARM. Compiler C51.
- Header File - <REG51.h>

## Program Descriptions

### 1. Toggle all bits of P1 continuously
- **File**: LA_1.c
- **Description**: This program continuously toggles all the bits of Port 1 (P1) on the 8051 microcontroller.

### 2. Get byte of data from P1 and send it to P2
- **File**: LA_2.c
- **Description**: This program reads a byte of data from Port 1 (P1), waits for half a second, and then sends the data to Port 2 (P2) on the 8051 microcontroller.

### 3. Toggle bit D0 of P1 (P1.0) 50,000 times
- **File**: LA_3.c
- **Description**: This program toggles bit D0 of Port 1 (P1.0) on the 8051 microcontroller 50,000 times.

### 4. Generate square wave on P0.0 with ON time 3ms and OFF time 10ms
- **File**: LA_4.c
- **Description**: This program generates a square wave on Pin 0.0 (P0.0) with an ON time of 3ms and an OFF time of 10ms using the 8051 microcontroller.

### 5. Write a C language program that takes packed BCD number as an input at port 0. Convert them to ASCII and display them on P1 and P2
- **File**: SE1.c
