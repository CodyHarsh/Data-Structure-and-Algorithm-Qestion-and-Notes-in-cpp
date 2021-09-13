# Print Subset Sum to K
#### Given an array A and an integer K, print all subsets of A which sum to K.

##### Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

##### Note : The order of subsets are not important. Just print them in different lines.

##### Input format :

```
Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

```

##### Sample Input:

```
9 
5 12 3 17 1 18 15 3 17 
6

```

##### Sample Output:

```
3 3
5 1
```

## SOLUTION:

    #include <iostream>
    using namespace std;
    
    void sub(int input[] , int n,  int k,int *allSub, int m ){
        if(n == 0){
            int add = 0;
            for(int i = 0; i<m; i++){
                add += allSub[i];
            }
            if(add == k){
                for(int i = 0; i<m; i++){
                    cout<<allSub[i]<<" ";
                }
                cout<<endl;
            }
            
            return ;
        }
       sub(input+1, n-1, k,allSub, m);
        allSub[m] = input[0];
       sub(input+1, n-1, k,allSub , m+1);
    }
    void printSubsetSumToK(int input[], int size, int k) {
        // Write your code here
        int *allSub = new int [10000000];
        sub(input , size, k, allSub, 0);
    }
    
    
    int main() {
      int input[1000],length,k;
      cin >> length;
      for(int i=0; i < length; i++)
        cin >> input[i];
      cin>>k;
      printSubsetSumToK(input, length,k);
    }

## SOLUTION (CN APPROACH):

    void subsetSumToKHelper(int input[], int startIndex, int size, int output[], int oSize, int k)
    {
    if(startIndex == size) {
    if(k == 0) {
    for(int i = 0; i < oSize; i++) {
    cout << output[i] << " ";
    }
    cout << endl;
    }
    return;
    }
    int smallOutout1[1000], smallOutput2[1000], smallSize1 = 0, smallSize2 = 0;
    subsetSumToKHelper(input, startIndex+1, size, output, oSize, k);
    if(k > 0) {
    int i;
    for(i = 0; i < oSize; i++) {
    smallOutput2[i] = output[i];
    }
    smallOutput2[i] = input[startIndex];
    subsetSumToKHelper(input, startIndex+1, size, smallOutput2, oSize+1, kinput[startIndex]);
    }
    }
    void printSubsetSumToK(int input[], int size, int k) {
    int output[1000];
    subsetSumToKHelper(input, 0, size, output, 0, k);
    }
