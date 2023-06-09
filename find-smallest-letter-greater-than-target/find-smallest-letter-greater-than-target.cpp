class Solution {
public:
    char binary(vector<char>& letters, char target,int s, int e)
    {
        if (s>e){return letters[0];}

        int mid = (s+e)/2;
        if (letters[mid] > target && letters[mid-1]<=target){return letters[mid];}
        else if (letters[mid] > target){return binary(letters,target,s,mid-1);}
        else{return binary(letters,target,mid+1,e);}
    }

    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        if (letters[0] > target || letters[n-1]<=target){return letters[0];}
        return binary(letters,target,0,n-1);
    }
};