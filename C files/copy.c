#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
int main (int argc, char* argv[]) {
  int src_fd;
  int cpy_fd;
  char filebuf[256]; /* a small buffer used to copy the file */
  ssize_t readSize;

  src_fd = open(argv[1], O_RDONLY);
  cpy_fd = open(argv[2], O_RDWR);

  if (src_fd < 0) {
	printf("Source file does not exist, exiting program");
	return -1;
  }

  else if (cpy_fd >= 0) {
	printf("Copied file already exists, exiting program");
	return -1;
  }

  else {
    cpy_fd = open(argv[2], O_RDWR|O_CREAT, 111111111);
    while (( readSize = read(src_fd, filebuf, sizeof(filebuf)-1)) > 0)
    {
       // I turn it into a string only because I'm using printf;
       // making a copy using "write" would not need this.
       // filebuf[readSize] = '\0';
       // printf("%s",filebuf);
       write(cpy_fd, filebuf, readSize);
    }
  }
  close(src_fd);
  close(cpy_fd);
  return 0;
}

