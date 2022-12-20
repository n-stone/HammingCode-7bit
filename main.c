#include <stdio.h>

#define MAX_NUM 16
#define MAX_BIT 8

int h_code[MAX_NUM][MAX_BIT] = { 0, };
int count = 0; //debug

int main()
{
    // hamming code
    printf(" [Hamming Code]\n\r");
    for (int num = 0; num < MAX_NUM; num++)
    {
        // put number val, 4bit 
        h_code[num][2] = (num & 1);
        h_code[num][4] = (num & 2) >> 1;
        h_code[num][5] = (num & 4) >> 2;
        h_code[num][6] = (num & 8) >> 3;
    
        // check parity odd
        int p1 = (h_code[num][2] + h_code[num][4] + h_code[num][6]) % 2;
        int p2 = (h_code[num][2] + h_code[num][5] + h_code[num][6]) % 2;
        int p3 = (h_code[num][4] + h_code[num][5] + h_code[num][6]) % 2;
        
        // check parity odd
        //int p1 = (h_code[num][2] ^ h_code[num][4] ^ h_code[num][6]);
        //int p2 = (h_code[num][2] ^ h_code[num][5] ^ h_code[num][6]);
        //int p3 = (h_code[num][4] ^ h_code[num][5] ^ h_code[num][6]);
        
        // put parity val, p1
        if (p1) h_code[num][0] = 0;
        else    h_code[num][0] = 1;
        
        // put parity val, p2
        if (p2) h_code[num][1] = 0;
        else    h_code[num][1] = 1;
    
        // put parity val, p3
        if (p3) h_code[num][3] = 0;
        else    h_code[num][3] = 1;
        
        // debug
        printf(" [%02d] ", num);
        for (int bit = (MAX_BIT - 1); bit >= 0; bit--) {
            printf("%d ", h_code[num][bit]);
        }
        printf("\n\r");
    }
    
    // hamming distane
    printf("\n [Hamming Distane]\n\r");
    for (int i = 0; i < (MAX_NUM - 1); i++)
    {
        for (int j = (i + 1); j < MAX_NUM; j++)
        {
            int distane = 0;
            
            // compare hamming code, calculation distane
            for (int bit = (MAX_BIT - 1); bit >= 0; bit--) {
                if (h_code[i][bit] != h_code[j][bit]) distane++;
            }
            
            // debug
            // compare 1
            printf(" [%02d] ", i);
            for (int bit = (MAX_BIT - 1); bit >= 0; bit--) {
                printf("%d ", h_code[i][bit]);
            }
            printf("\n\r");
            
            // compare 2
            printf(" [%02d] ", j);
            for (int bit = (MAX_BIT - 1); bit >= 0; bit--) {
                printf("%d ", h_code[j][bit]);
            }
            printf("\n\r");
            printf(" distane: %d\n\n\r", distane);
            
            count++;
        }
    }
    
    printf(" Calculation Count: %d\n\r", count);
}
