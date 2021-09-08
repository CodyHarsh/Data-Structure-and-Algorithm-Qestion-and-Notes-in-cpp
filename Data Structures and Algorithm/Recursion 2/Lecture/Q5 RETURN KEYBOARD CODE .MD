
# Return Keypad Code


#### Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.

#### Return empty string for numbers 0 and 1.

#### Note : 1. The order of strings are not important.

#### 2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

##### Input Format :

```
Integer n

```

##### Output Format :

```
All possible strings in different lines

```

##### Constraints :

#### 1 <= n <= 10^6

##### Sample Input:

```
23

```

##### Sample Output:

```
ad
ae
af
bd
be
bf
cd
ce
cf
```

## SOLUTION:
```
#include <iostream>
#include <string>
using namespace std;

#include <string>
using namespace std;

int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if(num == 0){
        output[0] = "";
        return 1;
    }
    
    int lastDigit = num%10;
    int count = keypad(num/10 , output);
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string str = mapping[lastDigit];
    int lenght = str.size();
    int start = count;
    
    for(int i = 1; i<lenght; i++){// i == 1because our 1st we have to take same copies of the number. We have to make 2 more extra copies and 1 copies we are using from the present string
        for(int j = 0; j<count; j++){
            output[j+start] =  output[j];
        }
        start += count;
    }
    
    
    int k = 0; //
     for(int i = 0; i<=lenght; i++){ // 
        for(int j = 0; j<count; j++){ //
            output[k] =  output[k] + str[i]; //
            k++; //
        } //
        start += count; //
    } //
    
    return count*lenght;
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
```
## SOLUTION (CN - APPROACH):

    #include <iostream>
    #include <string>
    using namespace std;
    int keypad(int num, string output[], string options[]){
    if(num == 0){
    output[0] = "";
    return 1;
    }
    int lastDigit = num % 10;
    int smallNumber = num / 10;
    string smallOutput[500];
    int smallCount = keypad(smallNumber, smallOutput, options);
    string op = options[lastDigit];
    int k = 0;
    for(int i = 0; i < op.length(); i++){
    for(int j = 0; j < smallCount; j++){
    output[k] = smallOutput[j] + op[i];
    k++;
    }
    }
    return k;
    }
    int keypad(int num, string output[]){
    string options[] = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs","tuv","wxyz"};
    return keypad(num, output, options);
    }
