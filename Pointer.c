#include<stdio.h>
/*row==num1 and column==num2*/
#define num1 3
#define num2 4
#define num3 7
const int row=3;
const int column =4;

/************************* Function returning pointers *************************/
float *fun(float p){
    return (&p);// since address are saved in pointer, it is returned by the function
}

/******************* 2 ways to pass an 1D array to a function *******************/

int fun1(int *a, int row);//a+1 will give address of next element
int fun2(int a[],int row);//a+1 will give address of next element

/******************* 3 ways of passing 2d array to a function *******************/

int fun3(int *a, int row, int column);// a is a int pointer not array pointer
int fun4(int a[][num1], int row, int column);// a is a array acts as a pointer to a 2d array | a+1 give you sizeof(int)num1 
int fun5(int (*p)[num1],int row, int column)// p is a Pointer to an 2d array | p+1 will give you sizeof(int)num1
{
    int *n=p;// an int pointer is required, since p+1==n*row and n+1 = sizeof(int)
    for (int i = 0; i < row; i++)
    {
        n=p+i;
        for (size_t i = 0; i < column; i++)
        {
            print("%d",*(n+column));
        }
        
    }
    
}

/***************** 3 ways of passing 3d array to a function *******************/
int fun6(int *p, int i,int j, int k);// p is an int pointer not an array
int fun7(int p[][num1][num2], int i,int j, int k);// a is an array
int fun8(int (*p)[num1][num2], int i,int j, int k);// p is a pointer to an 3d array, this function is extended similar to above function since p+1=(int*)*row*column

/******************** returning 2d array from function *************************/
int *fun9(){
    static int a[num1][num2];
    return (int*)a;// as definition of this function only an int pointer must be returned
}// main function part >> int *a; int *fun9(); a=fun9()
int (*fun10())[num2]{
    static int a[num1][num2];
    return (int(*)[num2])a;// as definition of the function only an pointer to an 1D array is returned
}// main function part >> int(*b)[num2]; int (*fun10())[num2]; b=fun2();
int (*fun11())[num1][num2]{
    static int a[num1][num2];
    return (int(*)[num1][num2])a;// as definition of the function only an pointer to an 1D array is returned
}// main function part >> int(*b)[num1][num2]; int (*fun10())[num1][num2]; b=fun2();

/****** returning 3d array from function 4 ways same as 2d array ****************/
int *fun9(){
    static int a[num1][num2];
    return (int*)a;// as definition of the function only an pointer to an int is returned
}// main function part >> int *a; int *fun9(); a=fun9()
int (*fun10())[num2]{
    static int a[num1][num2];
    return (int(*)[num2])a;// as definition of the function only an pointer to an 1D array is returned
}// main function part >> int(*b)[num2]; int (*fun10())[num2]; b=fun2();
int (*fun11())[num1][num2]{
    static int a[num1][num2];
    return (int(*)[num1][num2])a;// as definition of the function only an pointer to an 2D array is returned
}
int (*fun11())[num1][num2][num3]{
    static int a[num1][num2][num3];
    return (int(*)[num1][num2][num3])a;// as definition of the function only an pointer to an 3D array is returned
}

/***************************** returning const string using pointer ****************************/
const char* fun12(){
    return "rain";// now rain become constant string there
} 

/************************************* pointers and array *********************************/
// num[i]==*(num+1)==*(i+num)==i[num]
// num[i][j]==*(num[i]+j)==*(*(num+i)+j)


int main(int argc, char const *argv[])
{
    int i=3;
    float a =33.1;

    // char pointers
    char *ii,*m="hello", *n="hello";
    char s[]="Hello";
    ii=(char*)&i; // allowed //Pointer Expicit conversion 
    /****************************************************/
    char s2[10]="hello";
    // invalid s=s2;
    // valid m=n;

    // valid m="hey";
    // invalid s="hey";
    /*****************************************************/
    char *name[]={// Pointer to string
        "Sti_shabh",
        "qwerty",
        "hello"
    };
    // advantage - swapping is easy
    swap(name[1],name[2]);
    /********************************************************/

    /**********************const ***************************/
    //*pointer==string==" " and pointer==pointer==" "
    char *p="qwerty";//string and pointer both are variable
    const char *p="qwerty";//string const pointer not const
    char const *p="qwerty";//string const pointer not const
    char *const p="qwerty";//pointer const string not
    const char *const p="qwerty";//both are const
    /******************************************************/
    int (*p)[5];// Pointer to array of 2nd Dimenstion as 5 elements here p+1 jumps the address by sizeof(int)*5 bytes
   
    printf("Address in i is ",ii);
    printf("Address in a is ",fun(a));
    
    return 0;
}
