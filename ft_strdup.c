# include <stdlib.h>

unsigned int ft_strlen(char *str)
{
    unsigned int i;
    i = 0;
    while(str[i])
        i++;
    return (i);
}

char *ft_strdup(char *src)
{
     
    // malloc 
    char *dup;
    int i;
    i = 0;
    dup = malloc((ft_strlen(src) +  1 ) * sizeof(*src));
    if (dup == NULL)
        return (NULL);
    //dupicate
    while (src[i])
    {
        dup[i] = src[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

// # include <stdio.h>
// int main()
// {
//     char * str ="hey I am good.";
//     char *dup;
//     dup = ft_strdup(str);
//     printf("%s\n", dup);
//     free(dup);
// }
// mem checked