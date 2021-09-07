**Staircase**



#### A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.

##### Input format :

```
Integer N

```

##### Output Format :

```
Integer W

```

##### Constraints :

```
1 <= N <= 30

```

##### Sample Input 1 :

```
4

```

##### Sample Output 1 :

```
7

```

##### Sample Input 2 :

```
5

```

##### Sample Output 2 :

```
13
```

**HERE IS THE SOLUTION:**

      #include <iostream>
    using namespace std;
    int ans(int n){
        if(n==1||n==0)
        	return 1;
    	else if(n==2)
        	return 2;
     	return ans(n-3)+ans(n-2)+ans(n-1);
     
    }
    int staircase(int n){
        /* Don't write main().
         *  Don't read input, it is passed as function argument.
         *  Return output and don't print it.
         *  Taking input and printing output is handled automatically.
         */
        if(n == 0 ){
            return 1;
        }
       return ans(n);
    }
    
    int main() {
        int n, output;
        cin >> n;
        output=staircase(n);
        cout<< output <<endl;
    }



