// I often do mistake in -ve modulo traversal in circular array.
// this is just a code to get a hint for that rather than wasting time in hit and try.

// the trick is -ve number are needed to be dealt backwards only if they are bigger than i of loop.
//  temp = (nums[i] + i) % n; this condition sees the value lies in -(n-1)<temp<(n-1)
// if positive you move that many places right from i and modules  handeles rest
// but if -ve even after getting reduced by i, we just reduce it from n
// the thing gets me confused is how n+temp(temp<0) handles the situaution

// but actually its very simple lets take a example
// statement we need to get the ith index value in new array with i+nums[i] of given one,  if -ve move left, +ve move right
// example1:  [-1,-1,4]
//  for i=0, temp=-1 and ans will have value of n+temp=4-1=3(last value of nums) easy
// exampl21:  [3,-2,1,1]
// for this example for i=1 we will have temp=-1 but i have to move 2 left time know, so how does this give correct ans?
// well , we are considering a place for pos 0 as well so we reduce 1 for that same is the case when we actually move left.

// vector<int> constructTransformedArray(vector<int> &nums)
// {
//     int n = nums.size();
//     vector<int> res(n, 0);
//     for (int i = 0; i < n; i++)
//     {
//         int temp = (nums[i] + i) % n;
//         if (temp < 0)
//         {

//             res[i] = nums[n + temp];
//         }
//         else
//             res[i] = nums[temp];
//     }
//     return res;
// }