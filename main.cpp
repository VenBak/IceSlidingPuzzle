#include <iostream>
#include <vector>
#include <fstream>
#include <cassert>

using namespace std;

const char ICE_CELL = '.';
const char ROCK_CELL = 'r';
const char FLAMINGO_CELL = 'f';
const char FLAMINGO_ON_RESCUE_CELL = 'F';
const char RESCUE_CELL = 'x';
const char UNKNOWN_CELL = '?';

enum Action
{
    MoveNorth,
    MoveEast,
    MoveSouth,
    MoveWest,
    Reset,
    Quit,
    Invalid
};

struct Puzzle
{
    // TODO: design your puzzle data structure
    // Terrain to traverse
    vector<vector<char>> Map;
    // Current position of the FLamingo
    int flamingoRow;
    int flamingoCol;
    // Current position of the solution
};

bool operator==(const Puzzle &lhs, const Puzzle &rhs)
{ // Precondition:
    assert(true);
    /*  Postcondition: return value is true if `lhs` and `rhs` have the same puzzle state
     */
    return lhs.Map == rhs.Map;
}

bool operator!=(const Puzzle &lhs, const Puzzle &rhs)
{ // Precondition:
    assert(true);
    /*  Postcondition: return value is true if `!(lhs == rhs)`
     */
    return !(lhs == rhs);
}

bool is_solved(const Puzzle &puzzle)
{ // Precondition:
    assert(true);
    /*  Postcondition: return value is true if the flamingo is at the rescue position in `puzzle`
     */
    if ((puzzle.flamingoCol >= 0 && puzzle.flamingoCol <= ssize(puzzle.Map.at(0)) - 1) && (puzzle.flamingoRow >= 0 && puzzle.flamingoRow <= ssize(puzzle.Map) - 1))
        return (puzzle.Map.at(puzzle.flamingoRow).at(puzzle.flamingoCol) == RESCUE_CELL) || (puzzle.Map.at(puzzle.flamingoRow).at(puzzle.flamingoCol) == FLAMINGO_ON_RESCUE_CELL);
    return false;
}

bool is_solvable(const Puzzle &puzzle)
{ // Precondition:
    assert(true);
    /*  Postcondition: return value is true if the flamingo in `puzzle` is alive
     */
    // TODO: implement this function
    // Check if the flamingo is in a valid position (not on a rock and within bounds)

    if (!(puzzle.flamingoCol >= 0 && puzzle.flamingoCol <= ssize(puzzle.Map.at(0)) - 1))
    {
        return false;
    }
    if (!(puzzle.flamingoRow >= 0 && puzzle.flamingoRow <= ssize(puzzle.Map) - 1))
    {
        return false;
    }
    char currentCell = puzzle.Map.at(puzzle.flamingoRow).at(puzzle.flamingoCol);
    if (currentCell == FLAMINGO_ON_RESCUE_CELL)
        return false;

    if (currentCell == ROCK_CELL)
        return false;

    return true;
}

ostream &operator<<(ostream &os, const Puzzle &puzzle)
{ // Precondition:
    assert(true);
    /*  Postcondition: `puzzle` has been printed to `os`
     */
    // TODO: implement this function
    for (int i = 0; i < ssize(puzzle.Map); i++)
    {
        const vector<char> &row = puzzle.Map.at(i);

        for (int j = 0; j < ssize(row); j++)
        {
            os << row.at(j) << ' ';
        }

        os << '\n';
    }
    return os;
}

bool load_puzzle(const vector<vector<char>> &field, Puzzle &puzzle)
{ // Precondition:
    assert(true);
    /*  Postcondition: return value is true if `field` denotes a valid puzzle, in which case `field` has been parsed into `puzzle`
     */
    // TODO: implement this function
    int x_count = 0;
    int f_count = 0;
    vector<char> puzzle_line;
    vector<vector<char>> puzzle_total;

    // Inside each row
    for (int i = 0; i < ssize(field); i++)
    {
        // Check if the length of each line is equal
        int width = ssize(field.at(0));
        if (width != ssize(field.at(i)))
        {
            return false;
        }

        // Inside each char of a specific line
        for (int j = 0; j < ssize(field.at(i)); j++)
        {
            // If there is no exit point x or the flamingo is already on the exit increment the number
            if (field.at(i).at(j) == RESCUE_CELL || field.at(i).at(j) == FLAMINGO_ON_RESCUE_CELL)
            {
                x_count++;
            }
            // If there is more than one flamingo add 1 to the counter of flamingos
            if (field.at(i).at(j) == FLAMINGO_CELL || field.at(i).at(j) == FLAMINGO_ON_RESCUE_CELL)
            {
                puzzle.flamingoRow = i;
                puzzle.flamingoCol = j;
                f_count++;
            }
            //  If the char is not an option for the possibilities return false
            if (field.at(i).at(j) != FLAMINGO_CELL && field.at(i).at(j) != ICE_CELL && field.at(i).at(j) != RESCUE_CELL && field.at(i).at(j) != FLAMINGO_ON_RESCUE_CELL && field.at(i).at(j) != ROCK_CELL && field.at(i).at(j) != UNKNOWN_CELL)
            {
                return false;
            }
        }
    }
    if (f_count > 1 || f_count == 0)
    {
        return false;
    }
    if (x_count < 1)
    {
        return false;
    }
    puzzle.Map = field;
    return true;
}

bool read_puzzle(istream &is, Puzzle &puzzle)
{ // Precondition:
    assert(true);
    /*  Postcondition: return value is true if a valid puzzle has been read from `is`, in which case it is stored in `puzzle`
     */
    vector<vector<char>> field;
    vector<char> line;
    char c;

    // Convert `is` to a 2d array of chars.
    while (is.get(c))
    {
        if (c == '\n')
        {
            field.push_back(line);
            line = {};
        }
        else
        {
            line.push_back(c);
        }
    }

    if (!line.empty())
    {
        field.push_back(line);
    }

    // Attempt to parse the 2d arrays of chars into a proper puzzle.
    return load_puzzle(field, puzzle);
}

bool open_puzzle(string file, Puzzle &puzzle)
{ // Precondition:
    assert(true);
    /*  Postcondition: return value is true if a puzzle has been successfully read from filename `file` into `puzzle`
     */
    ifstream fs(file);

    if (!fs.is_open())
    {
        cout << "Failed to open file" << endl;
        return false;
    }
    else if (!read_puzzle(fs, puzzle))
    {
        cout << "Failed to read puzzle" << endl;
        return false;
    }

    cout << "Loaded the puzzle shown below:\n";
    cout << puzzle << endl;

    return true;
}

Action get_action()
{ // Precondition:
    assert(true);
    /*  Postcondition: return value is action chosen by user.
     */
    cout << "Pick an action: " << endl;
    cout << "'n': Move north" << endl;
    cout << "'e': Move east" << endl;
    cout << "'s': Move south" << endl;
    cout << "'w': Move west" << endl;
    cout << "'r': Reset" << endl;
    cout << "'q': Quit" << endl;
    cout << "> ";

    char c;
    cin >> c;

    switch (c)
    {
    case 'n':
        return MoveNorth;
    case 'e':
        return MoveEast;
    case 's':
        return MoveSouth;
    case 'w':
        return MoveWest;
    case 'r':
        return Reset;
    case 'q':
        return Quit;
    default:
        return Invalid;
    }
}

bool check_rock(Puzzle &puzzle, Action action)
{
    // Pre-condition:
    assert(puzzle.flamingoCol>=0 && puzzle.flamingoRow>=0
    && puzzle.flamingoRow<ssize(puzzle.Map) && puzzle.flamingoCol<ssize(puzzle.Map.at(0)));

    /* Post-condition:  if in bounds, check for rock in direction of travel,
     if at the edge, continue moving without accesing the vector as it would return an error */

    switch (action)
    {
    case MoveNorth:
        if (puzzle.flamingoRow > 0)
        {
            return (puzzle.Map.at(puzzle.flamingoRow - 1).at(puzzle.flamingoCol) != ROCK_CELL);
        }
        else
        {
            puzzle.flamingoRow--;
            return false;
        }

    case MoveSouth:

        if (puzzle.flamingoRow < ssize(puzzle.Map) - 1)
        {
            return (puzzle.Map.at(puzzle.flamingoRow + 1).at(puzzle.flamingoCol) != ROCK_CELL);
        }
        else
        {
            puzzle.flamingoRow++;
            return false;
        }

    case MoveWest:
        if (puzzle.flamingoCol > 0)
        {
            return (puzzle.Map.at(puzzle.flamingoRow).at(puzzle.flamingoCol - 1) != ROCK_CELL);
        }
        else
        {
            puzzle.flamingoCol--;
            return false;
        }

    case MoveEast:
        if (puzzle.flamingoCol < ssize(puzzle.Map.at(0)) - 1)
        {
            return (puzzle.Map.at(puzzle.flamingoRow).at(puzzle.flamingoCol + 1) != ROCK_CELL);
        }
        else
        {
            puzzle.flamingoCol++;
            return false;
        }

    default:
        return false;
    }
    return false;
}

#ifndef TESTING
int main()
{ // Precondition:
    assert(true);
    /*  Postcondition: the user chosen puzzle file has been read and played.
     */
    string file;
    Puzzle puzzle;

    cout << "Enter file to open: ";
    getline(cin, file);

    if (!open_puzzle(file, puzzle))
    {
        return 1;
    }
    else if (is_solved(puzzle))
    {
        cout << "This puzzle is already solved!" << endl;
        return 0;
    }

    Puzzle initial_puzzle = puzzle;
    int steps = 0;
    Action action;

    while ((action = get_action()) != Quit)
    {
        switch (action)
        {
        case MoveNorth:
            while (is_solvable(puzzle) && check_rock(puzzle, MoveNorth))
            {

                if (puzzle.Map.at(puzzle.flamingoRow - 1).at(puzzle.flamingoCol) == RESCUE_CELL)
                {
                    puzzle.Map.at(--puzzle.flamingoRow).at(puzzle.flamingoCol) = FLAMINGO_ON_RESCUE_CELL;
                    puzzle.Map.at(puzzle.flamingoRow + 1).at(puzzle.flamingoCol) = ICE_CELL;
                }
                else
                {
                    puzzle.Map.at(--puzzle.flamingoRow).at(puzzle.flamingoCol) = FLAMINGO_CELL;
                    puzzle.Map.at(puzzle.flamingoRow + 1).at(puzzle.flamingoCol) = ICE_CELL;
                }
            }

            steps++;
            break;
        case MoveEast:
            while (is_solvable(puzzle) && check_rock(puzzle, MoveEast))
            {
                if (puzzle.Map.at(puzzle.flamingoRow).at(puzzle.flamingoCol + 1) == RESCUE_CELL)
                {
                    puzzle.Map.at(puzzle.flamingoRow).at(++puzzle.flamingoCol) = FLAMINGO_ON_RESCUE_CELL;
                    puzzle.Map.at(puzzle.flamingoRow).at(puzzle.flamingoCol - 1) = ICE_CELL;
                }
                else
                {

                    puzzle.Map.at(puzzle.flamingoRow).at(++puzzle.flamingoCol) = FLAMINGO_CELL;
                    puzzle.Map.at(puzzle.flamingoRow).at(puzzle.flamingoCol - 1) = ICE_CELL;
                }
            }
            steps++;
            break;
        case MoveSouth:
            while (is_solvable(puzzle) && check_rock(puzzle, MoveSouth))
            {
                if (puzzle.Map.at(puzzle.flamingoRow + 1).at(puzzle.flamingoCol) == RESCUE_CELL)
                {
                    puzzle.Map.at(++puzzle.flamingoRow).at(puzzle.flamingoCol) = FLAMINGO_ON_RESCUE_CELL;
                    puzzle.Map.at(puzzle.flamingoRow - 1).at(puzzle.flamingoCol) = ICE_CELL;
                }
                else
                {
                    puzzle.Map.at(++puzzle.flamingoRow).at(puzzle.flamingoCol) = FLAMINGO_CELL;
                    puzzle.Map.at(puzzle.flamingoRow - 1).at(puzzle.flamingoCol) = ICE_CELL;
                }
            }
            steps++;
            break;
        case MoveWest:
            while (is_solvable(puzzle) && check_rock(puzzle, MoveWest))
            {

                if (puzzle.Map.at(puzzle.flamingoRow).at(puzzle.flamingoCol - 1) == RESCUE_CELL)
                {
                    puzzle.Map.at(puzzle.flamingoRow).at(--puzzle.flamingoCol) = FLAMINGO_ON_RESCUE_CELL;
                    puzzle.Map.at(puzzle.flamingoRow).at(puzzle.flamingoCol + 1) = ICE_CELL;
                }
                else
                {

                    puzzle.Map.at(puzzle.flamingoRow).at(--puzzle.flamingoCol) = FLAMINGO_CELL;
                    puzzle.Map.at(puzzle.flamingoRow).at(puzzle.flamingoCol + 1) = ICE_CELL;
                }
            }
            steps++;
            break;
        case Reset:
            puzzle = initial_puzzle;
            steps = 0;
            break;
        case Invalid:
        case Quit: // dummy case to suppress compiler warning
            cout << "Invalid action" << endl;
            break;
        }

        cout << puzzle << endl;

        if (is_solved(puzzle))
        {
            cout << "Congratulations, you have completed the puzzle in " << steps << " steps!" << endl;
            return 0;
        }
        else if (!is_solvable(puzzle))
        {
            cout << "Oh no, the flamingo has drowned!" << endl;
            puzzle = initial_puzzle;
            steps = 0;
            cout << puzzle << endl;
        }
    }

    return 0;
}
#endif
