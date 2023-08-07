class Solution {
public:
    int n;
    int m;
    bool binary(vector<vector<int>>& matrix, int target,int x,int y)
    {
        if (x>y){return 0;}
        int mid = (x+y)/2;
        int a = mid/m;
        int b = mid%m;
        if (matrix[a][b] == target){return 1;}
        else if (matrix[a][b] < target){return binary(matrix,target,mid+1,y);}
        else{return binary(matrix,target,x,mid-1);}
        return 0;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        n = matrix.size();
        m = matrix[0].size();
        return binary(matrix,target,0,(m*n)-1);
    }
};