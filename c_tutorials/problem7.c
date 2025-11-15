//16. Soru
#include <stdio.h>

int main()
{
    int customer_number;
    int items;
    float total_price = 0;
    float price_per_costumer;
    float price;
    printf("Enter number of customers:");
    scanf("%d",&customer_number);
    for (int i = 1 ; i <= customer_number ; i++){
        printf("\nCustomer %d\n",i);
        printf("Enter the number of items:");
        scanf("%d",&items);

        price_per_costumer = 0.0;
    
        for (int j = 1 ; j <= items ; j++){
            printf("Enter price of item %d:",j);
            scanf("%f",&price);
            price_per_costumer += price;
        }
        printf("Price for Customer %d = %.2f\n",i,price_per_costumer);
        total_price += price_per_costumer;
    }

    printf("\nGrand total for all customers: %.2f\n", total_price);

    return 0;
        
}