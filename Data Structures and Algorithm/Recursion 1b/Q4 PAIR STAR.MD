# Pair Star


#### Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

##### Input format :

```
String S

```

##### Output format :

```
Modified string

```

##### Constraints :

```
0 <= |S| <= 1000
where |S| represents length of string S.

```

##### Sample Input 1 :

```
hello

```

##### Sample Output 1:

```
hel*lo

```

##### Sample Input 2 :

```
aaaa

```

##### Sample Output 2 :

```
a*a*a*a
```

## SOLUTION:

    #include <iostream>
    using namespace std;
    
    // Change in the given string itself. So no need to return or print the changed string.
    #include<cstring>
    void addStar(char input[], int length){
        if(input[0] == '\0'){
            return;
        }
        if(input[0] == input[1]){
            for(int i = length+1; i>1; i--){
                input[i] = input[i-1];
            }
            input[1] = '*';
            return addStar(input+2, length-1);
        }else{
            return addStar(input+1, length-1);
        }
    }
    void pairStar(char input[]) {
        // Write your code here
        int length = strlen(input);
        addStar(input, length);
    }
    
    
    int main() {
       char input[100];
       cin.getline(input, 100);
       pairStar(input);
       cout << input << endl;
    }

## SOLUTION (CN APPROACH):

    /*
    Time Complexity : O(n)
    Space Complexity : O(n)
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
    void pairStar(char input[], int start)
    {
    if (input[start] == '\0')
    {
    return;
    }
    pairStar(input, start + 1);
    if (input[start] == input[start + 1])
    {
    int l = length(input);
    input[l + 1] = '\0';
    int i;
    for (i = l - 1; i >= start + 1; i--)
    {
    input[i + 1] = input[i];
    }
    input[i + 1] = '*';
    }
    }
    void pairStar(char input[])
    {
    pairStar(input, 0);
    }
