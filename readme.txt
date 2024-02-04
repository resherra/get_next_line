hell
oja
cred
this is the linee


BUFFER_SIZE: 10;

char buffer[BUFFER_SIZE + 1];
static char *line;
char *next_line;
char *tmp;
int readed;
int truncated;


FIRST ITERATION

buffer[11]
line = null;
next_line = NULL;
readed = 10;
tmp = NULL;
truncated = -1;



readed = 10;
buffer = "hell\noja\nc\0"
line = strjoin(line, buffer); ==> "hell\noja\nc\0"
truncated = ft_trunc(line); ==> 4;
next_line[4 + 2];
strlcpy(next_line, "hell\noja\nc\0", 4 + 2);
next_line = hell\n;
line = strdup(line + truncated + 1); ==> "hell\noja\nc\0" ==> oja\nc\0


return "hell\n"




SECOND ITERATION

buffer[11]
line = oja\nc\0
next_line = NULL;
readed = 10;
tmp = NULL;
truncated = -1;



readed = 10;
buffer = "red\nthis i\0"
line = strjoin(line, buffer); ==> "oja\ncred\nthis i\0"
truncated = ft_trunc(line); ==> 3;
next_line[3 + 2];
strlcpy(next_line, "oja\ncred\nthis i\0", 3 + 2);
next_line = oja\n;
line = strdup(line + truncated + 1); ==> "oja\ncred\nthis i\0" ==> "cred\nthis i\0"

return "oja\n"



THIRD ITERATION

buffer[11]
line = cred\nthis i\0
next_line = NULL;
readed = 10;
tmp = NULL;
truncated = -1;


readed = 10;
buffer = "s the line\0"
line = strjoin(line, buffer); ==> "cred\nthis is the line\0"
truncated = ft_trunc(line); ==> 4;
next_line[4 + 2];
strlcpy(next_line, "cred\nthis is the line\0", 4 + 2);
next_line = "cred\n"
line = strdup(line + truncated + 1); ==> "cred\nthis is the line\0" ==> "this is the line\0"

return "cred\n"


LAST ITERATION

buffer[11]
line = this is the line\0
next_line = NULL;
readed = 10;
tmp = NULL;
truncated = -1;


readed = 1
buffer = "e\0";
line = strjoin(line, buffer); ==> "this is the linee\0";
truncated = ft_trunc(line); ==> -1;

IF (truncated < 0)

tmp = strdup(line) ==> "this is the linee\0"
line = NULL;


return tmp ==> "this is the linee\0"















