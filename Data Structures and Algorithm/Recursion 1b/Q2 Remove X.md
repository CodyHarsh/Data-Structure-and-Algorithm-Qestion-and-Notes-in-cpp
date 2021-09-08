# Remove X


#### Given a string, compute recursively a new string where all 'x' chars have been removed.

##### Input format :

```
String S

```

##### Output format :

```
Modified String

```

##### Constraints :

```
1 <= |S| <= 10^3
where |S| represents the length of string S. 

```

##### Sample Input 1 :

```
xaxb

```

##### Sample Output 1:

```
ab

```

##### Sample Input 2 :

```
abc

```

##### Sample Output 2:

```
abc

```

##### Sample Input 3 :

```
xx

```

##### Sample Output 3:
```
```
## SOLUTION:

    #include <iostream>
    using namespace std;
    
    // Change in the given string itself. So no need to return or print anything
    // Change in the given string itself. So no need to return or print anything
    #include<cstring>
       void removePi(char input[] ,int  length){
        if(input[0] == '\0'){
            return;
        }
        
        if(input[0] == 'x'){
        for(int i = 0; input[i] != '\0'; i++){
            input[i] = input[i+1];
        }
        
         return removePi(input , length -1);
        }
        else{
        return removePi(input + 1 , length);
        }
    
    }
    
    void removeX(char input[]) {
        // Write your code here
            int length = strlen(input);
        removePi(input, length);
    }
    
    
    int main() {
        char input[100];
        cin.getline(input, 100);
        removeX(input);
        cout << input << endl;
    }

## SOLUTION (CN APPROACH):

    /*
    Time Complexity : O(n^2)
    Space Complexity : O(n^2)
    where n is size of input array
    */
    int length(char input[])
    {
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
    len++;
    }
    return len;
    }
    void removeX(char input[], int start)
    {
    if (input[start] == '\0')
    {
    return;
    }
    removeX(input, start + 1);
    if (input[start] == 'x')
    {
    int len = length(input);
    int i;
    for (i = start + 1; i < len; i++)
    {
    input[i - 1] = input[i];
    }
    input[i - 1] = '\0';
    }
    }
    void removeX(char input[])
    {
    removeX(input, 0);
    }

