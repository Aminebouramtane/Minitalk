# Minitalk

Minitalk is a simple client-server communication program implemented in C, where the server receives a string of characters from the client and displays it. This project is part of the 42 curriculum.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

The aim of this project is to introduce the concept of inter-process communication using signals in Unix-based systems. The client sends a message to the server one character at a time, and the server receives and prints the message once it's complete.

## Features

- Simple client-server architecture
- Inter-process communication using signals
- Support for transmitting messages between client and server

## Installation

To install and run this program, follow these steps:

1. Clone this repository:
    ```sh
    git clone https://github.com/your-username/minitalk.git
    ```

2. Navigate to the project directory:
    ```sh
    cd minitalk
    ```

3. Compile the server and client programs:
    ```sh
    make
    ```

## Usage

### Server

To run the server, execute the following command:
```sh
./server ```
The server will display its process ID (PID) upon startup and wait for messages from the client.
