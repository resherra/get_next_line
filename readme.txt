hell
o ja
ck red
this is the first line 


BUFFER_SIZE 6;

read 6 | 'hello ' | check for \n --> not found.
read 6 | 'jack r' | check for \n --> not found. ==> join();
read 6 | 'ed\nthi'| check for \n --> found ==> store the part after \n in a static variable (char *rest)
                                           ==> join() the part before \n add \0 and return the line;
read 6 | 's is t' | check for \n --> not found. ==> join() with char *rest;
read 6 | 'he fir' | check for \n --> not found ==> join();
read 6 | 'st lin' | check for \n --> not found ==> join();
read 6 | 'e' (BUFFER_SIZE > read() return ;) => check for \n --> not found ==> join();




// first iteration
buffer[7];
char *line;
int readed;

buffer:
0 0 0 0 0 0 0

line:
0 0 0 0 0 0 0 

buffer:
'h e l l o '

line  = 'hello ';



//second iteration

buffer:
"hello "

line:
"hello "


buffer: 'jack r'


line:
hello buffer

thi



hello jack red

ed\nthi

read - truncated