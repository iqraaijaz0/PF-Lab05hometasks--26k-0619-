#include<stdio.h>

int main(){
    int customercategory, orderamount, productcategory, ordernumber, remainder;
    float discountpercent = 0.0, discountamount = 0.0, finalpayableamount = 0.0, deliverycharges = 0.0, prioritycharges = 0.0;
    float deliverydistance = 0.0;

    printf("Enter product category:\n1. Electronics\n2. Clothing\n3. Books\n4. Household\n");
    scanf("%d", &productcategory);

    printf("Enter customer category:\n1. Regular\n2. Premium\n3. Corporate\n");
    scanf("%d", &customercategory);

    printf("Enter your order amount: ");
    scanf("%d", &orderamount);

    printf("Enter your delivery distance (in km): ");
    scanf("%f", &deliverydistance);

    switch(productcategory){
        case 1:
            switch(customercategory){
                case 1: discountpercent = 5.0; break;
                case 2: discountpercent = 10.0; break;
                case 3: discountpercent = 15.0; break;
            }
            break;
        case 2:
            switch(customercategory){
                case 1: discountpercent = 10.0; break;
                case 2: discountpercent = 15.0; break;
                case 3: discountpercent = 20.0; break;
            }
            break;
        case 3:
            switch(customercategory){
                case 1: discountpercent = 8.0; break;
                case 2: discountpercent = 12.0; break;
                case 3: discountpercent = 18.0; break;
            } 
            break;
        case 4:
            switch(customercategory){
                case 1: discountpercent = 7.0; break;
                case 2: discountpercent = 14.0; break;
                case 3: discountpercent = 20.0; break;
            }
            break;
    }

    discountamount = orderamount * (discountpercent / 100.0);
    finalpayableamount = orderamount - discountamount;

    deliverycharges = deliverydistance * 10; 

    if(finalpayableamount >= 5000 || customercategory == 2 || customercategory == 3) {
        deliverycharges = 0; 
    }

    if((customercategory == 2 || customercategory == 3) && orderamount >= 10000) {
        prioritycharges = 500.0;
    }

    finalpayableamount = finalpayableamount + deliverycharges + prioritycharges;

    printf("Enter order number: ");
    scanf("%d", &ordernumber);
    
    remainder = ordernumber % 4;

    printf("\n------ FINAL REPORT ------\n");
    printf("Product Category: %d\n", productcategory);
    printf("Customer Category: %d\n", customercategory);
    printf("Original Order Amount: %d\n", orderamount);
    printf("Discount Percentage: %.1f%%\n", discountpercent);
    printf("Discount Amount: %.2f\n", discountamount);
    printf("Delivery Distance: %.1f km\n", deliverydistance);
    printf("Delivery Charges: %.2f\n", deliverycharges);
    printf("Priority Delivery Charges: %.2f\n", prioritycharges);
    
    if(remainder == 0) printf("Processing Group: Group A\n");
    else if(remainder == 1) printf("Processing Group: Group B\n");
    else if(remainder == 2) printf("Processing Group: Group C\n");
    else if(remainder == 3) printf("Processing Group: Group D\n");

    printf("Total Amount Payable: %.2f\n", finalpayableamount);

    return 0;
}
