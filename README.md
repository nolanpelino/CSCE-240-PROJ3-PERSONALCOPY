# Project 3 CSCE 240 Fall 2021
  
## ArrayList member variables
- `T *data`: a dynamic pointer array that holds each element of type T in the ArrayList
- `int size`: the size of the `data` array

## ArrayList Methods
- `bool operator!=(const ArrayList<T> &) const`
  - Checks to see if the calling object and the passed object are different
  - Returns true if they are different (either different sizes or if content differs
  - Returns false if sizes are the same and all content are the same. 
- `ArrayList<T> operator+(T) const`                     
  - Creates and returns an object that has a `data` array that is the calling object's data + the value of the passed arugement.
  - Example: 
```
ArrayList<int> a(2,1); // [1, 1] 
ArrayList<int> c; 
c = a + 1; // c == [2, 2] 
```
- `ArrayList<T> operator+(const ArrayList<T> &) const`
  - Pairwise addition (should only work if the sizes are the same)
  - Creates and returns an object that has a `data` array that is the calling object's data + the value of the passed arugement's data array.
  - Example: 
```
ArrayList<int> a(2,1); // [1, 1] 
ArrayList<int> b(2,2); // [2, 2]
ArrayList<int> c; 
c = a + b; // c == [3, 3] 
```
- `ArrayList<T> & operator--()`                      
  - Pre 
  - We are going to be inventive here! The `operator--` in this case will mean removal of the last element of the `data` array. 
  - If the `data` array is empty then it should just return an empty object and make no changes to itself
  - Example: 
```
ArrayList<int> a(2,1), b;  // a == [1,1]
a[1] = 2;             // a == [1,2]
b = --a;        
b.print();            // b == [1]
a.print();            // a == [1]
```
- `ArrayList<T> operator--(int)`                        
  - Post
  - Same as the `operator--` description as above, this time just as the post instead of the pre. 
  - If the `data` array is empty then it returns an empty object and make no changes to itself
  - Example: 
```
ArrayList<int> a(2,1), b;  // a == [1,1]
a[1] = 2;             // a == [1,2]
b = a--;        
b.print();            // b == [1,2]
a.print();            // a == [1]
```
- `void operator+=(T)`                                  
  - Appends an element on to the end of the `data` array.
  - Example: 
```
ArrayList<int> a(2,1);  // a == [1,1]
a += 2;                 // a == [1,1,2]
```
- `void operator+=(const ArrayList<T> &)`                     
  - Appends the values of the ArrayList passed to the end of the calling object object's data. 
  - Example: 
```
ArrayList<int> a(2,1), b(2,2);  // a == [1,1] b == [2,2]
a += b;                         // a == [1,1,2,2]
```
- `ArrayList<T> operator*(int) const`                     
  - The `*` operator takes in an `int` and returns an object that has the calling object's `data` array duplicated that many times
  - Example: 
```
ArrayList<int> a(2,1), c;     // a == [1,1]
c = a*2;                      // c == [1,1,1,1]
```
- `ArrayList<T> operator/(int) const`                
  - Takes in an `int` and return an object that has the corresponding fraction (dictated by the `int` passed in) of the calling object's `data` array. 
  - If the size is not divisible by the `int` passed in, then it truncates the new size (5/2 == 2). 
  - Example: 
```
ArrayList<int> a(5,1), c;     // a == [1,1,1,1,1]
c = a/2;                      // c == [1,1] (the first 2 elements of a)
```
