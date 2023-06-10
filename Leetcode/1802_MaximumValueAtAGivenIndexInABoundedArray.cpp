class Solution {
public:
    long long helper(long long mid, int index, int n){
        long long leftOffset = std::max(mid - static_cast<long long>(index), 0LL);
        long long result = (mid + leftOffset) * (mid - leftOffset + 1)/2;
        long long rightOffset = std::max(mid - static_cast<long long>((n-1) - index), 0LL);

        result += (mid + rightOffset) * (mid - rightOffset + 1)/2;
        return result - mid;
    }

    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        int low = 0, high = maxSum;

        while(low < high){
            int mid = (low + high + 1)/2;
            if(helper(mid, index, n) <= maxSum){
                low = mid;
            }
            else{
                high = mid-1;
            }
        }
        return low+1;
    }
};
