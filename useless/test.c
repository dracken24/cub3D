#include "./includes/cube3d.h"

char    *ft_returnstr_end(char *str, int len)
{
    char *ret;
    int mylen;
    int i;
    int k;

    ret = ft_calloc(sizeof(char), len + 1);
    if (!str || !ret)
        return (NULL);
    mylen = (int)ft_strlen(str) - 1;
    i = -1;
    while (str[len] != '\0' && len > 0)
    {
        ret[len - 1] = str[mylen];
        mylen--;
        len--;
    }
    return (ret);
}

int main()
{
    printf("%s\n", ft_returnstr_end("fewef #ff9484", 7));
    return 0;
}