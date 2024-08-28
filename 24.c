#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Team {
    int id;
    int points;
    int pointsScored;
    int pointsAgainst;

    double getCestaAverage() const {
        return pointsAgainst == 0 ? pointsScored : static_cast<double>(pointsScored) / pointsAgainst;
    }

    bool operator<(const Team& other) const {
        if (points != other.points)
            return points > other.points;
        if (getCestaAverage() != other.getCestaAverage())
            return getCestaAverage() > other.getCestaAverage();
        return id < other.id;
    }
};

int main() {
    int n, instance = 1;

    while (cin >> n && n != 0) {
        vector<Team> teams(n);
        for (int i = 0; i < n; ++i) {
            teams[i].id = i + 1;
            teams[i].points = 0;
            teams[i].pointsScored = 0;
            teams[i].pointsAgainst = 0;
        }

        int totalMatches = n * (n - 1) / 2;
        for (int i = 0; i < totalMatches; ++i) {
            int x, y, z, w;
            cin >> x >> y >> z >> w;

            teams[x - 1].pointsScored += y;
            teams[x - 1].pointsAgainst += w;

            teams[z - 1].pointsScored += w;
            teams[z - 1].pointsAgainst += y;

            if (y > w) {
                teams[x - 1].points += 2;
                teams[z - 1].points += 1;
            } else {
                teams[z - 1].points += 2;
                teams[x - 1].points += 1;
            }
        }

        sort(teams.begin(), teams.end());

        if (instance > 1) {
            cout << endl;
        }
        cout << "Instancia " << instance++ << endl;
        for (int i = 0; i < n; ++i) {
            if (i > 0) cout << " ";
            cout << teams[i].id;
        }
        cout << endl;
    }

    return 0;
}
