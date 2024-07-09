# Clackalack  Shell

Shell designed in C, which runs basic commands including mkdir, ls
date, cd, echo, cat, pwd and rm. Addtionally clear and man commands also included
Documentation is my implementation of main commands.


## Features

- 2 options for each command.
- External commands implemented via forking and threading as well.
- man <command> prints details of function onto the function.
- cd pwd can read(or ignore) symoblic links and options availabe specially for handelling symoblic links.
- cat commmand can redirect output to file mentioned(creates the file in the directory if not already present)


## Contributing

Feel free to fork and add additional features on top of the shell. See all the
Documentations attached to get an idea of the capabilites of various commands and their
options. If you want me to update my repository feel free to reach out to me on github.


## Appendix

The external commands are by default run through forking
the shell process and running the respective file, however the project had
additonally demanded for implementing external commands also via threading
i.e you can run external commands on a sperate thread instead of a new process
as it does by default by using "&t" after the command.

example :
```sh
ls&t
```
```sh
date&t
```

## FAQ

#### What are symbolic links

Symbolic links are essentially and false links made to deceive programs that
a fail is in directory while it is else where. A file ka be present on a directory
but can be accessed through other directories by adding a symbolic link to original locaiton
of file in other directory.

#### What is redirection

Redirection allows commands to redirect their output from standard out(terminal usuall)
to another file, where you can process the output further.

