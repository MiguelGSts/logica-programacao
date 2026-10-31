/*
CASO A:
int *ptr;
*ptr = 10;

CASO B:
int *ptr = NULL;
printf("%d\n", *ptr);

CASO C:
float taxa = 1.5f;
int *ptr = &taxa;

CASO D:
int v[3] = {3, 5, 8};
int *ptr = v;
printf("%d\n", *(ptr + 3));

CASO E:
Equipe equipe = {"Zeta", 12};
Equipe *ptr = &equipe;
printf("%d\n", ptr.pontos);

*/