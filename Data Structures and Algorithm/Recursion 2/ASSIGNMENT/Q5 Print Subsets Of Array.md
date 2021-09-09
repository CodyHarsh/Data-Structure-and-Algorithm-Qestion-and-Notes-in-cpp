# Print Subsets of Array


#### Given an integer array (of length n), find and print all the subsets of input array.

##### Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

##### Note : The order of subsets are not important. Just print the subsets in different lines.

##### Input format :

```
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

```

##### Constraints :

#### 1 <= n <= 15

##### Sample Input:

```
3
15 20 12

```

##### Sample Output:

```
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
```

## SOLUTION:

    #include <iostream>
    using namespace std;
    
    void printSubset(int input[] , int size, int *output, int m){
        if(size == 0){
            for(int i = 0; i<m; i++){
                cout<<output[i]<<" ";
            }
            cout<<endl;
            return;
        }
        
        printSubset(input+1, size-1, output, m);
        output[m] = input[0];
        printSubset(input+1, size-1,output, m+1);
    }
    void printSubsetsOfArray(int input[], int size) {
    	// Write your code here
        
       printSubset(input, size, new int[10000000], 0);
    }
    
    
    int main() {
      int input[1000],length;
      cin >> length;
      for(int i=0; i < length; i++)
      	cin >> input[i];
      printSubsetsOfArray(input, length);
    }

## SOLUTION (CN APPROACH):

    void printSubsetsOfArrayHelper(int input[], int startIndex, int size, int output[], int oSize)
    {
    if(startIndex == size) {
    for(int i = 0; i < oSize; i++) {
    cout << output[i] << " ";
    }
    cout << endl;
    return;
    }
    int smallOutput[40], smallOSize = 0;
    printSubsetsOfArrayHelper(input, startIndex+1, size, output, oSize);
    int i;
    for(i = 0; i < oSize; i++) {
    smallOutput[i] = output[i];
    }
    smallOutput[i] = input[startIndex];
    printSubsetsOfArrayHelper(input, startIndex+1, size, smallOutput, oSize+1);
    }
    void printSubsetsOfArray(int input[], int size) {
    int output[1000];
    return printSubsetsOfArrayHelper(input, 0, size, output, 0);
    }
