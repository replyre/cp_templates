
// search in rotated array (WIP)
// we need to find where answer lies sorted or unsorted part and manuevor it as per our requirement

// Type 1:  find min in array(with duplicates) (specific type)

// eg3: [13 3 5 7 9 11] okay, here we need to find the minimum which is 3, but mid gives 5, if we reduce left pointer, we will not get 3, so we reduce the right one
// eg4: [2 2 3 6 7 8 1 1 ], in this case, mid will be larger from both the ends, but with observation, if mid>left then left>right as well due to property of being rotated.

// so, we just need to check for right element here

// code:
int findMin(vector<int> &arr)
{
    int l = 0, h = arr.size() - 1;

    while (l < h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] > arr[h])
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    return arr[l];
}


// search in 2d sorted matrix
// the ros are multiple of (m-1) the size of row;
//the cols are modulo of m-1; as we keep moving over them;
//example: 
class Solution {
  public:
    // Function to search a given number in row-column sorted matrix.
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n= mat.size();
        int m= mat[0].size();
        int l=0;
        int h=n*m-1;
        while(l<=h){
            int mid=(l+h)/2;
            int r= mid/m, col=mid%m;
            if(mat[r][col]==x) return true;
            if(mat[r][col]< x) l=mid+1;
            else h=mid-1;
        }
        return false;
    }
};
