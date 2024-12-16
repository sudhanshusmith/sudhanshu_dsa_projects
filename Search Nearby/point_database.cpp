#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

class PointDatabase {
private:
    struct Node {
        Point point;
        vector<Point> y_sorted;
        Node* left;
        Node* right;

        Node(Point p) : point(p), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* build2DTree(vector<Point>& points) {
        if (points.empty()) return nullptr;
        int mid = points.size() / 2;
        Node* node = new Node(points[mid]);
        node->y_sorted = points;

        vector<Point> left_points(points.begin(), points.begin() + mid);
        vector<Point> right_points(points.begin() + mid + 1, points.end());

        node->left = build2DTree(left_points);
        node->right = build2DTree(right_points);
        return node;
    }

    void rangeQuery(Node* node, int x_min, int x_max, int y_min, int y_max, vector<Point>& result) {
        if (!node) return;

        // Check the current point
        if (x_min <= node->point.x && node->point.x <= x_max &&
            y_min <= node->point.y && node->point.y <= y_max) {
            result.push_back(node->point);
        }

        // Traverse left and right subtrees
        if (node->point.x >= x_min) {
            rangeQuery(node->left, x_min, x_max, y_min, y_max, result);
        }
        if (node->point.x <= x_max) {
            rangeQuery(node->right, x_min, x_max, y_min, y_max, result);
        }
    }

public:
    PointDatabase(vector<Point> points) {
        sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
            return a.x < b.x;
        });
        root = build2DTree(points);
    }

    vector<Point> searchNearby(int x_min, int x_max, int y_min, int y_max) {
        vector<Point> result;
        rangeQuery(root, x_min, x_max, y_min, y_max, result);
        return result;
    }
};

int main() {
    vector<Point> points = {{1, 2}, {3, 6}, {5, 8}, {4, 7}, {7, 2}, {6, 5}, {2, 4}};
    PointDatabase db(points);

    int x_min = 2, x_max = 6;
    int y_min = 3, y_max = 7;

    vector<Point> result = db.searchNearby(x_min, x_max, y_min, y_max);

    cout << "Points in range: ";
    for (const auto& p : result) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;
    return 0;
}
