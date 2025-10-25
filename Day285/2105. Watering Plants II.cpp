class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int refills = 0;
        int left = 0, right = n - 1;
        int currentA = capacityA, currentB = capacityB;
        
        while (left <= right) {
            if (left == right) {
                if (currentA >= currentB) {
                    if (currentA < plants[left]) {
                        refills++;
                    }
                } else {
                    if (currentB < plants[right]) {
                        refills++;
                    }
                }
                break;
            }
            
            if (currentA < plants[left]) {
                refills++;
                currentA = capacityA;
            }
            currentA -= plants[left];
            left++;
            
            if (currentB < plants[right]) {
                refills++;
                currentB = capacityB;
            }
            currentB -= plants[right];
            right--;
        }
        
        return refills;
    }
};