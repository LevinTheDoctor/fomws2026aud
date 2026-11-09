#include <stdio.h>

int main()
{
    u_int16_t days = 1331;

    u_int16_t fulldays = days;

    u_int16_t years = 1331 / 365;

    days = days - (years * 365);

    u_int16_t weeks = days / 7;

    days = days - (weeks * 7);

    printf("Tage %u = %u Jahre, %u Wochen und %u Tage", fulldays, years, weeks, days);

    return 0;
}