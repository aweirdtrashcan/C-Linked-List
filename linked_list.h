typedef struct node {
	int value;
	struct node *next;
} node_t;

node_t *create_new_node();
void print_list(node_t *head);
void insert_at_head(node_t **head, int value);
void insert_at_end(node_t **head, int value);
int pop(node_t **head);
int delete_node_at_index(node_t **head, int index);
node_t *find_node(node_t *head, int value);
void initialize_first_index(node_t **head, int value);
int get_node_size(node_t *head);