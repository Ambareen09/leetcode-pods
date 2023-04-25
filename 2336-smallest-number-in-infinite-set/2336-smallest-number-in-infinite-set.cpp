class SmallestInfiniteSet {
    unordered_set<int> isPresent;
    priority_queue<int, vector<int>, greater<int>> addedIntegers;
    int currentInteger;

public:
    SmallestInfiniteSet() {
        currentInteger = 1;
    }

    int popSmallest() {
        int answer;
        if (!addedIntegers.empty()) {
            answer = addedIntegers.top();
            isPresent.erase(answer);
            addedIntegers.pop();
        } 

        else {
            answer = currentInteger;
            currentInteger += 1;
        }
        return answer;
    }

    void addBack(int num) {
        if (currentInteger <= num || isPresent.find(num) != isPresent.end()) {
            return;
        }
        addedIntegers.push(num);
        isPresent.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */