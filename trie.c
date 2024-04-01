#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct s_trie {
    struct s_trie *children[ALPHABET_SIZE];
    bool        end_of_word;
}               t_trie;

t_trie	*create_word(char *word) {
	int	i = 0;
	t_trie	*current;
	t_trie	*head = malloc(sizeof(t_trie));
	if (!head)
		return NULL;
	for (int j = 0; j < ALPHABET_SIZE; j++)
		head->children[j] = NULL;
	while (word[i]) {
		int	i_cia = word[i] - 'a'; // index char in alphabet
		t_trie  *new = malloc(sizeof(t_trie));
		if (!new)
			return NULL;
		for (int j = 0; j < ALPHABET_SIZE; j++)
			new->children[j] = NULL;
		if (i == 0) {
			head->children[i_cia] = new;
			head->end_of_word = false;
		}
		else {
			current->children[i_cia] = new;
			current->end_of_word = false;
		}
		current = new;
		i++;
	}
	current->end_of_word = true;
	return head;
}

bool	validate_word(t_trie *head, char *word) {
	int	i = 0;

	while (word[i]) {
		int	i_cia = word[i] - 'a';
		if (!head->end_of_word && head->children[i_cia]) {
			// printf("%c", word[i]);
			head = head->children[i_cia];
			i++;
		}
		else
			return false;
	}
	return true;
}

void	free_trie(t_trie *head) {
	if (head) {
		for (int i = 0; i < ALPHABET_SIZE; i++) {
			free_trie(head->children[i]);
		}
		free(head);
	}
}

int main(void) {
	t_trie *test = create_word("doei");

	bool	result = validate_word(test, "dag");
	printf("\nresult: %i\n", result);
	free_trie(test);
	return 0;
}
