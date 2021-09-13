# Print all Codes - String


#### Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.

##### Note : The order of codes are not important. Just print them in different lines.

##### Input format :

```
A numeric string S

```

##### Output Format :

```
All possible codes in different lines

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
    using namespace std;
    
    void print(string input, string output){
        if(input[0] == '\0'){
            //output[0] = "";
           // int size = output.size();
            cout<<output<<endl;
            return ;
        }
        int num1 = input[0] - '0';
        char ch1 = num1 + 'a' - 1;
       print(input.substr(1) , output+ch1);
        char ch2 = '\0';
        if(input[1] != '\0'){
            int num2 = (num1*10) + (input[1] - '0');
            ch2 = num2 + 'a' - 1;
            if(num2 >=10 && num2 <= 26){
                 print(input.substr(2) , output+ch2);
            }
        }
        
    }
    
    void printAllPossibleCodes(string input) {
        /*
        Given the input as a string, print all its possible combinations. You do not need to return anything.
        */
    
        
        print(input , "");
        
    }
    
    
    
    int main(){
        string input;
        cin >> input;
    
        printAllPossibleCodes(input);
        return 0;
    }

## SOLUTION(CN APPROACH):

    #include <string.h>
    using namespace std;
    void printAllPossibleCodesHelper(string input, string output){
    if(input[0] == '\0'){
    cout << output << endl;
    return;
    }
    int num = input[0] - 48;
    char ch = num - 1 + 'a';
    printAllPossibleCodesHelper(input.substr(1), output + ch);
    if(input[1] != '\0'){
    num = num * 10 + input[1] - 48;
    ch = num - 1 + 'a';
    if(num >= 10 && num <= 26){
    printAllPossibleCodesHelper(input.substr(2), output + ch);
    }
    }
    }
    void printAllPossibleCodes(string input) {
    printAllPossibleCodesHelper(input, "");
    }
