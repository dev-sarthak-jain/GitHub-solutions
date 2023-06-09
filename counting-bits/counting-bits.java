class Solution {
    public int[] countBits(int n) {
        int[] arr = new int[n+1];
        arr[0] = 0;
        for(int i = 1; i <= n; i++){
            arr[i] = count(i);
        }
        return arr;
    }
    public static int count(int n){
        int counter = 0;
        while(n != 0){
            int rsbm = n & -n;
            n -= rsbm;
            counter++;
        }
        return counter;
    }
}