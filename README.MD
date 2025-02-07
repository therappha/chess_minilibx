Work in progress, needs check validation.

# Minitalk Chess? Why Not?!

As if Minitalk wasn't boring enough...

This is a chess game I made using the concept of the **Minitalk** project from 42School, powered by the **MinilibX** library! 🎮♟️

## What is Minitalk?

Minitalk is a project at 42School where the goal is to communicate between two processes using only two signals: `SIGUSR1` and `SIGUSR2`. The objective is to send strings from a **client** and display them on a **server**.

In this project, I combined that concept with chess to create a fun project.

## Features

- Communicates between two processes with signals (just like Minitalk).

## How to Use

### Step 1: Clone the Repository

Clone the repository using the following command:

```bash
git clone --recursive git@github.com:therappha/chess_minilibx.git
```

### Step 2: Build the Game

Navigate into the project directory and build the game using:

```bash
make
```

### Step 3: Run the Server and Client

1. Start the server (this will print the server PID):

   ```bash
   ./server
   ```

2. Copy the server PID from the terminal and run the client:

   ```bash
   ./client <server_pid>
   ```

### Default Version (Local Game)

The default version of the game is just a normal chess game without the Minitalk communication. It's a local game using a single process. To run this version:

1. Build the default version with:

   ```bash
   make default
   ```

2. Launch the game with:

   ```bash
   ./chess
   ```

