class Solution {
public:
    bool canAliceWin(int n) {
        int s = 10; 
        bool isAlice = true; 
        while (n > 0) {
            if (n < s) {
                return !isAlice; 
            }
            n -= s;  
            s--;     
            isAlice = !isAlice; 
        }
        
        return !isAlice;
    }
};