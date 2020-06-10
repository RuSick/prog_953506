#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <io.h>
#include <conio.h>
int main()
{   FILE* fp;
    char name[] = "test.txt";
    if ((fp = fopen(name, "rt")) == NULL)
    {
        printf("fail");
        getchar();
        return 0;
    }
    else
    {
        int  any, allletters = 0,schet = 0;
        do
        {
            any = fgetc(fp);
            allletters++;
            printf("%c", any);
            if (any == '/')
            {
                any = fgetc(fp);
                printf("%c", any);
                allletters++;
                if (any == '/')
                {
                    schet +=2;
                    while (any != '\n')
                    {
                        any = fgetc(fp);

                        printf("%c", any);
                        allletters++;
                        schet++;
                    }
                }
                else if (any == '*')
                {
                    schet += 2;
                    while(1)
                    {
                        any = fgetc(fp);
                        printf("%c", any);
                        schet++;
                        allletters++;
                        if (any == '*')
                        {
                            any = fgetc(fp);
                            printf("%c", any);
                            schet++;
                            allletters++;
                            if (any == '/')
                                break;
                        }                    
                    }                
                }
            }
        } while (any != EOF);
        double end1 = schet, end2 = allletters;
        double end = end1 / end2;
        printf("\nall:%d Comments:%d  End:%.2f procents",allletters,schet, end*100);
    }
    fclose(fp);
    getchar();
}