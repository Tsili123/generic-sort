 // ------------------ Quick sort ----------------------
 
#include "quicksort.h"
#define NUMBER_OF_STRING 5
#define MAX_STRING_SIZE 40


// sorts the array using quick sort algorithm
// gets: pointer to array, low index, high index, 
// pointer to compare function,pointer to swap function
void quicksort(void *array, int low, int high,int size,
		int (*Compare) (const void * x,const void * y), void (*gswap) (void* ptra, void* ptrb, int size))
{
	if (low >= high) // stop condition
		return;
	//set pivot location
	int pivot = place_pivot(array, low, high,size, Compare, gswap); 

	quicksort(array, low, pivot-1,size, Compare, gswap); // sort bottom half
	quicksort(array, pivot+1, high,size, Compare, gswap); // sort top half
}

// moves all the objects smaller than low to it's left
// and all the objects bigger than low to it's right
// gets: array, low, high, compare function, swap function
int place_pivot(void *array, int low, int high,int size,
		int (*Compare) (const void * x,const void * y), void (*gswap) (void* ptra, void* ptrb, int size))
{
	int pivot = low; // set pivot
	int switch_i;
	int i;
	
	for (switch_i = low+1, i = low+1; i <= high; i++) // run on array
	{
		if (Compare(array+i*size,array+pivot*size)) // compare pivot and i
		{
			gswap(array+i*size,array+switch_i*size,size); // swap i and i to switch
			gswap(array+pivot*size,array+switch_i*size,size); // swap pivot and i to switch
			pivot++; // set current location of pivot
			switch_i++; // set location for i to switch with pivot
		}
	}
	return pivot; // return pivot location
}

//gswap() takes two pointers, prta and ptrb, and the size of the data they point to
void gswap(void* ptra, void* ptrb, int size)
{
	int i;
    // temp will be our temporary variable for exchanging the values
    char temp;
    // We reinterpret the pointers as char* (byte) pointers
    char *pa = (char*)ptra;
    char *pb = (char*)ptrb;
    // We loop over each byte of the type/structure ptra/b point too, i.e. we loop over size
    for (i = 0 ; i < size ; i++) {
        temp = pa[i]; //store a in temp
        pa[i] = pb[i]; // replace a with b
        pb[i] = temp; // replace b with temp = old(a)
    }
}


void srtheap(void *base, int nelem, int size, int (*compar)(const void *, const void *))
{
    char *cb = (char *)base;

    int i = (nelem / 2);
    while (1) {
        heapify(cb, size, i, nelem-1, compar);
        if (i == 0) break;
        i--;
    }

    for (i = nelem-1; i >= 1; i--) {
        gswap(cb, cb+(size * i), size);
        heapify(cb, size, 0, i-1, compar);
    }
}

void heapify(char *base, const int size, int root, const int bottom, int (*compar)(const void *, const void *))
{
    int maxChild = root * 2 + 1;

    if (maxChild < bottom) {
        size_t otherChild = maxChild + 1;
        maxChild = (compar(base + (otherChild * size), base + (maxChild * size)) >=0 ) ? otherChild : maxChild;
    } else {
        if (maxChild > bottom) return;
    }
	
	
    if (compar(base + (root * size), base + (maxChild * size)) >= 0 ) return;

    gswap(base + (root * size), base + (maxChild * size), size);

    heapify(base, size, maxChild, bottom, compar);
}



int compare_int_quick(const void * x,const void * y){
    int * value1 = (int*)x;
    int * value2 = (int*)y;
    return *value1 >= *value2 ? 0 : 1;
}


int compare_int_heap(const void * x,const void * y){
    int * value1 = (int*)x;
    int * value2 = (int*)y;
    
    if(*value1 == *value2)
    	return 0;
    else if(*value1 > *value2)
    	return 1;
    else 
    	return -1;
}


/*
 * func_strcmp
 * Utility function for  normal strings.
 * Returns the result of comparing two strings using the strcmp function.
 */
int func_strcmp_quick(const void *p1, const void *p2) {
  return !strcmp((const char*)p1,(const char*)p2);
}

/*
 * func_strcmp
 * Utility function for  normal strings.
 * Returns the result of comparing two strings using the strcmp function.
 */
int func_strcmp_heap(const void *p1, const void *p2) {
  return strcmp((const char*)p1,(const char*)p2);
}

int main(void){
	
	
	char arr[NUMBER_OF_STRING][MAX_STRING_SIZE] =
	{ "array of c string",
	  "is fun to use",
	  "make sure to properly",
	  "why",
	  "tell the array size"
	};
	//int arr[8]={3,2,6,8,3,7,1,9};
	int i;
	//int i,len=MAX_STRING_SIZE,size=NUMBER_OF_STRING;
	
	//srtheap(arr,8,sizeof(int),compare_int_heap);
	//quicksort(arr,0,7,sizeof(int),compare_int_quick,gswap);
	
	srtheap(arr,5,MAX_STRING_SIZE,func_strcmp_heap);
	//quicksort(arr,0,3,MAX_STRING_SIZE,func_strcmp,gswap);
	
	//printf("%d\n",func_strcmp(arr[1],arr[2]));
	//printf("%d\n",IntCompare(arr[1],arr[2]));
	
	/*
	gswap(&arr[1], &arr[2], sizeof(int));
	printf("%d       %d\n",arr[1],arr[2]);*/
	
	/*
	gswap(&arr[1], &arr[2], MAX_STRING_SIZE);
	printf("%s       %s\n",arr[1],arr[2]);*/
	
	//Quicksort(arr,3,sizeof(arr[0]),IntCompare,gswap);
	
	for (i = 0; i < 5; i++){
    printf("%s \n", arr[i]);
    //printf("%d ", arr[i]);
	}
	return 0;
}
