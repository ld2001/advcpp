#include "maze.h"
#include "path.h"
#include<queue>
#include<vector>
#include<list>
#include<tuple>
#include<utility>
#include<iostream>
#include<climits>
#include<sstream>
#include<stack>
#include<unordered_map>
#include<map>
#include<set>
#include<functional>

using namespace std;

path solve_dfs(Maze& m, int rows, int cols);
path solve_bfs(Maze& m, int rows, int cols);
path solve_dijkstra(Maze& m, int rows, int cols);
path solve_tour(Maze& m, int rows, int cols);


int main(int argc, char** argv)
{
    if(argc != 4)
    {
        cerr << "usage:\n"
             << "./maze option rows cols\n"
             << " options:\n"
             << "  -dfs: depth first search (backtracking)\n"
             << "  -bfs: breadth first search\n"
             << "  -dij: dijkstra's algorithm\n"
             << "  -tour: all corners tour\n"
             << "  -basic: run dfs, bfs, and dij\n"
             << "  -advanced: run dfs, bfs, dij and tour" << endl;
        return 0;
    }
    string opt(argv[1]);

    int rows, cols;
    stringstream s;
    s << argv[2] << " " << argv[3];
    s >> rows >> cols;

    // construct a new random maze;
    Maze m(rows, cols);

    // print the initial maze out
    cout << "Initial maze" << endl;
    m.print_maze(cout, opt == "-dij" || opt == "-tour");

    if(opt == "-dfs")
    {
        cout << "\nSolved dfs" << endl;
        path p = solve_dfs(m, rows, cols);
        m.print_maze_with_path(cout, p, false, false);
    }


    if(opt == "-bfs")
    {
        cout << "\nSolved bfs" << endl;
        path p = solve_bfs(m, rows, cols);
        m.print_maze_with_path(cout, p, false, false);
    }

    if(opt == "-dij")
    {
        cout << "\nSolved dijkstra" << endl;
        path p = solve_dijkstra(m, rows, cols);
        m.print_maze_with_path(cout, p, true, false);
    }

    if(opt == "-tour")
    {
        cout << "\nSolved all courners tour" << endl;
        path p = solve_tour(m, rows, cols);
        m.print_maze_with_path(cout, p, true, true);
    }
    if(opt == "-basic")
    {
        cout << "\nSolved dfs" << endl;
        path p = solve_dfs(m, rows, cols);
        m.print_maze_with_path(cout, p, false, false);

        cout << "\nSolved bfs" << endl;
        p = solve_bfs(m, rows, cols);
        m.print_maze_with_path(cout, p, false, false);

        cout << "\nSolved dijkstra" << endl;
        p = solve_dijkstra(m, rows, cols);
        m.print_maze_with_path(cout, p, true, false);
    }
    if(opt == "-advanced")
    {
        cout << "\nSolved dfs" << endl;
        path p = solve_dfs(m, rows, cols);
        m.print_maze_with_path(cout, p, false, false);

        cout << "\nSolved bfs" << endl;
        p = solve_bfs(m, rows, cols);
        m.print_maze_with_path(cout, p, false, false);

        cout << "\nSolved dijkstra" << endl;
        p = solve_dijkstra(m, rows, cols);
        m.print_maze_with_path(cout, p, true, false);

        cout << "\nSolved all courners tour" << endl;
        p = solve_tour(m, rows, cols);
        m.print_maze_with_path(cout, p, true, true);
    }
}

bool pointEqual (point a, point b) {

    if(a.first == b.first && a.second == b.second)
    {
        return true;
    }
    return false;
}



path solve_dfs(Maze& m, int rows, int cols)
{
    // initialize a vector for directions for easier iterations
    vector<int> directions {0,1,2,3};

    // Set your end and current points
    point end = make_pair(rows-1,cols-1);
    point current = make_pair(0,0);

    list<point> returnList;

    // Create visited array
    bool ** visited = new bool*[rows];

    // Visited array all set to false
    for(int i = 0; i < rows; i++)
    {
        visited[i] = new bool[cols];
        for(int j = 0; j < cols; j++)
        {
            visited[i][j] = false;
        }
    }

    // Dfs stack used to track points;
    stack<pair<int,int>> s;

    // Visit starting and push it onto stack
    visited[current.first][current.second] = true;
    s.push(current);


    // Our goal is to iteratively visit all possible paths from our current position (DFS). We do this with a stack that keeps track of all our paths and a visited array that tracks where we have visited
    // Everytime we visit a point we push that point onto the stack, move current to that point, and check all the neighbors to see if they are non-visited points. We visit the non visited points (if any).
    // If we run out of non visited points and we aren't at the end point, then we pop the stack, we set the current to the top, and carry on again. If our current is ever pointing to the end, we stop and output path.
    bool noDirection;
    point proposed;

    while(!s.empty()){
        cout << s.size() << endl;
        noDirection = true;

        // if current is equal to the end
        if (pointEqual(current,end))
        {
            break;
        }

        for(int i: directions)
        {
            proposed = current + moveIn(i);

            if(m.can_go(i,current.first,current.second) && !visited[proposed.first][proposed.second] ){
                current = current + moveIn(i);
                s.push(current);
                visited[current.first][current.second] = true;
                noDirection = false;
                break;
            }
        }



        // No further directions move back
        if(noDirection && !s.empty()){
            s.pop();
            if(!s.empty())
            {
                current = s.top();
            }
        }
    }

    while(!s.empty())
    {
        returnList.push_front(s.top());
        s.pop();
    }

    cout << "list" << endl;

    return returnList;
}

path solve_bfs(Maze& m, int rows, int cols)
{
    // initialize a vector for directions for easier iterations
    vector<int> directions {0,1,2,3};

    // Set your end and current points
    point end = make_pair(rows-1,cols-1);
    point current = make_pair(0,0);

    // Initialize maps with empty array
    map<point, list <point>> pathMap;
    list<point> empty;
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            pathMap[make_pair(i,j)] = empty;
        }
    }


    // Initialize a queue
    queue<point> orderQueue;

    // Initialize a visited set
    set<point> visitedSet;

    // Put the current into the queue
    // Add current to its map
    // Add current to visited
    orderQueue.push(current);
    pathMap[current].push_back(current);
    visitedSet.insert(current);

    // While the queue is not empty:
    while( !orderQueue.empty())
    {
        current = orderQueue.front();
        orderQueue.pop();

        if(current == end)
        {
            break;
        }
        // For each direction you can visit, if it's not visited
        for(int i: directions)
        {
            // If you can visit that direction
                // Temp = direction
                // Add temp to queue
                // Take currents map and add it to temp map and append temp
                // Add temp to visited
            point temp = current + moveIn(i);

            if(m.can_go(i,current.first,current.second) && (visitedSet.find(temp) == visitedSet.end()))
            {
               orderQueue.push(temp);
               visitedSet.insert(temp);
               pathMap[temp] = pathMap[current];
               pathMap[temp].push_back(temp);
            }
        }
    }

    if (current == end) {
        return pathMap[current];
    }

    return empty;
}

path solve_dijkstra(Maze& m, int rows, int cols)
{

    // initialize a vector for directions for easier iterations
    vector<int> directions {0,1,2,3};

    // Set your end and current points
    point end = make_pair(rows-1,cols-1);
    point current = make_pair(0,0);

    class Node {
    public:
        point loc;
        int cost;

        Node(point a, int b){
            this->loc = a;
            this->cost = b;
        }
    };

    struct Comp {
        bool operator()(Node &a, Node &b) {
            return a.cost > b.cost;
        }
    };

    // Initialize a priority queue
    priority_queue<Node> orderQueue;

    // Initialize a visited set
    set<point> visitedSet;

    // Initialize a previous map
    map <point,point > previousPath;

    previousPath[current] = current;

    Node currentNode(current,0);

    // Put the current into the queue
    // Add current to visited
    orderQueue.push(currentNode);
    visitedSet.insert(current);


    // Max elements = rows * columns
    int max = rows * cols;

    map <point, int> costMatrix;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            costMatrix[make_pair(i,j)] = max;
        }
    }

    // Lambda to visit all the local cells
    auto visitPoint = [](point a)
    {
        std::cout << message << "\n";
    };


    // Create a  visited set

    // Create a map of previous point

    // Create a priority queue, and set every container equal max value

    // While queue is not empty and visited set size != max elements

        //  If the element is not in the visited set, throw it out and continue
        // Else:
            // Call visit neighbor on the function
            // Add to visited set

    // Add traceback alogirthm for final



    return list<point>();
}

path solve_tour(Maze& m, int rows, int cols)
{
    return list<point>();
}
