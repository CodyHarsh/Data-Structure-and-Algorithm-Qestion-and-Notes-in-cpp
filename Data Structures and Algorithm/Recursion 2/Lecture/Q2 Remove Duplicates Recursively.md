# Remove Duplicates Recursively


#### Given a string S, remove consecutive duplicates from it recursively.

##### Input Format :

```
String S

```

##### Output Format :

```
Output string

```

##### Constraints :

```
1 <= |S| <= 10^3
where |S| represents the length of string

```

##### Sample Input 1 :

```
aabccba

```

##### Sample Output 1 :

```
abcba

```

##### Sample Input 2 :

```
xxxyyyzwwzzz

```

##### Sample Output 2 :

```
xyzwz
```
## SOLUTION:

    #include <iostream>
    using namespace std;
    
    void removeConsecutiveDuplicates(char *input) {
    	/* Don't write main().
    	* Don't read input, it is passed as function argument.    
    	* Change in the given string itself.
    	* No need to return or print anything
    	* Taking input and printing output is handled automatically.
    	*/
        if(input[0] == '\0'){
            return;
        }
        if(input[0] == input[1]){
            int i = 0;
            for(; input[i] != '\0'; i++){
                input[i] = input[i+1];
            }
            input[i] = input[i+1];
            removeConsecutiveDuplicates(input);
        }else{
            removeConsecutiveDuplicates(input+1);
        }
    }
    
    int main() {
        char s[100000];
        cin >> s;
        removeConsecutiveDuplicates(s);
        cout << s << endl;
    }
## SOLUTION 2 (CN - APPROACH):

    /*
    Time Complexity : O(n)
    Space Complexity : O(n)
    where n is size of input array
    */
    void remove(char *input, int newIndex, int index)
    {
    if (input[index] == '\0')
    {
    input[newIndex] = input[index - 1];
    input[newIndex + 1] = '\0';
    return;
    }
    if (input[index] == input[index - 1])
    {
    remove(input, newIndex, index + 1);
    return;
    }
    else
    {
    input[newIndex] = input[index - 1];
    }
    remove(input, newIndex + 1, index + 1);
    }
    void removeConsecutiveDuplicates(char *input)
    {
    remove(input, 0, 1);
    }
