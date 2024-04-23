#include<stdio.h>
#include<stdlib.h>

struct myArray{
    int total_size;
    int used_size;
    int *ptr;

};

void create_Array(struct myArray * a, int tsize, int usize)
{
    // (*a).total_size = tsize;
    // (*a).used_size = usize;
    // (*a).ptr = (int *)malloc(tsize*sizeof(int)); // dynamically creation of array

    // same thing using arrow operator
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = (int *)malloc(tsize*sizeof(int)); // dynamically creation of array

}

void set_value(struct myArray * a )
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("enter %d element:\n",i+1);
        scanf("%d",&(a->ptr)[i]);

    }
    
}

void show(struct myArray * a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d ",(a->ptr)[i]);
    }
    
}

int main()
{
    struct myArray marks;
    create_Array(&marks,10,2);
    set_value(&marks);
    show(&marks);

    return 0;
}