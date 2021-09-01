# C Workshop Exam

Exam solution for C Workshop course August 2021

## Documentation

[Documentation](https://abrahammurciano.github.io/C-Workshop-Exam/html/files.html)

## Visual Studio Code

The files [`.vscode/launch.json`](.vscode/launch.json) and [`.vscode/tasks.json`](.vscode/tasks.json) contain tasks to build, run, and debug the project.

## Makefile

To compile the String library, run the following command. It will create a file `libString.a` which is the library file that can be linked by the linker.

```
make String
```

To compile and run the tests, run the following commands.

```
make Test
./src/StringTest
```

To compile the documentation, run the following command.

```
make docs
```

To do all of above, run

```
make all
```

## Authors

-   [Abraham Murciano](https://www.github.com/abrahammurciano)
