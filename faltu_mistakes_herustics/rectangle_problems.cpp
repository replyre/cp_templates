// HMM.. the problems of geometry are little tedious, esp. when you left maths book to the dust for 5+years or so.

// The best way to go about geometry problems is to have a little knowledge of their properties.

// for the rectange problems, firstly you have to find a recatange from points

// just remember 2 conditions for it:
//  no. of point pairs >=4 in the given array
//  if (x1,y1) and (x2,y2) are 2 points the the other points are (x2,y1) and(x1,y2) where (x1!=x2) and (y1!=y2) (⭐ keep this in mind)

// how to find that the 2 points exist there are 2 ways:
// loop and find the values while considering the first 2, TC: O(n^3),
// Use an set and search e.g. st.count({x2,y1}) for one point, TC:  O(n^2), SC:O(n)