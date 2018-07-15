#include<bits/stdc++.h>
using namespace std;

class Solution
{
private:
public:
    Solution();
    void sortingAlgo(vector<int> &A);
    void mergeSort(vector<int> &A, int low, int high);
    void merge(vector<int> &A, int low, int mid, int high);
};
Solution::Solution(){}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void Solution::merge(vector<int> &A, int low, int mid, int high)
{
    int len1 = mid-low+1;
    int len2 = high-mid;
    int *l = (int *)malloc(sizeof(int ) * len1);
    for(int iter = 0; iter < len1; iter++)
    {
        l[iter] = A[low+iter];
    }
    int *r = (int *)malloc(sizeof(int ) * len2);
    for(int iter = 0; iter < len2; iter++)
    {
        r[iter] = A[mid+iter+1];
    }
    int iter = 0;
    int jter = 0;
    int kter = low;
    while(iter < len1 && jter < len2)
    {
        if(l[iter] <= r[jter])
        {
            A[kter] = l[iter];
            iter++;
        }
        else
        {
            A[kter] = r[jter];
            jter++;
        }
        kter++;
    }
    while(iter < len1)
    {
        A[kter] = l[iter];
        iter++;
        kter++;
    }
    while(jter < len2)
    {
        A[kter] = r[jter];
        jter++;
        kter++;
    }
    free(l);
    free(r);
    return;
}
void Solution::mergeSort(vector<int> &A, int low, int high)
{
    if(low < high)
    {
        int mid = low + (high-low)/2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A,low, mid, high);
    }
}
void Solution::sortingAlgo(vector<int> &A)
{
     int low = 0;
     int high = A.size()-1;
     mergeSort(A, low, high);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    int testCase;
    cin >> testCase;
    while(testCase--)
    {
        int n;
        cin >> n;
        vector<int> V;
        for(int iter = 0; iter < n; iter++)
        {
            int data;
            cin >> data;
            V.push_back(data);
        }
        sol.sortingAlgo(V);
        for(int iter = 0; iter < V.size(); iter++)
        {
            cout << V[iter] << " ";
        }
        cout << endl;
    }
    return 0;
}
