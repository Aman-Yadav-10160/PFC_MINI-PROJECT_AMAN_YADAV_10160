#include <stdio.h>

// function prototypes
void Display_menu(char items[][30],int prices[],int n){
    printf("               --=# RESTURANT #=--\n");
    printf("____________________ !Menu! ____________________\n");
    for(int i = 0; i<n;i++){
        printf("\t%d. %s\t-Rs.%d\n",i+1,items[i],prices[i]);
    }
}

int Calculate_bill(int price,int quantity){
    return price * quantity;

}


int main(){
    int n = 5;
    char food_items[5][30]={"Veg Fried Rice","Veg Biryani","Butter Roti","Paneer Butter Masala","Green Salad"};
    int prices[5]={200,200,250,300,200};

    int total_bill = 0;
    int choice, quantity;
    char more_order;

    int show = 1;

    int order_arr[50];
    int quantity_arr[50];
    int k = 0;




    do{
        if(show){
            Display_menu(food_items, prices, n);
        }

        printf("--------------------------------------------\n");
        printf("Enter the item number you want to oreder: ");
        scanf("%d",&choice);

        if(choice < 1 || choice > n){
            printf("Invalid Choice! Try Again.\n");
            continue;
        }

        printf("Enter Quantity for %s:",food_items[choice - 1]);
        scanf("%d",&quantity);

        total_bill += Calculate_bill(prices[choice-1],quantity);

        order_arr[k]=choice-1;
        quantity_arr[k]=quantity;
        k++;

        printf("Do you want to order more? (y/n): ");
        scanf(" %c", &more_order);
        show = 0;

    }while(more_order == 'y' || more_order == 'Y');

    printf("--------------------------------------------\n");
    printf("          !!! $Bill details !!!\n");
    for(int i = 0 ; i < k;i++){
        printf("\t(%c). %s   x%d = Rs. %d\n",97+i,food_items[order_arr[i]],quantity_arr[i],prices[order_arr[i]]*quantity_arr[i]);
    }
    printf("--------------------------------------------\n");
    printf("\tGrand total: Rs. %d\n",total_bill);
    printf("--------------------------------------------\n");
    printf("\tThank you for ordering!\n");
    printf("\tPlease Visit us again.\n");
    printf("_____________________________________________");

    return 0;
}