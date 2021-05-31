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
	int fd1[2],fd2[2];
	//Creating unmaned pipe1
	int ret1=pipe(fd1);
	if(ret1==-1)
	{
		printf("Pipe could not be created\n");
		return 1;
	}
	//Creating unnamed pipe2
	int ret2=pipe(fd2);
	if(ret2==-1)
	{
		printf("Pipe could not be created\n");
		return 1;
	}
	//Creating a child process
	int pid=fork();
	if(pid==0)//child process
	{
		//close write end of pipe1
		close(fd1[1]);
		//close the read end of pipe2
		close(fd2[0]);
		//recieve data from read end
		read(fd1[0],&r,sizeof(r));
		//Printing the recieved data
		printf("Data recieved from parent process:c=%d,d=%c\n",r.c,r.d);
		//Writing data back to parent process
		write(fd2[1],&r,sizeof(r));
	}
	else
	{
		//parent process
		//data stored to send
		s.a=20;
		s.b='c';
		//close the read end of pipe1
		close(fd1[0]);
		//close the write end of pipe2
		close(fd2[1]);
		//Writing data to teh child process
		write(fd1[1],&s,sizeof(s));
		//reading data from child process
		read(fd2[0],&r,sizeof(r));
		printf("Data recieved from child process:c=%d,d=%c\n",r.c,r.d);
		
	}
}

