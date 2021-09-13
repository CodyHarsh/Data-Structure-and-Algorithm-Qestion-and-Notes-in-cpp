
# Return all codes - String


#### Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.

##### Note : The order of codes are not important. And input string does not contain 0s.

##### Input format :

```
A numeric string

```

##### Constraints :

#### 1 <= Length of String S <= 10

##### Sample Input:

```
1123

```

##### Sample Output:

```
aabc
kbc
alc
aaw
kw
```

## SOLUTION:

    #include <iostream>
    #include <string.h>
    using namespace std;
    int getCodes(string input, string output[]) {
    
       // int size = input.size();
            if(input[0] == '\0'){
            output[0] = "";
            return 1;
        }
        string arr1[500];
        string arr2[500];
        int num1 = input[0] - 48;
        char ch1 = 'a' + num1 -1;
        char ch2= '\0';
        int x1 = getCodes(input.substr(1) , arr1);
        int x2 = 0;
         
        
        // arr1[0] =  ch;
        if(input[1] != '\0'){
            int num2  =( num1 *10) + (input[1] - 48);
            if(num2 >= 10 && num2<=26){
                ch2 = num2 + 'a' -1;
                x2 = getCodes(input.substr(2), arr2);
           
        }
        }
        int k=0;
        for(int i = 0; i<x1; i++){
            output[k++] = ch1+arr1[i];
        }
        
         for(int i = 0; i<x2; i++){
                output[k++] = ch2+arr2[i];
            }
        
       
        return k;
        
    }
    
    int main(){
        string input;
        cin >> input;
    
        string output[10000];
        int count = getCodes(input, output);
        for(int i = 0; i < count && i < 10000; i++)
            cout << output[i] << endl;
        return 0;
    }




