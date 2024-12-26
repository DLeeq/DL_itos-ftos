uint8_t DL_intToStr(char* str, int32_t num)
{
    uint8_t start = 0;
    uint8_t end = 0;

    if(num < 0)
    {
        str[0] = '-';

        num = -num;

        start = 1;
        end = 1;
    }

    do
    {
        str[end] = (char)(num % 10) + '0';
        end++;
        num /= 10;
    }
    while(num != 0);

    uint8_t len = end;

    str[end] = '\0';

    end--;

    for(; start < end; start++, end--)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
    }

    return len;
}

uint8_t DL_floatToStr(char* str, float num, uint8_t precision)
{
    if(precision > 6) precision = 6;

    uint8_t len = 0;
    int32_t whole_part = 0;

    if(num < 0)
    {
        str[0] = '-';
        num = -num;
        whole_part = (int32_t)num;
        len = DL_intToStr(str + 1, whole_part) + 1;
    }
    else
    {
        whole_part = (int32_t)num;
        len = DL_intToStr(str, whole_part);
    }

    if(precision > 0)
    {
        str[len] = '.';
        len++;
    }
    else
    {
        str[len] = '\0';
        return len;
    }

    float temp = num - whole_part;

    for(uint8_t i = 0; i < precision; i++, len++)
    {
        temp *= 10;
        int32_t frac_part = (int32_t)temp;
        DL_intToStr(str + len, frac_part);
        temp -= frac_part;
    }

    str[len] = '\0';

    return len;
}