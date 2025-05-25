#include <stdio.h>
#include <stdlib.h>

#define heap_size 10
struct heap
{
    int heap_index;
    int array[heap_size];
};

//function to swap current with parent in case current is bigger
//in case of min
void swap(struct heap *heap6, int current_data, int parent_data)
{   
    int temp = heap6->array[current_data];
    heap6->array[current_data] = heap6->array[parent_data];
    heap6->array[parent_data] = temp;
    return;
}
int right_child_exist(struct heap *heap8, int index)
{
    int right_child = index *2 + 2;
    printf("\nRIGHT %d", right_child);

    if(right_child <= heap8->heap_index-1)
    return 1;
    else return 0;
}

int left_child_exist(struct heap *heap8, int index)
{
    int left_child = index *2 + 1;
    printf("\nLEFT %d", left_child);

    if(left_child <= heap8->heap_index-1)
    return 1;
    else return 0;
}
//function to heapify down
// compare current with child nodes and swap
void heapify_down(struct heap *heap7, int current_index)
{
    if(heap7->heap_index <=0) return;
    if(current_index >= heap7->heap_index-1) return;
    int left_child = current_index *2 + 1;
    int right_child = current_index*2 + 2;
    int child =-1;
    printf("\nC : %d[%d] L: %d[%d] R: %d[%d] S: %d!",current_index,heap7->array[current_index],left_child,heap7->array[left_child],right_child,heap7->array[right_child], heap7->heap_index);
    
    if(left_child_exist(heap7,current_index))
    {
        if(right_child_exist(heap7,current_index))
        {
            if(heap7->array[right_child] > heap7->array[left_child])
            {
                child = left_child;
            }
            else child = right_child;
        }
        else child = left_child;
    }
    else return;
    
    if(heap7->array[current_index] > heap7->array[child])
    {
        printf("\nHeapify Down %d %d!", current_index, child);
        swap(heap7, current_index, child);
        heapify_down(heap7,child);
    }
    return;
}


//function to remove a value from heap
//search the value
// find the index
//swap with last node
//heapify down
void remove_node(struct heap *heap6)
{
    printf("\nBefore remove: length %d",heap6->heap_index );
    int current_index = 0;
    if(heap6->heap_index == 0)
    {
        printf("\nHeap Empty!");
        return;
    }
    
    printf("\nFound! element %d at Position %d: size %d",heap6->array[current_index],current_index,heap6->heap_index);
    if(current_index < 0)
    {
        printf("\nNot Found!");
        return;
    }
    heap6->array[current_index]=heap6->array[heap6->heap_index-1];
    printf("\n Swapped :%d at %d", heap6->array[current_index],current_index );
    heap6->heap_index--;
    printf("\nafter remove: length %d",heap6->heap_index );
    heapify_down(heap6,current_index);
}

//fucntion to heapify up
// compare with parent and swap if required
void heapify_up(struct heap *heap5, int current_index)
{
    int parent_index = (current_index-1)/2;
    if(heap5->array[current_index] < heap5->array[parent_index])
    {
        swap(heap5,current_index,parent_index);
    }
    else
    {
        return;
    }
    heapify_up(heap5,parent_index);
}

//function to write heap insert
//check if the heap if full, return
//check if the heap is empty, add to the array and increment heap_index
//if the array isnt empty or full, add to the last node;
int insert (struct heap *heap3, int data)
{
    if(heap3->heap_index == heap_size)
    {
        printf("\nHeap is Full!\n");
        return -1;
    }
    else if(heap3->heap_index == 0)
    {
        printf("\nHeap Empty!\n");
        heap3->array[heap3->heap_index] = data;
        heap3->heap_index++ ;
        return 1;
    }
    else
    {
        heap3->array[heap3->heap_index] = data;
        int current_index = heap3->heap_index;
        heapify_up(heap3, current_index);
        heap3->heap_index++;
        return 1;
    }
}
void heap_print(struct heap *heap4)
{
    if(heap4->heap_index == 0)
    {
        printf("\nHeap Empty!");
        return;
    }
    for(int i =0; i<heap4->heap_index;i++)
    {
        printf("\n Value :%d at %d", heap4->array[i],i);
    }
}
//function to craete a heap
struct heap *create_heap(void)
{
    //initializing heap
    struct heap *heap2 = (struct heap *)malloc(sizeof(struct heap));
    heap2->heap_index =0;
    if(heap2 != NULL)
    return heap2;
}

int main()
{   
    struct heap *heap1 = create_heap();
    if(heap1!= NULL) 
        printf("\nHeap allaocted!");
    insert(heap1,11);  
    insert(heap1,2);
    insert(heap1,30);
    insert(heap1,14);
    insert(heap1,52);
    insert(heap1,26);
    insert(heap1,7);
    insert(heap1,181);
    insert(heap1,91);
    heap_print(heap1);
    printf("\n***********\n");
    remove_node(heap1);
    remove_node(heap1);
    remove_node(heap1);
    remove_node(heap1);
    remove_node(heap1);
    remove_node(heap1);
    remove_node(heap1);
    remove_node(heap1);
    remove_node(heap1);hjhh

    heap_print(heap1);
}0- 