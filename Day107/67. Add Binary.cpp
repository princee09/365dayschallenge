class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        
        while (i >= 0 || j >= 0 || carry > 0) {
            int bit_a = (i >= 0) ? a[i--] - '0' : 0;
            int bit_b = (j >= 0) ? b[j--] - '0' : 0;
            int sum = bit_a + bit_b + carry;
            result.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};