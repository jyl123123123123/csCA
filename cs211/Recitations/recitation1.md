## Hello world!
This is cs211 recitation#1 note.

```txt
Host rutgers
    HostName cd.cs.rutgers.edu
    User jl3601
```
SSH rutgers

### nano
To edit: press i \
To quit: press esc, then input ":wq" to save and quit. \
To compile code: 
```
gcc -o 
```
after-compiledName 
```
fileName.c
```

### Use Terminal/Command Line application aka SSH
$ ssh netid@address \
If you want GUI and connect via web browser, go to https://weblogin.cs.rutgers.edu/ \
If you want GUI, install X2GO client 

## Basic Linux Commands

Check out this: http://linuxcommand.org/index.php
```
ssh: login to any machines remotely

pwd: show current location

cd: change directory (eg. $cd Documents, or $ cd ..)

ls: list all contents 
    (check http://www.rapidtables.com/code/linux/ls.htm)

locate: show location of a file (eg. $locate test.txt)

grep: search texts in files (e.g. $ grep “cs 211” *.txt)
     (check http://www.cyberciti.biz/faq/howto-use-grep-command-in-linux-unix/)

version: show version (eg. $ java -version)

cat: print contents on screen (ex. $ cat test.txt)

touch: create a file (eg. $ touch test.txt)

nano, vim: editor (eg. $ nano test.txt)
cp: copy file (eg. $ cp source.txt destination.txt)

mkdir: make directory (eg. $ mkdir myfolder)

rm: remove file (eg. $ rm test.txt)

mv: rename file (eg. $ mv oldname.txt newname.txt)

scp: transfer file from local to server machine and vice versa ( $ scp source destination)

Local computer to iLab

$ scp -r local-folder/ netid@ilab4.cs.rutgers.edu:~/

iLab to Local (execute command from local machine)

$ scp -r netid@ilab4.cs.rutgers.edu:~/remote-folder/ /home/

%9s indicates the length of the string
--> scanf("%9s", str);
```