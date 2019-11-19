#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

class Graph{
    private:
        vector <vector <int> > arr;
        vector <bool> visited;
        int size;
    public:
        void create(int n){
            size = n;
            for(int i = 0; i < size; i++){
                vector <int> points;
                arr.push_back(points);
                visited.push_back(false);
            }
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
                cout << i << ": ";
                for(int j = 0; j < arr[i].size(); j++)
                    cout << arr[i][j] << ' ';
                cout << endl;
            }
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
            if(found){
                result.push_back(from);
                result.push_back(to);
            }
            else{
                for(int i = 0; i < arr[from].size(); i++){
                    if(visited[arr[from][i]] == false){
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

    graph.sort_all();

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


    /*
    answer = graph.find_way(0, 2);
    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << ' ';
    }
    */
    // graph.findMin(last);



    return 0;
}
