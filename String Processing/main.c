#include <stdio.h>
#include <ctype.h>
#define MAX_LENGTH 101 

int getLength(char s[]) 
{
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    return i;
}

int is_equal(char s1[], char s2[])
{
    int i = 0;
  
    while(s1[i] != '\0' && s2[i] != '\0') 
    {
        if(s1[i] != s2[i]) 
        {
            return 0;
        }
        
        i++;
    }
    
    if(s1[i] == '\0' && s2[i] == '\0')
    {
        return 1;
    }
    
    return 0;
}

void str_copy(char dest[], char source[])
{
    int i = 0;
    
    while(source[i] != '\0')
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
}

void swap(char* a, char* b) 
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void str_reverse(char s[]) 
{
    int i = 0;
    int j = getLength(s) - 1;
    
    while(i < j) 
    {
        swap(&s[i], &s[j]);
        i++;
        j--;
    }
}

int is_palindrome(char s[]) 
{
    int i = 0;
    int j = getLength(s) - 1;
 
    while(i < j) 
    {
        if(s[i] != s[j]) 
        {
            return 0;
        }
        
        i++;
        j--;
    }
    return 1;
}

void capitalize_word(char *str)
{
   char c;
   int i;
   
   i = 0;
   
   if(str[0] >=  'a' && str[0] <=  'z')       
       str[0] = toupper(str[0]);          
   i++;                               

   while(str[i] != '\0')                   
   {
       if(str[i] == ' ')                   
       {
           i++;    
           
           if(str[i] >= 'a' && str[i] <= 'z')  
               str[i] = toupper(str[i]);       
       }
       else if(str[i] >= 'A' && str[i] <= 'Z')
       {
               str[i] = tolower(str[i]);       
       }
       i++;                               
   }
}

int main(void) 
{
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];
    char x;

    printf("Enter a string: ");
    scanf("%[^\n]s", s1);

    while((x = getchar() != '\n') && x != EOF); 
    
    printf("Enter another string: ");
    scanf("%[^\n]s", s2);

    printf("\nThe length of your first string is %d\n", getLength(s1));
    printf("The length of your second string is %d\n", getLength(s2));

    if(is_equal(s1, s2) == 1)
    {
        printf("You entered two equal strings.\n");
    }
    else 
    {
        printf("Your strings are different.\n");
    }

    if(is_palindrome(s1)) 
    {
        printf("%s is a palindrome string\n", s1);
    }
    else 
    {
        printf("%s is not a palindrome string\n", s1);
    }

    capitalize_word(s1);
    printf("Capitalized s1 is %s ", s1)
      
    return 0;
}
