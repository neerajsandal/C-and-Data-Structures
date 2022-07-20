#include<iostream>
#include<vector>
using namespace std;
class priorityQueues{
    vector<int> pq;
    public : 

    priorityQueues(){

    }
    bool IsEmpty()
    {
        return pq.size() == 0;
    }
    int getMin()
    {
        return pq[0];
    }
    int getSize()
    {
        if(IsEmpty())
           return 0;
        return pq.size();
    }
    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = pq.size() - 1;
        int parentIndex = (childIndex - 1)/2;
        while(childIndex > 0)
        {
            parentIndex = (childIndex - 1)/2;
            if(pq[childIndex] < pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
        }
    }
    int remove()
    {
        if(IsEmpty())
           return 0;
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();
        
        int minIndex = 0;
        while(1){
            int parent = minIndex;
            int leftChild = (2*parent) + 1;
            int rightChild = (2*parent) + 2;

            if(leftChild >= pq.size())
               break;
            if(leftChild < pq.size() && pq[leftChild] < pq[parent])
            {
                minIndex = leftChild;
            }

            if(rightChild < pq.size() && pq[rightChild] < pq[minIndex])
            {
                 minIndex = rightChild; 
            }

            if(minIndex == parent)
            break;
            else{
                int temp = pq[minIndex];
                pq[minIndex] = pq[parent];
                pq[parent] = temp;
            }
        }
        return ans;
    }
};
int main() {
    priorityQueues pq;

    int choice;
    cin >> choice;
    while (choice != -1) {
        switch (choice) {
            case 1:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2:  // getMin
                cout << pq.getMin() << "\n";
                break;
            case 3:  // removeMax
                cout << pq.remove() << "\n";
                break;
            case 4:  // size
                cout << pq.getSize() << "\n";
                break;
            case 5:  // isEmpty
                cout << (pq.IsEmpty() ? "true\n" : "false\n");
            default:
                return 0;
        }
        cin >> choice;
    }
}
