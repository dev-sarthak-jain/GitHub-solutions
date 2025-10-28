class Bank {
public:

    vector<long long> bal;
    int n;

    Bank(vector<long long>& balance) {
        bal = balance;
        n = bal.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > n || account2 >n){return 0;}
        long long temp = bal[account1-1];
        if (temp < money){return 0;}
        else{
            bal[account2-1] += money;
            bal[account1-1] -= money;
            return 1;
        }
    }
    
    bool deposit(int account, long long money) {
        if (account > n){return 0;}
        bal[account-1] += money;
        return 1;
    }
    
    bool withdraw(int account, long long money) {
        if (account > n){return 0;}
        if (bal[account-1] >= money)
        {
            bal[account-1]-=money;
            return 1;
        }
        else{return 0;}
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */