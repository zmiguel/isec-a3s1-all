#include <stdio.h>

#define MAX_ITEMS 100

struct item {
    double item1;
    double item2;
    double item3;
    double item4;
};

int main(void)
{
    struct item myItems[MAX_ITEMS];
    int i = 0;

    FILE *input;
    input = fopen("items.txt", "r");

    if(input == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while(fscanf(input, " %lf,%lf,%lf,%lf", &myItems[i].item1,&myItems[i].item2,
             &myItems[i].item3, &myItems[i].item4) == 4)
    {
       fscanf(input, " %lf,%lf,%lf,%lf", &myItems[i].item1,&myItems[i].item2,
             &myItems[i].item3, &myItems[i].item4);
       printf("%lf %lf %lf %lf\n", myItems[i].item1, myItems[i].item2,
             myItems[i].item3, myItems[i].item4);
       i++;
    }

  fclose(input);
  return 0;
}
