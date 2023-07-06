//cmp gcc -o rush-02 main.c
#include "rush02.h"

int main(int argc, char* argv[]){

    int nb;
    char *dictionary_file = NULL;
    char *result = "";
    char **dictionary_splited;
    t_dictionary **dictionary;

    if (argc < 2 || argc > 3) {
        write(1, "Error\n", 6);
        return 1;
    }
    else{
        verify_number(&nb, argc, argv, &dictionary_file);
        //se for 1 argumento    
        int file = open(dictionary_file, O_RDONLY);
        if(file > 0)
        {
            dictionary = malloc(sizeof(t_dictionary));

            while(result){
                result = get_next_line(file);
                if(!result)
                    break;
                if(result[0] == '\n')
                    continue;
                dictionary_splited = ft_split(result, ':');
                create_dictionary(dictionary_splited,dictionary);
            }  
            bubble_sort(dictionary);
            print_dictionary(*dictionary);
            
            t_dictionary* current = *dictionary;
            while (current != NULL) {
                //printf("nb: %d, str_number: %s\n", current->nb, current->str_number);
                if()
                
                
                current = current->next;
            }
        
        } 

    }
}
