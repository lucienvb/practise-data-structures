#include <stdlib.h>
#include <stdio.h>

typedef struct s_list {
    void        	*data;
    struct s_list	*next;
}					t_list;

struct s_list *create_linked_list(int len) {
    t_list	*head;
    t_list	*walker;
	int		i = 0;
	    
    while (i < len) {
		t_list	*new = malloc(sizeof(t_list));
		if (!new)
			return NULL;

		int	*num = malloc(sizeof(int));
		if (!num)
			return NULL;
		*num = i;

		new->data = num;
		new->next = NULL;
		if (i == 0) {
			head = new;
			walker = new;
		}
		else {
			walker->next = new;
			walker = walker->next;
		}
		i++;
	} 
	return head;
}

void	reverse_iterate(t_list *head) {
	if (head == NULL)
		return ;
	reverse_iterate(head->next);
	printf("free data: %i\n", *((int *)head->data));
	free(head->data);
	free(head);
}

int main() { 
    t_list *list = create_linked_list(4);
	t_list *head = list;
    while (list) {
        printf("created data: %i\n", *((int *)list->data));
        list = list->next;
    }
	list = head;
	reverse_iterate(list);
    return 0;
}

