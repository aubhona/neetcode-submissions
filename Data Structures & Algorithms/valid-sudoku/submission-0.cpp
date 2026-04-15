class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        const auto n = 9;
        const auto base = n / 3;

        uint16_t rows[n]{};
        uint16_t columns[n]{};
        uint16_t boxes[n]{};

        for (size_t i = 0; i < board.size(); ++i)
        {
            for (size_t j = 0; j < board[i].size(); ++j)
            {
                const auto c = board[i][j];

                if (c == '.')
                {
                    continue;
                }

                const uint16_t bit = 1 << (c - '1');
                const auto box_ind = i / base * base + j / base;

                if (rows[i] & bit || columns[j] & bit || boxes[box_ind] & bit) {
                    return false;
                }

                rows[i] |= bit;
                columns[j] |= bit;
                boxes[box_ind] |= bit;
            }   
        }

        return true;
    }
};