#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_FOOD 50
#define MAX_CART 20
#define MAX_ORDERS 100
typedef struct{
    int id;
    char name[40];
    char category[25];
    float price;
    int stock;
    int sold;
}Food;
typedef struct{
    int food_id;
    int quantity;
}CartItem;
typedef struct{
    int id;
    int table;
    CartItem items[MAX_CART];
    int item_count;
    float subtotal;
    float discount;
    float total;
}Order;
Food foods[MAX_FOOD]={
    {1,"Chicken Biryani","Main",180,30,0},
    {2,"Beef Burger","Fast Food",250,25,0},
    {3,"Chicken Pizza","Fast Food",450,20,0},
    {4,"Beef Steak","Main",650,15,0},
    {5,"Fried Rice","Main",200,25,0},
    {6,"Chicken Curry","Main",220,20,0},
    {7,"French Fries","Side",120,40,0},
    {8,"Cold Coffee","Drink",100,30,0},
    {9,"Mango Juice","Drink",80,35,0},
    {10,"Chocolate Cake","Dessert",150,20,0}
};
int food_count=10;
Order orders[MAX_ORDERS];
int order_count=0;
void clear_input(void);
void pause_screen(void);
void welcome(void);
void main_menu(void);
void customer_menu(void);
void show_menu(void);
void search_food(void);
void sort_price(void);
void sort_name(void);
void take_order(void);
void show_receipt(Order *order);
int find_food(int id);
float subtotal(Order *order);
float discount(float amount);
void save_data(void);
void load_data(void);
void recursive_message(int n);
int recursive_total(int n);
int main(void){
    load_data();
    welcome();
    main_menu();
    return 0;
}
void welcome(void){
    printf("\n");
    printf("===============================================\n");
    printf("          WELCOME TO FOOD HAVEN\n");
    printf("       RESTAURANT ORDERING SYSTEM\n");
    printf("===============================================\n");
    printf("\nStarting system");
    recursive_message(3);
    printf("\nSystem ready!\n");
}
void recursive_message(int n){
    if(n==0){
        return;
    }
    printf(".");
    fflush(stdout);
    recursive_message(n-1);
}
void main_menu(void){
    int choice;
    do{
        printf("\n===============================================\n");
        printf("              MAIN MENU\n");
        printf("===============================================\n");
        printf("1. Customer Mode\n");
        printf("2. Exit\n");
        printf("-----------------------------------------------\n");
        printf("Enter choice: ");
        if(scanf("%d",&choice)!=1){
            clear_input();
            printf("Invalid input.\n");
            continue;
        }
        if(choice==1){
            customer_menu();
        }else if(choice==2){
            save_data();
            printf("\nThank you for visiting Food Haven!\n");
        }else{
            printf("Invalid choice.\n");
        }
    }while(choice!=2);
}
void customer_menu(void){
    int choice;
    do{
        printf("\n===============================================\n");
        printf("              CUSTOMER MENU\n");
        printf("===============================================\n");
        printf("1. View Food Menu\n");
        printf("2. Search Food\n");
        printf("3. Sort by Price\n");
        printf("4. Sort by Name\n");
        printf("5. Place Order\n");
        printf("6. Back\n");
        printf("-----------------------------------------------\n");
        printf("Enter choice: ");
        if(scanf("%d",&choice)!=1){
            clear_input();
            printf("Invalid input.\n");
            continue;
        }
        switch(choice){
            case 1:
                show_menu();
                pause_screen();
                break;
            case 2:
                search_food();
                pause_screen();
                break;
            case 3:
                sort_price();
                pause_screen();
                break;
            case 4:
                sort_name();
                pause_screen();
                break;
            case 5:
                take_order();
                break;
            case 6:
                break;
            default:
                printf("Invalid choice.\n");
        }
    }while(choice!=6);
}
void show_menu(void){
    printf("\n================================================================\n");
    printf("                         FOOD MENU\n");
    printf("================================================================\n");
    printf("%-5s %-30s %-15s %-10s\n","ID","Food","Category","Price");
    printf("----------------------------------------------------------------\n");
    for(int i=0;i<food_count;i++){
        printf("%-5d %-30s %-15s %-10.2f\n",
               foods[i].id,
               foods[i].name,
               foods[i].category,
               foods[i].price);
    }
    printf("================================================================\n");
}
int find_food(int id){
    for(int i=0;i<food_count;i++){
        if(foods[i].id==id){
            return i;
        }
    }
    return -1;
}
void search_food(void){
    char word[40];
    int found=0;
    printf("\nEnter food name: ");
    clear_input();
    fgets(word,sizeof(word),stdin);
    word[strcspn(word,"\n")]='\0';
    for(int i=0;word[i];i++){
        word[i]=tolower((unsigned char)word[i]);
    }
    printf("\n================ SEARCH RESULTS ================\n");
    for(int i=0;i<food_count;i++){
        char name[40];
        strcpy(name,foods[i].name);
        for(int j=0;name[j];j++){
            name[j]=tolower((unsigned char)name[j]);
        }
        if(strstr(name,word)!=NULL){
            printf("ID       : %d\n",foods[i].id);
            printf("Food     : %s\n",foods[i].name);
            printf("Category : %s\n",foods[i].category);
            printf("Price    : %.2f BDT\n",foods[i].price);
            printf("-----------------------------------------------\n");
            found=1;
        }
    }
    if(!found){
        printf("No food found.\n");
    }
}
void sort_price(void){
    Food temp[MAX_FOOD];
    for(int i=0;i<food_count;i++){
        temp[i]=foods[i];
    }
    for(int i=0;i<food_count-1;i++){
        for(int j=0;j<food_count-i-1;j++){
            if(temp[j].price>temp[j+1].price){
                Food x=temp[j];
                temp[j]=temp[j+1];
                temp[j+1]=x;
            }
        }
    }
    printf("\n================ PRICE SORT ================\n");
    printf("%-5s %-30s %-10s\n","ID","Food","Price");
    printf("-----------------------------------------------\n");
    for(int i=0;i<food_count;i++){
        printf("%-5d %-30s %.2f BDT\n",
               temp[i].id,
               temp[i].name,
               temp[i].price);
    }
}
void sort_name(void){
    Food temp[MAX_FOOD];
    for(int i=0;i<food_count;i++){
        temp[i]=foods[i];
    }
    for(int i=0;i<food_count-1;i++){
        for(int j=0;j<food_count-i-1;j++){
            if(strcmp(temp[j].name,temp[j+1].name)>0){
                Food x=temp[j];
                temp[j]=temp[j+1];
                temp[j+1]=x;
            }
        }
    }
    printf("\n================ NAME SORT ================\n");
    printf("%-5s %-30s %-10s\n","ID","Food","Price");
    printf("-----------------------------------------------\n");
    for(int i=0;i<food_count;i++){
        printf("%-5d %-30s %.2f BDT\n",
               temp[i].id,
               temp[i].name,
               temp[i].price);
    }
}
void take_order(void){
    if(order_count>=MAX_ORDERS){
        printf("Order storage is full.\n");
        return;
    }
    Order order;
    order.id=1001+order_count;
    order.item_count=0;
    order.subtotal=0;
    order.discount=0;
    order.total=0;
    printf("\n===============================================\n");
    printf("                NEW ORDER\n");
    printf("===============================================\n");
    printf("Enter table number: ");
    if(scanf("%d",&order.table)!=1){
        clear_input();
        printf("Invalid table number.\n");
        return;
    }
    if(order.table<=0){
        printf("Table number must be positive.\n");
        return;
    }
    show_menu();
    while(order.item_count<MAX_CART){
        int id;
        int quantity;
        printf("\nEnter Food ID (0 to finish): ");
        if(scanf("%d",&id)!=1){
            clear_input();
            printf("Invalid input.\n");
            continue;
        }
        if(id==0){
            break;
        }
        int index=find_food(id);
        if(index==-1){
            printf("Food ID does not exist.\n");
            continue;
        }
        printf("Enter quantity: ");
        if(scanf("%d",&quantity)!=1){
            clear_input();
            printf("Invalid quantity.\n");
            continue;
        }
        if(quantity<=0){
            printf("Quantity must be greater than zero.\n");
            continue;
        }
        if(quantity>foods[index].stock){
            printf("Only %d available.\n",foods[index].stock);
            continue;
        }
        int existing=-1;
        for(int i=0;i<order.item_count;i++){
            if(order.items[i].food_id==id){
                existing=i;
                break;
            }
        }
        if(existing!=-1){
            if(order.items[existing].quantity+quantity>foods[index].stock){
                printf("Not enough stock for that quantity.\n");
                continue;
            }
            order.items[existing].quantity+=quantity;
        }else{
            order.items[order.item_count].food_id=id;
            order.items[order.item_count].quantity=quantity;
            order.item_count++;
        }
        foods[index].stock-=quantity;
        foods[index].sold+=quantity;
        printf("%d x %s added.\n",quantity,foods[index].name);
    }
    if(order.item_count==0){
        printf("No food was ordered.\n");
        return;
    }
    order.subtotal=subtotal(&order);
    order.discount=discount(order.subtotal);
    order.total=order.subtotal-order.discount;
    orders[order_count]=order;
    order_count++;
    show_receipt(&orders[order_count-1]);
    save_data();
}
float subtotal(Order *order){
    float total=0;
    for(int i=0;i<order->item_count;i++){
        int id=order->items[i].food_id;
        int quantity=order->items[i].quantity;
        int index=find_food(id);
        if(index!=-1){
            total+=foods[index].price*quantity;
        }
    }
    return total;
}
float discount(float amount){
    if(amount>=1500){
        return amount*0.15;
    }
    if(amount>=1000){
        return amount*0.10;
    }
    if(amount>=500){
        return amount*0.05;
    }
    return 0;
}
void show_receipt(Order *order){
    printf("\n******************************************************\n");
    printf("                    FOOD HAVEN\n");
    printf("                  CUSTOMER RECEIPT\n");
    printf("******************************************************\n");
    printf("Order ID : %d\n",order->id);
    printf("Table    : %d\n",order->table);
    printf("------------------------------------------------------\n");
    printf("%-25s %-5s %-10s\n","Food","Qty","Amount");
    printf("------------------------------------------------------\n");
    for(int i=0;i<order->item_count;i++){
        int id=order->items[i].food_id;
        int quantity=order->items[i].quantity;
        int index=find_food(id);
        if(index!=-1){
            float amount=foods[index].price*quantity;
            printf("%-25s %-5d %-10.2f\n",
                   foods[index].name,
                   quantity,
                   amount);
        }
    }
    printf("------------------------------------------------------\n");
    printf("Subtotal       : %.2f BDT\n",order->subtotal);
    printf("Discount       : -%.2f BDT\n",order->discount);
    printf("======================================================\n");
    printf("TOTAL          : %.2f BDT\n",order->total);
    printf("======================================================\n");
    if(order->discount>0){
        printf("Congratulations! You received a discount.\n");
    }
    if(order->total>=1500){
        printf("You are a VIP customer today!\n");
    }else if(order->total>=1000){
        printf("Thank you for being our premium customer!\n");
    }else{
        printf("Thank you for ordering!\n");
    }
    printf("******************************************************\n");
}
void save_data(void){
    FILE *file=fopen("restaurant.txt","w");
    if(file==NULL){
        return;
    }
    fprintf(file,"%d %d\n",food_count,order_count);
    for(int i=0;i<food_count;i++){
        fprintf(file,"%d|%s|%s|%.2f|%d|%d\n",
                foods[i].id,
                foods[i].name,
                foods[i].category,
                foods[i].price,
                foods[i].stock,
                foods[i].sold);
    }
    fclose(file);
}
void load_data(void){
    FILE *file=fopen("restaurant.txt","r");
    if(file==NULL){
        return;
    }
    int saved_foods;
    int saved_orders;
    if(fscanf(file,"%d %d\n",&saved_foods,&saved_orders)!=2){
        fclose(file);
        return;
    }
    if(saved_foods<0){
        saved_foods=0;
    }
    if(saved_foods>MAX_FOOD){
        saved_foods=MAX_FOOD;
    }
    for(int i=0;i<saved_foods;i++){
        char line[200];
        if(fgets(line,sizeof(line),file)==NULL){
            break;
        }
        char *part;
        part=strtok(line,"|");
        if(part!=NULL){
            foods[i].id=atoi(part);
        }
        part=strtok(NULL,"|");
        if(part!=NULL){
            strcpy(foods[i].name,part);
            foods[i].name[strcspn(foods[i].name,"\n")]='\0';
        }
        part=strtok(NULL,"|");
        if(part!=NULL){
            strcpy(foods[i].category,part);
            foods[i].category[strcspn(foods[i].category,"\n")]='\0';
        }
        part=strtok(NULL,"|");
        if(part!=NULL){
            foods[i].price=atof(part);
        }
        part=strtok(NULL,"|");
        if(part!=NULL){
            foods[i].stock=atoi(part);
        }
        part=strtok(NULL,"|");
        if(part!=NULL){
            foods[i].sold=atoi(part);
        }
    }
    food_count=saved_foods;
    if(saved_orders<0){
        saved_orders=0;
    }
    if(saved_orders>MAX_ORDERS){
        saved_orders=MAX_ORDERS;
    }
    order_count=saved_orders;
    fclose(file);
}
int recursive_total(int n){
    if(n<=0){
        return 0;
    }
    return n+recursive_total(n-1);
}
void clear_input(void){
    int c;
    while((c=getchar())!='\n'&&c!=EOF){
    }
}
void pause_screen(void){
    printf("\nPress ENTER to continue...");
    clear_input();
    getchar();
}
