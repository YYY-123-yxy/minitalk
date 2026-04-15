# Minitalk

*This project has been created as part of the 42 curriculum by ziyang.*

## Description 

Minitalk is a small client/server communication program designed to deepen the understanding of UNIX signals and process communication. The primary goal is to transmit a string from a client process to a server process using only two signals: SIGUSR1 and SIGUSR2.

The project challenges the developer to handle bitwise manipulation, signal interruption, and process synchronization. The server must be able to receive strings from multiple clients in succession without needing a restart, displaying the message once it is fully reconstituted.

## Instructions

### Compilation

The project includes a Makefile that compiles both the client and server executables.

```Bash
make
```
To compile the mandatory part

### Execution

- Start the Server:
Launch the server first. It will display its Process ID (PID).

```Bash
    ./server
```

- Run the Client:
    In a separate terminal, run the client by providing the server's PID and the message you wish to send.

```Bash
    ./client <SERVER_PID> "message"
```

## Resource

- [minitalk: a simple client-server communication system minitalk](https://medium.com/@leogaudin/minitalk-a-simple-client-server-communication-system-57ccc2ae5178)