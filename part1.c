#include <stdio.h>

char bytefromtext(unsigned char* text)
{   
    char result = 0;
    for(int i=0;i<8;i++)
    {
        if(text[i]=='1')
        {
            result |= (1 << (7-i));
        }
    }
    return result;
}

int main(int argc, char*argv[]){

FILE *ptr_bmp_in;
FILE *test_out;
FILE *ptr_text_out;
int c;


ptr_bmp_in=fopen("shopping.bmp","rb");
ptr_text_out=fopen("panda_to_text.txt","w");
test_out=fopen("test_out.txt","w");


if(!ptr_bmp_in)
{
    printf("Unable to open file\n");
    return 1;
}

while((c=fgetc(ptr_bmp_in)) != EOF)
    {
        for(int i=0;i<=7;i++)
        {
            if(c&(1<<(7-i)))
            {
				fputc('1',ptr_text_out);
                fprintf(test_out,"%d",c);
				//fputc(c,ptr_bmp_out);
				
            }
            else
            {
				fputc('0',ptr_text_out);
                fprintf(test_out,"%d",c);
				//fputc(c,ptr_bmp_out);
            }
        }
    }


    fclose(ptr_bmp_in);
    fclose(ptr_text_out);
    printf("Writing done\n");




    return 0;
}