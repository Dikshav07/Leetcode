class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int pos = 0;
        int target_mask = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    pos = i * n + j;
                } else if (classroom[i][j] == 'L') {
                    classroom[i][j] = target_mask + '0';
                    ++target_mask;
                }
            }
        }
        
        if (target_mask == 0) return 0;

        int ttl = m * n + 1;
        
        target_mask = (1 << target_mask) - 1;
        memset(cache, -1, m * n * (target_mask + 1) * sizeof(int16_t));
        
        vector<int> q;
        
        int nmk = pos * (target_mask + 1);
        q.push_back(nmk * ttl + energy);
        cache[nmk] = energy;
        
        int moves = 0, stt = 0, edd = 1;
        
        while (stt < edd) {
            for (int k = stt; k < edd; ++k) {
                auto ss = q[k];
                int curr_energy = ss % ttl, mask = (ss / ttl) % (target_mask + 1);
                
                if (mask == target_mask) {
                    return moves;
                }

                int pos = (ss / ttl) / (target_mask + 1);

                int y = pos / n, x = pos % n;
                char tmp = classroom[y][x];
                
                if (curr_energy == 0 && tmp != 'R') {
                    continue;
                }
                
                for (int i = 0; i < 4; ++i) {
                    int ny = y + dirs[i];
                    int nx = x + dirs[i + 1];
                    
                    if (ny < 0 || ny >= m || nx < 0 || nx >= n || classroom[ny][nx] == 'X') {
                        continue;
                    }

                    tmp = classroom[ny][nx];
                    
                    int next_energy = (tmp == 'R') ? energy: curr_energy - 1;
                    if (next_energy < 0) continue; 
                    
                    int next_mask = mask;
                    if (isdigit(tmp)) {
                        next_mask |= (1 << (tmp - '0'));
                    }
                    
                    nmk = (ny * n + nx) * (target_mask + 1) + next_mask;
                    if (cache[nmk] < next_energy) {
                        
                        q.push_back(nmk * ttl + next_energy);
                        cache[nmk] = next_energy;
                    }
                }
            }
            moves++;
            stt = edd;
            edd = q.size();
        }
        
        return -1; 
    }
private:
    inline static int16_t cache[20 * 20 * 1024];
    inline static constexpr int dirs[5] = {0, 1, 0, -1, 0};
};