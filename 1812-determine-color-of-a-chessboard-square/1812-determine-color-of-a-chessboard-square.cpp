class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int x = coordinates[0]-'a';
        int y = coordinates[1]-'1';
        cout << x << " " << y << endl;
        return (x+y)&1;
    }
};