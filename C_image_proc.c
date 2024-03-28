#include <stdio.h>


char bytefromtext(char* text){
	unsigned char result=0;
  for(int i=0;i<8;i++)
  {
    if(text[i]=='1')
    {
      result |= (1<< (7-i) );
    }
  }
  
  return result;
}

int main(){

	printf("hello world!");
	
	FILE *fptr;
	FILE *txt;
	int c;
	
		fptr=fopen("shopping.bmp","rb");
		txt=fopen("test1.txt","w");
		if(fptr==NULL){
    printf("NOTHING In FILE");
    fclose(fptr);
  }
  else{
    printf("success");
	while((c = fgetc(fptr)) !=EOF)
    {
      c=fgetc(fptr);
      for(int i=0;i<=7;i++)
      {
        if(c&(1<<(7-i)))
        {
          fputc('1',txt);
        }
        else
        {
          fputc('0',txt);
        }
      }
      // fprintf(txt,"\t");
    };

  }

  fclose(fptr);
  fclose(txt);

  printf("writing over");
  
  FILE *pfile;
  FILE *image;
  char buf[8];
  char b;
  int j=0;

  image=fopen("result.bmp","wb"); //open an empty .bmp file to
                                  //write characters from the source image file
  pfile=fopen("test1.txt","r");

  if(pfile==NULL)
    printf("error");
  else
  {
    b=fgetc(pfile);

    while(b!=EOF)
    {
      buf[j++]=b;
      if(j==8)
      {
        fputc(bytefromtext(buf),image);
        j=0;
      }
      b=fgetc(pfile);

    }

    fclose(pfile);
    fclose(image);
	printf("files closed");
  }
return 0;
}
