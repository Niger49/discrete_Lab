#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]); //int tmp
}

// Merge two subarrays L and M into arr
void merge_array(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int l, int r)
{
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    merge_sort(arr, l, m);
    merge_sort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge_array(arr, l, m, r);
  }
}

void sort_time() {

    int random_size;
    cout << "Enter random size value : ";
    cin >> random_size;

    srand(time(NULL)); //random number starting point
    ofstream out("out.txt");
    for(int i = 0; i < random_size; i++)
    {
        out << rand() << endl;
    }
    out.close();

    //read numbers from file and store in array
    ifstream read_in("out.txt");
    int a[random_size];
    for(int i = 0; i < random_size; i++)
    {
        read_in >> a[i];
    }
    read_in.close();

    clock_t start_time1;
    start_time1 = clock();

    bubble_sort(a,random_size);
    clock_t end_time1 = clock() - start_time1;
    cout << "Time took for " << random_size << " random number in bubble sorting is : " << (float)end_time1 / CLOCKS_PER_SEC << " s\n";
    cout << "Time took for " << random_size << " random number in bubble sorting is : " << (float)end_time1 / (1000*CLOCKS_PER_SEC) << " ms\n";
    cout << endl;

    clock_t start_time2;
    start_time2 = clock();

    merge_sort(a,0,random_size-1);
    clock_t end_time2 = clock() - start_time2;
    cout << "Time took for " << random_size << " random number in merge sorting is : " << (float)end_time2 / CLOCKS_PER_SEC << " s\n";
    cout << "Time took for " << random_size << " random number in merge sorting is : " << (float)end_time2  / (1000000000*CLOCKS_PER_SEC) << " ns\n";
    cout << endl;
}

int main()
{
    cout << "How many comparison ? ";
    int n;
    cin >> n;
    while (n--) {
        sort_time();
    }
}
