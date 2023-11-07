#include <iostream>
#include <vector>
/* time complexity for variouus operations to get the max element
            array     sorted array     bst     heap
insert      O(1)        O(N)            O(H)    O(LogN)
pop         O(N)        O(1)            O(H)    O(LogN)
get         O(N)        O(1)            O(H)    O(1)
*/
using namespace std;
class heap{
    vector <int> v;
    bool minheap;
    bool compare(int a,int b){
       if(minheap){
           return a<b;
       } 
       else{
           return a>b;
       }
    }
    //heapify works from top to down
    void heapify(int idx){
        int left=2*idx;
        int right=left+1;
        int min=idx;
        int last=v.size()-1;
        if(left<=last and compare(v[left],v[idx])){
            min=left;
        }
        if(right<=last and compare(v[right],v[min])){
            min=right;
        }
        if(min!=idx){
            swap(v[idx],v[min]);
            heapify(min);
        }
    }
    void heapifyvector(vector<int>&v,int idx){
        int left=2*idx;
        int right=left+1;
        int min=idx;
        int last=v.size()-1;
        if(left<=last and compare(v[left],v[idx])){
            min=left;
        }
        if(right<=last and compare(v[right],v[min])){
            min=right;
        }
        if(min!=idx){
            swap(v[idx],v[min]);
            heapifyvector(v,min);
        }
    }
    public:
    heap(int defaultsize=10,bool type=true){
        v.reserve(defaultsize);
        v.push_back(-1);
        minheap=type;
    }
    //to satisfy the complete binary tree property the index half of any index will be its parent node
    void push(int d){
        v.push_back(d);
        int i=v.size()-1;
        int parent=i/2;
        while(i>1 and compare(v[i],v[parent])){
            swap(v[i],v[parent]);
            i=parent;
            parent=parent/2;
        }
    }
    int top(){
        return v[1];
    }
    void pop(){
        int last=v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapify(1); //it converts the heap into a min max heap again
    }
    //to build heap inside a given vector in O(NLogN) time complexity 
    void buildheap(vector<int> &v){
        for(int i=2;i<v.size();i++){
            int idx=i;
            int parent=i/2;
            //if a given value is less than the parent value then shift it upwards
            while(idx>1 and compare(v[idx],v[parent])){
                swap(v[idx],v[parent]);
                idx=parent;
                parent=parent/2;
            }
        }
    }
    //the optimised approach works top to bottom and the last row of nodes arent considered since they cannot work top to bottom
    void buildheapoptimised(vector<int> &v){
        for(int i=(v.size()-1/2);i>=1;i--){
            heapifyvector(v,i);
        }
    }
};
int main()
{
    

    return 0;
}
