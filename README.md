## Warning 

The sharing of this project on my GitHub aims to help peoples to open their minds to new logics or help peoples in case of difficulty. In no way, that aims to copy and paste this work on your own repository.
# minitalk

**minitalk** is a project from the **42** Common Core, The project aims to create two programs, a server and a client. Those two programs can communicate only by using signals **SIGUSR1** and **SIGUSR2** and must transmit a message.

### Usage

    terminal 1 $> make
    terminal 1 $> ./server
    terminal 2 $> ./client <server_PID> "your_text"
		    or
	terminal 2 $> ./client <server_PID> < file.txt
## bonus

- Your server and client must to support UNICODE.
- Create an acknowledgement of receipt to check if every signal have been caught

