# Quick Sort Code


#### Sort an array A using Quick Sort.

#### Change in the input array itself. So no need to return or print anything.

  

##### Input format :

```
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

```

##### Output format :

```
Array elements in increasing order (separated by space)

```

##### Constraints :

```
1 <= n <= 10^3

```

##### Sample Input 1 :

```
6 
2 6 8 5 4 3

```

##### Sample Output 1 :

```
2 3 4 5 6 8

```

##### Sample Input 2 :

```
5
1 5 2 7 3

```

##### Sample Output 2 :

```
1 2 3 5 7 
```

## SOLUTION:

    #include<iostream>
    using namespace std;
    
    
    int partition(int input[] , int start, int end){
        int count = 0;
        for(int i = start+1; i<= end; i++){
            if(input[start] <= input[i]){
                count++;
            }
        }
        int index = start+count;
        if(count == 0){
            return index;
        }
        
        //swap
        int x = input[start];
        input[start] = input[index];  
        input[index] = x;
        
        
        int left = start;
        int right = end;
        for(; left<=index-1; left++){
         for(; right>=index+1; right--){
             if(input[left] < x){
                 if(input[right] >= x){
                     //swap
                     int temp = input[right];
                     input[right] = input[left];
                     input[left] = temp;
                     right--;
                     break;
                 }else{
                     continue;
                 }
             }else{
                 break;
             }
         }   
        }
        return index;
    }
    
    void quickSort1(int input[], int start, int end)
    	{
        		// your code goes here 
        if(start>= end){
            return;
        }
        int c = partition(input , start, end);
        quickSort1(input, start, c-1);
        quickSort1(input, c+1, end);
    }
    
    void quickSort(int input[], int size) {
      /* Don't write main().
         Don't read input, it is passed as function argument.
         Change in the given array itself.
         Taking input and printing output is handled automatically.
      */
        if(size == 0 || size == 1){
            return;
        }
       quickSort1(input, 0, size - 1);
    }
    
    int main(){
        int n;
        cin >> n;
      
        int *input = new int[n];
        
        for(int i = 0; i < n; i++) {
            cin >> input[i];
        }
        
        quickSort(input, n);
        for(int i = 0; i < n; i++) {
            cout << input[i] << " ";
        }
        
        delete [] input;
    
    }


## SOLUTION (CN - APPROACH):

    /*
    Time Complexity : O(n * log(n))
    Space Complexity : O(n)
    where n is size of input array
    */
    #include <iostream>
    using namespace std;
    int partitionArray(int input[], int start, int end)
    {
    // Chose pivot
    int pivot = input[start];
    // Count elements smaller than pivot and swap
    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
    if (input[i] <= pivot)
    {
    count++;
    }
    }
    int pivotIndex = start + count;
    int temp = input[start];
    input[start] = input[pivotIndex];
    input[pivotIndex] = temp;
    // ensure left half contains elements smaller than pivot
    // and right half larger
    int i = start, j = end;
    while (i <= pivotIndex && j >= pivotIndex)
    {
    while (input[i] <= pivot)
    {
    i++;
    }
    while (input[j] > pivot)
    {
    j--;
    }
    if (i < pivotIndex && j > pivotIndex)
    {
    int temp = input[i];
    input[i] = input[j];
    input[j] = temp;
    i++;
    j--;
    }
    }
    return pivotIndex;
    }
    void quickSort(int input[], int start, int end)
    {
    if (start >= end)
    {
    return;
    }
    int pivotIndex = partitionArray(input, start, end);
    quickSort(input, start, pivotIndex - 1);
    quickSort(input, pivotIndex + 1, end);
    }
    void quickSort(int input[], int n)
    {
    quickSort(input, 0, n - 1);
    }
