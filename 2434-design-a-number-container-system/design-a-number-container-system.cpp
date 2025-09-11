class NumberContainers {

private:

    map<int, int> hash;
    map<int, priority_queue<int,vector<int>,greater<int>>> hashmp;
public:

    NumberContainers() {

    }
    
    void change(int index, int number) {
        if(hash[index] == number) return ;

        hash[index] = number;
        hashmp[number].push(index);
    }
    
    int find(int number) {
        int ans, index;

        ans = INT_MAX;

        while(!hashmp[number].empty()) {
            index = hashmp[number].top();
            if(hash[index] != number) hashmp[number].pop();
            else {
                ans = index;
                break ;
            }
        }

        return (ans != INT_MAX)? ans: -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */