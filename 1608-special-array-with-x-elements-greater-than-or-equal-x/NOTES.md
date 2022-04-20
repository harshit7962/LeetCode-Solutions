This is  called the Bucket Solution...
Here we are creating a bucket of size 1001 (since nums[i]<=1000)
We are storing the count of each element in that vector/bucket
Next we are iterating  through that bucket and see if for any instance the number of elements in the bucket is equal to the current index... if so, we return that index... else we subtract the number of elements by the number of elements in the current index.