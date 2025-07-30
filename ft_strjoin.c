# include <stdlib.h>

//Take care of details

// this func return without nul terminate str !!
void    ft_strs_fillto_str(int size, char **strs, char *sep, char*dest)
{
    int i;
    int j;
    int len;

    len = 0;
    i = 0;
    j = 0;
    while(i < size)
    {
        while(strs[i][j])
        {
            dest[len] = strs[i][j];
            j++;
            len++;
        }
        j = 0;
        while(sep[j] && i < size - 1)
        {
            dest[len] = sep[j];
            j++;
            len++;
        }
        j= 0;
        i++;
    }
}

int ft_strlen(char * str)
{
    int len;
    len = 0;
    while(str[len])
        len++;
    return (len);
}

//calculate the given size of arrays of string
int ft_strslen_2d(char **strs, int size)
{
    int len;
    int i;
    int j;

    len = 0;
    i = 0;
    j = 0;

    while(i < size)
    {
        while(strs[i][j])
        {
            len++;
            j++;
        }
        i++;
        j = 0;
    }
    return (len);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    char *str;
    int size_str;
    int len_sep;

    if(size == 0)
    {
        str = malloc(sizeof(char) * 1);
        *str = '\0';
        return (str);
    }
    //cal space for malloc
    len_sep = ft_strlen(sep);
    size_str = ft_strslen_2d(strs, size) + 1 + len_sep * (size - 1);
    //malloc
    str = malloc(sizeof(char) * size_str);
    if (str == NULL)
        return (NULL);
    //fill in
    ft_strs_fillto_str(size, strs, sep, str);
    str[size_str - 1] = '\0';
    return (str);
}
// # include <stdio.h>
// int main()
// {
//     char *strs[3];
//     char *sep;
//     char *str;

//     strs[0] = "hello";
//     strs[1] = "world";
//     strs[2] = "!";
//     sep = ",";
//     str = ft_strjoin(3, strs, sep);
//     printf("%s", str);
//     free(str);
// }