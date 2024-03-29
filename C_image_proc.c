#include <stdio.h>


char bytefromtext(unsigned char* text){
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

int main(){

	printf("hello world!");
	
FILE *ptr_bmp_in;
FILE *ptr_text_out;
int c;
FILE *ptr_txt_in;
FILE *ptr_bmp_out;
unsigned char buf[8];
int b;
int j = 0;

ptr_bmp_in=fopen("shopping.bmp","rb");
ptr_text_out=fopen("test1.txt","w");

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
            }
            else
            {
                fputc('0',ptr_text_out);
            }
        }
    }


    fclose(ptr_bmp_in);
    fclose(ptr_text_out);
    printf("Writing done\n");

  printf("writing over");
  



ptr_txt_in=fopen("test1.txt","r");
ptr_bmp_out=fopen("results.bmp","wb");


if(!ptr_txt_in)
{
    printf("Unable to open file\n");
    return 1;
}

while((c=fgetc(ptr_txt_in)) != EOF)
    {
        buf[j++] = b;
        if(j==8)
        {
            fputc(bytefromtext(buf),ptr_bmp_out);
            j=0;
        }
    }


    fclose(ptr_txt_in);
    fclose(ptr_bmp_out);
    printf("Writing done\n");

    return 0;

}
