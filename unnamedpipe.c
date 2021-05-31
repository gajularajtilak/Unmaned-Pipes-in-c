#include<stdio.h>
#include<unistd.h>
struct senddata
{
int a;
char b;
}s;
struct recvdata
{
int c;
char d;
}r;
int main()
{
	//Creating 2 file descriptors for fd[0]-read end and fd[1]-write end
	int fd[2];
	//Creating a unmaned pipe
	int ret=pipe(fd);
	if(ret==-1)
	{
		printf("Pipe could not be created\n");
		return 1;
	}
	//Creating a child process
	int pid=fork();
	if(pid==0)//child process
	{
		//close write end of the child pipe which is cloned
		close(fd[1]);
		//recieve data from read end
		read(fd[0],&r,sizeof(r));
		//Printing the recieved data
		printf("Data recieved from parent process:c=%d,d=%c\n",r.c,r.d);
	}
	else
	{
		//parent process
		//data stored to send
		s.a=20;
		s.b='c';
		//close the read end of parent pipe
		close(fd[0]);
		//Writing data to teh child process
		write(fd[1],&s,sizeof(s));
	}
}

