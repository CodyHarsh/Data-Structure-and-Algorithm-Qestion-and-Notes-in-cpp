# Print Permutations


#### Given an input string (STR), print all possible permutations of the input string.

##### Note:

```
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.

```

##### Input Format:

```
The only input line contains a string (STR) of alphabets in lower case

```

##### Output Format:

```
Print each permutations in a new line

```

##### Note:

```
You do not need to print anything, it has already been taken care of. Just implement the function.  

```

##### Constraint:

```
1<=length of STR<=8
Time Limit: 1sec

```

#### Sample Input 1:

```
cba

```

#### Sample Output 1:

```
abc
acb
bac
bca
cab
cba
```

## SOLUTION:

    #include <iostream>
    #include <string>
    using namespace std;

    using namespace std;
    void perm(string input, string output){
        if(input.size() == 0){
            cout<<output<<endl;
            return;
        }
        for(int i = 0; i<input.size(); i++){
            string a = input.substr(0,i);
            string b = input.substr(i+1);
            string c = a +b;
            perm( c, output + input[i]);
        }
    }
    void printPermutations(string input){
    
        	/* Don't write main() function.
    	 * Don't read input, it is passed as function argument.
    	 * Print output as specified in the question
    	*/
        perm(input, "");
    }
    
    
    int main() {
        string input;
        cin >> input;
        printPermutations(input);
        return 0;
    }
