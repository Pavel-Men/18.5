
#include <iostream>
using namespace std;

class Player
{
    int points = 0;
    string name = "none";
public:
    Player() {}
    Player(int _points, string _name) : points(_points), name(_name) {}

    string getName() { return name; }
    int getPoints() { return points; }

    void setName(string& _name) { name = _name; }
    void setPoints(int& _points) { points = _points; }
};

int main()
{
    cout << "Enter the number of players: ";
    int count;
    cin >> count;

    Player* players = new Player[count];

    string name;
    int points;
    for (int i = 0; i < count; i++)
    {
        cout << "Enter the name of player #" << i + 1 << ": ";
        cin >> name;
        players[i].setName(name);
        cout << "Enter points of player #" << i + 1 << ": ";
        cin >> points;
        players[i].setPoints(points);
    }
    cout << endl;

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (players[i].getPoints() < players[j].getPoints())
            {
                swap(players[i], players[j]);
            }
        }
        cout << players[i].getName() << "\t" << players[i].getPoints() << endl;
    }
}
