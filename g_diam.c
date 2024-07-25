#include <unistd.h>
#include <stdlib.h>

#define MAX_NODES 1000

int get_number(const char *str, int *i) {
    int num = 0;

    while (str[*i] >= '0' && str[*i] <= '9') {
        num = num * 10 + (str[*i] - '0');
        (*i)++;
    }
    return num;
}

int parse_input(const char *input, int map[MAX_NODES][MAX_NODES]) {
    int i = 0;
    int maxNode = -1;

    while (input[i]) 
    {
        int node1 = get_number(input, &i);

        if (input[i] != '-')
            return -1;

        i++; // Skip '-'

        int node2 = get_number(input, &i);

        while (input[i] == ' ') {
            i++;
        }

        if (node1 < MAX_NODES && node2 < MAX_NODES) {

            map[node1][node2] = 1;
            map[node2][node1] = 1;

            if (node1 > maxNode)
                maxNode = node1;
            if (node2 > maxNode)
                maxNode = node2;
        }
    }
    return maxNode;
}

void dfs(
    int node, 
    int map[MAX_NODES][MAX_NODES], 
    int num_nodes, 
    int visited[MAX_NODES], 
    int path_length, 
    int *max_path_length
    ) {

    visited[node] = 1;
    path_length++;

    if (path_length > *max_path_length) {
        *max_path_length = path_length;
    }

    for (int i = 0; i < num_nodes; i++) {
        if (map[node][i] && !visited[i]) {
            dfs(i, map, num_nodes, visited, path_length, max_path_length);
        }
    }

    visited[node] = 0; // Backtrack
}

int find_diameter(int map[MAX_NODES][MAX_NODES], int num_nodes) { // num_nodes is max_nodes + 1
    int max_path_length = 0;

    for (int i = 0; i < num_nodes; i++) {
        int visited[MAX_NODES] = {0};
        dfs(i, map, num_nodes, visited, 0, &max_path_length);
    }

    return max_path_length - 1; // Subtract 1 to get the number of edges
}

void write_number(int num) {
    if (num == 0) {
        write(1, "0", 1);
        return ;
    }
    char str[12];
    for (int i = 0; i < 12; i++)
        str[i] = '\0';
    int j = 0;
    while (num > 0) {
        str[j] = (num % 10) + '0';
        num /= 10;
        j++;
    }
    while (j >= 0) {
        write(1, &str[j], 1);
        j--;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        write(1, "\n", 1);
        return 0;
    }

    int map[MAX_NODES][MAX_NODES] = {0}; // Adjacency matrix

    int max_node = parse_input(argv[1], map);

    if (max_node > 0) {

        int diameter = find_diameter(map, max_node + 1);
        write_number(diameter);
        write(1, "\n", 1);
    } 
    else
        write(1, "0\n", 2); // If no valid input, output 0

    return 0;
}
