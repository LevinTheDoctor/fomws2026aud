#include <stdio.h>

typedef struct
{
    float breite;
    float laenge;
} rechteck;

void calcAndPrintUmfang(rechteck *r)
{
    /* mit -> Derfernziert man*/
    float umfang = 2 * r->breite + 2 * r->laenge;
    printf("Umfang: %f\n", umfang);
}

void calcAndPrintFlache(rechteck *r)
{
    float flache = r->breite * r->laenge;
    printf("Flache: %f\n", flache);
}

int main()
{
    rechteck reck;
    reck.breite = 10.0;
    reck.laenge = 5.0;

    printf("Rechteck: Länge: %f, Breite: %f\n",
           reck.laenge, reck.breite);

    calcAndPrintUmfang(&reck);
    calcAndPrintFlaeche(&reck);

    return 0;
}