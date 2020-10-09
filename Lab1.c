#include <stdio.h>   
#define MAX_SIZE 1000   /* sets the max array size for inputting characters. */   


/*Function declarations.*/
int get_line(char line[], int array_size);   
int vowel_counter(char line[], int len);

int main()   {       

    int len, vowels = 0; /*len is the length of the line captured by get_line, vowels is the vowel count of the line.*/
    char line[MAX_SIZE];   /* char array line stores input from user.*/

    
    /*This while checks to see if there is anything in line and will execute as long as line > 0 or there is 
     * no EOF.  User can keep inputting chars and executing the code this way.*/
    while ((len = get_line(line, MAX_SIZE)) > 0){  /*if there is something in line, len is greater than 0.*/
        printf("Your line is %d chars long.\n", len);
        vowels = vowel_counter(line, len); /*call vowel_couter and pass it line and len.  */
        printf("The number of vowels in the line is: %d\n", vowels);

    } 

    return 0;
}   


/* From pg 29 of 'The C Programming Language.' with mods.
    * get_line reads user input into array line via the pointer s, 
    * returns an int giving the length of line.  
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
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){  /*array of size 1000 has elements 0-999, c cannot be EOF or newline.*/
        s[i] = c;      /* put c in ith array element */
        
    }

    return i;   
}   

/*
 * vowel_counter counts the vowels in the line array and returns an int
 * representing the total.  
 *
 * The nested for loops will compare each elelment of t (a pointer to line[])
 * to the elements in vow.  If the element is found to be in vow, count it.  
 * At the end of t, return the count to main.
 *
 */
int vowel_counter(char t[], int n){

    char vow[10] = {'A','a','E','e','I','i','O','o','U','u'};
    int i, j, v_count = 0;

    for (i = 0; i < n; i++){ /* n is the length of the string so the array will be from 0 to n-1. */
        for (j = 0; j <= 9; j++){
            if(t[i] == vow[j]){
                v_count++;
            }
        }
        
    }

    return v_count;

}
