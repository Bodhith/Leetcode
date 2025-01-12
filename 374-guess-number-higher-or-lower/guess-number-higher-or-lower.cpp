/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low, mid, high, hl;
        low = 0;
        high = n-1;

        while(true) {
            mid = low+(high-low)/2;
            hl = guess(mid);
            if(!hl)  return mid;
            else if(hl == -1)   high = mid-1;
            else    low = mid + 1;
        }

        return -1;
    }
};