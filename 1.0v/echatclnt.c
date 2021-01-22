#include <stdio.h>
#include <unistd.h>
#define FIFO_NAME "./chat-fifo"
int main()
{
char ch;
FILE * f =fopen ( FIFO_NAME, "r ");
do
{
ch=fgetc(f);
putchar(ch);
}
while (ch!='q');
fclose(f);
unlink(FIFO_NAME);
return 0;
}
 

