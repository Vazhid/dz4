

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int *bubble_sort(int *array, int array_size) {
    for (int i = 0; i < array_size - 1; i++) 
    {
      for (int j = (array_size - 1); j > i; j--)
      {
        if (array[j - 1] <= array[j])
        {
          int temp = array[j - 1];
          array[j - 1] = array[j];
          array[j] = temp;
        }
      }
    }
    return (array);
 }

int main() {
       int n;
       printf("Введите количество вершин в графе:\n");
       scanf("%d",&n);
       printf("\n");
       
       if(n<0){
           printf("Введите заново количество вершин, так как оно не может быть отрицательным!\n");
           scanf("%d",&n);
           printf("\n");
       }
       
       int mas[n][n];
       printf("Матрица смежности для данного графа:\n");
       for (int i=0;i<n;i++) {
           for (int j=0;j<n;j++) {
               if (i<j) {
                 mas[i][j]=-1+rand()%3;
               } else if(i==j) {
                   mas[i][j]=0;
               } else {
                   mas[i][j]=mas[j][i];
               }
               if (mas[i][j]==-1){
                   printf("%d  ",mas[i][j]);
               } else {
                   printf("%d   ",mas[i][j]);
               }
           }
           printf("\n");
       }
    
        printf("Введите номер вершины графа, которую вы хотите удалить (от 1 до %d):\n",n);
        int a;
        scanf("%d",&a);
        printf("\n");
        
   //удаление вершины
    int delarr[n-1][n-1];
    for (int i=0, ln=0; ln<n-1;){
        if(i != a-1){
            for (int j=0, cn=0; cn<n-1; j++, cn++){
                if (j==a-1) j++;
                delarr[ln][cn]=mas[i][j];
            }
            i++;
            ln++;
        } else i++;
    }
    //
    
    printf("Матрица смежности для модифицированного графа:\n");
    
    // вывод матрицы смежности полученного графа, после удаления вершины
        for (int i=0; i<n-1; i++) {
            for (int j=0; j<n-1; j++) {
                if (delarr[i][j]==-1){
                    printf("%d  ",delarr[i][j]);
                } else {
                    printf("%d   ",delarr[i][j]);
                }
            }
            printf("\n");
        }
    //
    
    // создание 2ух массивов со степенями вершин (один отсортированный, второй нет)
    int arr_s[n-1];
    int arr[n-1];
    for (int i = 0; i<n-1; i++){
        arr[i]=0;
    }
    for (int i = 0; i<n-1; i++){
        for (int j = 0; j<n-1; j++){
            if (delarr[i][j]==1 || delarr[i][j]==-1){
                arr[i]++;
            }
        }
    }
    for (int i = 0; i<n-1; i++){
        arr_s[i]=arr[i];
    }
    bubble_sort(arr_s, n);
    //
    
    for (int i = 0; i<n-1; i++){
        for (int j = 0; j<n-1; j++){
            if(arr_s[i]==arr[j]){
                printf("\nУ вершины с индексом %d степень равна %d\n",j+1,arr_s[i]);
                arr[j]=-10;
            }
        }
    }
    
    
    
    
    
    
    
    if (n<=10) {
        char *graph;
        graph = calloc(2048, sizeof(char));
        
        strcat(graph,"echo 'digraph G {");
        
        for(int i=0;i<n;i++) {
                char str0[2] = "0";
                str0[0] = i + '0';
                strcat(graph, str0);
                strcat(graph,";");
        }
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if (i<j) {
                    
                    if (mas[i][j]==1) {
                        char str1[2] = "0";
                        str1[0] = i + '0';
                        graph = strcat(graph, str1);
                        graph = strcat(graph, "->");
                        str1[0] ='\0';
                        
                        char str2[2] = "0";

                        str2[0] = j + '0';
                        graph = strcat(graph, str2);
                        graph = strcat(graph, ";");
                        str2[0] ='\0';
                    }
                    if (mas[i][j]==-1) {
                        char str3[2] = "0";
                        
                        str3[0] = j + '0';
                        graph = strcat(graph, str3);
                        graph = strcat(graph, "->");
                        str3[0] ='\0';

                        char str4[2] = "0";
                        str4[0] = i + '0';
                        graph = strcat(graph, str4);
                        graph = strcat(graph, ";");
                        str4[0] ='\0';

                    }
                }
            }
        }
        
    
        graph = strcat(graph,"}' | dot -Tpng >./graph.png");
        printf("");
        printf("%s\n",graph);
        system(graph);
    
    
        free(graph);
    }

    if (n<=10) {
        char *delgraph;
        delgraph = calloc(2048, sizeof(char));
        
        strcat(delgraph,"echo 'digraph G {");
        
        for(int i=0;i<n-1;i++) {
                char str5[2] = "0";
                str5[0] = i + '0';
                strcat(delgraph, str5);
                strcat(delgraph,";");
        }
        
        for(int i=0;i<n-1;i++) {
            for(int j=0;j<n-1;j++) {
                if (i<j) {
                    
                    if (delarr[i][j]==1) {
                        char str6[2] = "0";
                        str6[0] = i + '0';
                        delgraph = strcat(delgraph, str6);
                        delgraph = strcat(delgraph, "->");
                        str6[0] ='\0';
                        
                        char str7[2] = "0";

                        str7[0] = j + '0';
                        delgraph = strcat(delgraph, str7);
                        delgraph = strcat(delgraph, ";");
                        str7[0] ='\0';
                    }
                    if (delarr[i][j]==-1) {
                        char str8[2] = "0";
                        
                        str8[0] = j + '0';
                        delgraph = strcat(delgraph, str8);
                        delgraph = strcat(delgraph, "->");
                        str8[0] ='\0';

                        char str9[2] = "0";
                        str9[0] = i + '0';
                        delgraph = strcat(delgraph, str9);
                        delgraph = strcat(delgraph, ";");
                        str9[0] ='\0';

                    }
                }
            }
        }
        
    
        delgraph = strcat(delgraph,"}' | dot -Tpng >./delgraph.png");
        printf("");
        printf("%s\n",delgraph);
        system(delgraph);
    
    
        free(delgraph);
    }
    
}
