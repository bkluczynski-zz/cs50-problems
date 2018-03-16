#include <stdio.h>
#include <cs50.h>
#include <math.h>

int calculateChange(int);
int money = 0;
int remaining = 0;

int main()
{
    //ask for change
    float change = get_float("Change owed: ");
    //converted change to cents and round it up to the nearest penny
    int changeInCents = round(change * 100);
    //call calculateChange recursively
    printf("%i\n", calculateChange(changeInCents));

}

int calculateChange(int change)
{

   if (change == 0) {
       return money;
   }

   if (change >= 25) {
       remaining = change % 25;
       money += change / 25;
       return calculateChange(remaining);
   }

   if (change >= 10) {
       remaining = change % 10;
       money += change / 10;
       return calculateChange(remaining);
   }

   if (change >= 5) {
       remaining = change % 5;
       money += change / 5;
       return calculateChange(remaining);
   }

   if (change >= 1) {
       remaining = change % 1;
       money += change / 1;
       return calculateChange(remaining);
   }

   return calculateChange(remaining);
}
