#include <stdio.h>
#include <stdlib.h>

void printSubsetSum(int i, int n, int set[], int targetSum, int subset[], int subsetSize) {
	if (targetSum == 0) {
    	printf("[ ");
    	for (int j = 0; j < subsetSize; j++) {
        	printf("%d ", subset[j]);
    	}
    	printf("]\n");
    	return;
	}

	if (i == n || targetSum < 0) {
    	return;
	}

	// Include current element in the subset
	subset[subsetSize] = set[i];
	printSubsetSum(i + 1, n, set, targetSum - set[i], subset, subsetSize + 1);

	// Exclude current element from the subset and move to the next
	while (i + 1 < n && set[i] == set[i + 1]) {
    	i++;  // Skip duplicate elements
	}
	printSubsetSum(i + 1, n, set, targetSum, subset, subsetSize);
}

int main() {
	int n;
	printf("Enter the size of the set: ");
	scanf("%d", &n);

	int set[n];
	printf("Enter %d elements of the set:\n", n);
	for (int i = 0; i < n; i++) {
    	scanf("%d", &set[i]);
	}

	int sum;
	printf("Enter the target sum: ");
	scanf("%d", &sum);

	printf("Subsets with sum %d are:\n", sum);
	int subset[n]; // Maximum size of subset is n
	printSubsetSum(0, n, set, sum, subset, 0);

	return 0;
}
