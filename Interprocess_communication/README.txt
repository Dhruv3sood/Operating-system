
FIFO:
Two programs are created:
FIFO_Sender   : which sends five consecutive strings
FIFO_Reciever : which recieves the strings and sends the largest ID

A common FIFO file called Main_Fifo is created in the sender file.
This file acts as an intermediate point of communication between the two proceses.

FIFO_Sender:
A 2D array is created with 50 rows [50 strings] and 11 columns [assumed the length of each string to be 10 characters]
With the help of rand() function, random characters are added to each string.
After this, the Main_Fifo file is opened for writing the strings to file.
First the id of the current string is written. 
Then the length of the string
After this five strings are written one by one.
The file is then closed and reopened in read mode
Now read the ID value sent by the second program and display it. 
Close the file again. 

FIFO_Reciever:
2D array with the same dimensions as the sender array are created.
The Main_Fifo file is opened in read mode to read the strings.
First, the starting index is read followed by the size of the strings
Then the strings are read. 
The file is closed and reopened in write mode. 
The index of the last string is written back to the file and then the file is closed.

UNIX DOMAIN SOCKETS:

A random_string_generator() is written, which generates a random string of the specified lenght given in it as 
the argument.
The unix domain socket works two ways like the above two, one is the server which is our P1 program and the other is 
client which is our P2 program.
In the P1 program, firstly a socket connection is estabilished using the "socket" command. Then a bind command is used
to bind the socket to a known addres so that the client can connect to it. Then the listen command is used to mark the
socket as passive, i.e. now the socket will accept incoming connection requests.
We know that the servers are continously up, so it is a good practice to keep the funcionalities of the server in an
infinite loop. Now the accept command is used to accept the incoming connection request. Now again in a loop of 10, batches
of 5 strings is written using the write system call, to communicate to the client. 
In the P2 program also the socket is created with the same name as that of P1 to communicate with it. Then "connect" 
system call is used to coonnect to the server. Now in a loop of 10, the batches of 5 strings are read using the "read" 
syscall and is printed in the P2 terminal. Now the highest ID of the incoming strings is again sent to the server using 
the "write" syscall. In P1, these IDs is read and finally in the P1 terminal the highest IDs are being printed for each 
of the 10 batches. finally the connection is closed using the close syscall and the client is unlinked using the 
using the "unlink" syscall.
