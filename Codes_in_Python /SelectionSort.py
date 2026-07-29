def SelectionSort(arr):
    n = len(arr)
    for i in range(n):
        min_indx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_indx]:
                min_indx = j
        arr[i], arr[min_indx] = arr[min_indx], arr[i]

arr = list(map(int, input("Enter the array elements : ").split()))
SelectionSort(arr)
print("Sorted Elements :", arr)

