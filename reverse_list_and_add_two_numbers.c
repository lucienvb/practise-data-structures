#include <stdlib.h>
#include <stdio.h>

typedef struct s_list {
    void        *data;
    struct s_list *next;
}               t_list;

t_list	*add_two_numbers(t_list *l1, t_list *l2) {
	int		*val1;
	int		*val2;
	int		hold;
	t_list	*prev = NULL;
	t_list	*head = NULL;

	hold = 0;
	val1 = malloc(sizeof(int));
	if (!val1)
		return NULL;
	val2 = malloc(sizeof(int));
	if (!val2)
		return NULL;
	while (l1 || l2 || hold > 0) {
		*val1 = 0;
		*val2 = 0;
		t_list	*new = malloc(sizeof(t_list));
		if (!new)
			return NULL;
		new->next = NULL;
		if (!head)
			head = new;
		if (prev)
			prev->next = new;
		if (l1) {
			val1 = l1->data;
			l1 = l1->next;
		}
		if (l2) {
			val2 = l2->data;
			l2 = l2->next;
		}
		int *temp = malloc(sizeof(int));
		if (!temp)
			return NULL;
		*temp = *val1 + *val2 + hold;
		if (*temp > 0) {
			hold = *temp / 10;
			*temp %= 10;
		}
		else
			hold = 0;
		new->data = (void *)temp;
		prev = new;
	}
	return head;
}

t_list  *create_list(int count) {
    t_list  *head;
    t_list  *walker;
    int     i = 0;

    while (i < count) {
        t_list  *new = malloc(sizeof(t_list));
        if (!new)
            return NULL;
        new->next = NULL;
        int *value = malloc(sizeof(int));
        if (!value)
            return NULL;
        *value = i;
        new->data = (void *)value;
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

void	free_list(t_list *list) {
	if (list == NULL)
		return ;

	free_list(list->next);
	free(list);
}


void	reverse_list(t_list **head) {
	t_list	*prev = NULL;
	t_list	*current = *head;
	t_list	*next;
	
	while (current) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head = prev;
}

void	print_list(t_list *head) {
	while (head) {
		int	*val = head->data;
		printf("%i ", *val);
		head = head->next;
	}
}

int	main(void) {
	t_list *l1 = create_list(10);
	t_list *l2 = create_list(7);

	t_list *aggregated_list = add_two_numbers(l1, l2);
	print_list(aggregated_list);

	free(l1);
	free(l2);
	free(aggregated_list);
	return 0;
}

// int main(void) {
// 	t_list	*list = create_list(20);
// 	t_list	*head = list;

// 	printf("Original\n");
// 	print_list(head);
// 	reverse_list(&head);
// 	printf("\nReversed\n");
// 	print_list(head);
// 	free_list(head);
// }
