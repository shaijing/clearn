//
// Created by yulin on 2022/2/9.
//
#include "../../headers/practice/practice_chapter_13.h"
void r_file(void){
    int ch;
    FILE * fp,* fo;
    fp = fopen("null.log","r");
    fo = fopen("test.txt","w");
    if(fp == NULL){
        printf("Error!");
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(fp)) !=EOF){
        putchar(ch);
        putc(ch,fo);
    }
    if(fclose(fp)!=0||fclose(fo)!=0)
        printf("Error in closing file!");
}
void r_file_1(void){
    FILE * in,* out;
    char str[40];
    in = fopen("test.txt","r");
    out = fopen("test","w");
    fgets(str,40,in);
    fputs(str,stdout);
    fputs(str,out);
    fclose(in), fclose(out);
}

void f_byte(void){
    FILE * fp;
    char str[40];
    fp = fopen("test.txt","rb");
    fseek(fp,0L,SEEK_END);
    long byte = ftell(fp);
    rewind(fp);
    fgets(str,40,fp);
    fputs(str,stdout);
    printf("File occupy %ld byte",byte);
    fclose(fp);
}
void w_bin(void){
    FILE * fp;
    int num[5]={1,2,3,4,100};
    fp = fopen("num.dat","wb");
    fwrite(num,sizeof(int),5,fp);
    fclose(fp);
}
void r_bin(void){
    FILE * fp;
    int num[5];
    fp = fopen("num.dat","rb");
    if (fp ==NULL){
        fprintf(stderr,"Open %s error!","num.dat");
        exit(1);
    }
    int red = fread(num, sizeof(int),5,fp);
    if(red !=5 ){
        puts("读取失败!");
        exit(1);
    }
    else
        puts("读取成功!");
    fclose(fp);
    for (int i = 0; i <5 ; ++i) {
        printf("%d \n",(num+i));
    }
}
void r_w(int argc,char *argv[]){
#define LEN 40
    FILE  *in, *out;   // declare two FILE pointers
    int ch;
    char name[LEN];    // storage for output filename
    int count = 0;

    // check for command-line arguments
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // set up input
    if ((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                argv[1]);
        exit(EXIT_FAILURE);
    }
    // set up output
    strncpy(name,argv[1], LEN - 5); // copy filename
    name[LEN - 5] = '\0';
    strcat(name,".red");            // append .red
    if ((out = fopen(name, "w")) == NULL)
    {                       // open file for writing
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }
    // copy data
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);  // print every 3rd char
    // clean up
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr,"Error in closing files\n");
}


void a_w(void){
#define MAX 41
    FILE *fp;
    char words[MAX];

    if ((fp = fopen("  test.txt", "a+")) == NULL)
    {
        fprintf(stdout,"Can't open \"test.txt\" file.\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter words to add to the file; press the #");
    puts("key at the beginning of a line to terminate.");
    while ((fscanf(stdin,"%40s", words) == 1)  && (words[0] != '#'))
        fprintf(fp, "%s\n", words);

    puts("File contents:");
    rewind(fp);           /* go back to beginning of file */
    while (fscanf(fp,"%s",words) == 1)
        puts(words);
    puts("Done!");
    if (fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");
}

void r_rev(void){
#define CNTL_Z '\032'   /* eof marker in DOS text files */
#define SLEN 81
    char file[SLEN];
    char ch;
    FILE *fp;
    long count, last;

    puts("Enter the name of the file to be processed:");
    scanf("%80s", file);
    if ((fp = fopen(file,"rb")) == NULL)
    {                               /* read-only mode   */
        printf("reverse can't open %s\n", file);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);        /* go to end of file */
    last = ftell(fp);
    for (count = 1L; count <= last; count++)
    {
        fseek(fp, -count, SEEK_END); /* go backward      */
        ch = getc(fp);
        if (ch != CNTL_Z && ch != '\r')  /* MS-DOS files */
            putchar(ch);
    }
    putchar('\n');
    fclose(fp);

}

char * s_gets_1(char * st, int n)
{
    char * ret_val;
    char * find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
void append(FILE *source, FILE *dest){
#define BUFSIZE 4096
    size_t bytes;
    static char temp[BUFSIZE]; // allocate once

    while ((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
        fwrite(temp, sizeof (char), bytes, dest);
}
void f_append(void){

#define SLEN 81
    FILE *fa, *fs;	// fa for append file, fs for source file
    int files = 0;  // number of files appended
    char file_app[SLEN];  // name of append file
    char file_src[SLEN];  // name of source file
    int ch;

    puts("Enter name of destination file:");
    s_gets_1(file_app, SLEN);
    if ((fa = fopen(file_app, "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Enter name of first source file (empty line to quit):");
    while (s_gets_1(file_src, SLEN) && file_src[0] != '\0')
    {
        if (strcmp(file_src, file_app) == 0)
            fputs("Can't append file to itself\n",stderr);
        else if ((fs = fopen(file_src, "r")) == NULL)
            fprintf(stderr, "Can't open %s\n", file_src);
        else
        {
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n",stderr);
                continue;
            }
            append(fs, fa);
            if (ferror(fs) != 0)
                fprintf(stderr,"Error in reading file %s.\n",
                        file_src);
            if (ferror(fa) != 0)
                fprintf(stderr,"Error in writing file %s.\n",
                        file_app);
            fclose(fs);
            files++;
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        }
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", file_app);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);
}

void r_bin_1(void){
#define ARSIZE 1000
    double numbers[ARSIZE];
    double value;
    const char * file = "numbers.dat";
    int i;
    long pos;
    FILE *iofile;

    // create a set of double values
    for(i = 0; i < ARSIZE; i++)
        numbers[i] = 100.0 * i + 1.0 / (i + 1);
    // attempt to open file
    if ((iofile = fopen(file, "wb")) == NULL)
    {
        fprintf(stderr, "Could not open %s for output.\n", file);
        exit(EXIT_FAILURE);
    }
    // write array in binary format to file
    fwrite(numbers, sizeof (double), ARSIZE, iofile);
    fclose(iofile);
    if ((iofile = fopen(file, "rb")) == NULL)
    {
        fprintf(stderr,
                "Could not open %s for random access.\n", file);
        exit(EXIT_FAILURE);
    }
    // read selected items from file
    printf("Enter an index in the range 0-%d.\n", ARSIZE - 1);
    while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE)
    {
        pos = (long) i * sizeof(double); // calculate offset
        fseek(iofile, pos, SEEK_SET);    // go there
        fread(&value, sizeof (double), 1, iofile);
        printf("The value there is %f.\n", value);
        printf("Next index (out of range to quit):\n");
    }
    // finish up
    fclose(iofile);
    puts("Bye!");
}
