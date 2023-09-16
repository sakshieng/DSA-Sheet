#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-median-from-data-stream/

class MedianFinder {
private:
    void insertMin(int val){
        minHeap.push(-val);
    }
    void insertMax(int val){
        maxHeap.push(val);
    }
    int getMinTop(){
        return -minHeap.top();
    }
    int getMaxTop(){
        return maxHeap.top();
    }
public:
//tc O(logn) sc O(1)
priority_queue<int>maxHeap;
priority_queue<int>minHeap;
int n;
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if(n%2 == 0){
            if(n == 0){
                insertMax(num);
            }else{
                int topMin = getMinTop();
                if(num >= topMin){
                    insertMax(topMin);
                    minHeap.pop();
                    insertMin(num);
                }else{
                    insertMax(num);
                }
            }
        }else{
            int topMax = getMaxTop();
            if(topMax < num){
                insertMin(num);
            }else{
                maxHeap.pop();
                insertMax(num);
                insertMin(topMax);
            }
        }
        n++;
    }
    
    double findMedian() {
//if odd numbers are there max heap should have 1no extra 
        if(n%2 == 1) return maxHeap.top();
        return (double)(getMaxTop()+getMinTop())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */class MedianFinder {
private:
    void insertMin(int val){
        minHeap.push(-val);
    }
    void insertMax(int val){
        maxHeap.push(val);
    }
    int getMinTop(){
        return -minHeap.top();
    }
    int getMaxTop(){
        return maxHeap.top();
    }
public:
//tc O(logn) sc O(1)
priority_queue<int>maxHeap;
priority_queue<int>minHeap;
int n;
    MedianFinder() {
        n = 0;
    }
    
    void addNum(int num) {
        if(n%2 == 0){
            if(n == 0){
                insertMax(num);
            }else{
                int topMin = getMinTop();
                if(num >= topMin){
                    insertMax(topMin);
                    minHeap.pop();
                    insertMin(num);
                }else{
                    insertMax(num);
                }
            }
        }else{
            int topMax = getMaxTop();
            if(topMax < num){
                insertMin(num);
            }else{
                maxHeap.pop();
                insertMax(num);
                insertMin(topMax);
            }
        }
        n++;
    }
    
    double findMedian() {
//if odd numbers are there max heap should have 1no extra 
        if(n%2 == 1) return maxHeap.top();
        return (double)(getMaxTop()+getMinTop())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */