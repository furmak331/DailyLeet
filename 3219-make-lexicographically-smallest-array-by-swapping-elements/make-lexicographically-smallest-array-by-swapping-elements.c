/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// cmp function to sort copy of original array
int cmp(const void *a, const void *b){
    int *arr1 = (int *)a;
    int *arr2 = (int *)b;
    return (arr1[0] - arr2[0]);
}

// cmp function to sort indices of the cpy array
int cmp2(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}

int* lexicographicallySmallestArray(int* nums, int numsSize, int limit, int* returnSize) {
    int *ret = (int *)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    int cpy[numsSize][2]; // cpy[i][0] is the value, cpy[i][1] is its original pos/index in the array

    // ex: {1, 7, 6, 18, 2, 1} -> {{1,0},{7,1},{6,2},{18,3},{2,4},{1,5}}
    for (int i = 0; i < numsSize; i++){
        cpy[i][0] = nums[i];
        cpy[i][1] = i;
    }

    qsort(cpy, numsSize, sizeof(cpy[0]), cmp); // sort cpy by its values
    // following the example above
    // {{1,0},{7,1},{6,2},{18,3},{2,4},{1,5}} ->
    // {{1,0},{1,5},{2,4},{6,2},{7,1},{18,3}}

    int indices[numsSize]; // array to store the indices of the original values
    for (int i = 0; i < numsSize;){
        int size = 0;         // size of the current group
        int prev = cpy[i][0]; // track the value of the last value in the group
        // loop through cpy until the next value is too high to be apart of the same group
        // ex: limit = 3 cpy[i][1] = {1, 1, 2, 6, 7, 18}; first loop here it would stop at i = 3 because (6 - 3) > 2;
        while(i < numsSize && cpy[i][0] <= (prev + limit)){
            indices[size++] = cpy[i][1];
            prev = cpy[i][0];
            i++;
        }
        // ex: indices = {0,5,4}
        // sort the indices of values in the same group
        qsort(indices, size, sizeof(int), cmp2);
        // indices: {0,4,5}
        // assign values of cpy in accordance to the sorted indices array
        // k - i is to start at the last index copied from the cpy array
        for (int j = 0, k = i - size; j < size; j++, k++){
            ret[indices[j]] = cpy[k][0];
            // ret[0] = 1
            // ret[4] = 1
            // ret[5] = 2
            // ret = {1, ?, ?, ?, 1, 2};
        }
    }

    return ret;
}