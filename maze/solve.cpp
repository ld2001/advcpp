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

path solve_dfs(Maze& m, int rows, int cols)
{
    return list<point>();
}

path solve_bfs(Maze& m, int rows, int cols)
{
    return list<point>();
}

path solve_dijkstra(Maze& m, int rows, int cols)
{
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< Updated upstream
    return list<point>();
=======
=======
>>>>>>> c75eeb806a9b550f506bad3610343859f25d6ba5

    // initialize a vector for directions for easier iterations
    vector<int> directions {0,1,2,3};

    // Set your end and current points
    point end = make_pair(rows-1,cols-1);
    point current = make_pair(0,0);

    // Create node class and comparator for priority queue
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
    priority_queue<Node, vector<Node>, Comp> orderQueue;

    // Initialize a visited set
    set<point> visitedSet;

    // Initialize a previous map
    map <point,point > previousPath;

    previousPath[current] = current;

    Node currentNode(current,0);

    // Put the current into the queue
    // Add current to visited
    orderQueue.push(currentNode);


    // Max elements = rows * columns
    int max = rows * cols;

    map <point, int> costMap;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            costMap[make_pair(i,j)] = max;
        }
    }

    costMap[current] = 0;

    while(!orderQueue.empty()) {
        if (visitedSet.find(orderQueue.top().loc) == visitedSet.end()) {
            currentNode.loc = orderQueue.top().loc;
            currentNode.cost = orderQueue.top().cost;
            current = currentNode.loc;
            visitedSet.insert(current);

            for(int i: directions)
            {
                point temp = current + moveIn(i);

                if(m.can_go(i,current.first,current.second) && (visitedSet.find(temp) == visitedSet.end()))
                {
                    if (costMap[temp] > costMap[current] + m.cost(current.first,current.second,i))
                    {
                        costMap[temp] = costMap[current] + m.cost(current.first,current.second,i);
                        previousPath[temp] = current;
                        orderQueue.push(Node(temp, costMap[temp]));
                    }
                }
            }

            if(current == end) {
                break;
            }
        }
        cout << orderQueue.size() << endl;
        orderQueue.pop();
    }

    list<point> returnList;

    if(current == end) {


        returnList.push_front(end);
        

        point begin(0,0);

        while(current != begin) {
            returnList.push_front(previousPath[current]);
            current = previousPath[current];
        }

    }

    return returnList;

//     Create a  visited set
//
//     Create a map of previous point
//
//     Create a priority queue, and set every container equal max value
//
//     While queue is not empty and visited set size != max elements
//
//          If the element is not in the visited set, throw it out and continue
//         Else:
//             Call visit neighbor on the function
//             Add to visited set
//
//     Add traceback alogirthm for final

<<<<<<< HEAD
>>>>>>> Stashed changes
=======
>>>>>>> c75eeb806a9b550f506bad3610343859f25d6ba5
=======
    return list<point>();
>>>>>>> parent of c75eeb8... Merge pull request #1 from ld2001/DSF
=======
    return list<point>();
>>>>>>> parent of c75eeb8... Merge pull request #1 from ld2001/DSF
}

path solve_tour(Maze& m, int rows, int cols)
{
    return list<point>();
}
