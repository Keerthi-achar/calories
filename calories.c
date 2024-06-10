#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int burn=0,t_cal=0,tb_cal=0,tl_cal=0;
typedef struct slist node;
node *head=NULL,*cur;
struct slist2
{
    int b_cal;
    struct slist2*ptr2;
};
typedef struct slist2 node2;
node2 *head2=NULL,*new1,*cur2,*prev2;
struct slist3
{
    int l_cal;
    struct slist3*ptr3;
};
typedef struct slist3 node3;
node3 *head3=NULL,*cur3,*new2,*prev3;
void intake_calories();
void display_calories();
void breakfast();
void lunch_din();
void burned_calories();
void main()
{
    int ch;
    do
    {
        printf("\nENTER YOUR OPTION :");
        printf("\n 1) INTAKE 2) BURNED 3) DISPLAY MINI REPORT 4) EXIT \n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            intake_calories();break;
        case 2:
            burned_calories();break;
        case 3:
            display_calories();break;
        case 4:printf("\n\n\n\t\t\t\tThank you for using CALORIE TRACKER\n\t\t\t\tKeep tracking Stay Healthy : )\n\n\n\n");break;
        default :printf("\n Error:Please enter the valid choice");       }
    }
    while(ch!=4);
}
void intake_calories()
{
    system("cls");
    int r,n,c,i=0;
    do
    {
        printf("\n1. Breakfast\n2. Lunch/Dinner\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&r);
        switch(r)
        {
            case 1: breakfast();break;
            case 2: lunch_din();break;
            case 3: break;
            default: printf("\nEnter a valid option");
        }
    }
    while(r!=3);

}
void breakfast()
{
    int nd,ch,n,i=0;
    system("cls");
    printf("\nEnter the number of dishes: ");
    scanf("%d",&nd);
    printf("\n1.Idli\n2.Dosa\n3.Egg\n4.Bread\n5.Roti\n6.Puri:");
    for(i=0;i<nd;i++)
    {
        new1=(node2*)malloc(sizeof(node2));
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        printf("\nEnter the numbers you ate: ");
        scanf("%d",&n);
        new1->ptr2=NULL;
        if(head2==NULL)
        {
            head2=new1;
            cur2=new1;
        }
        else
        {
            prev2->ptr2=new1;
            cur2=new1;
        }
        switch(ch)
        {
            case 1:cur2->b_cal=(n*39);
                break;
            case 2:cur2->b_cal=(n*80);
                break;
            case 3:cur2->b_cal=(n*60);
                break;
            case 4:cur2->b_cal=(n*35);
                break;
            case 5:cur2->b_cal=(n*106);
                break;
            case 6:cur2->b_cal=(n*100);
                break;
        }
        prev2=new1;

    }
}

void lunch_din()
{
    int d,h,no,j=0;
    system("cls");
    printf("\nEnter the number of dishes: ");
    scanf("%d",&d);
    printf("\n1.Rice&Sambar\n2.CurdRice\n3.Rice with Meat\n4.Parota\n5.Fish\n6.Biryani:");
    for(j=0;j<d;j++)
    {
        new2=(node3*)malloc(sizeof(node3));
        printf("\nEnter your choice: ");
        scanf("%d",&h);
        printf("\nEnter the numbers you ate: ");
        scanf("%d",&no);
        new2->ptr3=NULL;
        if(head3==NULL)
        {
            head3=new2;
            cur3=new2;
        }
        else
        {
            prev3->ptr3=new2;
            cur3=new2;
        }
        switch(h)
        {
            case 1:cur3->l_cal=(no*258);
                break;
            case 2:cur3->l_cal=(no*376);
                break;
            case 3:cur3->l_cal=(no*300);
                break;
            case 4:cur3->l_cal=(no*126);
                break;
            case 5:cur3->l_cal=(no*142);
                break;
            case 6:cur3->l_cal=(no*348);
                break;
        }
        prev3=new2;
    }
}

void burned_calories()
{
    int ch,n,nm;
    system("cls");
    printf("Enter the number of physical activities done : ");
    scanf("%d",&n);
    printf("\n1. WALKING\n2. RUNNING\n3. CYCLING\n4. SWIMMING:\n");
    for(int i=0;i<n;i++)
    {
        printf("\nEnter the choice : ");
        scanf("%d",&ch);
        printf("\nEnter the number of minutes : ");
        scanf("%d",&nm);
        switch(ch)
        {
            case 1:burn+=(nm*5);
                break;
            case 2:burn+=(nm*10);
                break;
            case 3:burn+=(nm*10);
                break;
            case 4:burn+=(nm*10);
                break;
        }
    }
}

void display_calories()
{
    system("cls");
    tb_cal=0;
    tl_cal=0;
    printf("===========================================================================================");
    printf("\n\n\n\t\t\t\t\t:MINI REPORT:\n\n\n");
    printf("===========================================================================================");
    cur2=head2;
    cur3=head3;
    while(cur2!=NULL)
    {
        tb_cal+=cur2->b_cal;
        cur2=cur2->ptr2;
    }
    while(cur3!=NULL)
    {
        tl_cal+=cur3->l_cal;
        cur3=cur3->ptr3;
    }
    t_cal=tb_cal+tl_cal;
    printf("\n\nBreakfast calories = %d\nLunch/dinner calories = %d\nBurned calories = %d\n",tb_cal,tl_cal,burn);
    if(t_cal<=burn)
    {
        printf("\nBurned calories is more than Intake\nDo less physical activity/excersice");
    }
    if(tb_cal<150)
    {
        printf("\nIntake calorie for breakfast is not enough");
    }
    else if(tb_cal>500)
    {
        printf("\nIntake calorie for breakfast exceeds healthy limit\nDo eat less");
    }
    if(tl_cal<350)
    {
        printf("\nIntake calorie for lunch/dinner is not enough");
    }
    else if(tl_cal>550)
    {
        printf("\nIntake calorie for lunch/dinner exceeds healthy limit\nDo eat less");
    }

}
