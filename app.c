#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>
#include <stdarg.h>

#define  message_for(a, b)  \
   printf(#a " and " #b ": We love you!\n")

struct book
{
   char title[10];
   double price;
   int pages;
   double result;
};

struct book2{
   char *title;
   double price;
   int pages;
} b2;

struct mysTruct
{
   int a;
   struct mysTruct *b;
};

struct employee{
   char name[10];
   float salary;
   struct dob{
      int d, m, y;
   } d1;
};

typedef struct Books {
   char title[50];
   char author[50];
   char subject[100];
   int book_id;
} Book;

int* test2(int *a);
int calculate(int x, int *y, int *z);
static int count = 5; /* global variable */
/* extern int test = 32; */

int calculateMaxElement(int *arr, int length);
void assignArray(int number, int *arr);
float *arrfunction(int x);
char * hellomsg(char *x);
struct book displayBookInformation(struct book b1);
struct book calculatebookByReference(struct book *b1);
struct book *area(double x, double y);
void disp(int pos, int num, int input[50]);
typedef struct Gavno {
   int x;
   int y;
} gavno;


double average(int num,...) {

   va_list valist;
   double sum = 0.0;
   int i;

   /* initialize valist for num number of arguments */
   va_start(valist, num);

   /* access all the arguments assigned to valist */
   for (i = 0; i < num; i++) {
      sum += va_arg(valist, int);
   }
	
   /* clean memory reserved for valist */
   va_end(valist);

   return sum/num;
}

int runner()
{
    int count = 0;
    count++;
    return count;
}

void move(gavno *p){
   (*p).x++;
   (*p).y++;
}

typedef struct node {
    int val;
    char name[15];
    struct node * next;
} node_t;

void push(node_t ** head, int val) {
   /*Adding an item to the beginning of the list*/
   /*
   node_t * new_node;
   new_node = (node_t *)malloc(sizeof(node_t));
   
   new_node->val = val;
   strcpy(new_node->name, "Arturas3");
   new_node->next = *head;
   *head = new_node;
*/
   /*Adding an item to the end of the list*/
/*
   while (current->next != NULL)
   {
      printf("%d, %s\n", current->val, current->name);
      current = current -> next;
   }
   
   current->next = (node_t*)malloc(sizeof(node_t));
   current->next->val = val;
   strcpy(current->next->name, "Arturas3");
   current->next->next = NULL;

   */
}

int removeLastItem(node_t * head) {
   int retval = 0;
   /* if there is only one item in the list, remove it */
   if (head->next == NULL)
   {
      retval = head->val;

      free(head);

      return retval;
   }

    /* get to the second to last node in the list */
   node_t * current = head;
   while (current->next->next != NULL)
   {
      current = current->next;
   }
   
    /* now current points to the second to last item of the list, so let's remove current->next */
   retval = current->next->val;

   current->next = NULL;

   free(current->next);
   return retval;
}

int removeFirstItem(node_t ** head) {
   if (*head == NULL)
   {
      return -1;      
   }

   int retval = (*head)->val;

   free(*head);

   *head = (*head)->next;

   return retval;
}

int removeByIndex(node_t ** head, int n) {
   node_t * current = *head;

   if (n == 0)
   {
      return removeFirstItem(head);
   }

   for (int i = 0; i < n-1; i++)
   {
      if (current->next == NULL)
      {
         return -1;
      }
      current = current->next;
   }

   if (current->next = NULL)
   {
      return -1;
   }

   node_t * temp_node = current->next;
   int retval = temp_node->val;

   current->next = temp_node->next;

   free(temp_node);

   return retval;
}

void delete(int num, int* arr, int pos) {
   printf ("Before deletion \n");  

   for (int i = 0; i < num; i++)
   {
      printf("arr[%d]= %d\n", i, *(arr + i));
   }

   if (pos <= num)
   {
      for (int i = pos - 1; i < num; i++)
      {
         *(arr + i)= *(arr + i + 1);
      }      
   }
      printf (" \n The resultant array after deletion of the array elements are: \n");  
      for (int i = 0; i < num - 1; i++)  
      {  
         printf (" arr[%d] = %d \n", i, ( *(arr + i)));  
      }  
}

int main() {
    int *arr, num = 4, index;  
   //  printf (" Define the size of the array: ");  
   //  scanf (" %d", &num);  

   arr = (int *) malloc (sizeof(int) *num);  

   /*printf("Enter %d elements in ar array\n", num);

   for (int i = 0; i < num; i++)
   {
      printf("\n arr[%d=]", i);
      scanf("%d", (arr + i));
   }
  */ 
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
   //  printf (" Enter the position of the element to be deleted from an array: ");  
   //  scanf (" %d", &index);
    delete(num, arr, 4);

   /*Remove specific element from array*/   
   /*
   int input[50]= {1,2,3,4};
   int pos,  num;
   printf("\nEnter the number of elements in an array\n");
   scanf("%d", &num);

   printf("\n Enter %d elements in array \n", num);

   for (int i = 0; i < num; i++)
   {
      printf("arr[%d]=",i);
      scanf("%d", &input[i]);
   }
   
   printf("Define the position of the array element where you want to delete\n");
   scanf("%d", &pos);

   if (pos >= num +1)
   {
      printf("\n Deletion is not possible");
   } else {
      disp(pos, num, input);
   }

   printf("\n The resultant array is: \n");
   for (int i = 0; i < num -1; i++)
   {
      printf("input[%d] =", i);
      printf("%d\n", input[i]);    
   }
   */
   exit(EXIT_SUCCESS);
   node_t * node;
   node = (node_t *)malloc(sizeof(node_t));
   node->val = 1;
   strcpy(node->name, "Arturas");
   node->next = (node_t *)malloc(sizeof(node_t));
   node->next->val = 2;
   node->next->next = NULL;
   strcpy(node->next->name, "Arturas2");
   node->next->next = (node_t *)malloc(sizeof(node_t));
   node->next->next->val = 3;
   node->next->next->next = NULL;
   strcpy(node->next->next->name, "Arturas3");
   removeByIndex(&node, 2);
   /*
   push(&node, 3);
   */
   printf("after adding new item, we have result\n");

   node_t * current = node;
   while (current != NULL)
   {
      printf("%d, %s\n", current->val, current->name);
      current = current -> next;
   }

   /*
   gavno *newGavno = (gavno *)malloc(sizeof(gavno));  

   gavno g;
   g.x = 2;
   g.y = 3;
   move(&g);
   printf("%d\n", g.x);
   printf("%d\n", g.y);
*/
   /*
    printf("%d\n", runner());
    printf("%d\n", runner());
    */
   /*
   char name[100] = "test";
   char *description;

   strcpy(name, "Zara Ali");

   description = malloc(30 * sizeof(char));

   if (description == NULL)
   {
      fprintf(stderr, "error allocation");
   } else {
      strcpy(description, "Zara ali a DS student");
   }

   description = realloc(description, 100 * sizeof(char));

   if (description == NULL)
   {
      fprintf(stderr, "Error ");
   } else {
      strcat(description, ".She is in class 10th");
   }
   
   printf("Name= %s\n", name);
   printf("Description: %s\n", description);
   
   free(description);

   */
   /*
   printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
    FILE * pf;
   int errnum;
   pf = fopen ("unexist.txt", "rb");
	
   if (pf == NULL) {   
      errnum = errno;
      fprintf(stderr, "Value of errno: %d\n", errno);
      perror("Error printed by perror");
      fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
      exit(EXIT_FAILURE);
   } else {
   
      fclose (pf);
   }

   printf(EXIT_SUCCESS);
   */
   /*
   int a = 17, b = 5;
   double result = a/b;
   printf("result is %f\n", result);

   message_for(Carole, Debra);
   Book book; 
   strcpy( book.title, "C Programming");
   strcpy( book.author, "Nuha Ali"); 
   strcpy( book.subject, "C Programming Tutorial");
   book.book_id = 6495407;
 
   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);
   struct mysTruct *p1, *p2, *p3, *start;

   struct employee e1 = {"Kiran", 25000, {12, 5, 1990}};
   printf("Name: %s\n", e1.name);
   printf("Salary: %f\n", e1.salary);
   printf("Date of Birth: %d-%d-%d\n", e1.d1.d, e1.d1.m, e1.d1.y);
   */
    /* allocates memory and stores it in pointer variable*/    
    /*
   p1 = (struct mysTruct *)malloc(sizeof(struct mysTruct));
   p1-> a = 10;
   p1-> b=NULL;

   start = p1;

   for (int i = 1; i <=5; i++)
   {
      p2 = (struct mysTruct *)malloc(sizeof(struct mysTruct));
      p2->a=i*2;
      p2->b = NULL;
      p1->b = p2;
      p1=p2;
   }
   p1=start;
   while (p1 != NULL)
   {
      printf("Add of current %d a: %d of next: %d\n", p1, p1->a, p1->b);
      p1=p1->b;
   }
*/
   /*
   struct book b[3];

   b[0].price = 650.50;
   b[0].pages = 123;

   b[1].price = 175;
   b[1].pages = 225;

   b[2].price = 250;
   b[3].pages = 250;

   struct book temp;
   for (int i=0; i<2; i++){
      for (int j=i; j<3; j++){
         if (b[i].price>b[j].price){
            temp = b[i];
            b[i] = b[j];
            b[j] = temp;
         }
      }
   }

   printf("\nList of books in ascending order of price\n");
   for (int i=0; i<3; i++){
      printf("Title: %s Price: %7.2lf No of Pages: %d\n", b[i].title, b[i].price, b[i].pages);
   }
   */
  /* struct book b1 = {pages: 12, price:2.2};

   strcpy(b1.title, "Learn Csds");

   struct book result = displayBookInformation(b1);
   printf("After modification %d\n", result.pages);
   printf("After modification %f\n", result.price);
   printf("After modification %s\n", result.title);
   calculatebookByReference(&b1);
   printf("Result after calculation %f\n", b1.result);

   printf("Input length and breadth of a rectangle\n");
   //scanf("%f %f", &x, &y);
   float num1=10.5, num2=20.5;
   struct book *r= area(num1, num2);
   printf("Result: %f \n price: %f \n pages: %lf\n", r->result, r->price, r->pages);
*/
   /* int size = sizeof(langs) / sizeof(char*);

   for (int i = 0; i < size; i++)
   {
      printf("%s\n", langs[i]);
   }
   */
   
   /*char str1[12] = "Hello";
   char str2[12] = "World";
   */
   /* concatenates str1 and str2 */
   /*strcat( str1, str2);
   printf("strcat( str1, str2):   %s\n", str1 );
   */
   /*int numbers[] = {1,2,3,5};
   int size = sizeof(numbers) / sizeof(int);
   printf("size is %d", numbers[size - 1]);
   /*
   printf("address of numbers is %d", &number);
   int *result = test2(numbers);
   for (int i = 0; i < 4; i++)
   {
     printf("%d\n", result[i]);
   }*/ 
   /*
   int num[] = {23,1,243,3};
   int rows = sizeof(num) / sizeof(int);
    int result = GetCalculatedValues(num, rows); 
   int result = calculateMaxElement(num, rows);
   printf("max is %d", result);
*/
   int x = 100, i;
   /*float *arr = arrfunction(x);
   
   printf("Square of %d: %f\n", x, *arr);
   printf("cube of %d: %f\n", x, arr[1]);
   printf("Square root of %d: %f\n", x, arr[2]);
*/
 /*  char *name = "TutorialsPoint";
   char *arr = hellomsg(name);
   printf("%s\n", arr);
   */
   return 0;
}

void disp(int pos, int num, int input[50])
{
   for (int i = pos - 1; i < num - 1; i++)
   {
      input[i] = input[i + 1];
   }
}

struct book * area(double x, double y){
   double area = (double)(x*y);
   static struct book r;
   r.result = area; r.price=y; r.pages=x;
   return &r;
}

struct book calculatebookByReference(struct book *b1) {
   b1->result = b1->pages * b1->price;
}

/* struct book displayBookInformation(struct book b1) {
   printf("%d\n", b1.pages);
   printf("%f\n", b1.price);
   printf("%s\n", b1.title);
   struct book b = { pages: b1.pages , price: b1.price };
   strcpy(b.title, b1.title);
   return b;
}
*/
char * hellomsg(char *x) {
   char *arr = (char *)malloc(50*sizeof(char));
   strcpy(arr, "Hello ");
   strcat(arr, x);
   return arr;
}

float *arrfunction(int x){
   static float arr[3];
   arr[0]=pow(x,2);
   arr[1]=pow(x, 3);
   arr[2]=pow(x, 0.5);
   return arr;
}

void assignArray(int number, int *arr) {
    arr[0] = pow(number, 4);
    arr[1] = pow(number, 5);
}

int calculateMaxElement(int *arr, int length) {
   int max = *arr;
   for (int i = 0; i < length; i++)
   {
      printf("current item %d\n", *arr);
      if(*arr >max) {
        max = *arr;
      }

      *arr++;
   }

   return max;
}

/*double GetCalculatedValues(int numbers[], int rows){
    int sum = 0;
    int rows2 = sizeof(numbers) / sizeof(int);
    for (int counter = 0; counter < rows; counter++)
    {
        int value = numbers[counter];
        printf("current Value is: %d\n", value);
        sum+=value;
    }
    printf("Sume of values %d", sum);

    return pow(sum, 2);
}
*/
int * test2(int*a){
    int i;
    for(i=0; i<4; i++) {
        a[i] = 2 *a[i];
    }
    return a;
}

int calculate(int x, int *y, int *z) {
 *y = pow(x, 2);
 *z = pow(x, 3);

 return 0;
}

/* function definition */
void func( void ) {

   static int i = 5; /* local static variable */
   i++;

   printf("i is %d and count is %d\n", i, count);
}