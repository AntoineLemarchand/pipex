# Pipex
## Grade
**121/100**

A 42Paris project.

## Description

Pipex is a program to recreate a pipe system and redirection system

## Usage

```
make
./pipex file1 command1 command2 file2
```
should simulate
```
< file1 command1 | command2 > file2
```
for example
```
./pipex infile "ls -l" "wc -l" outfile
```
should act the same as
```
< infile ls -l | wc -l > outfile
```
