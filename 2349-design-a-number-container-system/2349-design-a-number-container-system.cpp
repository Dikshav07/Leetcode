class NumberContainers {
public:
    unordered_map<int,int> idxToNum;
    unordered_map<int, priority_queue<int, vector<int>, greater<>>> numToIndices;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        idxToNum[index] = number;
        numToIndices[number].push(index);
    }
    
    int find(int number) {
        if(!numToIndices.count(number))
        return -1;

        auto& pq = numToIndices[number];

        while(!pq.empty() && idxToNum[pq.top()] != number)
        {
            pq.pop();
        }

        return (!pq.empty()) ? pq.top() : -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */