# Unmaned-Pipes-in-c
Inter Process Communication using unnamed pipes in linux using C
Introduction to unnamed pipes:
1.Unnamed Pipes are method for Interprocess communication in linux and they can communicate between related process only(Ex: Parent and Child).
2. An unnamed pipe has 2 ends one to read from pipe and other to write to the pipe so pipes use 2 file descriptors for this.
3. To create a pipe we use a command call pipe(file descriptor name).
