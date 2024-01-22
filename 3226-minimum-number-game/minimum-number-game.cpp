class Solution {
public:
    class MinIntHeap {
    public:
        int MAX_INT = 9999;
        int heap_size = 0;
        vector<int> heap;

        void setHeapSize(int size) {
            heap.resize(size);
            heap_size = size;
        }

        int getLeftChildIndex(int parentIndex) { return 2 * parentIndex; }
        int getRightChildIndex(int parentIndex) { return 2 * parentIndex + 1; }
        int getParentIndex(int childIndex) { return childIndex / 2; }

        int getLeftChild(int parentIndex) {
            return heap[getLeftChildIndex(parentIndex)];
        }
        int getRightChild(int parentIndex) {
            return heap[getRightChildIndex(parentIndex)];
        }
        int getParent(int childIndex) {
            return heap[getParentIndex(childIndex)];
        }

        int getLeftChildOrMax(int parentIndex) {
            return (hasLeftChild(parentIndex)
                        ? heap[getLeftChildIndex(parentIndex)]
                        : MAX_INT);
        }
        int getRightChildOrMax(int parentIndex) {
            return (hasRightChild(parentIndex)
                        ? heap[getRightChildIndex(parentIndex)]
                        : MAX_INT);
        }

        bool hasLeftChild(int index) {
            return getLeftChildIndex(index) <= heap_size;
        }
        bool hasRightChild(int index) {
            return getRightChildIndex(index) <= heap_size;
        }

        void create_root(int data) {
            setHeapSize(2);
            heap_size = 1;
            heap[0] = -1;
            heap[1] = data;
        }

        void swapElements(int index_1, int index_2) {
            int temp;
            temp = heap[index_1];
            heap[index_1] = heap[index_2];
            heap[index_2] = temp;
        }

        void printHeap() {
            for (int val : heap) {
                cout << val << ' ';
            }
            cout << '\n';
        }

        bool hasViolatedMinHeap(int index) {
            return (hasLeftChild(index) and
                    heap[index] > getLeftChild(index)) or
                   (hasRightChild(index) and
                    heap[index] > getRightChild(index));
        }

        void min_heapify(int index = 1) {
            if (index == 0 or (!hasLeftChild(index) && !hasRightChild(index))) {
                return;
            }

            min_heapify(getLeftChildIndex(index));
            min_heapify(getRightChildIndex(index));

            if (hasViolatedMinHeap(index)) {
                int leftChild = getLeftChildOrMax(index);
                int rightChild = getRightChildOrMax(index);

                if (leftChild < heap[index] and leftChild < rightChild) {
                    swapElements(index, getLeftChildIndex(index));
                } else {
                    swapElements(index, getRightChildIndex(index));
                }
            }
        }

        void addToHeap(int data) {
            heap.push_back(data);
            heap_size++;
            min_heapify();
            // cout << data << '\n';
            // printHeap();
        }

        int getMin() {
            if (heap_size <= 0) {
                return -1;
            }
            return heap[1];
        }

        void removeRoot() {
            if (heap_size <= 0) {
                return;
            }
            heap.erase(heap.begin() + 1);
            heap_size--;
            min_heapify();
        }
    };

    vector<int> numberGame(vector<int>& nums) {
        int i, n, A, B;
        vector<int> ans;
        MinIntHeap heap;

        heap.create_root(nums[0]);

        for (i = 1, n = nums.size(); i < n; i++) {
            heap.addToHeap(nums[i]);
        }

        // heap.printHeap();

        while (heap.heap_size >= 2) {
            A = heap.getMin();
            heap.removeRoot();
            B = heap.getMin();
            heap.removeRoot();

            ans.push_back(B);
            ans.push_back(A);
        }

        return ans;
    }
};