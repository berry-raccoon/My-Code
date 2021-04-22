/*
 * @Description: 
 * @Author: Cai Minya
 * @Date: 2021-04-22 10:47:14
 * @LastEditTime: 2021-04-22 12:11:50
 * @LastEditors: Cai Minya
 */
#include <iostream>
#include <vector>
using namespace std;

class SortableArray {
public:
    int partition(vector<int>& array, int left_pointer, int right_pointer);
    void quick_sort(vector<int>& array, int left_pointer, int right_pointer);
};

int main() {
    SortableArray s;
    vector<int> array = {0, 5, 2, 1, 6, 3};
    s.quick_sort(array, 0 , array.size()-1);
    for(vector<int>::iterator it = array.begin(); it != array.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;
}
int SortableArray::partition(vector<int>& array, int left_pointer, int right_pointer) {
    /* 左指针指向矩阵第一个元素，右指针指向元素倒数第二元素 */
    
    /* 基准值始终选择最右端的值 */
    int pivot_position;
    int pivot_pointer = right_pointer;
    pivot_position = array[right_pointer];
    right_pointer -= 1;
    while(true) {
        /* 左指针向右移 */
        while(array[left_pointer] < pivot_position)
            left_pointer++;

        /* 右指针向左移 */
        while(array[right_pointer] > pivot_position)
            right_pointer--; 

        /* 若左指针大于等于右指针，表示交换完毕，否则交换元素的值 */
        if(left_pointer >= right_pointer){
            int temp = pivot_position;
            array[pivot_pointer] = array[left_pointer];
            array[left_pointer] = temp;
            break;
        }
        else {
            int temp = array[right_pointer];
            array[right_pointer] = array[left_pointer];
            array[left_pointer] = temp;
        }
    
    }
    return left_pointer;

}
/**
 * @description: 对left_pointer与right_pointer+1范围内的矩阵进行快速排序
 * @return {*}
 * @param {vector<int>&} 要排序的矩阵
 * @param {int} left_pointer 这个矩阵的左指针，一般传 0
 * @param {int} right_pointer 这个矩阵的右指针，一般传 size - 1
 */
void SortableArray::quick_sort(vector<int>& array, int left_index, int right_index) {
    /* 基准条件为数组一侧只有一个元素未排序 */
    if(right_index - left_index <= 0) {
        return;
    }
    int pivot_position;
    /* 将数组分区，返回轴所在的索引 */
    pivot_position = partition(array, left_index, right_index);
    
    /* 对右侧进行递归排序 */
    quick_sort(array, left_index, pivot_position - 1);
    /* 对轴左侧进行递归排序 */
    quick_sort(array, pivot_position + 1, right_index);
}