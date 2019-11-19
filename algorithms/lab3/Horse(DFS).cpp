#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Graph{
    private:
        vector <vector <int> > arr;
        vector <bool> visited;
        int size, side, count;
        vector <pair <int, int> > all_cells(int m, int n){
            vector <pair <int, int> > result;

            result.push_back(make_pair(m - 2, n - 1));
            result.push_back(make_pair(m - 2, n + 1));

            result.push_back(make_pair(m - 1, n - 2));
            result.push_back(make_pair(m - 1, n + 2));

            result.push_back(make_pair(m + 1, n - 2));
            result.push_back(make_pair(m + 1, n + 2));

            result.push_back(make_pair(m + 2, n - 1));
            result.push_back(make_pair(m + 2, n + 1));

            return result;
        }
    public:
        void create(int side){
            this->side = side; size = side*side;

            for(int i = 0; i < side; i++){
                for(int j = 0; j < side; j++){
                    vector <int> points;
                    vector <pair <int, int> > cells = all_cells(i, j);
                    // cout << i << ' ' << j << endl;
                    // cout << cells.size() << endl;
                    for(int k = 0; k < cells.size(); k++){
                        int y = cells[k].first, x = cells[k].second;
                        if(0 <= x && x < side && 0 <= y && y < side){
                            points.push_back(y * side + x);
                        }
                    }
                    arr.push_back(points);
                    visited.push_back(false);
                }
            }
            /*
            for(int i = 0; i < size; i++){
                vector <int> points;
                arr.push_back(points);
                visited.push_back(false);
            }
            */
        }
        void addConn(int parent, int point){
            arr[parent].push_back(point);
        }

        void clear_visited(){
            for(int i = 0; i < size; i++){
                visited[i] = false;
            }
        }

        void sort_all(){
            for(int i = 0; i < size; i++){
                sort(arr[i].begin(), arr[i].end());
            }
        }

        void print(){
            for(int i = 0; i < arr.size(); i++){
                cout << i << " - ";
                for(int j = 0; j < arr[i].size(); j++)
                    cout << arr[i][j] << ' ';
                cout << endl;
            }
        }
        void set_visited(int index){
            visited[index] = true;
            count = 1;
        }
        vector <int> find_way(int from, int to){
            vector <int> result;
            bool found = false;
            for(int i = 0; i < arr[from].size(); i++){
                if(arr[from][i] == to){
                    found = true;
                    break;
                }
            }
            if(found && count == size){
                result.push_back(from);
                result.push_back(to);
            }
            else{
                for(int i = 0; i < arr[from].size(); i++){
                    if(visited[arr[from][i]] == false){
                        if(visited[arr[from][i]] == false) count += 1;
                        visited[arr[from][i]] = true;
                        result = find_way(arr[from][i], to);
                        if(result.size() > 0){
                            result.push_back(0);
                            for(int i = (result.size() - 1); i >= 1; i--){
                                result[i] = result[i - 1];
                            }
                            result[0] = from;
                            break;
                        }
                    }
                }
            }
            return result;
        }
};

/*
int main(){

    int v, a; cin >> v >> a;
    int parent, point, first, last;


    Graph graph;
    graph.create(v);

    // cin >> first; graph.createPoint(first);
    // parent = first;


    for(int i = 0; i < a; i++){
        scanf("%d %d", &parent, &point);
        graph.addConn(parent, point);
    }

    // last = point;

    // graph.print(); cout << endl << endl;

    bool found = false;
    for(int i = 0; i < v; i++){
        graph.clear_visited();
        vector <int> way = graph.find_way(i, i);
        if(way.size() > 0){
            cout << "Cycle:" << endl;
            for(int i = 0; i < (way.size() - 1); i++){
                cout << way[i] << ' ';
            }
            found = true;
            break;
        }
    }
    if(!found) cout << "No cycles";

    return 0;
}
*/


int main(){
    int side; cin >> side;
    int xs, ys; cin >> xs >> ys;

    Graph graph;
    graph.create(side);


    graph.print();

    graph.clear_visited();
    graph.set_visited(xs*side + ys);

    vector <int> res = graph.find_way(xs*side + xs, xs*side + xs);
    for(int i = 0; i < res.size(); i++) cout << res[i] << " ";


    return 0;
}
