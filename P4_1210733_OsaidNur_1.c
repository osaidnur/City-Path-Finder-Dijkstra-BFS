/* Name    : Osaid Hasan Nur
 * ID      : 1210733
 * Section : 1
 * Instructor : Ahmad Abusnaina
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 16

void insertCity(char city[30], char arr[MAX][30], int *);
int codeOf(char city[30], char cities[MAX][30], int);
void storePath(int parent[], int city);
int BFS(int adj[MAX][MAX], int, int, int);
int minDistance();
void Dijkstra(int src);
void findPath(int s, int v );

FILE *input, *output;
int numOfCities = 0;
int graph[MAX][MAX];
char cities[MAX][30] = {0};
int path_BFS[MAX];
int pathB_len = 0;
int path_Dijkstra[MAX];
int pathD_len = 0;

int predecessor[MAX]; /*predecessor of each vertex in shortest path*/
int pathLength[MAX];
int status[MAX];
int main()
{
    printf("***************** Welcome ***********************\n");
    input = fopen("cities.txt", "r");

    while (1)
    {
        printf("Choose the operation(1-4) : \n");
        printf("1- Load Cities\n");
        printf("2- Enter Starting City\n");
        printf("3- Enter Destination \n");
        printf("4- Exit \n");
        int sel;
        scanf("%d", &sel);
        char src[30], dest[30];

        // load the file and construct the graph
        if (sel == 1)
        {
            while (!feof(input))
            {
                char city1[30] = {0}, city2[30] = {0}, dis[20] = {0};
                fscanf(input, "%s%s%s", city1, city2, dis);
                insertCity(city1, cities, &numOfCities);
                insertCity(city2, cities, &numOfCities);
            }

            // int graph[numOfCities+1][numOfCities+1];
            //  initialize the graph
            for (int i = 0; i < numOfCities + 1; i++)
            {
                for (int j = 0; j < numOfCities + 1; j++)
                {
                    graph[i][j] = 0;
                }
            }

            // construct the undirected weighted graph
            rewind(input);
            while (!feof(input))
            {
                char city1[30] = {0}, city2[30] = {0}, dis[30] = {0}, dis2[30] = {0};
                int distance = 0;
                fscanf(input, "%s%s%s", city1, city2, dis);
                for (int i = 0; i < strlen(dis) - 2; i++)
                {
                    dis2[i] = dis[i];
                }
                distance = atoi(dis2);

                int c1 = codeOf(city1, cities, numOfCities);
                int c2 = codeOf(city2, cities, numOfCities);
                if (graph[c1][c2] == 0 && graph[c2][c1] == 0)
                {
                    graph[c1][c2] = graph[c2][c1] = distance;
                }
            }
        }

        // Enter the source
        else if (sel == 2)
        {
            printf("Enter the source city : ");
            scanf("%s", src);
            for (int k = 0; k < MAX; ++k)
            {
                path_BFS[k] = 0;
            }
            pathB_len = 0;
            path_BFS[pathB_len++] = codeOf(src, cities, numOfCities);
        }

        // Enter the destination
        else if (sel == 3)
        {
            printf("Enter the destination : ");
            scanf("%s", dest);
            printf("\n");
            BFS(graph, codeOf(src, cities, numOfCities), codeOf(dest, cities, numOfCities), numOfCities);
            int total = 0;
            for (int i = 0; i < pathB_len - 1; i++)
            {
                int distance = graph[path_BFS[i]][path_BFS[i + 1]];
                total += distance;
                printf("%s_____%dkm_____", cities[path_BFS[i]], distance);
            }
            printf("%s\n", cities[path_BFS[pathB_len - 1]]);
            printf("Total Distance  >>> %d km\n", total);
            printf("Number of edges >>> %d\n", pathB_len - 1);

            Dijkstra(codeOf(src, cities, numOfCities));
            findPath(codeOf(src, cities, numOfCities),codeOf(dest, cities, numOfCities));
        }

        // Exit the program and save the output to the file
        else if (sel == 4)
        {
            output = fopen("shortest_distance.txt", "w");

            fscanf(output, "******** BFS path from %s to %s  ***************************************\n ", cities[path_BFS[0]], cities[path_BFS[pathB_len - 1]]);
            int total = 0;
            for (int i = 0; i < pathB_len - 1; i++)
            {
                int distance = graph[path_BFS[i]][path_BFS[i + 1]];
                total += distance;
                fprintf(output, "%s_____%dkm_____", cities[path_BFS[i]], distance);
            }
            fprintf(output, "%s\n", cities[path_BFS[pathB_len - 1]]);
            fprintf(output, " Total Distance >>> %d km\n", total);
            
            fprintf(output,"******** Dijkstra path from %s to %s  ***************************************\n ", cities[s], cities[v]);
        for(int i=count; i>=1; i--)
                printf("%s    ",cities[path[i]]);
       
            printf("Data Stored to the file ...\n");

            printf("********** Thank you for using My Program  ************ \n");
            printf("-------------------- Good By -------------------------");
            break;
        }
        else
        {
            printf("Invalid input ! try again ...\n");
        }
    }

    fclose(input);
    return 0;
}

void insertCity(char city[30], char arr[MAX][30], int *n)
{
    for (int i = 0; i < *n; i++)
    {
        if (strcmp(arr[i], city) == 0)
            return;
    }
    strcpy(arr[*n], city);
    *n += 1;
}

int codeOf(char city[30], char cities[MAX][30], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(cities[i], city) == 0)
            return i;
    }
    return -1;
}

// Function to perform breadth-first search (BFS)
int BFS(int adj[MAX][MAX], int src, int dest, int n)
{
    int visited[MAX] = {0}; // Array to track visited cities
    int queue[MAX];         // Queue for BFS traversal
    int front = 0, rear = 0, found = 0;
    int parent[n]; // Array to store the parent cities
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1;
    }
    visited[src] = 1;    // Mark the source city as visited
    queue[rear++] = src; // Add the source city to the queue

    while (front != rear)
    {
        int currentCity = queue[front++];
        // Check if the destination city is found
        if (currentCity == dest)
        {
            printf("******** BFS path from %s to %s  ***************************************\n ", cities[src], cities[dest]);
            storePath(parent, dest);
            found = 1;
            break;
        }
        // Traverse all the adjacent cities
        for (int i = 0; i < n; i++)
        {
            // Check if the next city is connected and not visited
            if (graph[currentCity][i] > 0 && !visited[i])
            {
                visited[i] = 1;          // Mark the next city as visited
                parent[i] = currentCity; // Set the parent of next city
                queue[rear++] = i;       // Add the next city to the queue
            }
        }
    }

    if (!found)
        printf("No path found from %d to %d.\n", src, dest); // Destination city not found
}

void storePath(int parent[], int city)
{
    if (parent[city] == -1)
        return;
    storePath(parent, parent[city]);

    path_BFS[pathB_len++] = city;
}

// Dijkstra's Algorithm in C


void Dijkstra( int s)
{
        int i,current;

        /* Make all vertices 0orary */
        for(i=0; i<numOfCities; i++)
        {
                predecessor[i] =  -1;
                pathLength[i] = INT_MAX;
                status[i] = 0;
        }
        /* Make pathLength of source vertex equal to 0 */
        pathLength[s] = 0;

        while(1)
        {
                //Search for 0orary vertex with minimum pathLength
                //and make it current vertex*/
                current = minDistance( );

                if( current == -1 )
                        return;

                status[current] = 1;

                for(i=0; i<numOfCities; i++)
                {
                        //Checks for adjacent 0orary vertices 
                        if ( graph[current][i] !=0 && status[i] == 0 )
                                if( pathLength[current] + graph[current][i] < pathLength[i] )
                                {
                                        predecessor[i] = current;  
                                        pathLength[i] = pathLength[current] + graph[current][i];
                                }
                }
        }
}

//Returns the  vertex with minimum value of pathLength
 // Returns NIL if no 0orary vertex left or
 // all 0orary vertices left have pathLength infinity*/
int minDistance( )
{
        int i;
        int min = INT_MAX;
        int k = -1;
        for(i=0;i< numOfCities ;i++)
        {
                if(status[i] == 0 && pathLength[i] < min)
                {
                        min = pathLength[i];
                        k = i;
                }
        }
        return k;
}
int count = 0 ;
void findPath(int s, int v )
{
        int i,u;
        int path[MAX];         //stores the shortest path
        int shortdist = 0;      ///length of shortest path*/
       count = 0;          ///number of vertices in the shortest path*/

        //Store the full path in the array path
        while( v != s )
        {
                count++;
                path[count] = v;
                u = predecessor[v];
                shortdist += graph[u][v];
                v = u;
        }
        count++;
        path[count]=s;
        printf("******** Dijkstra path from %s to %s  ***************************************\n ", cities[s], cities[v]);
        for(i=count; i>=1; i--)
                printf("%s    ",cities[path[i]]);
        printf("\nTotal distance >>> %d\n", shortdist);
}
