class Solution
{
    public:
       	//Logics

       	//Naive Solution
       	//1. Maanlo 1,2,3,4 diya hain to ek tareeka to apna tha ki saare permutations nikal lenge like (Permutations 2) then we will find the K the one.
       	//2. But it is very naive solution so we will look for some optimal solution.

       	//Optimal Solution
       	//1. Agar ham dhyan se dekhe to hame ek pattern dikhayi dega.
       	//2. For some range in permuations the position of the numbers are fixed.
       	//3. So with this pattern we can start from the first index all the way to last index.
       	//4. Kth sequence pe pata lagayenge ki 1st index pe kya tha, Fir wo num ab use ho gaya to aage use nahin hoga to use erase kar diya.
       	//5. Yeh saari ranges ke ham blockSize banayenge aur un blockSize mein k ki subpositioning hoti rahegi.
       	//6. Jab tak K=0 nahin ho jata tab tak yeh sub positioning chalti rahegi.
        //7. blockSize = (n-1)!
       	//8. Num ki position for some index numbers[k/blockSize] and k = k%blockSize(subpositioning in the bloc), fir num jo use ho gaya use remove karenge to blockSize =(num-2)! use karenge aage.
       	//blockSize bhi change hoga as the numbers are being removed.
       	//9.Isi process se ham all the 4 indexes bhar lenge.

       	//EXAMPLE: 1,2,3,4, k=17
        string getPermutation(int n, int k)
        {
            string ans = "";
            vector<int> numbers;
           	//1-n tak saare numbers store karlenge
            int fact = 1;
           	//This is the factorial
            for (int i = 1; i <= n; i++)
            {
                fact = fact * i;	//4!=24
                numbers.push_back(i);
            }
           	//Now the value of fact is the number of permutations or total ranges.
           	//Now these ranges can be divided in blocks of blockSizes
            int blockSize = fact / n;	//blockSize = 24/4 = 6 size ke 4 blocks
            k = k - 1;	//For 0 based indexing//16
            while (true)
            {
                ans += to_string(numbers[k / blockSize]);	
                //3,_,_,_
                //3,4,_,_
                //3,4,1,_
                //3,4,1,2
               	//Index by index answers mein push karenge
                numbers.erase(numbers.begin() + k / blockSize);
               	//Jo index use ho gayi use remove kar denge
                if (numbers.size() == 0)
               	//Agar koi index use karne ko hain hi nahin
                {
                    break;
                }
                k = k % blockSize;	//16->4->0
               	//K is repositioned for remaining numbers 
                blockSize = blockSize / numbers.size();	//6->2->1
               	//Blocks are also changed according to remaining numbers
            }
            return ans;
        }
};
