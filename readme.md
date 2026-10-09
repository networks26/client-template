okay, so

* accept the task
* connect to the server
* git clone
* cd
* now, you need to connect to some port on the local machine with C program

yes, you may not know c, but you have most of the code, and you can figure out the rest.

# task 0

for that you need to modify this code, look in the source for comments
** you need to find how to pass a port number to a corresponding function

** you need to find out how to write  and read to the socket

** build it (cc -o client client.c)

** if the program compiled then run `nc -l -p <yourport>` and run your program to connect (in unix you run the program from the current directory by using `./programname`)

** there are remarks, you can try to use other functions instead of write and read

# task 1

now copy this file as client_http.c

```
cp client.c client_http.c
```


modify it to make a HTTP request to neverssl.com

for that you need to

* find its IP address (use some commandline tool)
* figure out the port (less /etc/services ?)
* write to the socket:

```
GET / HTTP/1.1\r\nHost: neverssl.com\r\nConnection: close\r\n\r\n
```

increase the receiving buffer size and see what you get.

compile client_http.c and run it.


try also to connect to mozz.us

that's all folks.
