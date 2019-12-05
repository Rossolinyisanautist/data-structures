#include<iostream>
#include<vector>

using namespace std;

struct point{
    int x, y;
};

bool isSafe(point p1, point p2) { 
    if (p1.x == p2.x) { 
        return true; }
  
    if (p1.y == p2.y) { 
        return true; }
  
    if (abs(p1.x - p2.x) == abs(p1.y - p2.y)) { 
        return true; 
    }
  
    return false; 
} 

int main() {
    vector<point> points;

    for(int i = 0; i < 8;i++) {
        string line;
        cin >> line;
        for(int j = 0; j < 8;j++) {
            if(s[j] == '*') {
                point p;
                temp.x = j;
                temp.y = i;
                points.push_back(p);
            }
        }
    }

    for(int i = 0; i < 8; i++) {
        point p1 = points[i];
        for(int j = 0; j < 8; j++) {
            if(i != j) {
                point p2 = points[j];
                if(isSafe(p1, p2)) { goto invalid; }
            }

        }
    }
    cout << "valid\n";
    return 0;
    invalid:
        cout << "invalid\n";
}