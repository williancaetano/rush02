//cmp gcc -o rush-02 main.c
#include "rush02.h"

int main(int argc, char* argv[]){

    int nb;
    char *dicionary_file = NULL;
    char *result = "";
    char **dicionary_splited;
    t_dicionary **dicionary;

    if (argc < 2 || argc > 3) {
        write(1, "Erro\n", 5);
        return 1;
    }
    else{
        verify_number(&nb, argc, argv, &dicionary_file);
        //se for 1 argumento    
        int file = open(dicionary_file, O_RDONLY);
        printf("%i\n", file);
        if(file > 0)
        {
            dicionary = malloc(sizeof(t_dicionary));

            while(result){
                result = get_next_line(file);
                if(!result)
                    break;
                if(result[0] == '\n')
                    continue;
                dicionary_splited = ft_split(result, ':');
                create_dicionary(dicionary_splited,dicionary);
                printf("%s\n", result);
            }  

            printf("antes da ordenação\n");
            print_dicionary(*dicionary);
    

            bubble_sort(dicionary);
            //ordenar a lista
            
            printf("depois da ordenação\n");
            print_dicionary(*dicionary);
            
        } 

    }
}



// dicionary = malloc(sizeof(t_dicionary));

// dicionary.nb = 100;

// dicionary.nb = 1000;
// dicionary.str_number = 457;















































