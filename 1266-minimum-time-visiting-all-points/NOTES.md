Here moving diagonally is same as moving one unit horizantally and one unit vertically
and distance between two points can be considered as the difference between their X coordinated and difference between their Y coordinates.
Since here we can move diagonally we need to move cover only that difference which is more in cost
​
max(x2-x1, y2-y1)
​
if y2-y1 is greater than x2-x1
we move diagonally till the point x1=x2 and after that cover the difference vertically.
Similary we can visualize when the reverse is true.