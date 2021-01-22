#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#define FIFO_NAME "./chat-van"
int main()
{
char ch;
mkfifo(FIFO_NAME , 0600);
FILE * f = fopen ( FIFO_NAME, "w");
if (f == NULL)
{
printf("Failed to open FIFO!\n");
return -1;
}
do
{
ch=getchar();
fputc(ch,f);
if (ch==10) fflush(f);
}
while(ch!= 'q');
fclose(f);
unlink(FIFO_NAME);
return 0;

}


