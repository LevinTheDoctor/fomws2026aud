#include <stdio.h>
#include <stdlib.h>

int main()
{
    // man resviert eine speicher adresse mit der Größe von 5 Byte denn ein Char ist ein Byte.
    char *test = malloc(5 * sizeof(char));

    for (int i = 0; i < 5; i++)
    {
        // mit dem +1 spring man immer ein stück weiter wie bei ein array nur ist c so Hardwear nah das es dash zulässt das man es manuell macht.
        // Laut Gemini ist das dieselbe logik die eine array intenr hat
        *(test + i) = 10 + i;
    }

    for (int i = 4; i >= 0; i--)
    {
        printf("%d\n", *(test + i));
    }

    // malloc weißt speicher dynamisch zu alles was man dynamisch zuweist muss am ende befreit werden
    free(test);

    return 0;
}
