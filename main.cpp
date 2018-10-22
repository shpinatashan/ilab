//created by Natalia

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/stat.h>
using namespace std;

struct stat st = {};

void ReadPoem(int size , char buf[]);
int Count_change(char buf[], int size, char* text[]);
void OutputFile(char* text[], int nlines);

int main()
{
stat("poem.txt", &st);
int size = st.st_size +1;
char * buf = (char*) calloc(size, sizeof(char));
char** text = (char**)calloc(size,sizeof(char*));

ReadPoem(size, buf);
int nlines = Count_change(buf, size, text);
OutputFile(text, nlines);


free(text);
text = NULL;
free(buf);
buf = NULL;
    return 0;
}

void ReadPoem(int size , char buf[])
{

    FILE* onegin = fopen("1.txt", "r");

    if (onegin == NULL)
    {
        printf("Cannot open file");
        return;
    }

    fread(buf, sizeof(char), size,onegin);
    buf [size] = '\n';
    fclose(onegin);
}

int Count_change(char buf[], int size, char* text[])
{
    int nlines = 0;

    text[0] = &buf[0];
    for (int i = 0; i < size; i++)
    {
        if (buf[i] == '\n')
        {
            int n = 0;
            nlines++;
            buf[i] = '\0';
            text[n] = &buf[i+1];
            n++;
        }
    }

    return nlines;
}

void OutputFile(char* text[], int nlines)
{
    FILE* f2 = fopen("result.txt", "w");


    for(int i = 0; i < nlines; i++)
    {
        fputs(text[i], f2);
    }
    fclose(f2);
}
