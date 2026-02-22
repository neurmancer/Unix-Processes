# Unix-Processes 

- **This repo is for learning fork() and processes for improve ShittyJukebox project and all the lecture(ish) shit will be in here**

## Lectures
- Added 1.c, about fork() (Introduction)
- Added 2.c, about wait() (Introduction)
- Added 3.c, still about wait(but now I partially know what the NULL thingy is)
- Added 4.c, about pipe() (it was cool, felt like cyber-sorcery)
- Added 5.c, using pipe() to split work between processes (R.I.P my Ryzen5 2600X from 2018)
- Added 6.c about fifo() an introduction to fifos
- Added 7-1.c & 7-2.c continuing to poke fifo() and idea is reading data in 7-2.c written to 'sum' by 7-1.c compile <br>
them both and execute at the same time or they'll simply wait idle 
- Added 8.c about IPC with more than one pipe sending/getting data from both parent and child process
- Added 9.c about execlp() and running bash commands on terminal
- Added 10.c about error handling and wait(&errID)
- Added 11.c based on 10.c and redirecting exec()'s output to another file using dup2()
 

## Examples 
- This part is fuck around and find out zone(probably will have a forkbomb for fun too)
- Yup I did as I said added a fucking fork bomb without any guardrails using it isn't advised and at your own risk(IDC)


## STATS

- **Encountered zombies** : 2
- **Killed children** : 1   (R.I.P)
