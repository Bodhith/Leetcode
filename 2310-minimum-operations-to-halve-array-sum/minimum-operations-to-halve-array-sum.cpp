class MaxHeap {
    public:
    vector<double> a;

    MaxHeap() {
        this->a.push_back(INT_MAX * 1.0);
    }

    MaxHeap(vector<int> &a) {
        for(int val: a) this->a.push_back(val * 1.0);
        this->a.insert(this->a.begin(), INT_MAX * 1.0);
    }

    bool hasLeftChild(int pos) {
        int index;
        index = 2 * pos;
        return index < a.size();
    }

    bool hasRightChild(int pos) {
        int index;
        index = 2 * pos + 1;
        return index < a.size();
    }

    void swap(int x, int y) {
        double t;
        t = a[x];
        a[x] = a[y];
        a[y] = t;
    }

    void show() {
        cout << '\n';
        for(double var: a) cout << var << ' ';
        cout << '\n';
    }

    float top() {
        return a[1];
    }

    void add(double val) {
        int i;

        a.push_back(val);
        i = a.size() - 1;
        
        while (i > 1 && a[i/2] < a[i]) {
            swap(i, i/2);
            i /= 2;
        }
    }

    void remove(int pos) {
        swap(pos, a.size()-1);
        a.pop_back();
        heapifySubTree(pos);
    }

    void heapifySubTree(int pos) {
        if (!hasLeftChild(pos) and !hasRightChild(pos)) return ;
        
        int leftChildIndex, rightChildIndex;

        leftChildIndex = 2 * pos;
        rightChildIndex = 2 * pos + 1;
        
        double left, right, root;

        left = (hasLeftChild(pos))? a[leftChildIndex] : INT_MIN;
        right = (hasRightChild(pos))? a[rightChildIndex] : INT_MIN;
        root = a[pos];

        if (right > root and right >= left) {
            swap(rightChildIndex, pos);
            heapifySubTree(rightChildIndex);
        }

        if (left > root and left >= right) {
            swap(leftChildIndex, pos);
            heapifySubTree(leftChildIndex);
        }
    }

    void heapify(int pos) {
        if (!hasLeftChild(pos) and !hasRightChild(pos)) return ;
        
        int leftChildIndex, rightChildIndex;

        leftChildIndex = 2 * pos;
        rightChildIndex = 2 * pos + 1;

        heapify(leftChildIndex);
        heapify(rightChildIndex);

        double left, right, root;

        left = (hasLeftChild(pos))? a[leftChildIndex] : INT_MIN;
        right = (hasRightChild(pos))? a[rightChildIndex] : INT_MIN;
        root = a[pos];

        if (right > root and right >= left) {
            swap(rightChildIndex, pos);
            heapifySubTree(rightChildIndex);
        }

        if (left > root and left >= right) {
            swap(leftChildIndex, pos);
            heapifySubTree(leftChildIndex);
        }
    }
};


class Solution {
public:

    double initialSum(vector<int> &a) {
        double ans;
        
        ans = 0;
        
        for(double val: a) ans += val;
        
        return ans;
    }

    int arrayHalfer(vector<int> &a) {
        int ans;
        double sum, totalSum, temp;

        totalSum = initialSum(a);

        MaxHeap *heap = new MaxHeap(a);

        heap->heapify(1);

        ans = 0;
        sum = 0;

        while(sum < (totalSum/(double)2.0)) {
            temp = heap->top();

            sum += temp / 2;

            heap->remove(1);
            heap->add(temp/2);

            ans += 1;
        }

        return ans;
    }

    int halveArray(vector<int>& nums) {
        int ans;

        ans = arrayHalfer(nums);

        return ans;
    }
};