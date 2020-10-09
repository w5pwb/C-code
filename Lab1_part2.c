#include <stdio.h>   
#define MAX_SIZE 1000   /* sets the max array size for inputting characters. */   


int get_line(char line[], int array_size);   
void inverter(char line[], int len);

int main()   {       

    int len;           /*the length of the input from get_line.*/
    char line[MAX_SIZE];   /* array line stores input from user.*/

    
    /*This while checks to see if there is anything in line and will execute as long as line > 0 or there is 
     * no EOF.  User can keep inputting lines and executing the code this way.*/
    while ((len = get_line(line, MAX_SIZE)) > 0){/*if there is something in line, len is greater than 0.*/
        if (len >= 50){
            inverter(line, len);
        }
        else{
            printf("The line you have entered is less than 50 chars long.\n");
        }
    } 


    return 0;   

}   


/* From pg 29 of 'The C Programming Language.' with mods.
    * get_line reads user input into array line via the pointer s, 
    * returns an int giving the length of line.  
    * the array line, thus filling it up for use outside of get_line
    */   

int get_line(char s[],int lim)   
{       
    int c, i; /*c holds the char from the keyboard, i increments */      
    
    printf(">"); /*A Zork style prompt.*/

    /*
     * This for loop gets a character from the keyboard and reads it into the line array (via the pointer s).
     * Since the index starts at 0, i cannot go to 1000 or the world will end.
     * If the character read is either the end of file or newline character, the loop will end.
     */
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){ 
        s[i] = c;      /*put c in ith array element */
    }

    return i;   
}   


/*
 * The 'inverter' function takes the characters from the array 'line' via the pointer u.
 * and reverses them, reading them into the array 'inverted.'
 *
 * 'inverted' is given size 'size' to match the length of the incoming array.
 * 
 * The int size must be one less than the int n, which is the absolute size of line.
 * If size was equal to n, the array function would try to read a char into 
 * an element of 'inverted' that doesn't exist and the world would end.
 *
 *
 *
*/

void inverter(char u[], int n) {
    int i;
    int size = n-1;
    char inverted[n]; 
 
    /*
     * This for loop reads the first element of u and
     * passes it to the last element of 'inverted.'
     * Kind of fun.
     *
    */
    for(i = 0; i <= size; ++i){
        inverted[size-i] = u[i];
    }
    
    inverted[n] = '\0'; /*Add the null char to complete the string for printing.*/
    printf("%s \n",inverted);
}
